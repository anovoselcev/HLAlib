#include "ModelGuard.hpp"

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
            ModelingControl<ModelMode::THREADING>();
        else if(_federate->_mode == ModelMode::FOLLOWING)
            ModelingControl<ModelMode::FOLLOWING>();
        else if(_federate->_mode == ModelMode::MANAGING)
            ModelingControl<ModelMode::MANAGING>();
    }

/**
* @brief ModelGuard::~ModelGuard
*/
    ModelGuard::~ModelGuard(){
        lock.unlock();
    }

    template<>
    void ModelGuard::ModelingControl<ModelMode::THREADING>(){
        _federate->_cond.wait(lock,[this]{
            return _federate->_state==State::DOING;
        });
        _federate->_state = State::PROCESSING;
    }

    template<>
    void ModelGuard::ModelingControl<ModelMode::FOLLOWING>(){
        _federate->_state = State::PROCESSING;
        _federate->Modeling<ModelMode::FOLLOWING>();
        _federate->_last_time = std::chrono::steady_clock::now();
    }

    template<>
    void ModelGuard::ModelingControl<ModelMode::MANAGING>(){

    }
}
