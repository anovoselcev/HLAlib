#ifndef MODELMUTEX_HPP
#define MODELMUTEX_HPP
#include <mutex>

namespace HLA {

    class BaseFederate;

    class ModelMutex{
    public:

        ModelMutex() = delete;

        ModelMutex(BaseFederate*);

        ~ModelMutex();

        ModelMutex(const ModelMutex&) = delete;

        ModelMutex(ModelMutex&&) = delete;

        ModelMutex& operator=(const ModelMutex&) = delete;

        ModelMutex& operator=(ModelMutex&&) = delete;

    private:
        BaseFederate* _federate = nullptr;
        std::unique_lock<std::mutex> lock;
    };
}

#endif // MODELMUTEX_HPP
