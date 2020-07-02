#ifndef FOLLOWFEDERATE_HPP
#define FOLLOWFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../HLAdata/HLAdata.hpp"

class FollowFederate final: public HLA::BaseFederate{
public:
    FollowFederate(std::wstring&& name,
                   std::wstring&& FOM) :
        HLA::BaseFederate(name,L"Following",FOM,L"Test"){
        _mode = HLA::ModelMode::FOLLOWING;
    }

    FollowFederate(const std::wstring& name,
                   const std::wstring& FOM) :
        HLA::BaseFederate(name,L"Following",FOM,L"Test"){
        _mode = HLA::ModelMode::FOLLOWING;
    }
    std::wstring _other=L"";
    bool firstly = true;

protected:
    void UpdateAttributes() const override{
        rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(_federate_name);
        rti1516e::AttributeHandleValueMap map;
        map[_AttributesMap.at(_MyClass).at(L"Name")] = v;
        _rtiAmbassador->updateAttributeValues(_MyInstanceID,map,rti1516e::VariableLengthData());
    }

    void AttributeProcess() override{
        std::lock_guard<std::mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            _other = HLA::cast_from_rti<HLA::Wstring>(message.data.find(_AttributesMap[_ObjectClasses[L"Threading"]][L"Name"])->second);
            _qAttributes.pop();
        }
    }

};

#endif // FOLLOWINGFEDERATE_HPP
