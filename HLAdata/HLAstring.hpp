#ifndef RTISTRING_HPP
#define RTISTRING_HPP

#include "BasicTemplates.hpp"
#include <cstring>
#include <type_traits>

namespace HLA {

    template<typename HLAtype>
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);


    template <typename StringType,
              typename symb = typename std::conditional<std::is_same<StringType,std::string>::value,char,wchar_t>::type,
              int OBV = sizeof (symb),
              int unit = 4>
    class BaseHLAstring final: public ClassForRTI<StringType,OBV> {
    public:

        using type = StringType;
        using assertion_type = type;

      BaseHLAstring() {
        unsigned lenth = 0;
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
      }

      void get(const BaseHLAstring &str) {
        m_str = str;
      }

      virtual void get(const StringType &str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<symb*>(&lenth),unit);
        m_str += str;
      }

      void getDataFromRTI(const rti1516e::VariableLengthData &obj){
        unsigned iq = static_cast<unsigned>(obj.size());
        m_str = StringType(reinterpret_cast<const symb*>(obj.data()),iq/OBV);
      }
      void getData(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, unit);
        Tools::changeENDIAN(_size);
        if (_size != inSize - unit)
          throw std::runtime_error("The size of the data did not match. Must recive " + std::to_string(getsize()) +
                                   " recived " + std::to_string(inSize) + " bytes. In String getData");;
        m_str = StringType(reinterpret_cast<symb*>(ptrSource),_size+unit);

      }

      void getDataMax(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, unit);
        Tools::changeENDIAN(_size);


        if (_size > inSize - unit)
          throw std::runtime_error("The size of the data did not match. Must recive  " + std::to_string(getsize()) +
                             " recived " + std::to_string(inSize) + " bytes. In String getDataMax");

        m_str = StringType(reinterpret_cast<symb*>(ptrSource),_size + unit);
      }

      void get(StringType& ModelStr) {
        unsigned lenth = static_cast<unsigned>(ModelStr.length());
        Tools::changeENDIAN(lenth);
        m_str = StringType(reinterpret_cast<symb*>(&lenth), unit);
        m_str += ModelStr;
      }

      void setDataToRTI(rti1516e::VariableLengthData &data) {
        data.setData(reinterpret_cast<symb*>(&m_str[0]), static_cast<unsigned long>(m_str.size() * OBV));
      }

      void setData(void* ptrDest, unsigned long inSize) {
        if (getsize() != inSize)
          throw std::runtime_error("The size of the data did not match. Must recive  " + std::to_string(getsize()) +
                                   " recived " + std::to_string(inSize) + " bytes. In String SetData");

        memcpy(ptrDest, reinterpret_cast<symb*>(&m_str[0]), inSize);
      }

      unsigned setData(void* ptrDest) const {
        memcpy(ptrDest, &m_str[0], getsize());
        return getsize();
      }

      void set(StringType& ModelStr) {
        ModelStr = StringType(&m_str[4], m_str.size() - 4);
      }

      unsigned getsize() const {
        return static_cast<unsigned>(m_str.size()) * OBV;
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
