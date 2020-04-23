#ifndef RTIENUM_HPP
#define RTIENUM_HPP

#include <RTI/RTI1516.h>

#include "RTItypes.hpp"

namespace HLA {

    template <class Type, class RTI_Representation = Integer32BE, unsigned m_OBV = 4>
    class RTIenum : public ClassForRTI <Type,m_OBV>
    {
    public:

      RTIenum() {
        m_data = 0;
      }

      RTIenum(const Type& source) {
        m_data = source;
      }

      RTIenum(Type&& source) {
        m_data = std::move(source);
      }

      void get(RTI_Representation const &obj) {
        m_data = obj.m_data;
      }

      virtual void get(Type const &source){
        m_data = source;
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
        unsigned iq = static_cast<unsigned>(obj.size());
        if (getsize()!=iq) {
          std::stringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << getsize()
              << L" пришло " << iq << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.getDataFromRTI(obj);
      }

      void getData(void* ptrSource, unsigned long inSize){
        if (getsize()!=inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << getsize()
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.getData(ptrSource,inSize);
      }

      void getDataMax(void* ptrSource, unsigned long inSize){
        unsigned long current_size = getsize();
        if (current_size > inSize) {
          ExceptionForRTI ex(L"Данные исчерпаны");
          throw ex;
        }
        m_data.getData(ptrSource,current_size);
      }

      void get(Type &data) {
        m_data = data;
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        m_data.setDataToRTI(obj);
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (getsize()!=inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << getsize()
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_data.setData(ptrDest,inSize);
      }

      unsigned setData(void* ptrDest){
        unsigned inSize;
        inSize = m_data.setData(ptrDest);
        return inSize;
      }

      void set(Type& data) {
        data = static_cast<Type>(m_data.get());
      }

      unsigned getsize() {return m_data.getsize();}

      unsigned getOctetBoundary(){return m_data.getOctetBoundary();}

      const Type get() {
        Type data;
        set(data);
        return data;
      }

      void get(const RTIenum& source) {
        if (this != &source) {
          m_data = source.m_data;
        }
      }
    private:
      RTI_Representation m_data;
};


}
#endif // RTIENUM_HPP
