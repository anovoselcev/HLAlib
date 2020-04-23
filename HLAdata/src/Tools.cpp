#include "../include/Tools.hpp"

using namespace std;

namespace HLA {
  namespace Tools {


    std::string UTF16toUTF8(const wstring & in)
    {
      string out;
      unsigned int codepoint=0;
      bool completecode = false;
      wstring::const_iterator p;
      for (p = in.begin();  p != in.end();  ++p)
      {
        if (*p >= 0xd800 && *p <= 0xdbff)
        {
          codepoint = ((*p - 0xd800) << 10) + 0x10000;
          completecode = false;
        }
        else if (!completecode && *p >= 0xdc00 && *p <= 0xdfff)
        {
          codepoint |= *p - 0xdc00;
          completecode = true;
        }
        else
        {
          codepoint = *p;
          completecode = true;
        }
        if (completecode)
        {
          if (codepoint <= 0x7f)
            out.push_back(codepoint);
          else if (codepoint <= 0x7ff)
          {
            out.push_back(0xc0 | ((codepoint >> 6) & 0x1f));
            out.push_back(0x80 | (codepoint & 0x3f));
          }
          else if (codepoint <= 0xffff)
          {
            out.push_back(0xe0 | ((codepoint >> 12) & 0x0f));
            out.push_back(0x80 | ((codepoint >> 6) & 0x3f));
            out.push_back(0x80 | (codepoint & 0x3f));
          }
          else
          {
            out.push_back(0xf0 | ((codepoint >> 18) & 0x07));
            out.push_back(0x80 | ((codepoint >> 12) & 0x3f));
            out.push_back(0x80 | ((codepoint >> 6) & 0x3f));
            out.push_back(0x80 | (codepoint & 0x3f));
          }
        }
      }
      return out;
    }

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
      std::wstring out;
#ifdef WIN32
      int iSize = (int)in.size()+1;
      std::vector<WCHAR> s2(iSize);// room for 100 characters
      //...
      MultiByteToWideChar(
            CP_UTF8,
            //CP_THREAD_ACP, // code page
            0, // character-type options
            in.c_str(), // string to std::map
            (int)in.length(), // number of bytes in string
            &s2[0], // wide-character buffer (must use std::vector here!)
          iSize // size of buffer
          );
      out = &s2[0]; // Assign std::vector cont
#else
      unsigned n;
      n = mbstowcs(NULL,in.c_str(),0)+1;
      wchar_t* wch_t = new wchar_t[n];
      n = mbstowcs(wch_t,in.c_str(),n);
      out = wch_t;
      delete []wch_t;
#endif
      return out;
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
