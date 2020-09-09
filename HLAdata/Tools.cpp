#include "Tools.hpp"
#include <vector>

using namespace std;

namespace HLA {
  namespace Tools {

  void changeENDIAN(void* value, unsigned size)
  {
    for(char *low=(char*)value,*high=low+size-1;low<high;++low,--high)
    {
      char c=*low;
      *low=*high;
      *high=c;
    }
  }

    unsigned getPendingBytes(unsigned uiElementSize, unsigned OctetBoundaryValue)
    {
      unsigned PendingBytes;
      PendingBytes = uiElementSize%OctetBoundaryValue;
      if (PendingBytes!=0) {
        PendingBytes=OctetBoundaryValue-PendingBytes;
      }
      return PendingBytes;
    }

    std::wstring widen( const std::string& in)
    {
        std::wstring ws;
        ws.assign(in.begin(),in.end());
        return ws;
    }

    std::wstring widen(std::string&& s){
        std::wstring ws;
        ws.assign(s.begin(),s.end());
        return ws;
    }

    std::string unwiden(const std::wstring & s){
        std::string str(s.begin(),s.end());
        return str;
    }

    std::string unwiden(std::wstring&& s){
        std::string str(s.begin(),s.end());
        return str;
  }
}
}
