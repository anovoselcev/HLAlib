//================================================================================================================================================
/*
 * Written by Novoseltsev Artemy
 * This program is free software.
 * This program is distributed in the hope that it will be useful.
*/
//================================================================================================================================================

#include "ModelGuard.hpp"

namespace HLA {

/**
* @brief ModelGuard::ModelGuard
* @param fed pointer on target federate based on BaseFederate
*/
    ModelGuard::ModelGuard(BaseFederate* fed) : _federate(fed){
        if(_federate)                                                   // Check if federate pointer nullptr
            lock = std::unique_lock<std::mutex>(_federate->_smutex);    // Lock federate state mutex and take control under federate state
        else
            throw std::runtime_error("Nullptr federate");               // If federate pointer is nullptr throw run-time error

        if(_federate->_mode == ModelMode::THREADING)                    // If federate model mode is Threading start Threading control
            ModelingControl<ModelMode::THREADING>();
        else if(_federate->_mode == ModelMode::FOLLOWING)               // If federate model mode is Following start Following control
            ModelingControl<ModelMode::FOLLOWING>();
        else if(_federate->_mode == ModelMode::MANAGING)                // If federate model mode is Managing..........................
            ModelingControl<ModelMode::MANAGING>();
    }

/**
* @brief ModelGuard::~ModelGuard
* When ModelGuard is destructed  the scope thread go on
*/
    ModelGuard::~ModelGuard(){
        lock.unlock();         // Release the federate state mutex
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::THREADING>
* Method which control execution of federate with Threading Model Mode
*/
    void ModelGuard::ModelingControl<ModelMode::THREADING>(){
        _federate->_cond.wait(lock,[this]{              // Wait for DOING federate state, federate notify ModelGuard about state change
            return _federate->_state==State::DOING;
        });
        _federate->_state = State::PROCESSING;          // Set federate step for proccessing
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::FOLLOWING>
* Method which control execution of federate with Following Model Mode
*/
    void ModelGuard::ModelingControl<ModelMode::FOLLOWING>(){
        _federate->_state = State::PROCESSING;                      // Set federate step for proccessing
        _federate->Modeling<ModelMode::FOLLOWING>();                // Run federate follow modeling method
        *_federate->_last_time = std::chrono::steady_clock::now();   // Save last time
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::MANAGING>
* ..............................
*/
    void ModelGuard::ModelingControl<ModelMode::MANAGING>(){

    }
}
