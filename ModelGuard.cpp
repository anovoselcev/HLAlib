#include "ModelGuard.hpp"

namespace HLA {

/**
* @brief ModelGuard::ModelGuard
* @param fed pointer on target federate based on BaseFederate
*/
    ModelGuard::ModelGuard(BaseFederate* fed) : _federate(fed){

        if(_federate)                                                   // Check if federate pointer nullptr
            _lock = std::unique_lock<std::mutex>(_federate->_smutex);    // Lock federate state mutex and take control under federate state
        else
            throw std::runtime_error("Nullptr federate");               // If federate pointer is nullptr throw run-time error

        if(_federate->_mode == MODELMODE::FREE_THREADING)                    // If federate model mode is Threading start Threading control
            ModelingControl<MODELMODE::FREE_THREADING>();
        else if(_federate->_mode == MODELMODE::FREE_FOLLOWING)               // If federate model mode is Following start Following control
            ModelingControl<MODELMODE::FREE_FOLLOWING>();
        else if(_federate->_mode == MODELMODE::MANAGING_FOLLOWING)                // If federate model mode is Managing..........................
            ModelingControl<MODELMODE::MANAGING_FOLLOWING>();
        else if(_federate->_mode == MODELMODE::MANAGING_THREADING)
            ModelingControl<MODELMODE::MANAGING_THREADING>();
    }

/**
* @brief ModelGuard::~ModelGuard
* When ModelGuard is destructed  the scope thread go on
*/
    ModelGuard::~ModelGuard(){
        _lock.unlock();         // Release the federate state mutex
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::THREADING>
* Method which control execution of federate with Threading Model Mode
*/
    void ModelGuard::ModelingControl<MODELMODE::FREE_THREADING>(){
        _federate->_cond.wait(_lock,[this]{              // Wait for DOING federate state, federate notify ModelGuard about state change
            return _federate->_state == STATE::DOING;
        });
        _federate->_state = STATE::PROCESSING;          // Set federate step for proccessing
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::FOLLOWING>
* Method which control execution of federate with Following Model Mode
*/
    void ModelGuard::ModelingControl<MODELMODE::FREE_FOLLOWING>(){
        _federate->_state = STATE::PROCESSING;                      // Set federate step for proccessing
        _federate->Modeling<MODELMODE::FREE_FOLLOWING>();                // Run federate follow modeling method
        _federate->_last_time = std::chrono::steady_clock::now();   // Save last time
    }

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::MANAGING>
* ..............................
*/
    void ModelGuard::ModelingControl<MODELMODE::MANAGING_FOLLOWING>(){
        _federate->_state = STATE::READY;
        _federate->ReadyToGo();

        _federate->_cond.wait(_lock,[this]{                      // Wait for GO federate state, federate notify ModelGuard about state change
            return _federate->_state == STATE::PROCESSING;
        });
        _federate->Modeling<MODELMODE::MANAGING_FOLLOWING>();

    }

    template<>
    void ModelGuard::ModelingControl<MODELMODE::MANAGING_THREADING>(){
        this->~ModelGuard();
    }
}
