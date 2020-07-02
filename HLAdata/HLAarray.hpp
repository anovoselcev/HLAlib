#ifndef RTIARRAY_HPP
#define RTIARRAY_HPP

#include "BasicTemplates.hpp"

namespace HLA{

    template <class T_FOM, class T_MOD, size_t uiDim, unsigned m_OBV>
    class Array final: public ClassForRTI <std::array<T_MOD,uiDim>, m_OBV>{
      Array & operator = (const Array &/*fixedArray*/) {
        return *this;
      }
    public:

      using type = T_MOD;

      Array(const Array &fixedArray): ClassForRTI<std::array<T_MOD,uiDim>, m_OBV>(fixedArray) {
      }

      Array() {
        ptrData = nullptr;
        m_uiSizeData = 0;
      }

      Array(std::array<T_MOD,uiDim> &inData) {
        ptrData = nullptr;
        m_uiSizeData = 0;
        get(inData);
      }

      virtual ~Array() {
        if (ptrData!=nullptr) {
          delete[] ptrData;
          ptrData=nullptr;
        }
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
         // LOG_DURATION("Get Data Array")
        getData(const_cast<void*>(obj.data()), static_cast<unsigned long>(obj.size()));
      }

      void getData(void* input_data, unsigned long inSize){
        chekSize(input_data, inSize);

        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet_[m_uiSizeData];
        memcpy(reinterpret_cast<void*>(ptrData), input_data,m_uiSizeData);
      }

      void getDataMax(void* input_data, unsigned long inSize){
        chekSize(input_data, inSize);
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet_[m_uiSizeData];
        memcpy(reinterpret_cast<void*>(ptrData), input_data,m_uiSizeData);
      }

      void get(std::array<T_MOD,uiDim> const & inData) {
       // LOG_DURATION("Get Array")
        unsigned uiSizeEl, uiSizeData, P;
        T_FOM tmpFOMobj;
        m_uiSizeData = 0;
        uiSizeData = 0;
        uiSizeEl = 0;
        for (size_t i=0; i<uiDim-1; i++) {
          tmpFOMobj.get(inData[i]);
          uiSizeEl = tmpFOMobj.getsize();
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl+P;
        }
        tmpFOMobj.get(inData[uiDim-1]);
        uiSizeEl = tmpFOMobj.getsize();
        m_uiSizeData = uiSizeData + uiSizeEl;
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet_[m_uiSizeData];
        uiSizeData=0;
        for (size_t i=0; i<uiDim-1; i++) {
          tmpFOMobj.get(inData[i]);
          uiSizeEl = tmpFOMobj.setData(ptrData+uiSizeData);
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl+P;
        }
        tmpFOMobj.get(inData[uiDim-1]);
        uiSizeEl = tmpFOMobj.setData(ptrData+uiSizeData);
      }

      void get (Array<T_FOM,T_MOD,uiDim,m_OBV>& obj) {
        if (this != &obj) {
          m_uiSizeData = obj.m_uiSizeData;
          if (ptrData!=nullptr) delete[] ptrData;
          ptrData = new Octet_[m_uiSizeData];
          obj.setData(ptrData,m_uiSizeData);
        }
      }

      void setDataToRTI(rti1516e::VariableLengthData &obj) {
       // LOG_DURATION("Set Data Array")
        if (ptrData!=nullptr)  {
          obj.setData(ptrData,m_uiSizeData);
        } else {
            ExceptionForRTI ex(L"RTIFixedArray.setDataToRTI. Нулевой указатель.");
            throw ex;
        }
      }

      void setData(void* ptrDest, unsigned long inSize){
        if (m_uiSizeData!=inSize) {
          std::stringstream wstrOut;
          wstrOut
              << L"RTIFixedArray\n" << L"Размер данных не совпал. Должно быть " << m_uiSizeData
              << L" пришло " << inSize << L" байт";

            ExceptionForRTI ex(wstrOut.str());
            throw ex;
        }
        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
            ExceptionForRTI ex(L"RTIFixedArray.setData. Нулевой указатель.");
            throw ex;
        }
      }

      unsigned setData(void* ptrDest){
        if (ptrData!=nullptr)  {
          memcpy(ptrDest, ptrData, m_uiSizeData);
        } else {
            ExceptionForRTI ex(L"RTIFixedArray.setData. Нулевой указатель.");
            throw ex;
        }
        return m_uiSizeData;
      }

      void set (std::array<T_MOD,uiDim>& obj){
        //LOG_DURATION("Set Array")
        unsigned uiSizeEl, P;
        T_FOM objFOM;
        unsigned uiSizeData = 0;
        if (ptrData!=nullptr)  {
          for (unsigned i=0; i<uiDim; i++) {
            objFOM.getDataMax(ptrData+uiSizeData, m_uiSizeData-uiSizeData);
            objFOM.set(obj[i]);

            uiSizeEl = objFOM.getsize();
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
            uiSizeData += uiSizeEl+P;
          }
        }
      }

      unsigned getsize() {return m_uiSizeData;}
      unsigned getOctetBoundary(){return m_OBV;}

    private:
      Octet_* ptrData;
      unsigned m_uiSizeData;

      void chekSize(void* input_data, unsigned long inSize){
        m_uiSizeData = 0;
        if (inSize < m_uiSizeData) {
            throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
    }
    unsigned uiSizeEl,P;
    T_FOM tmpT;
    for (unsigned i=0; i<uiDim; i++) {
    if (inSize < m_uiSizeData) {
            throw ExceptionForRTI(L"RTIvariableArray Данные исчерпаны до завершения считывания!.");
          }
          try {
            tmpT.getDataMax((reinterpret_cast<char*>(input_data)+m_uiSizeData), inSize-m_uiSizeData);
          } catch (ExceptionForRTI & ex) {
                throw ExceptionForRTI(L"RTIvariableArray" + Tools::widen(ex.what()));
          }
          uiSizeEl = tmpT.getsize();
          if (i != uiDim-1) {
            P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          }
          else {
            P=0;
          }
          m_uiSizeData+=uiSizeEl+P;
        }
      }
    };

    template<typename HLAtype, unsigned Size, unsigned OBV = 8>
    rti1516e::VariableLengthData cast_to_rti(const std::array<typename HLAtype::type,Size>& t){
        Array<HLAtype,typename HLAtype::type, Size, OBV> conv;
        rti1516e::VariableLengthData v;
        conv.get(t);
        conv.setDataToRTI(v);
        return v;
    }

    template<typename HLAtype, unsigned Size, unsigned OBV>
    typename std::array<typename HLAtype::type, Size> cast_from_rti(const rti1516e::VariableLengthData& v){
        Array<HLAtype,typename HLAtype::type, Size, OBV> conv;
        std::array<typename HLAtype::type, Size> t;
        conv.getDataFromRTI(v);
        conv.set(t);
        return t;
    }
}
#endif // RTIARRAY_HPP