#ifndef BASICTEMPLATES_HPP
#define BASICTEMPLATES_HPP
#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#pragma warning(disable: 4482)
#endif

#ifdef WIN32
#include <typeinfo>
#endif
#include <fstream>
#include "BasicException.hpp"
#include <RTI/RTI1516.h>

namespace HLA {
//Template for RTI presentation of Type with mem (Octet Boundary Value)
    template <class Type, unsigned mem>
    class ClassForRTI {
    public:
    //Default constructor
      ClassForRTI() noexcept{}
    //Destructor
      virtual ~ClassForRTI() {}
    //Copy constructor
      ClassForRTI(const ClassForRTI<Type,mem>& obj) {
        rti1516e::VariableLengthData data;
        if (this != &obj) {
          obj.setDataToRTI(data);
          getDataFromRTI(data);
        }
      }
    //Copy assigment operator
      ClassForRTI<Type,mem>& operator = (ClassForRTI<Type,mem> & obj) {
        rti1516e::VariableLengthData data;
        if (this != &obj) {
          obj.setDataToRTI(data);
          getDataFromRTI(data);
        }
        return *this;
      }
    //Get data from RTI
      virtual void getDataFromRTI(rti1516e::VariableLengthData const &obj) = 0;
    //Get data from ptrSource with fixed size from RTI
      virtual void getData(void* ptrSource, unsigned long inSize) = 0;
    //Get data from ptrSource with max size form RTI
      virtual void getDataMax(void* ptrSource, unsigned long uiMaxSize) = 0;
    //Get object of Type to transform in Variable Data
      virtual void get(Type const &obj) = 0;
    //Copy
      virtual void copy(ClassForRTI<Type,mem>& obj);
    //Set Data to object, it prepare Variable Length Data to RTI
      virtual void setDataToRTI(rti1516e::VariableLengthData &obj) = 0;

      void writeData(std::ofstream &OutStream){
        rti1516e::VariableLengthData obj;
        size_t obj_size;
        if (OutStream.is_open()) {
          setDataToRTI(obj);
          obj_size = obj.size();
          OutStream.write(static_cast<char*>(static_cast<void*>(&obj_size)), sizeof(size_t));
          OutStream.write(static_cast<const char*>(obj.data()), static_cast<std::streamsize>(obj_size));
        } else {
          throw ExceptionForRTI("Файл не открыт");
        }
      }

      void readData(std::ifstream &InputStream){
        size_t obj_size;
        char* ptrData = nullptr;
        try {
          if (InputStream.is_open()) {
            InputStream.read(static_cast<char*>(static_cast<void*>(&obj_size)),sizeof(size_t));
            ptrData = new char[obj_size];
            InputStream.read(ptrData,static_cast<std::streamsize>(obj_size));
            getData(ptrData,static_cast<unsigned long>(obj_size));
            delete []ptrData;
          } else {
            throw ExceptionForRTI("Файл не открыт");
          }
        } catch (ExceptionForRTI &ex) {
          if (ptrData != nullptr) {
            delete []ptrData;
          }
          throw ex;
        }
      }
    //Set data to ptrDest with fixed size
      virtual void setData(void* ptrDest, unsigned long inSize) = 0;
    //Set data to ptrDest
      virtual unsigned setData(void* ptrDest) = 0;
    //Set to object data from RTI
      virtual void set(Type &obj) = 0;

      virtual unsigned getsize() = 0;

      unsigned getOctetBoundary(){return mem;}
    };

    template <class Type, unsigned mem>
    void ClassForRTI<Type, mem>::copy(ClassForRTI<Type,mem>& obj) {
      rti1516e::VariableLengthData data;
      if (this != &obj) {
        obj.setDataToRTI(data);
        this->getDataFromRTI(data);
      }
    }

}

#endif // BASICTEMPLATES_HPP
