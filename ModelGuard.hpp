#ifndef MODELMUTEX_HPP
#define MODELMUTEX_HPP
#include <mutex>

namespace HLA {

    class BaseFederate;

    class ModelGuard{
    public:

        ModelGuard() = delete;

        ModelGuard(BaseFederate*);

        ~ModelGuard();

        ModelGuard(const ModelGuard&) = delete;

        ModelGuard(ModelGuard&&) = delete;

        ModelGuard& operator=(const ModelGuard&) = delete;

        ModelGuard& operator=(ModelGuard&&) = delete;

    private:
        BaseFederate* _federate = nullptr;
        std::unique_lock<std::mutex> lock;
    };
}

#endif // MODELMUTEX_HPP
