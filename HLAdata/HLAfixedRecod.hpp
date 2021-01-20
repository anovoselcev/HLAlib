#ifndef RTIFIXEDRECOD_HPP
#define RTIFIXEDRECOD_HPP
#define BOOST_PFR_USE_CPP17 0
#include "BasicTemplates.hpp"
#include "boost/pfr.hpp"

namespace HLA {

    template<typename HLAtype>
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);

    template <typename T_MOD, unsigned OBV = 8>
    class BaseFixedRecord : public ClassForRTI <T_MOD, OBV> {
    protected:
      byte* ptrData = nullptr;
    public:

      using type = T_MOD;
      using assertion_type = type;

      unsigned m_uiSizeData = 0;

      virtual ~BaseFixedRecord() {
        if (ptrData) {
          delete[] ptrData;
          ptrData = nullptr;
        }
      }

      virtual void get(BaseFixedRecord &obj) {
        rti1516e::VariableLengthData data;
        if (this != &obj) {
          obj.setDataToRTI(data);
          this->getDataFromRTI(data);
        }
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        if (ptrData)  {
          obj.setData(ptrData, m_uiSizeData);
        }
        else {
          ExceptionForRTI ex(L"HLAfixedRecord.setDataToRTI. NULL pointer.");
          throw ex;
        }
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (m_uiSizeData != inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"HLAfixedRecord\n" << L"The size of the data did not match. Must recive " << m_uiSizeData
              << L" recived " << inSize << L" bytes";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        if (ptrData)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        }
        else {
            ExceptionForRTI ex(L"HLAfixedRecord.setData. ) + NULL pointer.");
            throw ex;
        }
      }

      unsigned setData(void* ptrDest) const{
        if (ptrData)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        }
        else {
          ExceptionForRTI ex(L"HLAfixedRecord.setData. NULL pointer.");
          throw ex;
        }
        return m_uiSizeData;
      }

      void getDataFromRTI(const rti1516e::VariableLengthData &obj){
        getDataMax(const_cast<void*>(obj.data()),static_cast<unsigned long>(obj.size()));
      }

      void getData(void* ptrSource, unsigned long inSize){
        getDataMax(ptrSource,inSize);
      }

      void getDataMax(void* , unsigned long ){}

      unsigned getsize() const {return m_uiSizeData;}

      template <class FieldType,
                class FieldTypeNext>
      void F_offset(FieldType& field,
                    FieldTypeNext& fieldNext,
                    unsigned &offset,
                    void* ptrSource,
                    unsigned uiMaxSize) {
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
      void auto_offset(unsigned &offset,
                       void* ptrSource,
                       unsigned long uiMaxSize,
                       FieldType& field){
          F_offsetLast<FieldType>(field,offset,ptrSource,static_cast<unsigned>(uiMaxSize));
          if (ptrData) delete[] ptrData;
            m_uiSizeData = offset;
            ptrData = new HLA::byte[m_uiSizeData];
            memcpy(ptrData, ptrSource, m_uiSizeData);
      }

      template<typename Field1, typename Field2, typename ...Fields>
      void auto_offset(unsigned &offset,
                       void* ptrSource,
                       unsigned long uiMaxSize,
                       Field1& field1,
                       Field2& field2,
                       Fields&... fields){
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
          if(ptrData) delete[] ptrData;
          ptrData = new HLA::byte[m_uiSizeData];
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




    template< typename Struct,
              unsigned OBV,
              typename ...HLA_types>
    class Struct_wrapper final : public BaseFixedRecord<Struct, OBV>{

    public:

        void getDataMax(void *ptrSource, unsigned long uiMaxSize){
            unsigned offset = 0;
            ref_offset<HLA_types...>(offset, ptrSource, uiMaxSize);
        }

        void get(const Struct &obj){
            unsigned offset = 0, uiSize;
            this->m_uiSizeData = 0;
            std::tuple<HLA_types...> converters;
            ref_geter_first<true, 0, HLA_types...>(offset,uiSize,converters,obj);

            ref_geter_second<true, 0, HLA_types...>(offset, uiSize,converters);

        }

        void set(Struct &obj){
            unsigned offset = 0, uiSize;
            ref_seter<true, 0, HLA_types...>(offset,uiSize,obj);
        }

    private:

        template <class FieldType,
                  class FieldTypeNext>
        void Fideld_offset(FieldType& field,
                           FieldTypeNext& fieldNext,
                           unsigned &offset,
                           void* ptrSource,
                           unsigned uiMaxSize) {
          unsigned P, uiSize, mmOBV;
          field.getDataMax(reinterpret_cast<char*>(ptrSource)+offset, uiMaxSize-offset);
          uiSize = field.getsize();
          mmOBV = fieldNext.getOctetBoundary();
          P = Tools::getPendingBytes(offset+uiSize,mmOBV);
          offset += uiSize+P;
        }

        template <class FieldType>
        void Field_offsetLast(FieldType& field,
                              unsigned &offset,
                              void* ptrSource,
                              unsigned uiMaxSize) {
          unsigned uiSize;
          field.getDataMax(reinterpret_cast<char*>(ptrSource)+offset, uiMaxSize-offset);
          uiSize = field.getsize();
          offset += uiSize;
        }

        template<typename FieldType>
        void ref_offset(unsigned &offset,
                        void* ptrSource,
                        unsigned long uiMaxSize){
            FieldType field;
            Field_offsetLast<FieldType>(field,offset,ptrSource,static_cast<unsigned>(uiMaxSize));
            if (this->ptrData)
                delete[] this->ptrData;
            this->m_uiSizeData = offset;
            this->ptrData = new HLA::byte[this->m_uiSizeData];
            memcpy(this->ptrData, ptrSource, this->m_uiSizeData);
        }

        template<typename Field1,
                 typename Field2,
                 typename ...Fields>
        void ref_offset(unsigned &offset,
                        void* ptrSource,
                        unsigned long uiMaxSize){
            Field1 field1;
            Field2 field2;
            Fideld_offset< Field1, Field2 >(field1,field2,offset,ptrSource,uiMaxSize);
            ref_offset<Field2, Fields...>(offset, ptrSource,uiMaxSize);
        }

        template<bool first,
                 size_t count,
                 typename Field>
        std::enable_if_t<first, void> ref_geter_first(unsigned& offset,
                             unsigned& uiSize,
                             std::tuple<HLA_types...>& conv,
                             const Struct& obj){

            auto value = boost::pfr::get<count>(obj);
            static_assert (std::is_same<typename Field::assertion_type, decltype (value)>::value, "Types don't match" );

            std::get<count>(conv).get(value);
            uiSize = std::get<count>(conv).getsize();
            offset += uiSize;
            this->m_uiSizeData = offset;
            if(this->ptrData)
                delete[] this->ptrData;
            this->ptrData = new HLA::byte[this->m_uiSizeData];
            offset = 0;
        }

        template<bool first,
                 size_t count,
                 typename Field>
        std::enable_if_t<!first, void> ref_geter_first(unsigned& offset,
                             unsigned& uiSize,
                             std::tuple<HLA_types...>& conv,
                             const Struct& obj){

            auto value = boost::pfr::get<count>(obj);
            static_assert (std::is_same<typename Field::assertion_type, decltype (value)>::value, "Types don't match" );

            std::get<count>(conv).get(value);
            unsigned P,mmOBV;
            mmOBV = std::get<count>(conv).getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset + uiSize,mmOBV);
            offset += uiSize + P;
            uiSize = std::get<count>(conv).getsize();
            offset += uiSize;
            this->m_uiSizeData = offset;
            if(this->ptrData)
                delete[] this->ptrData;
            this->ptrData = new HLA::byte[this->m_uiSizeData];
            offset = 0;
        }


        template<bool first ,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<first, void> ref_geter_first(unsigned& offset,
                             unsigned& uiSize,
                             std::tuple<HLA_types...>& conv,
                             const Struct& obj){
            auto value = boost::pfr::get<count>(obj);
            static_assert (std::is_same<typename Field1::assertion_type, decltype(value)>::value, "Types don't match" );
            std::get<count>(conv).get(value);
            uiSize = std::get<count>(conv).getsize();
            ref_geter_first<false, count + 1, Field2, Fields...>(offset,uiSize, conv, obj);
        }

        template<bool first ,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<!first, void> ref_geter_first(unsigned& offset,
                             unsigned& uiSize,
                             std::tuple<HLA_types...>& conv,
                             const Struct& obj){
            auto value = boost::pfr::get<count>(obj);
            static_assert (std::is_same<typename Field1::assertion_type, decltype(value)>::value, "Types don't match" );
            std::get<count>(conv).get(value);
            unsigned P,mmOBV;
            mmOBV = std::get<count>(conv).getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = std::get<count>(conv).getsize();
            ref_geter_first<false, count + 1, Field2, Fields...>(offset,uiSize, conv, obj);
        }

        template<bool first,
                 size_t count,
                 typename Field>
         std::enable_if_t<first, void> ref_geter_second(unsigned& offset,
                               unsigned& uiSize,
                               std::tuple<HLA_types...>& conv){
            uiSize = std::get<count>(conv).getsize();
            std::get<count>(conv).setData(this->ptrData + offset,uiSize);
        }

         template<bool first,
                  size_t count,
                  typename Field>
          std::enable_if_t<!first, void> ref_geter_second(unsigned& offset,
                                unsigned& uiSize,
                                std::tuple<HLA_types...>& conv){
             unsigned P, mmOBV;
             mmOBV = std::get<count>(conv).getOctetBoundary();
             P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
             offset += uiSize+P;
             uiSize = std::get<count>(conv).getsize();
             std::get<count>(conv).setData(this->ptrData+offset,uiSize);
         }

        template<bool first,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<first, void> ref_geter_second(unsigned& offset,
                              unsigned& uiSize,
                              std::tuple<HLA_types...>& conv){
            uiSize = std::get<count>(conv).getsize();
            std::get<count>(conv).setData(this->ptrData+offset,uiSize);
            ref_geter_second<false, count + 1, Field2, Fields...>(offset, uiSize, conv);
        }

        template<bool first,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<!first, void> ref_geter_second(unsigned& offset,
                              unsigned& uiSize,
                              std::tuple<HLA_types...>& conv){
            unsigned P,mmOBV;
            mmOBV = std::get<count>(conv).getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            uiSize = std::get<count>(conv).getsize();
            std::get<count>(conv).setData(this->ptrData+offset,uiSize);
            ref_geter_second<false, count + 1, Field2, Fields...>(offset, uiSize, conv);
        }

        template<bool first,
                 size_t count,
                 typename Field>
        std::enable_if_t<first, void> ref_seter(unsigned& offset,
                       unsigned& uiSize,
                       Struct& obj){

            std::remove_reference_t<decltype (boost::pfr::get<count>(obj))> value;
            static_assert (std::is_same<typename Field::assertion_type, decltype (value)>::value, "Types don't match" );
            Field field;
            field.getDataMax(this->ptrData+offset,this->m_uiSizeData-offset);
            field.set(value);
            boost::pfr::get<count>(obj) = std::move(value);
            uiSize = field.getsize();
        }

        template<bool first,
                 size_t count,
                 typename Field>
        std::enable_if_t<!first, void> ref_seter(unsigned& offset,
                       unsigned& uiSize,
                       Struct& obj){

            std::remove_reference_t<decltype (boost::pfr::get<count>(obj))> value;
            static_assert (std::is_same<typename Field::assertion_type, decltype (value)>::value, "Types don't match" );
            unsigned P, mmOBV;
            Field field;
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field.getDataMax(this->ptrData+offset,this->m_uiSizeData-offset);
            field.set(value);
            boost::pfr::get<count>(obj) = std::move(value);
            uiSize = field.getsize();
        }

        template<bool first,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<first, void> ref_seter(unsigned& offset,
                       unsigned& uiSize,
                       Struct& obj){
            std::remove_reference_t<decltype (boost::pfr::get<count>(obj))> value;
            static_assert (std::is_same<typename Field1::assertion_type, decltype (value)>::value, "Types don't match" );
            Field1 field;
            field.getDataMax(this->ptrData+offset,this->m_uiSizeData-offset);
            field.set(value);
            boost::pfr::get<count>(obj) = std::move(value);
            uiSize = field.getsize();
            ref_seter<false, count + 1, Field2, Fields...>(offset,uiSize,obj);
        }


        template<bool first,
                 size_t count,
                 typename Field1,
                 typename Field2,
                 typename ...Fields>
        std::enable_if_t<!first, void> ref_seter(unsigned& offset,
                       unsigned& uiSize,
                       Struct& obj){
            std::remove_reference_t<decltype (boost::pfr::get<count>(obj))> value;
            static_assert (std::is_same<typename Field1::assertion_type, decltype (value)>::value, "Types don't match" );
            unsigned P, mmOBV;
            Field1 field;
            mmOBV = field.getOctetBoundary();
            P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
            offset += uiSize+P;
            field.getDataMax(this->ptrData+offset,this->m_uiSizeData-offset);

            field.set(value);
            boost::pfr::get<count>(obj) = std::move(value);
            uiSize = field.getsize();
            ref_seter<false, count + 1, Field2, Fields...>(offset,uiSize,obj);
        }
    };


}
#endif // RTIFIXEDRECOD_HPP
