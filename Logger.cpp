#include "Logger.hpp"
#include <ctime>

namespace HLA {

    Logger::Logger(const std::string& str){
        _file.open(str, std::ios_base::app);
    }

    Logger::Logger(std::string&& str){
        _file.open(std::move(str));
    }

    Logger& Logger::operator<<(const std::wstring &str){
        _stream << str+L' ';
        return *this;
    }

    Logger& Logger::operator<<(std::wstring &&str){
        _stream << std::move(str)+L' ';
        return *this;
    }

    Logger::Flush::Flush(){}

    Logger& Logger::operator<<(Flush){
        time_t seconds = time(nullptr);
        tm* timeinfo = localtime(&seconds);
        std::wostringstream os;
        os << L">>" << asctime(timeinfo) << L": " << _stream.str() << L'\n';
        _stream.str(L"");
        _file << os.str();
        return *this;
    }

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
