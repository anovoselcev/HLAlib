#ifndef TOOLS_HPP
#define TOOLS_HPP
#define FUNCTION_COMMON_API
/////////////////////////////////

#include <sstream>


namespace HLA {

  namespace Tools {


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

    std::wstring widen(const std::string& s);

    std::wstring widen(std::string&& s);

    std::string unwiden(const std::wstring& s);

    std::string unwiden(std::wstring&& s);

  }
}
#endif // TOOLS_HPP
