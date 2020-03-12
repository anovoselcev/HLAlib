#ifndef BASICEXCEPTION_HPP
#define BASICEXCEPTION_HPP
#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#pragma warning(disable: 4482)
#endif
#include<exception>
#include<string>
#include"include_sup/Tools.hpp"
namespace HLA {
  class ExceptionForRTI : public std::exception {
  public:
    ExceptionForRTI(const std::exception& Ex);

    ExceptionForRTI(const std::string& strEx);

    ExceptionForRTI(const wchar_t *const& wchEx);

    ExceptionForRTI(const std::wstring& wstrEx);

    virtual const char *what( ) const throw();

    virtual const std::wstring whatWstr( ) const;

    std::string getstring();

    const ExceptionForRTI & operator + (ExceptionForRTI &obj);

  private:
    std::string _ExceptionMessage;
  };

  #define EXCEPTION(A)                                        			\
    class A : public ExceptionForRTI                                 	\
    {                                                             		\
      public:                                                     		\
      A (const std::string& strEx)    : ExceptionForRTI(strEx) {};      \
      A (const wchar_t *const& wchEx) : ExceptionForRTI(wchEx) {};   	\
      A (const std::wstring& wstrEx)  : ExceptionForRTI(wstrEx) {};   	\
    };

  #define EXCEPTION_2_ARGS(A, STR)                            						\
    class A : public ExceptionForRTI                                 				\
    {                                                             					\
      public:                                                     					\
      A (const std::string& strEx=std::string("")) : ExceptionForRTI(STR+strEx) {}; \
      A (const wchar_t *const& wchEx)              : ExceptionForRTI(wchEx)  {};  	\
      A (const std::wstring& wstrEx)               : ExceptionForRTI(wstrEx)  {};  	\
    };

  EXCEPTION_2_ARGS(EndOfFile, "Достигнут конец файла")
  EXCEPTION_2_ARGS(FileIsNotOpen, "Файл не открыт")
  EXCEPTION(ERROR_BAD_ENVIRONMENT_RRTI)
  EXCEPTION(ReadConfigDataTypeMissmatch)
  EXCEPTION(ReadConfigUncknownReason)
  EXCEPTION(ReadConfigParameterNotFound)
  EXCEPTION(ReadConfigParameterOutOfBounds)
  EXCEPTION(ObjectClassIsNotInitialized)

}
#endif // BASICEXCEPTION_HPP
