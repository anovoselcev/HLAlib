#ifndef TOOLS_HPP
#define TOOLS_HPP
#define FUNCTION_COMMON_API
/////////////////////////////////
#include <cstdint>
#ifdef WIN32
#include <winsock2.h>
#include <Windows.h>
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
    ///////////////////////////////////////
    //		Работа со временем
    ///////////////////////////////////////

    /**
    * @fn getCurrentTime
    *
    * @brief Возвращает текущее календарное время в формате time_t
    *
    * @return Текущее календарное время в формате в формате time_t
    * @author Вислоцкий А.И.
    */
    time_t FUNCTION_COMMON_API getCurrentTime();

    /**
    * @fn getCurrentTimeString
    * @brief Возвращает строковое представление текущего UTС времени
    *
    * Строка имеет следующий формат: "Mon Apr 28 11:08:54.230 2003" (добавлены миллисекунды)
    * @return Текущее локальное время
    * @author Вислоцкий А.И.
    */
    std::wstring FUNCTION_COMMON_API getCurrentTimeString(void);

    /**
    * @fn getCurrentTimeStringLocal
    * @brief Возвращает строковое представление текущего локального времени
    *
    * Строка имеет следующий формат: "Mon Apr 28 11:08:54.230 2003" (добавлены миллисекунды)
    * @return Текущее локальное время
    * @author Вислоцкий А.И.
    */
    std::wstring FUNCTION_COMMON_API getCurrentTimeStringLocal(void);

    /**
    * @fn timeToWstring(time_t time);
    *
    * @brief Переводит календарное время в символьную строку wstring
    *
    * @param[in] time Календарное время в формате time_t
    * @return Календарное время в формате символьной строки wstring
    * @author Вислоцкий А.И.
    */
    std::wstring timeToWstring(time_t time);

    /**
    * @brief Определяет строковое представление UTC времени с начала эпохи в миллисекндах
    *
    * @return Строковое представление UTC времени с начала эпохи в миллисекндах
    * @author Вислоцкий А.И.
    */
    std::string FUNCTION_COMMON_API getTimeSinceEpoch();

    timespec timespecAdd(timespec t1, timespec t2);

    ///////////////////////////////////////
    //		Классы синхронизации
    ///////////////////////////////////////

#ifdef WIN32
/** @def TEST_CRITICAL_SECTION
  * @brief Указаель на критическую секцию
  *
  * @author Вислоцкий А.И.
  */
#define TEST_CRITICAL_SECTION CRITICAL_SECTION*
/** @def TEST_INITIALIZE_CS(cs)
  * @brief Макрос инициализирующий критическую секцию \a cs
  *
  * @author Вислоцкий А.И.
  */
#define TEST_INITIALIZE_CS(cs) cs=new CRITICAL_SECTION();	InitializeCriticalSectionAndSpinCount(cs,0x80000400)
/** @def TEST_DELETE_CS(cs)
  * @brief Макрос уничтожающий критическую секцию \a cs
  *
  * @author Вислоцкий А.И.
  */
#define TEST_DELETE_CS(cs)		DeleteCriticalSection(cs); delete cs; cs=nullptr;
#else
/** @def TEST_CRITICAL_SECTION
  * @brief Указаель на mutex
  *
  * @author Вислоцкий А.И.
  */
#define TEST_CRITICAL_SECTION pthread_mutex_t*
/** @def TEST_CRITICAL_SECTION
  * @brief Создает и инициализирует рекурсивный мютекс
  *
  * @author Вислоцкий А.И.
  */
#define TEST_INITIALIZE_CS(cs)\
{\
  cs = new pthread_mutex_t();\
  pthread_mutexattr_t mattr;\
  pthread_mutexattr_init(&mattr);\
  /* initialize an attribute to default value */\
  pthread_mutexattr_settype(&mattr , PTHREAD_MUTEX_RECURSIVE);\
  pthread_mutex_init(cs, &mattr);\
  pthread_mutexattr_destroy(&mattr);\
  }
/** @def TEST_CRITICAL_SECTION
  * @brief Удаляет мютекс
  *
  * @author Вислоцкий А.И.
  */
#define TEST_DELETE_CS(cs)	 \
{\
  if (cs != nullptr) {\
  pthread_mutex_destroy(cs);\
  cs=nullptr;\
  };\
  }
#endif // WIN32

  /**
  * @class LockUnLock
  * @brief Класс для защиты данных в теле функций\n
  *			при работе в разных потоках
  *
  * Экземпляр класса создается в стеке функции.\n
  * и программа входит в критическую секцию, указатель на
  * которую передается при ее создании.
  * @author Вислоцкий А.И.
  */
#ifdef WIN32
    class LockUnLock {
    public:
      LockUnLock(TEST_CRITICAL_SECTION in_ptr_cs) {
        m_ptrCS = in_ptr_cs;
        if (m_ptrCS == NULL) return;
        EnterCriticalSection(in_ptr_cs);
      }
      virtual ~LockUnLock() {
        if (m_ptrCS == NULL) return;
        LeaveCriticalSection(m_ptrCS);
      }
    private:
      CRITICAL_SECTION* m_ptrCS;
    };

    inline void LockCS(TEST_CRITICAL_SECTION in_ptr_cs) {
      EnterCriticalSection(in_ptr_cs);
    }

    inline void UnLockCS(TEST_CRITICAL_SECTION in_ptr_cs) {
      LeaveCriticalSection(in_ptr_cs);
    }

#else
    class LockUnLock {
    public:
      LockUnLock(TEST_CRITICAL_SECTION in_ptr_cs);
      virtual ~LockUnLock();
    private:
      pthread_mutex_t* m_ptrCS;
    };

    void LockCS(TEST_CRITICAL_SECTION in_ptr_cs);

    void UnLockCS(TEST_CRITICAL_SECTION in_ptr_cs);

#endif // WIN32

    ///////////////////////////////////////
    //	Работа со строками
    ///////////////////////////////////////

    /**
    * @brief Функция преобразует wstring в string
    *
    * @param[in] in Широкая строка (wstring).
    * @return string
    * @author Вислоцкий А.И.
    */
    std::string UTF16toUTF8(std::wstring const & in);


    /** @fn wideLiteralToWstring( const wchar_t* pwsz_source )
    * @brief Преобразовывает строку L"xxx" в wstring\n
    *		 Текст кода должен быть в UTF8
    *
    * @param[in] pwsz_source Указатель на L-строку
    * @return L-строка, преобразованная в wstring
    * @author Вислоцкий А.И.
    */
    std::wstring wideLiteralToWstring( const wchar_t* pwsz_source );
    /** @fn widen(const std::string& in);
    * @brief Преобразовывает string в wstring
    *
    * @param[in] in Исходная строка (string)
    * @return wstring
    * @author Вислоцкий А.И.
    */
    std::wstring widen(std::string const & in);
    /** @fn widen(const char* ch_in);
    * @brief Преобразовывает массив символов char в wstring
    *
    * @param[in] ch_in Указатедь на char строку C++
    * @return wstring
    * @author Вислоцкий А.И.
    */
    std::wstring widen(char const* ch_in);

    ///////////////////////////////////////
    //	Функции (Типы данных) для RRTI
    ///////////////////////////////////////
    /**
    * @enum IksBool
    * @brief Values that represent Bool.
    */
    enum IksBool : char {
      IksFalse  =0,
      IksTrue   =1
    };

    /**
    * @brief Находит листьевое имя класса.
    *
    * @param[in] m_wstrClassName Ссылка на полное имя класса.
    * @return wstring листьевое имя класса.
    * @author Вислоцкий А.И.
    */
    std::wstring getClassNameLast(const std::wstring& m_wstrClassName);

    /**
    * @brief Шаблон-функция преобразования порядка байт из BE в LE и обратно.
    *
    * @tparam T тип данных.
    * @param[in,out] value Ссылка на преобразуемые данные.
    * @author Вислоцкий А.И.
    */
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

    template<typename T>
    int32_t find_first_of_same(
        const std::vector<T>& in,
        typename std::enable_if<std::is_arithmetic<T>::value>::type* = nullptr)
    {
      int32_t rez = -1;
      for (size_t i = 0; i<in.size()-1; ++i) {
        for (size_t j = i+1; j<in.size(); ++j) {
          if (in[i] == in[j]) {
            rez = static_cast<int32_t>(i);
            break;
          }
        }
      }
      return rez;
    }

    /**
  * @brief Функция преобразования порядка байт из BE в LE и обратно.
  *
  * @param[in,out] value Указатель на начало расположения данных.
  * @param[in] size Размер поля данных.
  * @author Вислоцкий А.И.
  */
    void FUNCTION_COMMON_API changeENDIAN(void* value, unsigned size);

    /**
  * @brief Функция вычисляет количество выравнивающих байт, которые должны быть добавлены\n
  *				 при отправке данных через RTI (по стандарту)
  *
  * @param[in] uiElementSize размер элемента.
  * @param[in] OctetBoundaryValue OBV рассматриваемого типа данных.
  * @return Количество байтов выравнивания
  * @author Вислоцкий А.И.
  */
    unsigned getPendingBytes(unsigned uiElementSize, unsigned OctetBoundaryValue);


    ///////////////////////////////////////
    //	Системные функции
    ///////////////////////////////////////
    /**
    * @brief Приостановка потока на заданное число милисекунд
    *
    * @param[in] msec Число милисекунд на которые приостанавливается поток.
    * @author Вислоцкий А.И.
    */
    void FUNCTION_COMMON_API iksSleep(unsigned int msec);

  }
}
#endif // TOOLS_HPP
