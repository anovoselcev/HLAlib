#ifndef RTIVECTOR_HPP
#define RTIVECTOR_HPP
#include <RTI/RTI1516.h>

#include "RTItypes.hpp"

namespace HLA {

    template <class T_FOM, class T_MOD, unsigned m_OBV=1>
    class RTIvector : public ClassForRTI<Vector<T_MOD>,m_OBV>
    {
      RTIvector& operator = (const RTIvector & variableArray) {
        return *this;
      }

    public:

      using type = T_MOD;

      RTIvector(const RTIvector &variableArray):ClassForRTI<Vector<T_MOD>,m_OBV>(variableArray) {}

      RTIvector() {
        ptrData = nullptr;
        m_uiSizeData = 0;
        m_DIM = 0;
      }

      RTIvector(Vector<T_MOD> &inData) {
        ptrData = nullptr;
        m_uiSizeData = 0;
        get(inData);
      }

      virtual ~RTIvector() {
        if (ptrData!=nullptr) {
          delete[] ptrData;
          ptrData=nullptr;
        }
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
       // LOG_DURATION("Get Data Vector")
        getData(const_cast<void*>(obj.data()), static_cast<unsigned long>(obj.size()));
      }

      void getData(void* input_data, unsigned long inSize){

        chekSize(input_data, inSize);

        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet[m_uiSizeData];
        memcpy(ptrData, input_data,m_uiSizeData);
      }

      void getDataMax(void* input_data, unsigned long inSize){
        chekSize(input_data, inSize);
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet[m_uiSizeData];
        memcpy(ptrData, input_data, m_uiSizeData);
      }

      void get(Vector<T_MOD> const & inData) {
        //LOG_DURATION("Get Vector")
        unsigned uiSizeEl, uiSizeData, P;
        unsigned uiHeder;
        T_FOM tmpFOBobj;
        m_uiSizeData = 0;

        m_DIM = static_cast<unsigned>(inData.size());

        uiSizeData = 4;
        uiSizeEl = 0;
        if (m_DIM !=0) {
          for (unsigned i=0; i<m_DIM-1; i++) {
            tmpFOBobj.get(inData[i]);
            uiSizeEl = tmpFOBobj.getsize();
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
            uiSizeData += uiSizeEl+P;
          }
          tmpFOBobj.get(inData[m_DIM-1]);
          uiSizeEl = tmpFOBobj.getsize();
        } else {
          uiSizeEl=0;
          P=0;
        }
        m_uiSizeData = uiSizeData + uiSizeEl;

        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet[m_uiSizeData];

        uiHeder = m_DIM;
        Tools::changeENDIAN(uiHeder);
        uiSizeData=4;
        memcpy(ptrData,&uiHeder,4);
        if (m_DIM !=0) {
          for (unsigned i=0; i<m_DIM-1; i++) {
            tmpFOBobj.get(inData[i]);
            uiSizeEl = tmpFOBobj.setData(ptrData+uiSizeData);
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
            uiSizeData += uiSizeEl+P;
          }
          tmpFOBobj.get(inData[m_DIM-1]);
          uiSizeEl = tmpFOBobj.setData(ptrData+uiSizeData);
        }
      }

      void get (RTIvector<T_FOM,T_MOD,m_OBV>& obj) {

        if (this != &obj) {
          m_DIM = obj.m_DIM;
          m_uiSizeData = obj.m_uiSizeData;
          if (ptrData!=nullptr) delete[] ptrData;
          ptrData = new Octet[m_uiSizeData];
          obj.setData(ptrData,m_uiSizeData);
        }
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
      //  LOG_DURATION("Set Data Vector")
        if (ptrData!=nullptr)  {
          obj.setData(ptrData,m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"RTIvariableArray.setDataToRTI. ) Нулевой указатель.");
          throw ex;
        }
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (m_uiSizeData!=inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"RTIvariableArray\n" << L"Размер данных не совпал. Должно прийти " << m_uiSizeData
              << L" пришло "<< inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }

        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"RTIvariableArray.setData. Нулевой указатель.");
          throw ex;
        }
      }

      unsigned setData(void* ptrDest){

        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"RTIvariableArray.setData. Нулевой указатель.");
          throw ex;
        }
        return m_uiSizeData;
      }

      void set(Vector<T_MOD>& outData) {
       // LOG_DURATION("Set Vector")
        outData.clear();
        unsigned uiSizeEl, P;
        T_MOD obj;
        T_FOM objFOM;
        unsigned uiSizeOfVector;
        unsigned uiSizeData = 4;
        memcpy(&uiSizeOfVector, ptrData, 4);
        Tools::changeENDIAN(uiSizeOfVector);
        outData.reserve(m_DIM);
        for (unsigned i=0; i<m_DIM; i++) {
          objFOM.getDataMax(ptrData+uiSizeData, m_uiSizeData-uiSizeData);
          objFOM.set(obj);
          outData.push_back(obj);
          uiSizeEl = objFOM.getsize();
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl+P;
        }
      }

      Vector<T_MOD> get() {
        Vector<T_MOD> vRet;
        set(vRet);
        return vRet;
      }

      unsigned getsize() {return m_uiSizeData;}

      unsigned getOctetBoundary(){return m_OBV;}

    private:
      Octet* ptrData;
      unsigned m_uiSizeData;
      unsigned m_DIM;

      void chekSize(void* input_data, unsigned long inSize){
        m_uiSizeData = 4;
        if (inSize < m_uiSizeData) {
          throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
        }
        memcpy(&m_DIM, input_data,m_uiSizeData);
        Tools::changeENDIAN(m_DIM);
        //-----------------------------------
        unsigned uiSizeEl,P;
        T_FOM tmpT;
        for (unsigned i=0; i<m_DIM; i++) {
          if (inSize <= m_uiSizeData) {
            throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
          }
          try {
            tmpT.getDataMax(static_cast<char*>(input_data)+m_uiSizeData, inSize-m_uiSizeData);
          } catch (ExceptionForRTI & ex) {
            throw ExceptionForRTI(L"RTIvariableArray" + Tools::widen(ex.what()));
          }
          uiSizeEl = tmpT.getsize();
          if (i != m_DIM-1) {
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          }
          else {
            P=0;
          }
          m_uiSizeData+=uiSizeEl+P;
        }
      }
    };

    template<typename RTItype, unsigned OBV = 8>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename RTItype::type>& t){
        RTIvector<RTItype,typename RTItype::type,OBV> conv;
        rti1516e::VariableLengthData v;
        conv.get(t);
        conv.setDataToRTI(v);
        return v;
   }

    template<typename RTItype, unsigned OBV>
    std::vector<typename RTItype::type> cast_from_rti(const rti1516e::VariableLengthData& v){
        std::vector<typename RTItype::type> t;
        RTIvector<RTItype, typename RTItype::type, OBV> conv;
        conv.getDataFromRTI(v);
        conv.set(t);
        return std::move(t);
    }
}
#endif // RTIVECTOR_HPP
