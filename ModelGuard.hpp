#ifndef MODELGUARD_HPP
#define MODELGUARD_HPP
#include <mutex>

namespace HLA {

class BaseFederate;

/**
* @brief The ModelGuard class
*/
    class ModelGuard{
    public:

/**
* @brief ModelGuard
*/
        ModelGuard();

/**
* @brief ModelGuard
* @param federate_ptr
*/
        ModelGuard(BaseFederate* federate_ptr);

/**
* @brief ~ModelGuard
* @param federate_ptr
*/
        ~ModelGuard();

/**
* @brief ModelGuard
*/
        ModelGuard(const ModelGuard&) = delete;

/**
* @brief ModelGuard
*/
        ModelGuard(ModelGuard&&) = delete;

/**
* @brief operator =
* @return
*/
        ModelGuard& operator=(const ModelGuard&) = delete;

/**
* @brief operator =
* @return
*/
        ModelGuard& operator=(ModelGuard&&) = delete;


    protected:

/**
* @brief ThreadModelingControl
*/
        void ThreadModelingControl();

/**
* @brief FollowModelingControl
*/
        void FollowModelingControl();

/**
* @brief _federate
*/
        BaseFederate* _federate = nullptr;

/**
* @brief lock
*/
        std::unique_lock<std::mutex> lock;

/**
* @brief _start
*/
        std::chrono::time_point<std::chrono::steady_clock> _start;
    };
}

#endif // MODELGUARD_HPP
