#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <sstream>

namespace HLA {

    class Logger{
    public:
        Logger(const std::string& log_filename);

        Logger(std::string&& log_filename);

        ~Logger();

        Logger& operator<<(const std::wstring& info);

        Logger& operator<<(std::wstring&& info);

        Logger& operator<<(int info);

        Logger& operator<<(double info);

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
