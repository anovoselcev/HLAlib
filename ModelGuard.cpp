#include "ModelGuard.hpp"
#include "BaseFederate.hpp"

namespace HLA {

/**
* @brief ModelGuard::ModelGuard
*/
    ModelGuard::ModelGuard(){}

/**
* @brief ModelGuard::ModelGuard
* @param fed
*/
    ModelGuard::ModelGuard(BaseFederate* fed) : _federate(fed){
        _start = std::chrono::steady_clock::now();
        if(_federate)
            lock = std::unique_lock<std::mutex>(_federate->_smutex);
        else
            throw std::runtime_error("Nullptr federate");

        if(_federate->_mode == ModelMode::THREADING)
            ThreadModelingControl();
        else
            FollowModelingControl();
    }

/**
* @brief ModelGuard::~ModelGuard
*/
    ModelGuard::~ModelGuard(){
        lock.unlock();
    }

/**
* @brief ModelGuard::ThreadModelingControl
*/
    void ModelGuard::ThreadModelingControl(){
        _federate->_cond.wait(lock,[this]{
            return _federate->_state==State::DOING;
        });
        _federate->_state = State::PROCESSING;
    }

/**
* @brief ModelGuard::FollowModelingControl
*/
    void ModelGuard::FollowModelingControl(){
        _federate->_state = State::PROCESSING;
        _federate->FollowModeling();
        _federate->_last_time = std::chrono::steady_clock::now();
    }
}
