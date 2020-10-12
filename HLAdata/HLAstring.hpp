#ifndef RTISTRING_HPP
#define RTISTRING_HPP

#include "BasicTemplates.hpp"
#include <type_traits>

namespace HLA {

    template <class StringType,
              class symb = typename std::conditional<std::is_same<StringType,std::string>::value,char,wchar_t>::type,
              int OBV = sizeof (symb),
              int unit = 4>
    class BaseHLAstring final: public ClassForRTI<StringType,OBV> {
    public:

        using type = StringType;

      BaseHLAstring() {
        unsigned lenth = 0;
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
      }

      void get(BaseHLAstring const &str) {
        m_str = str;
      }

      BaseHLAstring(StringType const &str) {
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
        m_str += str;
      }

      virtual void get(StringType const &str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
        m_str += str;
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj) /*noexcept(false)*/ {
        unsigned iq = static_cast<unsigned>(obj.size());
        m_str = StringType(reinterpret_cast<const symb*>(obj.data()),iq/OBV);
      }
      void getData(void* ptrSource, unsigned long inSize) /*noexcept(false)*/{
        unsigned _size;
        memcpy(&_size, ptrSource, unit);
        Tools::changeENDIAN(_size);
        if (_size!=inSize-unit) {

          ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize()) +
                             L" пришло " + std::to_wstring(inSize) + L" байт. In String getData");
          throw ex;
        }
        m_str = StringType(reinterpret_cast<symb*>(ptrSource),_size+unit);

      }

      void getDataMax(void* ptrSource, unsigned long inSize) /*noexcept(false)*/
      {
        unsigned _size;
        memcpy(&_size, ptrSource, unit);
        Tools::changeENDIAN(_size);


        if (_size > inSize-unit) {
          ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize()) +
                             L" пришло " + std::to_wstring(inSize) + L" байт. In String getDataMax");
          throw ex;
        }
        m_str = StringType(reinterpret_cast<symb*>(ptrSource),_size+unit);
      }

      void get(StringType& ModelStr) {
        unsigned lenth = static_cast<unsigned>(ModelStr.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
        m_str += ModelStr;
      }

      void setDataToRTI(rti1516e::VariableLengthData &data) /*noexcept(false)*/ {
        data.setData(reinterpret_cast<symb*>(&m_str[0]), static_cast<unsigned long>(m_str.size()*OBV));
      }

      void setData(void* ptrDest, unsigned long inSize) /*noexcept(false)*/ {
        if (getsize()!=inSize) {

          ExceptionForRTI ex(L"Размер данных не совпал. Должно прийти " + std::to_wstring(getsize()) +
                             L" пришло " + std::to_wstring(inSize) + L" байт. In String SetData");
          throw ex;
        }
        memcpy(ptrDest, reinterpret_cast<symb*>(&m_str[0]), inSize);
      }

      unsigned setData(void* ptrDest) /*noexcept(false)*/ {
        memcpy(ptrDest, &m_str[0], getsize());
        return getsize();
      }

      void set(StringType& ModelStr) {
        ModelStr = StringType(&m_str[4], m_str.size()-4);
      }

      unsigned getsize() {
        return static_cast<unsigned>(m_str.size())*OBV;
      }
      unsigned getOctetBoundary() {return OBV;}


    private:
      StringType m_str;
};

    using String = BaseHLAstring<std::string>;
    using Wstring = BaseHLAstring<std::wstring>;

template<>
inline rti1516e::VariableLengthData cast_to_rti<Wstring>(const typename std::wstring& t){
        String conv;
        std::string str(Tools::unwiden(t));
        rti1516e::VariableLengthData v;
        conv.get(str);
        conv.setDataToRTI(v);
        return v;
    }

template<>
inline std::wstring cast_from_rti<Wstring>(const rti1516e::VariableLengthData& v){
        String conv;
        std::string str;
        conv.getDataFromRTI(v);
        conv.set(str);
        return Tools::widen(std::move(str));
    }
}
#endif // RTISTRING_HPP
