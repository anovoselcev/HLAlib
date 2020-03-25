#ifndef BASICCONVERTER_HPP
#define BASICCONVERTER_HPP
#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#pragma warning(disable: 4482)
#endif
#define FUNCTION_COMMON_API
#include <string.h>

#include <RTI/RTI1516.h>
#include "BasicTypes.hpp"
#include "BasicTemplates.hpp"

namespace HLA {

template <class T, unsigned mem, bool blLE=true>
  class SimpleData: public ClassForRTI <T,mem>{
    public:

      SimpleData() {
            m_data=0;
      }

      SimpleData(const SimpleData& obj);

      SimpleData(SimpleData&& obj) = default;

      SimpleData(const T& obj) {
        m_data = obj;
        if (!blLE) changeENDIAN(m_data);
      }

      virtual void get(T const &obj) {
        m_data = obj;
        if (!blLE) Tools::changeENDIAN(m_data);
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj);

      void getData(void* input_data, unsigned long size){
        if (sizeof(T)!=size) {
          std::ostringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << (unsigned)sizeof(T)
              << L" пришло " << size << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        memcpy(&m_data, input_data, size);
      }


      void getDataMax(void* ptrSource, unsigned long inSize)
      {
        size_t current_size = getsize();
        if (current_size > inSize) {
            ExceptionForRTI ex(L"Данные исчерпаны");
          throw ex;
        }
        memcpy(&m_data, ptrSource, current_size);
      }

      void get(T& obj){
        m_data=obj;
        if (!blLE) changeENDIAN(m_data);
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        obj.setData(&m_data,sizeof(T));
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (sizeof(T)!=inSize) {
          std::ostringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << (unsigned)sizeof(T)
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        memcpy(ptrDest, &m_data, inSize);
      }

      unsigned setData(void* ptrDest){
        size_t inSize = sizeof(T);
        memcpy(ptrDest, &m_data, inSize);
        return (unsigned)inSize;
      }

      void set(T& data) {
        data=m_data;
        if (!blLE) {
          Tools::changeENDIAN(data);
        }
      }

      unsigned getsize() {return sizeof(T);}

      void get(const SimpleData<T,mem,blLE>& obj) {
        if (this != &obj) {
          m_data = obj.m_data;
        }
      }

      SimpleData<T,mem,blLE>& operator = (const T& obj) {
        m_data=obj;
        if (!blLE) Tools::changeENDIAN(m_data);
        return *this;
      }

      const T get() {
        T dataLE=m_data;
        if (!blLE) Tools::changeENDIAN(dataLE);
        return dataLE;
      }
    private:
      T m_data;
      T& getOrg() {return m_data;}
    };

    template <class T, unsigned mem, bool blLE>
    SimpleData<T,mem,blLE>::SimpleData(const SimpleData& obj):ClassForRTI<T,mem>(obj) {
      if (this != &obj) {
        obj.setData(&m_data);
      }
    }

    template <class T, unsigned mem, bool blLE>
    void SimpleData<T,mem,blLE>::getDataFromRTI(rti1516e::VariableLengthData const &obj){
      unsigned size = (unsigned)obj.size();
      if (sizeof(T)!=size) {
        std::ostringstream wstrOut;
        wstrOut
            << L"Размер данных не совпал. Должно прийти " << (unsigned)sizeof(T)
            << L" пришло " << size << L" байт";
        ExceptionForRTI ex(wstrOut.str());
        throw ex;
      }
      memcpy(&m_data, obj.data(), size);
    }

    using RTIinteger16BE    = SimpleData<Integer16BE, 2, false>;
    using RTIinteger32BE    = SimpleData<Integer32BE, 4, false>;
    using RTIinteger64BE    = SimpleData<Integer64BE, 8, false>;
    using RTIoctetPairBE    = SimpleData<OctetPairBE, 2, false>;
    using RTIfloat32BE      = SimpleData<Float32BE, 4, false>;
    using RTIfloat64BE      = SimpleData<Float64BE, 8, false>;
    using RTIoctet          = SimpleData<Octet, 1, true>;
    using RTIbyte           = SimpleData<Byte, 1, true>;
    using RTIinteger16LE    = SimpleData<Integer16LE, 2, true>;
    using RTIinteger32LE    = SimpleData<Integer32LE, 4, true>;
    using RTIinteger64LE    = SimpleData<Integer64LE, 8, true>;
    using RTIoctetPairLE    = SimpleData<OctetPairLE, 2, true>;
    using RTIfloat32LE      = SimpleData<Float32LE, 4, true>;
    using RTIfloat64LE      = SimpleData<Float64LE, 8, true>;
    using RTIUnsignedShort  = SimpleData<UnsignedShort, 2, true>;
    using RTIUnsigned32LE   = SimpleData<Unsigned32LE, 4, true> ;
    using RTIUnsigned64LE   = SimpleData<Unsigned64LE, 8, true>;
    using RTIchar           = SimpleData<Char,2,true>;
    using RTIunicodeChar    = SimpleData<unicodeChar,2,true>;
    using RTIASCIIchar      = SimpleData<ASCIIchar,2,true>;
  }
#endif // BASICCONVERTER_HPP
