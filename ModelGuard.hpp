#ifndef MODELGUARD_HPP
#define MODELGUARD_HPP
#include <mutex>

namespace HLA {

class BaseFederate;

    class ModelGuard{
    public:

        ModelGuard();

        ModelGuard(BaseFederate* federate_ptr);

        ~ModelGuard();

        ModelGuard(const ModelGuard&) = delete;

        ModelGuard(ModelGuard&&) = delete;

        ModelGuard& operator=(const ModelGuard&) = delete;

        ModelGuard& operator=(ModelGuard&&) = delete;


    protected:

        void ThreadModelingControl();

        void FollowModelingControl();

        BaseFederate* _federate = nullptr;
        std::unique_lock<std::mutex> lock;
        std::chrono::time_point<std::chrono::steady_clock> _start;
    };
}

#endif // MODELGUARD_HPP
