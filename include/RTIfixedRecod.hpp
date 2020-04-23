#ifndef RTIFIXEDRECOD_HPP
#define RTIFIXEDRECOD_HPP
#include <RTI/RTI1516.h>

#include "RTItypes.hpp"

namespace HLA {

    template <class T_MOD, unsigned OBV>
    class BaseRTIFixedRecord : public ClassForRTI <T_MOD, OBV> {
    protected:
      Octet* ptrData;
    public:

      using type = T_MOD;

      unsigned m_uiSizeData;

      BaseRTIFixedRecord() : ClassForRTI<T_MOD, OBV>() {
        ptrData=nullptr;
        m_uiSizeData = 0;
      }

      BaseRTIFixedRecord(const BaseRTIFixedRecord &fixedRecord) : ClassForRTI<T_MOD, OBV>(fixedRecord) {
      }

      virtual ~BaseRTIFixedRecord() {
        if (ptrData!=nullptr) {
          delete[] ptrData;
          ptrData=nullptr;
        }
      }

      virtual void get(BaseRTIFixedRecord &obj) {
        rti1516e::VariableLengthData data;
        if (this != &obj) {
          obj.setDataToRTI(data);
          this->getDataFromRTI(data);
        }
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        if (ptrData!=nullptr)  {
          obj.setData(ptrData,m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"BaseHLAfixedRecord.setDataToRTI. Нулевой указатель.");
          throw ex;
        }
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (m_uiSizeData!=inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"BaseHLAfixedRecord\n" << L"Размер данных не совпал. Должно быть " << m_uiSizeData
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
            ExceptionForRTI ex(L"BaseHLAfixedRecord.setData. ) + Нулевой указатель.");
            throw ex;
        }
      }

      unsigned setData(void* ptrDest){
        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"BaseHLAfixedRecord.setData. Нулевой указатель.");
          throw ex;
        }
        return m_uiSizeData;
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
        getDataMax(const_cast<void*>(obj.data()),static_cast<unsigned long>(obj.size()));
      }

      void getData(void* ptrSource, unsigned long inSize){
        getDataMax(ptrSource,inSize);
      }

      void getDataMax(void* , unsigned long ){}

      unsigned getsize(){return m_uiSizeData;}

      template <class FieldType, class FieldTypeNext>
      void F_offset(FieldType& field, FieldTypeNext& fieldNext,  unsigned &offset, void* ptrSource, unsigned uiMaxSize) {
        unsigned P, uiSize, mmOBV;
        field.getDataMax(reinterpret_cast<char*>(ptrSource)+offset, uiMaxSize-offset);
        uiSize = field.getsize();
        mmOBV = fieldNext.getOctetBoundary();
        P = Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
      }

      template <class FieldType>
      void F_offsetLast(FieldType& field,  unsigned &offset, void* ptrSource, unsigned uiMaxSize) {
        unsigned uiSize;
        field.getDataMax(reinterpret_cast<char*>(ptrSource)+offset, uiMaxSize-offset);
        uiSize = field.getsize();
        offset += uiSize;
      }

      template<typename FieldType>
      void auto_offset(unsigned &offset, void* ptrSource, unsigned uiMaxSize,FieldType& field){
          F_offsetLast<FieldType>(field,offset,ptrSource,static_cast<unsigned>(uiMaxSize));
          if (ptrData!=nullptr) delete[] ptrData;
            m_uiSizeData = offset;
            ptrData = new HLA::Octet[m_uiSizeData];
            memcpy(ptrData, ptrSource, m_uiSizeData);
      }

      template<typename Field1, typename Field2, typename ...Fields>
      void auto_offset(unsigned &offset, void* ptrSource, unsigned uiMaxSize,Field1& field1,Field2& field2,Fields&... fields){
        F_offset< Field1, Field2 >(field1,field2,offset,ptrSource,uiMaxSize);
        auto_offset(offset, ptrSource,uiMaxSize,field2,fields...);
      }

      template<bool first = true, typename Field>
      void auto_geter_first(unsigned& offset, unsigned& uiSize, Field& field,typename Field::type const & t){
          field.get(t);
          unsigned P,mmOBV;
          if(!first){
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
          }
          uiSize = field.getsize();
          offset+=uiSize;
          m_uiSizeData = offset;
          if(ptrData!=nullptr) delete[] ptrData;
          ptrData = new HLA::Octet[m_uiSizeData];
          offset = 0;
      }

      template<bool first = true, typename Field, typename ...Fields>
      void auto_geter_first(unsigned& offset, unsigned& uiSize, Field& field,typename Field::type const & t, Fields&... fields){
          field.get(t);
          unsigned P,mmOBV;
          if(!first){
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
          }
          uiSize = field.getsize();
          auto_geter_first<false>(offset,uiSize,fields...);
      }

      template<bool first = true, typename Field>
      void auto_geter_second(unsigned& offset, unsigned& uiSize, Field& field){
          unsigned P, mmOBV;
          if(!first){
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
          }
          uiSize = field.getsize();
          field.setData(ptrData+offset,uiSize);
      }

      template<bool first = true, typename Field, typename ...Fields>
      void auto_geter_second(unsigned& offset, unsigned& uiSize, Field& field, Fields&... fields){
          unsigned P,mmOBV;
          if(!first){
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
          }
          uiSize = field.getsize();
          field.setData(ptrData+offset,uiSize);
          auto_geter_second<false>(offset,uiSize,fields...);
      }

      template<bool first = true, typename Field>
      void auto_seter(unsigned& offset, unsigned& uiSize, Field& field,typename Field::type& t){
          unsigned P, mmOBV;
          if(!first){
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
        }
        field.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field.set(t);
        uiSize = field.getsize();
      }

      template<bool first = true, typename Field, typename ...Fields>
      void auto_seter(unsigned& offset, unsigned& uiSize, Field& field,typename Field::type& t, Fields&... fields){
          unsigned P, mmOBV;
          if(!first){
              mmOBV = field.getOctetBoundary();
              P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
              offset += uiSize+P;
          }
          field.getDataMax(ptrData+offset,m_uiSizeData-offset);
          field.set(t);
          uiSize = field.getsize();
          auto_seter<false>(offset,uiSize,fields...);
      }
};


}
#endif // RTIFIXEDRECOD_HPP
