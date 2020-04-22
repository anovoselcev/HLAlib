#ifndef RTISTRING_HPP
#define RTISTRING_HPP
#include <RTI/RTI1516.h>

#include "RTItypes.hpp"

namespace HLA {
    template <class StringType>
    class BaseRTIstring : public ClassForRTI<StringType,1> {
    public:

      using type = StringType;

      BaseRTIstring() {
        unsigned lenth = 0;
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
      }

      void get(BaseRTIstring const &str) {
        m_str = str;
      }

      void get(BaseRTIstring&& str){
          m_str = std::move(str);
      }

      BaseRTIstring(StringType const &str) {
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
        m_str += str;
      }

      BaseRTIstring(StringType&& str) {
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
        m_str += std::move(str);
      }

      virtual void get(StringType const &str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
        m_str += str;
      }

      virtual void get(StringType&& str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
        m_str += std::move(str);
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
        unsigned iq = static_cast<unsigned>(obj.size());
        m_str = StringType(reinterpret_cast<const char*>(obj.data()),iq);
      }

      void getData(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, 4);
        Tools::changeENDIAN(_size);
        if (_size!=inSize-4) {

          ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize())
                              + L" пришло " + std::to_wstring(inSize) + L" байт");
          throw ex;
        }
        m_str = StringType(reinterpret_cast<char*>(ptrSource),_size+4);

      }

      void getDataMax(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, 4);
        Tools::changeENDIAN(_size);
        if (_size > inSize-4) {

          ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize())
                             + L" пришло " + std::to_wstring(inSize) + L" байт");
          throw ex;
        }
        m_str = StringType(reinterpret_cast<char*>(ptrSource),_size+4);
      }

      void get(StringType& ModelStr) {
        unsigned lenth = static_cast<unsigned>(ModelStr.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<char*>(&lenth),4);
        m_str += ModelStr;
      }

      void setDataToRTI(rti1516e::VariableLengthData &data){
        data.setData(reinterpret_cast<char*>(&m_str[0]), static_cast<unsigned long>(m_str.size()));
      }

      void setData(void* ptrDest, unsigned long inSize) /*noexcept(false)*/ {
        if (getsize()!=inSize) {
            ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize())
                               + L" пришло " + std::to_wstring(inSize) + L" байт");
            throw ex;
        }
        memcpy(ptrDest, reinterpret_cast<char*>(&m_str[0]), inSize);
      }

      unsigned setData(void* ptrDest)  {
        memcpy(ptrDest, &m_str[0], getsize());
        return getsize();
      }

      void set(StringType& ModelStr) {
        ModelStr = StringType(&m_str[4], m_str.size()-4);
      }

      unsigned getsize() {
        return static_cast<unsigned>(m_str.size());
      }

      unsigned getOctetBoundary() {return 1;}

    private:
      StringType m_str;
    };

    using RTIstring = BaseRTIstring<String>;
    using RTIwstring = BaseRTIstring<Wstring>;
}
#endif // RTISTRING_HPP
