#include "SimFederate.hpp"
namespace HLA {
    using namespace  rti1516e;

struct Button{
    int push;
    std::string name="";
};

struct Tumbler{
    int state = 0;
    std::string name="";
};

class RTIButton : public HLA::BaseFixedRecord<Button,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0;
        auto_offset(offset,ptrSource,uiMaxSize,field1,field2);
    }
    void get(Button const &obj){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0, uiSize;
        m_uiSizeData=0;
       auto_geter_first(offset,uiSize,field1,obj.push,field2,obj.name);
        auto_geter_second(offset,uiSize,field1,field2);
    }
    void set(Button &obj){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0,uiSize;
       auto_seter(offset,uiSize,field1,obj.push,field2,obj.name);
    }
};
class RTITumbler : public HLA::BaseFixedRecord<Tumbler,8>{
public:
    void getDataMax(void *ptrSource, unsigned long uiMaxSize){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0;
        auto_offset(offset,ptrSource,uiMaxSize,field1,field2);
    }
    void get(Tumbler const &obj){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0,uiSize;
        m_uiSizeData=0;
        auto_geter_first(offset,uiSize,field1,obj.state,field2,obj.name);
        auto_geter_second(offset,uiSize,field1,field2);
    }
    void set(Tumbler &obj){
        HLA::Integer32BE field1;
        HLA::String field2;
        unsigned offset = 0,uiSize;
       auto_seter(offset,uiSize,field1,obj.state,field2,obj.name);
    }
};

    SimFederate::SimFederate() noexcept{}

    SimFederate::SimFederate(const std::wstring& name,
                             const std::wstring& type,
                             const std::wstring& FOMname,
                             const std::wstring& fname,
                             const std::wstring& ip) noexcept:
                                   BaseFederate(name,type,FOMname,fname,ip){}


    SimFederate::SimFederate(std::wstring&& name,
                             std::wstring&& type,
                             std::wstring&& FOMname,
                             std::wstring&& fname,
                             std::wstring&& ip) noexcept:
                                    BaseFederate(std::move(name),std::move(type),std::move(FOMname),std::move(fname),std::move(ip)){}

    void SimFederate::SendToRTI(double value){
//         VariableLengthData v1,v2,v3;
//         Staff d,p;
//         RTIStaff s;
//         d.f = value;
//         d.b = false;
//         s.get(d);
//         s.setDataToRTI(v1);
//         RTIStaff r;
//         r.getDataFromRTI(v1);
//         r.set(p);
//         AttributeHandleValueMap m;
//         m[_AttributesMap[_MyClass][L"Aim"]] = v1;
//         HLA::RTIASCIIstring str;
//         HLA::Vector<HLA::Float64BE> vec(1000,1.2);
//         HLA::RTIvariableArray<HLA::RTIfloat64BE,HLA::Float64BE> varr;
//         HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,1000,2> arr;
//         varr.get(vec);
//         varr.setDataToRTI(v2);
//         m[_AttributesMap[_MyClass][L"Var"]] = v2;
//         HLA::Array<HLA::Char,1000> a;
//         a.fill('2');
//         arr.get(a);
//         arr.setDataToRTI(v3);
//         m[_AttributesMap[_MyClass][L"Ar"]] = v3;
//          _rtiAmbassador->updateAttributeValues(_MyInstanceID,m,VariableLengthData());
    }
    void SimFederate::ParameterProcess(){
        std::lock_guard<std::mutex> guard(_pmutex);
        InteractionClassHandle name = _InteractionClasses.at(L"ARMaction");
        while(!_qParameters.empty()){
            auto& message = _qParameters.front();
            Button b = HLA::cast_from_rti<RTIButton>(message.data.find(_ParametersMap.at(name).at(L"Button"))->second);
            //std::wcout << L"Button " << HLA::Tools::widen(b.name) << " " << b.push << std::endl;
            _qParameters.pop();
        }
    }

    void SimFederate::reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                              const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                              const rti1516e::VariableLengthData &theUserSuppliedTag,
                                              rti1516e::OrderType sentOrder,
                                              rti1516e::TransportationType theType,
                                              rti1516e::SupplementalReflectInfo theReflectInfo)
    throw (rti1516e::FederateInternalError){
        if(_state >= State::STARTED){
            Staff d;
//             RTIStaff t;
//             HLA::RTIvariableArray<HLA::RTIfloat64BE,HLA::Float64BE> varr;
//             HLA::RTIFixedArray<HLA::RTIchar,HLA::Char,1000,2> arr;
//             HLA::Vector<HLA::Float64BE> vec;
//             HLA::Array<HLA::Char,1000> a;
//             t.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Aim"])->second);
//             varr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Var"])->second);
//             arr.getDataFromRTI(theAttributeValues.find(_AttributesMap[_MyClass][L"Ar"])->second);
//             t.set(d);
//             varr.set(vec);
//             arr.set(a);
//             std::wcout << HLA::Tools::widen(d.s) << " " << static_cast<wchar_t>(d.c) << " " << d.f << std::endl;
//             std::wcout << vec[0] << " " << vec[3] << " " << vec.size() << std::endl;
//             std::wcout << a[0] << " " << a[33] << std::endl;
        }
    }

    void SimFederate::receiveInteraction (
      InteractionClassHandle theInteraction,
      ParameterHandleValueMap const & theParameterValues,
      VariableLengthData const & theUserSuppliedTag,
      OrderType sentOrder,
      TransportationType theType,
      SupplementalReceiveInfo theReceiveInfo)
      throw (
            FederateInternalError){
        if(_state >= State::STARTED){
            std::lock_guard<std::mutex> guard(_pmutex);
            _qParameters.push({theUserSuppliedTag,theParameterValues});
        }
    }

//    void RTIStaff::getDataMax(void* ptrSource, unsigned long uiMaxSize){
//        HLA::Byte field0;
//        HLA::Float64BE field1;
//        HLA::Integer16BE  field2;
//        HLA::String field3;
//        HLA::Char field4;
//        unsigned offset = 0;
//        auto_offset(offset,ptrSource,uiMaxSize,field0,field1,field2,field3,field4);
//    }

//    void RTIStaff::get(Staff const &obj){
//        HLA::Byte field0;
//        HLA::Float64BE field1;
//        HLA::Integer16BE  field2;
//        HLA::String field3;
//        HLA::Char field4;
//        unsigned offset = 0,uiSize;
//        m_uiSizeData=0;
//        auto_geter_first(offset,uiSize,field0,obj.b,field1,obj.f,field2,obj.i,field3,obj.s,field4,obj.c);
//        auto_geter_second(offset,uiSize,field0,field1,field2,field3,field4);
//    }

//    void RTIStaff::set(Staff &obj){
//        HLA::Byte field0;
//        HLA::Float64BE field1;
//        HLA::Integer16BE  field2;
//        HLA::String field3;
//        HLA::Char field4;
//        //********************************************
//        unsigned offset = 0, uiSize;
//        //********************************************
//        auto_seter(offset,uiSize,field0,obj.b,field1,obj.f,field2,obj.i,field3,obj.s,field4,obj.c);
//    }
}
