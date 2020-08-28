#ifndef LOGGER_HPP
#define LOGGER_HPP
#include <fstream>
#include <sstream>

namespace HLA {

/**
* @brief The Logger class
*/
    class Logger{
    public:

/**
* @brief Logger
* @param log_filename
*/
        Logger(const std::string& log_filename);

/**
* @brief Logger
* @param log_filename
*/
        Logger(std::string&& log_filename);
/**
* @brief ~Logger()
* Destructor of basic federate
*/
        ~Logger();

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

/**
* @brief operator <<
* @return
*/
        Logger& operator<<(Flush);

    private:

/**
* @brief _file
*/
        std::wofstream _file;
/**
* @brief _stream
*/
        std::wostringstream _stream;

    };


}

#endif // LOGGER_HPP
