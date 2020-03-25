#include "../include/Tools.hpp"
#include <locale>
#include <vector>
#include <algorithm>

#ifndef WIN32
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#else
#include <mbstring.h>
#include <sys/timeb.h>
#include <time.h>
#include <stdio.h>
#endif

using namespace std;

namespace HLA {
  namespace Tools {
    void iksSleep(unsigned int msec) {
#ifdef WIN32
      Sleep(msec);
#else
      struct timespec req, rem;
      req.tv_sec = msec / 1000;
      req.tv_nsec = (msec % 1000) * 1000000;
      nanosleep(&req, &rem);
#endif
    }

    /**
  * @fn timeToWstring(time_t time);
  *
  * @brief Переводит календарное время в символьную строку wstring
  *
  * @param[in] time Календарное время в формате time_t
  * @return Календарное время в формате символьной строки wstring
  * @author Вислоцкий А.И.
  */
    std::wstring timeToWstring(time_t time)
    {
      std::wostringstream wstrOut;
      std::wstring wstrOutput;
#ifdef WIN32
      char chBuf[26];
      ctime_s(chBuf,26,&time);
      wstrOut << chBuf;
#else
      wstrOut << ctime( &time );
#endif
      wstrOutput = wstrOut.str();
      wstrOutput.resize(wstrOutput.size()-1);
      return wstrOutput;
    }
    /**
  * @fn getCurrentTime
  *
  * @brief Возвращает текущее календарное время в формате time_t
  *
  * @return Текущее календарное время в формате в формате time_t
  * @author Вислоцкий А.И.
  */
    time_t getCurrentTime()
    {
      // TODO Отсутствуют миллисекунды
      return time( nullptr );
    }

    void getCurrentTimeStringLocal(std::string& time) {
      char acTimeCurrent[26];
      char ac_buffer[40];
#ifdef WIN32
      struct _timeb timebufferCurrent;
      _ftime_s( &timebufferCurrent ); // C4996
      ctime_s( acTimeCurrent, 26, & ( timebufferCurrent.time ) );
      sprintf_s( ac_buffer, 40,
                 "%.19s.%3.3hu %s",
                 acTimeCurrent,
                 timebufferCurrent.millitm,
                 &acTimeCurrent[20] );
#else
      struct timeb timebufferCurrent;
      ftime( &timebufferCurrent );
      time_t timeCurrent = timebufferCurrent.time;
      ctime_r( &timeCurrent, acTimeCurrent );
      sprintf( ac_buffer,
               "%.19s.%3.3hu %s",
               acTimeCurrent,
               timebufferCurrent.millitm,
               &acTimeCurrent[20] );
#endif
      time = string(ac_buffer);
    }

    std::wstring getCurrentTimeStringLocal(void)
    {
      char acTimeCurrent[26];
      char ac_buffer[40];
#ifdef WIN32
      struct _timeb timebufferCurrent;
      _ftime_s( &timebufferCurrent ); // C4996
      ctime_s( acTimeCurrent, 26, & ( timebufferCurrent.time ) );
      sprintf_s( ac_buffer, 40,
                 "%.19s.%3.3hu %s",
                 acTimeCurrent,
                 timebufferCurrent.millitm,
                 &acTimeCurrent[20] );
#else
      struct timeb timebufferCurrent;
      ftime( &timebufferCurrent );
      time_t timeCurrent = timebufferCurrent.time;
      ctime_r( &timeCurrent, acTimeCurrent );
      sprintf( ac_buffer,
               "%.19s.%3.3hu %s",
               acTimeCurrent,
               timebufferCurrent.millitm,
               &acTimeCurrent[20] );
#endif
      std::wostringstream wstrOut;
      std::wstring wstrOutput;
      wstrOut << ac_buffer;
      wstrOutput = wstrOut.str();
      wstrOutput.resize(wstrOutput.size()-1);
      return wstrOutput;
    }


    std::wstring getCurrentTimeString(void)
    {
      time_t timer;
      char acTimeCurrent[26];
      char ac_buffer[40];
      time(&timer);
#ifdef WIN32
      struct tm newtime;
      struct _timeb timebufferCurrent;
      // Obtain coordinated universal time:
      gmtime_s(&newtime,&timer);
      asctime_s(acTimeCurrent, 26, &newtime);
      _ftime_s( &timebufferCurrent ); // C4996
      sprintf_s( ac_buffer, 40,
                 "%.19s.%3.3hu %s",
                 acTimeCurrent,
                 timebufferCurrent.millitm,
                 &acTimeCurrent[20] );
#else
      struct tm *newtime;
      struct timeb timebufferCurrent;
      // Obtain coordinated universal time:
      newtime = gmtime(&timer); // C4996
      asctime_r(newtime, acTimeCurrent);
      ftime( &timebufferCurrent );
      sprintf( ac_buffer,
               "%.19s.%3.3hu %s",
               acTimeCurrent,
               timebufferCurrent.millitm,
               &acTimeCurrent[20] );
#endif
      std::wostringstream strOut;
      std::wstring wstrOutput;
      strOut << ac_buffer;
      wstrOutput = strOut.str();
      wstrOutput.resize(wstrOutput.size()-1);
      strOut.str(L"");
      return wstrOutput;
    }


    void getCurrentTimeString( char* ac_buffer )
    {
      char acTimeCurrent[26];
      // format is "Mon Apr 28 11:08:54.230 2003"
#ifdef WIN32
      struct _timeb timebufferCurrent;
      _ftime_s( &timebufferCurrent ); // C4996
      ctime_s( acTimeCurrent, 26, & ( timebufferCurrent.time ) );
      sprintf_s( ac_buffer, 40,
                 "%.19s.%hu %s",
                 acTimeCurrent,
                 timebufferCurrent.millitm,
                 &acTimeCurrent[20] );
#else
      struct timeb timebufferCurrent;
      ftime( &timebufferCurrent );
      time_t timeCurrent = timebufferCurrent.time;
      ctime_r( &timeCurrent, acTimeCurrent );
      sprintf( ac_buffer,
               "%.19s.%hu %s",
               acTimeCurrent,
               timebufferCurrent.millitm,
               &acTimeCurrent[20] );
#endif
    }

    timespec timespecAdd(timespec t1, timespec t2) {
      constexpr long BILLION = 1000000000;
      timespec ret;
      ret.tv_sec = t2.tv_sec + t1.tv_sec;
      ret.tv_nsec = t2.tv_nsec + t1.tv_nsec;
      if (ret.tv_nsec >= BILLION) {
        ret.tv_nsec -= BILLION;
        ret.tv_sec++;
      }
      return ret;
    }


    std::wstring wideLiteralToWstring( const wchar_t* pwsz_source)
    {

      std::wstring wstrResult(L"");


#ifdef WIN32
      size_t nSize = wcslen(pwsz_source) + 1;
      size_t nLength;
      wchar_t* pwszString=NULL;
      char* pszTemp = new char[nSize];
      // Преобразует, как ни странно, широкий литерал в строку UTF-8
      int nRet = WideCharToMultiByte(
                   CP_ACP,
                   0,
                   pwsz_source,
                   -1,
                   pszTemp,
                   (int)nSize,
                   NULL,
                   NULL );
      if( nRet != 0)
      {
        nLength = _mbslen( (const unsigned char*)pszTemp) + 1;
        pwszString = new wchar_t[ nLength ];
        int nRet;
        nRet = MultiByteToWideChar (
                 CP_UTF8,
                 0,
                 (LPCSTR)pszTemp,
                 -1,
                 pwszString,
                 (int)nLength
                 );
        if (nRet != 0) {
          wstrResult.append( pwszString );
        }
        delete [] pwszString;
      }
      delete[] pszTemp;
#else
      wstrResult.append( pwsz_source );
#endif

      return wstrResult;
    };

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

    std::wstring widen(char const* ch_in)
    {
      std::string in;
      in.insert(0,ch_in);
      return widen(in);
    }

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

    string getTimeSinceEpoch()
    {
      char mbstr[100];
      char buf[4];

      std::chrono::time_point<std::chrono::system_clock> t = std::chrono::system_clock::now();
      std::time_t tm_t = std::chrono::system_clock::to_time_t(t);
      struct tm result_tm;
#ifdef WIN32
      gmtime_s(&result_tm, &tm_t);
#else
      gmtime_r(&tm_t, &result_tm);
#endif
      auto t_msec= std::chrono::duration_cast<std::chrono::milliseconds>(t.time_since_epoch()).count() %1000;
      std::strftime(mbstr, 100, "%y.%m.%d %H:%M:%S.", &result_tm);
#ifdef WIN32
      sprintf_s(buf,4,"%3.3d",(int)t_msec);
#else
      snprintf(buf,4,"%3.3d",(int)t_msec);
#endif
      return std::string(mbstr) + buf;
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

    wstring getClassNameLast(const wstring &m_wstrClassName) {
      std::wstring wstrLast; /*< листьевое имя класса */
      std::wstring::size_type found = m_wstrClassName.find_last_of(L".");
      if (found != std::wstring::npos) {
        wstrLast.assign(m_wstrClassName.begin()+found+1,m_wstrClassName.end());
        return wstrLast;
      }
      return m_wstrClassName;
    }
#ifndef WIN32
    LockUnLock::LockUnLock(TEST_CRITICAL_SECTION in_ptr_cs) {
      m_ptrCS = in_ptr_cs;
      if (pthread_mutex_lock(m_ptrCS)!=0) {
        std::wcout << wideLiteralToWstring(L" ERRRROR.... LOCK: ") <<  (long)m_ptrCS << std::endl;
      };
    }

    LockUnLock::~LockUnLock() {
      pthread_mutex_unlock(m_ptrCS);
    }

    void LockCS(TEST_CRITICAL_SECTION in_ptr_cs) {
      pthread_mutex_lock(in_ptr_cs);
    }

    void UnLockCS(TEST_CRITICAL_SECTION in_ptr_cs) {
      pthread_mutex_unlock(in_ptr_cs);
    }

#endif

  } // end namespace tools
} // end namespace rbtvan

