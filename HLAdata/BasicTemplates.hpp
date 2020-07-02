#ifndef BASICTEMPLATES_HPP
#define BASICTEMPLATES_HPP

#include "BasicException.hpp"
#include <RTI/RTI1516.h>

namespace HLA {
//Template for RTI presentation of Type with mem (Octet Boundary Value)
    template <class Type, unsigned OBV>
    class ClassForRTI {
    public:
    //Default constructor
      ClassForRTI() noexcept{}
    //Destructor
      virtual ~ClassForRTI() {}
    //Copy constructor
      ClassForRTI(const ClassForRTI<Type,OBV>& obj) {
        rti1516e::VariableLengthData data;
        if (this != &obj) {
          obj.setDataToRTI(data);
          getDataFromRTI(data);
        }
      }
    //Copy assigment operator
      ClassForRTI<Type,OBV>& operator = (ClassForRTI<Type,OBV> & obj) {
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
      virtual void copy(ClassForRTI<Type,OBV>& obj);
    //Set Data to object, it prepare Variable Length Data to RTI
      virtual void setDataToRTI(rti1516e::VariableLengthData &obj) = 0;

    //Set data to ptrDest with fixed size
      virtual void setData(void* ptrDest, unsigned long inSize) = 0;
    //Set data to ptrDest
      virtual unsigned setData(void* ptrDest) = 0;
    //Set to object data from RTI
      virtual void set(Type &obj) = 0;

      virtual unsigned getsize() = 0;

      unsigned getOctetBoundary(){return OBV;}
    };

    template <class Type, unsigned OBV>
    void ClassForRTI<Type, OBV>::copy(ClassForRTI<Type,OBV>& obj) {
      rti1516e::VariableLengthData data;
      if (this != &obj) {
        obj.setDataToRTI(data);
        this->getDataFromRTI(data);
      }
    }
#ifndef WIN32
    using  Octet_ = uint8_t;
#else
    using Octet_ = unsigned char;
#endif


}

#endif // BASICTEMPLATES_HPP