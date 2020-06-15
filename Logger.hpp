#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <sstream>

namespace HLA {

    class Logger{
    public:
        Logger(const std::string&);

        Logger(std::string&&);

        ~Logger();

        Logger& operator<<(const std::wstring&);

        Logger& operator<<(std::wstring&&);

        struct Flush{
            Flush();
        };

        Logger& operator<<(Flush);

    private:

        std::wofstream _file;
        std::wostringstream _stream;

    };


}

#endif // LOGGER_HPP
