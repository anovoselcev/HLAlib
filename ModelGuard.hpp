#ifndef MODELGUARD_HPP
#define MODELGUARD_HPP

#include "BaseFederate.hpp"

namespace HLA {

/**
* @brief The ModelGuard class
* The class ModelGuard is a Federate wrapper that provides a convenient RAII-style mechanism for control a modeling time of scoped thread and federate mpdeling proccessing for the duration of a scoped block.
* When a ModelGuard object is created, it attempts to take ownership of the federate it is given and scoped thread. When control leaves the scope in which the ModelGuard object was created, the ModelGuard is destructed and the scope thread go on.
* The ModelGuard class is non-copyable.
*/
    class ModelGuard{
//================================================================================================================================================

//          Public API

//================================================================================================================================================

    public:

/**
* @brief ModelGuard
* Default constructor makes no sense
*/
        ModelGuard() = delete;

/**
* @brief ModelGuard
* @param federate_ptr pointer on target federate based on BaseFederate
*/
        ModelGuard(BaseFederate* federate_ptr);

/**
* @brief ~ModelGuard
* When ModelGuard is destructed  the scope thread go on
*/
        ~ModelGuard();

/**
* @brief ModelGuard
* Copy constructor of ModelGuard deleted, only unique entity can exist
*/
        ModelGuard(const ModelGuard&) = delete;

/**
* @brief ModelGuard
* Move constructor of ModelGuard deleted, only unique entity can exist
*/
        ModelGuard(ModelGuard&&) = delete;

/**
* @brief operator =
* Copy assignment operator of ModelGuard deleted, only unique entity can exist
* @return ModelGuard&
*/
        ModelGuard& operator=(const ModelGuard&) = delete;

/**
* @brief operator =
* Move assignment operator of ModelGuard deleted, only unique entity can exist
* @return ModelGuard&
*/
        ModelGuard& operator=(ModelGuard&&) = delete;

//================================================================================================================================================

//          Protected Methods and fields

//================================================================================================================================================

    protected:

        template<MODELMODE>
        void ModelingControl();

/**
* @brief _federate
* Pointer on target federate, which ModelingThread ModelGuard control
*/
        BaseFederate* _federate = nullptr;

/**
* @brief lock
* Locker for federate state mutex. It means that ModelGuard control state of federate.
*/
        std::unique_lock<std::mutex> _lock;

    };


    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::THREADING>
* Method which control execution of federate with Threading Model Mode
*/
    void ModelGuard::ModelingControl<MODELMODE::FREE_THREADING>();

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::FOLLOWING>
* Method which control execution of federate with Following Model Mode
*/
    void ModelGuard::ModelingControl<MODELMODE::FREE_FOLLOWING>();

    template<>
/**
* @brief ModelGuard::ModelingControl<ModelMode::MANAGING>
* ..............................
*/
    void ModelGuard::ModelingControl<MODELMODE::MANAGING_FOLLOWING>();

    template<>
    void ModelGuard::ModelingControl<MODELMODE::MANAGING_THREADING>();
}

#endif // MODELGUARD_HPP
