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
  class Simple: public ClassForRTI <T,mem>{
    public:

      Simple() {
        m_data=0;
      }

      Simple(Simple& obj);

      Simple(const T& obj) {
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
          std::stringstream wstrOut;
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
          std::stringstream wstrOut;
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

      void get(const Simple<T,mem,blLE>& obj) {
        if (this != &obj) {
          m_data = obj.m_data;
        }
      }

      Simple<T,mem,blLE> &operator = (const T& obj) {
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
    Simple<T,mem,blLE>::Simple(Simple& obj):ClassForRTI<T,mem>(obj) {
      if (this != &obj) {
        obj.setData(&m_data);
      }
    }

    template <class T, unsigned mem, bool blLE>
    void Simple<T,mem,blLE>::getDataFromRTI(rti1516e::VariableLengthData const &obj){
      unsigned size = (unsigned)obj.size();
      if (sizeof(T)!=size) {
        std::stringstream wstrOut;
        wstrOut
            << L"Размер данных не совпал. Должно прийти " << (unsigned)sizeof(T)
            << L" пришло " << size << L" байт";
        ExceptionForRTI ex(wstrOut.str());
        throw ex;
      }
      memcpy(&m_data, obj.data(), size);
    }

    using RTIinteger16BE    = Simple<Integer16BE, 2, false>;
    using RTIinteger32BE    = Simple<Integer32BE, 4, false>;
    using RTIinteger64BE    = Simple<Integer64BE, 8, false>;
    using RTIoctetPairBE    = Simple<OctetPairBE, 2, false>;
    using RTIfloat32BE      = Simple<Float32BE, 4, false>;
    using RTIfloat64BE      = Simple<Float64BE, 8, false>;
    using RTIoctet          = Simple<Octet, 1, true>;
    using RTIbyte           = Simple<Byte, 1, true>;
    using RTIinteger16LE    = Simple<Integer16LE, 2, true>;
    using RTIinteger32LE    = Simple<Integer32LE, 4, true>;
    using RTIinteger64LE    = Simple<Integer64LE, 8, true>;
    using RTIoctetPairLE    = Simple<OctetPairLE, 2, true>;
    using RTIfloat32LE      = Simple<Float32LE, 4, true>;
    using RTIfloat64LE      = Simple<Float64LE, 8, true>;
    using RTIUnsignedShort  = Simple<UnsignedShort, 2, true>;
    using RTIUnsigned32LE   = Simple<Unsigned32LE, 4, true> ;
    using RTIUnsigned64LE   = Simple<Unsigned64LE, 8, true>;
  }
#endif // BASICCONVERTER_HPP
