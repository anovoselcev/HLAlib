#ifndef THREADFEDERATE_HPP
#define THREADFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../Tools/Logger.hpp"
#include "../HLAdata/HLAdata.hpp"
#include <iostream>

extern std::unique_ptr<HLA::Logger> logger;

class ThreadFederate final : public HLA::BaseFederate{
public:

    ThreadFederate(HLA::JSON& file) :
                   HLA::BaseFederate(file){}

    std::wstring _other=L"-";
    bool firstly = true;

protected:

    void UpdateAttributes() const override{
        rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(_federate_name);
        rti1516e::VariableLengthData type = HLA::cast_to_rti<HLA::Wstring>(_federate_type);
        rti1516e::AttributeHandleValueMap map;
        map[_AttributesMap.at(_MyClass).at(L"Name")] = v;
        _rtiAmbassador->updateAttributeValues(_MyInstanceID,map,type);
    }

    void AttributeProcess(rti1516e::ObjectClassHandle &handle,
                          rti1516e::AttributeHandleValueMap &data,
                          rti1516e::VariableLengthData &info) override{
        std::wcout << HLA::cast_from_rti<HLA::Wstring>(data.find(_AttributesMap[_ObjectClasses[L"Following"]][L"Name"])->second) << std::endl;
        std::wcout << HLA::cast_from_rti<HLA::Float64BE>(info) << std::endl;
    }

};

#endif // THREADFEDERATE_HPP
