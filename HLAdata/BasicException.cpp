#include "BasicException.hpp"

namespace HLA {

  ExceptionForRTI::ExceptionForRTI(const std::exception& Ex) : _ExceptionMessage(Ex.what()) {
  }

  ExceptionForRTI::ExceptionForRTI(const std::string& strEx)  : _ExceptionMessage(strEx) {
  }

  ExceptionForRTI::ExceptionForRTI(const wchar_t *const& wchEx) {
    _ExceptionMessage = Tools::unwiden(std::wstring(wchEx));
  }

  ExceptionForRTI::ExceptionForRTI(const std::wstring& wstrEx) {
    _ExceptionMessage = Tools::unwiden(wstrEx);
  }


  const char *ExceptionForRTI::what( ) const throw() {
    return _ExceptionMessage.c_str();
  }

  const std::wstring ExceptionForRTI::whatWstr( ) const {
    std::wstring tmp;
    tmp.assign(_ExceptionMessage.begin(),_ExceptionMessage.end());
    return tmp;
  }

  std::string ExceptionForRTI::getstring() {
    return _ExceptionMessage;
  }
  const ExceptionForRTI & ExceptionForRTI::operator + (ExceptionForRTI &obj) {
    _ExceptionMessage = _ExceptionMessage + obj.getstring();
    return *this;
  }

}
