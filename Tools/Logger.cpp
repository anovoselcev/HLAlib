#include "Logger.hpp"
#include <ctime>

namespace HLA {

/**
* @brief Logger::Logger
* @param str
*/
    Logger::Logger(const std::wstring& str, const std::wstring& fedname){
        std::string _fedname, pref;
        _fedname.assign(fedname.begin(), fedname.end());
        pref.assign(str.begin(), str.end());
        time_t seconds = time(nullptr);
        std::string time = asctime(localtime(&seconds));
        std::hash<std::string> hash;
        _file.open(pref + "_" + _fedname + "_" + std::to_string(hash(time)), std::ios_base::out);
    }

/**
* @brief Logger::Logger
* @param str
*/
    Logger::Logger(std::wstring&& str, const std::wstring& fedname){
        std::string _fedname, pref;
        _fedname.assign(fedname.begin(), fedname.end());
        pref.assign(str.begin(), str.end());
        time_t seconds = time(nullptr);
        std::string time = asctime(localtime(&seconds));
        std::hash<std::string> hash;
        _file.open(pref + "_" + _fedname + "_" + std::to_string(hash(time)), std::ios_base::out);
    }

    Logger& Logger::operator<<(MSG m){
        _mut.lock();
        if(m == MSG::INFO)
            _stream << L"INFO: ";
        else if(m == MSG::ERROR)
            _stream << L"ERROR: ";
        return *this;
    }

/**
* @brief Logger::operator <<
* @param str
* @return
*/
    Logger& Logger::operator<<(const std::wstring &str){
        _stream << str+L' ';
        return *this;
    }

/**
* @brief Logger::operator <<
* @param str
* @return
*/
    Logger& Logger::operator<<(std::wstring &&str){
        _stream << std::move(str)+L' ';
        return *this;
    }

/**
* @brief Logger::operator <<
* @param info
* @return
*/
    Logger& Logger::operator<<(int info){
        _stream << std::to_wstring(info) +  L' ';
        return *this;
    }

/**
* @brief Logger::operator <<
* @param info
* @return
*/
    Logger& Logger::operator<<(double info){
        _stream << std::to_wstring(info) + L' ';
        return *this;
    }

/**
* @brief Logger::Flush::Flush
*/
    Logger::Flush::Flush(){}

/**
* @brief Logger::operator <<
* @return
*/
    Logger& Logger::operator<<(Flush){
        time_t seconds = time(nullptr);
        tm* timeinfo = localtime(&seconds);
        std::wostringstream os;
        os << L">>" << asctime(timeinfo) << L": " << _stream.str() << L'\n';
        _stream.str(L"");
        _file << os.str();
        _file.flush();
        _mut.unlock();
        return *this;
    }

/**
* @brief Logger::~Logger
*/
    Logger::~Logger(){
        std::wstring str = _stream.str();
        if(!str.empty()){
            time_t seconds = time(nullptr);
            tm* timeinfo = localtime(&seconds);
            std::wostringstream os;
            os << L">>" << asctime(timeinfo) << ": " << _stream.str() << L'\n';
            _stream.clear();
            _file << os.str();
        }
        _file.close();
    }

}
