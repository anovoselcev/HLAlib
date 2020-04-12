#ifndef TOOLS_HPP
#define TOOLS_HPP
#define FUNCTION_COMMON_API
/////////////////////////////////
#include <cstdint>
#ifdef WIN32
//#include <winsock2.h>
//#include <Windows.h>
#include <direct.h>
#include <string.h>
#else
#include <sys/timeb.h>
#include <sys/time.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#endif // WIN32

#ifdef WIN32
#include <conio.h>
#else
#include <termios.h>
#include <unistd.h>
#include <sys/utsname.h>
#endif

#include <stdlib.h>
#include <errno.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <chrono>
#include <algorithm>

#ifndef _USE_MATH_DEFINES
#define _USE_MATH_DEFINES
#endif
#include <cmath>
namespace HLA {

  namespace Tools {

    std::string UTF16toUTF8(std::wstring const & in);


    template<class T> void changeENDIAN(T& value)
    {
      for(char *low= static_cast<char*>(static_cast<void*>(&value)),
          *high=low+sizeof(value)-1; low<high; ++low, --high)
      {
        char c=*low;
        *low=*high;
        *high=c;
      }
    }

    void FUNCTION_COMMON_API changeENDIAN(void* value, unsigned size);

    unsigned getPendingBytes(unsigned uiElementSize, unsigned OctetBoundaryValue);

    std::wstring widen(std::string& s);

    std::wstring widen(std::string&& s);

  }
}
#endif // TOOLS_HPP
