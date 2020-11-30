#ifndef HLAENUM_HPP
#define HLAENUM_HPP

#include "HLAtypes.hpp"

namespace HLA {

    template<typename HLAtype>
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);

    template <class Type, class RTItype = Integer32BE, unsigned OBV = 4>
    class Enum final: public ClassForRTI <Type,OBV>
    {
    public:

      using type = Type;
      using assertion_type = type;

      Enum() {
        m_data = 0;
      }

      Enum(const Type& source) {
        m_data = int(source);
      }

      Enum(Type&& source) {
        m_data = std::move(source);
      }

      void get(RTItype const &obj) {
        m_data = obj.m_data;
      }

      virtual void get(Type const &source){
        m_data = int(source);
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
        unsigned iq = static_cast<unsigned>(obj.size());
        if (getsize() != iq) {
          std::stringstream wstrOut;
          wstrOut
              << L"The size of the data did not match. Must recive  " << getsize()
              << L" recived " << iq << L" bytes";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.getDataFromRTI(obj);
      }

      void getData(void* ptrSource, unsigned long inSize){
        if (getsize() != inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"The size of the data did not match. Must recive  " << getsize()
              << L" recived " << inSize << L" bytes";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.getData(ptrSource, inSize);
      }

      void getDataMax(void* ptrSource, unsigned long inSize){
        unsigned long current_size = getsize();
        if (current_size > inSize) {
          ExceptionForRTI ex(L"Data exhausted");
          throw ex;
        }
        m_data.getData(ptrSource, current_size);
      }

      void get(Type &data) {
        m_data = data;
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        m_data.setDataToRTI(obj);
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (getsize() != inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"The size of the data did not match. Must recive  " << getsize()
              << L" recived " << inSize << L" bytes";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.setData(ptrDest, inSize);
      }

      unsigned setData(void* ptrDest) const {
        unsigned inSize;
        inSize = m_data.setData(ptrDest);
        return inSize;
      }

      void set(Type& data) {
        data = static_cast<Type>(m_data.get());
      }

      unsigned getsize() const {return m_data.getsize();}

      unsigned getOctetBoundary(){return m_data.getOctetBoundary();}

      const Type get() {
        Type data;
        set(data);
        return data;
      }

      void get(const Enum& source) {
        if (this != &source) {
          m_data = source.m_data;
        }
      }
    private:
      RTItype m_data;
};


}
#endif // HLAENUM_HPP
