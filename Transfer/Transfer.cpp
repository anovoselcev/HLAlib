#include "Transfer.hpp"
namespace UPIM {
    using namespace  rti1516e;
    Transfer::Transfer() noexcept{}

    Transfer::Transfer(const std::wstring& name,
                             const std::wstring& type,
                             const std::wstring& FOMname,
                             const std::wstring& ip,
                             const std::wstring& fname) noexcept:
                                   UPIMFederate(name,type,FOMname,ip,fname){}


    Transfer::Transfer(std::wstring&& name,
                             std::wstring&& type,
                             std::wstring&& FOMname,
                             std::wstring&& ip,
                             std::wstring&& fname) noexcept:
                                    UPIMFederate(std::move(name),std::move(type),std::move(FOMname),std::move(ip),std::move(fname)){}

    void Transfer::SendToRTI(double value){
        VariableLengthData v1,v2,v3;
        Staff d,p;
        RTIStaff s;
        d.f = value;
        d.b = false;
        s.get(d);
        s.setDataToRTI(v1);
        RTIStaff r;
        r.getDataFromRTI(v1);
        r.set(p);
        AttributeHandleValueMap m;
        m[_AttributesMap[_MyClass][L"Aim"]] = v1;
        HLA::RTIASCIIstring str;
        HLA::Vector<HLA::Float64BE> vec(1000,1.2);
        HLA::RTIvariableArray<HLA::RTIfloat64BE,HLA::Float64BE> varr;
        HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,1000,2> arr;
        varr.get(vec);
        varr.setDataToRTI(v2);
        m[_AttributesMap[_MyClass][L"Var"]] = v2;
        HLA::Array<HLA::Char,1000> a;
        a.fill('2');
        arr.get(a);
        arr.setDataToRTI(v3);
        m[_AttributesMap[_MyClass][L"Ar"]] = v3;
         _rtiAmbassador->updateAttributeValues(_MyInstanceID,m,VariableLengthData());
    }

    void Transfer::reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                              const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                              const rti1516e::VariableLengthData &theUserSuppliedTag,
                                              rti1516e::OrderType sentOrder,
                                              rti1516e::TransportationType theType,
                                              rti1516e::SupplementalReflectInfo theReflectInfo)
    throw (rti1516e::FederateInternalError){
        if(_f_start){
            Staff d;
            RTIStaff t;
            HLA::RTIvariableArray<HLA::RTIfloat64BE,HLA::Float64BE> varr;
            HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,1000,2> arr;
            HLA::Vector<HLA::Float64BE> vec;
            HLA::Array<HLA::Char,1000> a;
            t.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Aim"])->second);
            varr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Var"])->second);
            arr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Ar"])->second);
            t.set(d);
            varr.set(vec);
            arr.set(a);
            std::wcout << HLA::Tools::widen(d.s) << " " << static_cast<wchar_t>(d.c) << " " << d.f << std::endl;
            std::wcout << vec[0] << " " << vec[3] << " " << vec.size() << std::endl;
            std::wcout << a[0] << " " << a[33] << std::endl;
        }
    }

    void RTIStaff::getDataMax(void* ptrSource, unsigned long uiMaxSize){
        HLA::RTIbyte  field0;
        HLA::RTIfloat64BE field1;
        HLA::RTIinteger16BE  field2;
        HLA::RTIstring field3;
        HLA::RTIchar field4;
        unsigned offset = 0;
        // Определяем размер поля данных
        F_offset< HLA::RTIbyte, HLA::RTIfloat64BE >(field0,field1,offset,ptrSource,uiMaxSize);
        F_offset< HLA::RTIfloat64BE, HLA::RTIinteger16BE >(field1,field2,offset,ptrSource,uiMaxSize);
        F_offset< HLA::RTIinteger16BE, HLA::RTIstring >(field2,field3,offset,ptrSource,uiMaxSize);
        F_offset< HLA::RTIstring, HLA::RTIchar >(field3,field4,offset,ptrSource,uiMaxSize);
        F_offsetLast< HLA::RTIchar >(field4,offset,ptrSource,static_cast<unsigned>(uiMaxSize));

        // Создаем новое поле данных и копируем туда данные;

        if (ptrData!=nullptr) delete[] ptrData;
        m_uiSizeData = offset;
        ptrData = new HLA::Octet[m_uiSizeData];
        memcpy(ptrData, ptrSource, m_uiSizeData);
    }

    void RTIStaff::get(Staff const &obj){
        HLA::RTIbyte  field0;
        HLA::RTIfloat64BE field1;
        HLA::RTIinteger16BE  field2;
        HLA::RTIstring field3;
        HLA::RTIchar field4;
        unsigned offset = 0, P, uiSize, mmOBV;
        m_uiSizeData=0;
        // 0-ое поле
        field0.get(obj.b);
        uiSize = field0.getsize();

        // 1-ое поле
        field1.get(obj.f);
        mmOBV = field1.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field1.getsize();
        // 2-ое поле
        field2.get(obj.i);
        mmOBV = field2.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field2.getsize();
        // 3-e поле
        field3.get(obj.s);
        mmOBV = field3.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field3.getsize();
        // 4-ое поле
        field4.get(obj.c);
        mmOBV = field3.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field4.getsize();

        offset += uiSize;
        m_uiSizeData = offset;
        if (ptrData!=nullptr) delete[] ptrData;
        ptrData = new HLA::Octet[m_uiSizeData];
        offset = 0;
        // 0-ое поле
        uiSize = field0.getsize();
        field0.setData(ptrData+offset,uiSize);
        // 1-ое поле
        mmOBV = field1.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field1.getsize();
        field1.setData(ptrData+offset,uiSize);
        // 2-ое поле
        mmOBV = field2.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field2.getsize();
        field2.setData(ptrData+offset,uiSize);
        // 3-е поле
        mmOBV = field3.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field3.getsize();
        field3.setData(ptrData+offset,uiSize);
        // 4-ое поле
        mmOBV = field4.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        uiSize = field4.getsize();
        field4.setData(ptrData+offset,uiSize);
    }

    void RTIStaff::set(Staff &obj){
        HLA::RTIbyte  field0;
        HLA::RTIfloat64BE field1;
        HLA::RTIinteger16BE  field2;
        HLA::RTIstring field3;
        HLA::RTIchar field4;
        //********************************************
        unsigned offset = 0, P, uiSize, mmOBV;
        //********************************************
        // 0-ое поле
        field0.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field0.set(obj.b);
        uiSize = field0.getsize();
        // 1-ое поле
        mmOBV = field1.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        field1.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field1.set(obj.f);
        uiSize = field1.getsize();
        // 2-ое поле
        mmOBV = field2.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        field2.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field2.set(obj.i);
        uiSize = field2.getsize();
        // 3-е поле
        mmOBV = field3.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        field3.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field3.set(obj.s);
        uiSize = field3.getsize();
        // 4-ое поле
        mmOBV = field4.getOctetBoundary();
        P = HLA::Tools::getPendingBytes(offset+uiSize,mmOBV);
        offset += uiSize+P;
        field4.getDataMax(ptrData+offset,m_uiSizeData-offset);
        field4.set(obj.c);
        uiSize = field4.getsize();
    }
}