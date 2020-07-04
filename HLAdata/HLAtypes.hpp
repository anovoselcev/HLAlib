#ifndef RTITYPES_HPP
#define RTITYPES_HPP

#include "BasicTemplates.hpp"

namespace HLA {

    template <class T, unsigned mem, bool blLE=true>
      class SimpleData: public ClassForRTI <T,mem>{
        public:

          using type = T;

          SimpleData() {
                m_data=0;
          }

          SimpleData(const SimpleData& obj){
              if (this != &obj) {
                obj.setData(&m_data);
              }
            }

          SimpleData(SimpleData&& obj) = default;

          SimpleData(const T& obj) {
            m_data = obj;
            if (!blLE) changeENDIAN(m_data);
          }

          virtual void get(T const &obj) {
            m_data = obj;
            if (!blLE) Tools::changeENDIAN(m_data);
          }

          void getDataFromRTI(rti1516e::VariableLengthData const &obj){
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

          SimpleData<T,mem,blLE>& operator = (const T & obj) {
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



        using Integer16BE    = SimpleData<int16_t, 2, false>;
        using Integer32BE    = SimpleData<int, 4, false>;
        using Integer64BE    = SimpleData<int64_t, 8, false>;
        using OctetPairBE    = SimpleData<uint16_t, 2, false>;
        using Float32BE      = SimpleData<float, 4, false>;
        using Float64BE      = SimpleData<double, 8, false>;
        using Octet          = SimpleData<Octet_, 1, true>;
        using Byte           = SimpleData<bool, 1, true>;
        using Integer16LE    = SimpleData<int16_t, 2, true>;
        using Integer32LE    = SimpleData<int, 4, true>;
        using Integer64LE    = SimpleData<int64_t, 8, true>;
        using OctetPairLE    = SimpleData<uint16_t, 2, true>;
        using Float32LE      = SimpleData<float, 4, true>;
        using Float64LE      = SimpleData<double, 8, true>;
        using UnsignedShort  = SimpleData<uint16_t, 2, true>;
        using Unsigned32LE   = SimpleData<uint32_t, 4, true> ;
        using Unsigned64LE   = SimpleData<uint64_t, 8, true>;
        using Char           = SimpleData<char,2,true>;
        using Wchar          = SimpleData<wchar_t, 4, true>;

        template<typename HLAtype>
        rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t){
            HLAtype conv;
            rti1516e::VariableLengthData v;
            conv.get(t);
            conv.setDataToRTI(v);
            return v;
        }

        template<typename HLAtype>
        typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v){
            HLAtype conv;
            typename HLAtype::type t;
            conv.getDataFromRTI(v);
            conv.set(t);
            return t;
        }
  }
#endif // RTITYPES_HPP
