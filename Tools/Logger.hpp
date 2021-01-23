#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <sstream>
#include <mutex>

namespace HLA {

/**
* @brief The Logger class
*/
    class Logger{
    public:

        enum class MSG{
            ERRORR = 0,
            INFO = 1
        };

/**
* @brief Logger
* @param log_filename
*/
        Logger(const std::wstring& log_filename, const std::wstring& fedname);

/**
* @brief Logger
* @param log_filename
*/
        Logger(std::wstring&& log_filename, const std::wstring& fedname);
/**
* @brief ~Logger()
* Destructor of basic federate
*/
        ~Logger();

        Logger& operator<<(MSG);

/**
* @brief operator <<
* @param info
* @return
*/
        Logger& operator<<(const std::wstring& info);

/**
* @brief operator <<
* @param info
* @return
*/
        Logger& operator<<(std::wstring&& info);

/**
* @brief operator <<
* @param info
* @return
*/
        Logger& operator<<(int info);

/**
* @brief operator <<
* @param info
* @return
*/
        Logger& operator<<(double info);

/**
* @brief The Flush struct
*/
        struct Flush{
            Flush();
        };

        struct Endl{
            Endl();
        };

/**
* @brief operator <<
* @return
*/
        Logger& operator<<(Flush);

        Logger& operator<<(Endl);

    private:

/**
* @brief _file
*/
        std::wfstream _file;
/**
* @brief _stream
*/
        std::wstringstream _stream;

        mutable std::mutex _mut;

    };


}

#endif // LOGGER_HPP
