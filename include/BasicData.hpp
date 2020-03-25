#ifndef BASICDATA_HPP
#define BASICDATA_HPP
#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#pragma warning(disable: 4482)
#endif

#include <string.h>
#include <iostream>

#include <RTI/RTI1516.h>

#include "BasicConverter.hpp"

//#include "profile.hpp"

namespace HLA {

    template <class Type, class RTI_Representation = Integer32BE, unsigned m_OBV = 4>
    class RTIEnum : public ClassForRTI <Type,m_OBV>
    {
    public:

      RTIEnum() {
        m_data = 0;
      }

      RTIEnum(const Type& source) {
        m_data = source;
      }

      RTIEnum(Type&& source) {
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

      void get(const RTIEnum& source) {
        if (this != &source) {
          m_data = source.m_data;
        }
      }
    private:
      RTI_Representation m_data;
    };


    template <class T2=ASCIIstring>
    class RTIASCIIstringType : public ClassForRTI<T2,1> {
    public:

      RTIASCIIstringType() {
        unsigned lenth = 0;
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
      }

      void get(RTIASCIIstringType const &str) {
        m_str = str;
      }

      void get(RTIASCIIstringType&& str){
          m_str = std::move(str);
      }

      RTIASCIIstringType(std::string const &str) {
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
        m_str += str;
      }

      RTIASCIIstringType(std::string&& str) {
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
        m_str += std::move(str);
      }

      virtual void get(std::string const &str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
        m_str += str;
      }

      virtual void get(std::string&& str){
        unsigned lenth = static_cast<unsigned>(str.length());
        Tools::changeENDIAN(lenth);
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
        m_str += std::move(str);
      }

      void getDataFromRTI(rti1516e::VariableLengthData const &obj){
        unsigned iq = static_cast<unsigned>(obj.size());
        m_str = std::string(reinterpret_cast<const char*>(obj.data()),iq);
      }

      void getData(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, 4);
        Tools::changeENDIAN(_size);
        if (_size!=inSize-4) {
          std::stringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << getsize()
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_str = std::string(reinterpret_cast<char*>(ptrSource),_size+4);

      }

      void getDataMax(void* ptrSource, unsigned long inSize){
        unsigned _size;
        memcpy(&_size, ptrSource, 4);
        Tools::changeENDIAN(_size);
        if (_size > inSize-4) {
          std::stringstream wstrOut;
          wstrOut
              << L"Размер данных не совпал. Должно прийти " << getsize()
              << L" пришло " << inSize << L" байт";

          ExceptionForRTI ex(wstrOut.str());
          throw ex;
        }
        m_str = std::string(reinterpret_cast<char*>(ptrSource),_size+4);
      }

      void get(T2& ModelStr) {
        unsigned lenth = static_cast<unsigned>(ModelStr.length());
        Tools::changeENDIAN(lenth);
        m_str = std::string(reinterpret_cast<char*>(&lenth),4);
        m_str += ModelStr;
      }

      void setDataToRTI(rti1516e::VariableLengthData &data){
        data.setData(reinterpret_cast<char*>(&m_str[0]), static_cast<unsigned long>(m_str.size()));
      }

      void setData(void* ptrDest, unsigned long inSize) /*noexcept(false)*/ {
        if (getsize()!=inSize) {
            std::stringstream wstrOut;
            wstrOut
                << L"Размер данных не совпал. Должно прийти " << getsize()
                << L" пришло " << inSize << L" байт";

            ExceptionForRTI ex(wstrOut.str());
            throw ex;
        }
        memcpy(ptrDest, reinterpret_cast<char*>(&m_str[0]), inSize);
      }

      unsigned setData(void* ptrDest)  {
        memcpy(ptrDest, &m_str[0], getsize());
        return getsize();
      }

      void set(T2& ModelStr) {
        ModelStr = std::string(&m_str[4], m_str.size()-4);
      }

      unsigned getsize() {
        return static_cast<unsigned>(m_str.size());
      }

      unsigned getOctetBoundary() {return 1;}


      friend std::wostream& operator << (std::wostream &qut, RTIASCIIstringType<> & D) {
        T2 ModelStr;
        D.set(ModelStr);

        qut << std::endl
            << L"--------------------------------------------------" << std::endl
            << L"type (RtiHLAASCIIstringType):" << std::endl << ModelStr.c_str() << std::endl
            << L"--------------------------------------------------" << std::endl;
        return qut;
      }

    private:
      std::string m_str;
    };

    using unicodeString = Vector<unicodeChar>;
    using RTIunicodeString = RTIASCIIstringType<unicodeString>;
    using RTIASCIIstring = RTIASCIIstringType<>;
    using RTIEIMS_UTF8string = RTIASCIIstringType<>;
    using RTIstring = RTIASCIIstringType<>;

    using RTIboolean = RTIEnum<RTIinteger32BE, Boolean, 4>;


    void initializeMOD (ASCIIstring & data);


    template <class T_FOM, class T_MOD, unsigned m_OBV=1>
    class RTIvariableArray : public ClassForRTI<Vector<T_MOD>,m_OBV>
    {
      RTIvariableArray& operator = (const RTIvariableArray & variableArray) {
        return *this;
      }

    public:
      RTIvariableArray(const RTIvariableArray &variableArray):ClassForRTI<Vector<T_MOD>,m_OBV>(variableArray) {}

      RTIvariableArray() {
        ptrData = nullptr;
        m_uiSizeData = 0;
        m_DIM = 0;
      }

      RTIvariableArray(Vector<T_MOD> &inData) {
        ptrData = nullptr;
        m_uiSizeData = 0;
        get(inData);
      }

      virtual ~RTIvariableArray() {
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

      void get (RTIvariableArray<T_FOM,T_MOD,m_OBV>& obj) {

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

    template<typename T, unsigned dim>
    class FixedArray : public std::array<T, dim> {};

    template <class T_MOD, unsigned dim>
    class HLAfixedArray {
    public:

      T_MOD & operator[](unsigned ind) {
        if (ind <dim) {
          return data[ind];
        } else {
          return data[0];
        }
      }

      T_MOD const & operator[](unsigned ind) const {
        if (ind <dim) {
          return data[ind];
        }
        return data[0];
      }

      void set(HLAfixedArray &obj) {
        if (obj.dimension() == dim) {
          memcpy(data, &obj, sizeof(dim*sizeof(T_MOD)));
        }
      }

      void set(std::vector<T_MOD> &obj) {
        if (obj.size() == dim) {
          obj.copy(data,dim);
        }
      }

      void set(const T_MOD* ptrObj) {
        for (unsigned i=0; i<dim; i++) {
          data[i] = ptrObj[i];
        }
      }

      void set(std::string const &obj)  {
        if (sizeof(T_MOD) == 1 && (unsigned)obj.size() == dim) {
          for (unsigned i=0; i<dim; i++) {
            data[i]= (T_MOD)obj[i];
          }
        }
      }

      void get(HLAfixedArray &obj) const{
        memcpy(&obj, data, sizeof(dim*sizeof(T_MOD)));
      }

      void get(std::vector<T_MOD> &obj)  const{
        for (unsigned i=0; i<dim; i++) {
          obj.push_back(data[i]);
        }
      }
      void get(void* obj)  const{
        memcpy((void*)obj, (void*)&data[0], dim*sizeof(T_MOD));
      }

      void get(std::string &obj)  const{
        if (sizeof(T_MOD) == 1) {
          obj.clear();
          for (unsigned i=0; i<dim; i++) {
            obj.push_back(data[i]);
          }
        }
      }
      friend std::ofstream& operator << (std::ofstream &StreamOut, HLAfixedArray const & obj) {
        for (unsigned i=0; i<dim; i++) {
          StreamOut << obj[i] << " ";
        }
        return StreamOut;
      }

      friend std::ifstream& operator << (std::ifstream &StreamInput, HLAfixedArray & obj) {
        for (unsigned i=0; i<dim; i++) {
          StreamInput >> obj[i];
        }
        return StreamInput;
      }

      unsigned dimension() {return dim;}
    private:
      T_MOD data[dim];
    };


    template <class T_MOD, unsigned dim>
    int readMOD(std::ifstream &File, HLA::FixedArray<T_MOD,dim>& data) {
      int retCod = 1;
      for (unsigned i=0; i<dim; i++) {
        retCod = readMOD(File,data[i]);
        if (retCod != 1) return retCod;
      }
      return retCod;
    }

    template <class T_MOD, unsigned dim>
    int writeMOD(std::ifstream &File, HLA::FixedArray<T_MOD,dim> const &data) {
      int retCod = 1;
      for (unsigned i=0; i<dim; i++) {
        retCod = writeMOD(File,data[i]);
        if (retCod != 1) return retCod;
      }
      return retCod;
    }


    template <class T_FOM, class T_MOD, unsigned uiDim, unsigned m_OBV>
    class RTIFixedArray : public ClassForRTI <Array<T_MOD,uiDim>, m_OBV>{
      RTIFixedArray & operator = (const RTIFixedArray &/*fixedArray*/) {
        return *this;
      }
    public:

      RTIFixedArray(const RTIFixedArray &fixedArray): ClassForRTI<Array<T_MOD,uiDim>, m_OBV>(fixedArray) {
      }

      RTIFixedArray() {
        ptrData = nullptr;
        m_uiSizeData = 0;
      }

      RTIFixedArray(Array<T_MOD,uiDim> &inData) {
        ptrData = nullptr;
        m_uiSizeData = 0;
        get(inData);
      }

      virtual ~RTIFixedArray() {
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
        ptrData = new Octet[m_uiSizeData];
        memcpy(reinterpret_cast<void*>(ptrData), input_data,m_uiSizeData);
      }

      void getDataMax(void* input_data, unsigned long inSize){
        chekSize(input_data, inSize);
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet[m_uiSizeData];
        memcpy(reinterpret_cast<void*>(ptrData), input_data,m_uiSizeData);
      }

      void get(Array<T_MOD,uiDim> const & inData) {
       // LOG_DURATION("Get Array")
        unsigned uiSizeEl, uiSizeData, P;
        T_FOM tmpFOMobj;
        m_uiSizeData = 0;
        uiSizeData = 0;
        uiSizeEl = 0;
        for (unsigned i=0; i<uiDim-1; i++) {
          tmpFOMobj.get(inData[i]);
          uiSizeEl = tmpFOMobj.getsize();
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl+P;
        }
        tmpFOMobj.get(inData[uiDim-1]);
        uiSizeEl = tmpFOMobj.getsize();
        m_uiSizeData = uiSizeData + uiSizeEl;
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new Octet[m_uiSizeData];
        uiSizeData=0;
        for (unsigned i=0; i<uiDim-1; i++) {
          tmpFOMobj.get(inData[i]);
          uiSizeEl = tmpFOMobj.setData(ptrData+uiSizeData);
          P = Tools::getPendingBytes(uiSizeEl,m_OBV);
          uiSizeData += uiSizeEl+P;
        }
        tmpFOMobj.get(inData[uiDim-1]);
        uiSizeEl = tmpFOMobj.setData(ptrData+uiSizeData);
      }

      void get (RTIFixedArray<T_FOM,T_MOD,uiDim,m_OBV>& obj) {
        if (this != &obj) {
          m_uiSizeData = obj.m_uiSizeData;
          if (ptrData!=nullptr) delete[] ptrData;
          ptrData = new Octet[m_uiSizeData];
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

      void set (Array<T_MOD,uiDim>& obj){
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
      Octet* ptrData;
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

    template <class T_MOD, unsigned OBV>
    class BaseRTIFixedRecord : public ClassForRTI <T_MOD, OBV> {
    protected:
      Octet* ptrData;
    public:
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

    };
  }

template <class T_el>
void initializeMOD (std::vector<T_el> & data) {
  T_el el;
  initializeMOD(el);
  data.assign(4,el);
}

template <class T_MOD, unsigned dim>
void initializeMOD(HLA::FixedArray<T_MOD,dim>& data) {
  for (unsigned i=0; i<dim; i++) {
    initializeMOD(data[i]);
  }
}


void initializeMOD(rti1516e::FederateHandle& data);
void initializeMOD(rti1516e::ObjectClassHandle& data);
void initializeMOD(rti1516e::InteractionClassHandle& data);
void initializeMOD(rti1516e::ObjectInstanceHandle& data);
void initializeMOD(rti1516e::AttributeHandle& data);
void initializeMOD(rti1516e::ParameterHandle& data);
void initializeMOD(rti1516e::DimensionHandle& data);
void initializeMOD(rti1516e::MessageRetractionHandle& data);
void initializeMOD(rti1516e::RegionHandle& data);
#endif // BASICDATA_HPP
