#ifndef FOLLOWFEDERATE_HPP
#define FOLLOWFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../HLAdata/HLAdata.hpp"
#include <iostream>

class FollowFederate final: public HLA::BaseFederate{
public:
    FollowFederate(HLA::JSON& file) :
                   HLA::BaseFederate(file){}
    std::wstring _other=L"-";
    bool firstly = true;

protected:
    void UpdateAttributes() const override{
        //std::wcout << L"I update" << std::endl;
        rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(_federate_name);
        rti1516e::VariableLengthData info = HLA::cast_to_rti<HLA::Float64BE>(100.102);
        rti1516e::AttributeHandleValueMap map;
        map[_AttributesMap.at(_MyClass).at(L"Name")] = v;
        _rtiAmbassador->updateAttributeValues(_MyInstanceID,map, info);
    }

    void AttributeProcess(rti1516e::ObjectClassHandle &handle,
                          rti1516e::AttributeHandleValueMap &data,
                          rti1516e::VariableLengthData &info) override{
        std::wcout << HLA::cast_from_rti<HLA::Wstring>(data.find(_AttributesMap[_ObjectClasses[L"Threading"]][L"Name"])->second) << std::endl;
        std::wcout << HLA::cast_from_rti<HLA::Wstring>(info) << std::endl;
    }




};

#endif // FOLLOWINGFEDERATE_HPP
