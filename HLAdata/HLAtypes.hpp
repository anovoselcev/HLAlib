#ifndef RTITYPES_HPP
#define RTITYPES_HPP

#include "BasicTemplates.hpp"

namespace HLA {

    template<typename HLAtype>
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);


    template <typename T, unsigned mem, bool blLE = true>
    class SimpleData final: public ClassForRTI <T,mem>{
    public:

        using type = T;
        using assertion_type = type;

        SimpleData() {
            m_data = 0;
        }

        virtual void get(const T &obj) {
            m_data = obj;
            if (!blLE)
                Tools::changeENDIAN(m_data);
        }

        void getDataFromRTI(const rti1516e::VariableLengthData &obj){
            unsigned size = static_cast<unsigned>(obj.size());
            if (sizeof(T) != size) {
                std::ostringstream wstrOut;
                wstrOut
                        << "The size of the data did not match. Must recive " << static_cast<unsigned>(sizeof(T))
                        << " recived " << size << " bytes";
                throw std::runtime_error(wstrOut.str());
            }
            memcpy(&m_data, obj.data(), size);
        }

        void getData(void* input_data, unsigned long size){
            if (sizeof(T) != size) {
                std::ostringstream wstrOut;
                wstrOut
                        << "The size of the data did not match. Must recive " << static_cast<unsigned>(sizeof(T))
                        << " recived " << size << " bytes";

                throw std::runtime_error(wstrOut.str());
            }
            memcpy(&m_data, input_data, size);
        }


        void getDataMax(void* ptrSource, unsigned long inSize){
            size_t current_size = getsize();
            if (current_size > inSize)
                throw std::runtime_error("Data exhausted");

            memcpy(&m_data, ptrSource, current_size);
        }

        void get(T& obj){
            m_data=obj;
            if (!blLE)
                Tools::changeENDIAN(m_data);
        }

        void setDataToRTI(rti1516e::VariableLengthData &obj){
            obj.setData(&m_data,sizeof(T));
        }

        void setData(void* ptrDest, unsigned long inSize){
            if (sizeof(T) != inSize) {
                std::ostringstream wstrOut;
                wstrOut
                        << "The size of the data did not match. Must recive " << static_cast<unsigned>(sizeof(T))
                        << " recived " << inSize << " bytes";

                throw std::runtime_error(wstrOut.str());
            }
            memcpy(ptrDest, &m_data, inSize);
        }

        unsigned setData(void* ptrDest) const{
            size_t inSize = sizeof(T);
            memcpy(ptrDest, &m_data, inSize);
            return static_cast<unsigned>(inSize);
        }

        void set(T& data) {
            data = m_data;
            if (!blLE) {
                Tools::changeENDIAN(data);
            }
        }

        unsigned getsize() const {return sizeof(T);}

        void get(const SimpleData<T,mem,blLE>& obj) {
            if (this != &obj) {
                m_data = obj.m_data;
            }
        }

        SimpleData<T,mem,blLE>& operator = (const T & obj) {
            m_data = obj;
            if (!blLE) Tools::changeENDIAN(m_data);
            return *this;
        }

        const T get() {
            T dataLE = m_data;
            if (!blLE)
                Tools::changeENDIAN(dataLE);
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
    using Octet          = SimpleData<byte, 1, true>;
    using Bool           = SimpleData<bool, 1, true>;
    using Integer16LE    = SimpleData<int16_t, 2, true>;
    using Integer32LE    = SimpleData<int, 4, true>;
    using Integer64LE    = SimpleData<int64_t, 8, true>;
    using OctetPairLE    = SimpleData<uint16_t, 2, true>;
    using Float32LE      = SimpleData<float, 4, true>;
    using Float64LE      = SimpleData<double, 8, true>;
    using Unsigned8LE    = SimpleData<uint8_t, 1, true>;
    using Unsigned16LE   = SimpleData<uint16_t, 2, true>;
    using Unsigned32LE   = SimpleData<uint32_t, 4, true> ;
    using Unsigned64LE   = SimpleData<uint64_t, 8, true>;
    using Unsigned32BE   = SimpleData<uint32_t, 4, false> ;
    using Unsigned64BE   = SimpleData<uint64_t, 8, false>;
    using UcharLE        = SimpleData<unsigned char, 1, true>;
    using UcharBE        = SimpleData<unsigned char, 1, false>;
    using CharLE         = SimpleData<char, 2, true>;
    using CharBE         = SimpleData<char, 2, false>;
    using WcharLE        = SimpleData<wchar_t, 4, true>;
    using WcharBE        = SimpleData<wchar_t, 4, false>;


}
#endif // RTITYPES_HPP
