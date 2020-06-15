#ifndef THREADFEDERATE_HPP
#define THREADFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../HLAdata/HLAdata.hpp"

class ThreadFederate final : public HLA::BaseFederate{
public:
    ThreadFederate(std::wstring&& name,
                   std::wstring&& FOM) :
        HLA::BaseFederate(name,L"Threading",FOM,L"Test"){
        _mode = HLA::ModelMode::THREADING;
    }

    ThreadFederate(const std::wstring& name,
                   const std::wstring& FOM) :
        HLA::BaseFederate(name,L"Threading",FOM,L"Test"){
        _mode = HLA::ModelMode::THREADING;
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
            _other = HLA::cast_from_rti<HLA::Wstring>(message.find(_AttributesMap[_ObjectClasses[L"Following"]][L"Name"])->second);
            _qAttributes.pop();
        }
    }
};

#endif // THREADFEDERATE_HPP
