#include "ModelMutex.hpp"
#include "BaseFederate.hpp"

namespace HLA {

    ModelMutex::ModelMutex(BaseFederate* fed) : _federate(fed){
        if(_federate!=nullptr){
            lock = std::unique_lock<std::mutex>(_federate->_smutex);
            _federate->_cond.wait(lock,[this]{
                return _federate->_f_state;
            });
            _federate->_f_state = false;
        }
        else
            throw std::runtime_error("Nullptr federate");
    }

    ModelMutex::~ModelMutex(){
        lock.unlock();
    }
}
