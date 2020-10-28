#ifndef RTIVECTOR_HPP
#define RTIVECTOR_HPP

#include "BasicTemplates.hpp"
namespace HLA {

    template<typename HLAtype, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t);

    template<typename HLAtype, unsigned OBV>
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v);

    template <typename T_FOM, unsigned m_OBV = 1, typename T_MOD = typename T_FOM::type>
    class Vector final: public ClassForRTI<std::vector<T_MOD>,m_OBV>
    {
      Vector& operator = (const Vector &) {
        return *this;
      }

    public:

      using type = T_MOD;

      Vector(const Vector &variableArray):ClassForRTI<std::vector<T_MOD>,m_OBV>(variableArray) {}

      Vector() {
        ptrData = nullptr;
        m_uiSizeData = 0;
        m_DIM = 0;
      }

      Vector(std::vector<T_MOD> &inData) {
        ptrData = nullptr;
        m_uiSizeData = 0;
        get(inData);
      }

      virtual ~Vector() {
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
        ptrData = new Octet_[m_uiSizeData];
        memcpy(ptrData, input_data,m_uiSizeData);
      }

      void getDataMax(void* input_data, unsigned long inSize){
        chekSize(input_data, inSize);
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet_[m_uiSizeData];
        memcpy(ptrData, input_data, m_uiSizeData);
      }

      void get(std::vector<T_MOD> const & inData) {
        //LOG_DURATION("Vector Get")
        unsigned uiSizeEl = 0, uiSizeData = 4, P;
        unsigned uiHeder;
        T_FOM tmpFOBobj;
        m_uiSizeData = 0;

        m_DIM = static_cast<size_t>(inData.size());

        if (m_DIM) {
            //LOG_DURATION("First for Get")
          for (size_t i = 0; i < m_DIM - 1; i++) {
            tmpFOBobj.get(inData[i]);
            uiSizeEl = tmpFOBobj.getsize();
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
            uiSizeData += uiSizeEl+P;
          }
          tmpFOBobj.get(inData[m_DIM - 1]);
          uiSizeEl = tmpFOBobj.getsize();
        }
        else {
          uiSizeEl = 0;
          P = 0;
        }

        m_uiSizeData = uiSizeData + uiSizeEl;

        if (ptrData) delete[] ptrData;
        ptrData = new Octet_[m_uiSizeData];

        uiHeder = m_DIM;
        //Tools::changeENDIAN(uiHeder);
        uiSizeData = 4;
        memcpy(ptrData,&uiHeder,4);
        if (m_DIM) {
            //LOG_DURATION("Second for Get")
          for (size_t i = 0; i < m_DIM - 1; i++) {
            tmpFOBobj.get(inData[i]);
            uiSizeEl = tmpFOBobj.setData(ptrData+uiSizeData);
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
            uiSizeData += uiSizeEl + P;
          }
          tmpFOBobj.get(inData[m_DIM - 1]);
          uiSizeEl = tmpFOBobj.setData(ptrData+uiSizeData);
        }
      }

      void get (Vector<T_FOM,m_OBV>& obj) {

        if (this != &obj) {
          m_DIM = obj.m_DIM;
          m_uiSizeData = obj.m_uiSizeData;
          if (ptrData) delete[] ptrData;
          ptrData = new Octet_[m_uiSizeData];
          obj.setData(ptrData,m_uiSizeData);
        }
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj){
        if (ptrData)  {
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

        if (ptrData)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        }
        else {
          ExceptionForRTI ex(L"RTIvariableArray.setData. Нулевой указатель.");
          throw ex;
        }
      }

      unsigned setData(void* ptrDest){

        if (ptrData)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
          ExceptionForRTI ex(L"RTIvariableArray.setData. Нулевой указатель.");
          throw ex;
        }
        return m_uiSizeData;
      }

      void set(std::vector<T_MOD>& outData) {
        //LOG_DURATION("Vector Set")
        //outData.clear();
        unsigned uiSizeEl, P;
        T_MOD obj;
        T_FOM objFOM;
        unsigned uiSizeOfVector;
        unsigned uiSizeData = 4;
        memcpy(&uiSizeOfVector, ptrData, 4);
        Tools::changeENDIAN(uiSizeOfVector);
        outData.resize(m_DIM);
        for (size_t i = 0; i < m_DIM; i++) {
          objFOM.getDataMax(ptrData + uiSizeData, m_uiSizeData - uiSizeData);
          objFOM.set(obj);
          outData[i] = std::move(obj);
          uiSizeEl = objFOM.getsize();
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl + P;
        }
      }

      std::vector<T_MOD> get() {
        std::vector<T_MOD> vRet;
        set(vRet);
        return vRet;
      }

      unsigned getsize() {return m_uiSizeData;}

      unsigned getOctetBoundary(){return m_OBV;}

    private:
      Octet_* ptrData;
      unsigned m_uiSizeData;
      size_t m_DIM;

      void chekSize(void* input_data, unsigned long inSize) /*noexcept(false)*/ {
        m_uiSizeData = 4;
        if (inSize < m_uiSizeData) {
          throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
        }
        memcpy(&m_DIM, input_data,m_uiSizeData);
        unsigned uiSizeEl,P;
        T_FOM tmpT;
        for (size_t i = 0; i < m_DIM; i++) {
          if (inSize <= m_uiSizeData) {
           throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
          }
          try {
            tmpT.getDataMax(static_cast<char*>(input_data)+m_uiSizeData, inSize-m_uiSizeData);
          } catch (ExceptionForRTI & ex) {
            throw ExceptionForRTI(L"RTIvariableArray" + Tools::widen(ex.what()));
          }
          uiSizeEl = tmpT.getsize();
          if (i != m_DIM - 1) {
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          }
          else
            P = 0;
          m_uiSizeData+=uiSizeEl+P;
        }
      }
    };


    template<typename HLAtype, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t){
        Vector<HLAtype,OBV> conv;
        rti1516e::VariableLengthData v;
        conv.get(t);
        conv.setDataToRTI(v);
        return v;
   }

    template<typename HLAtype, unsigned OBV>
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v){

        std::vector<typename HLAtype::type> t;
        Vector<HLAtype, OBV> conv;
        conv.getDataFromRTI(v);
        conv.set(t);
        return t;
    }

}
#endif // RTIVECTOR_HPP
