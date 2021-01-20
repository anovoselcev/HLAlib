#ifndef THREADFEDERATE_HPP
#define THREADFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../Tools/Logger.hpp"
#include "../HLAdata/HLAdata.hpp"
#include <iostream>

extern std::unique_ptr<HLA::Logger> logger;

class ThreadFederate final : public HLA::BaseFederate{
public:
    ThreadFederate(std::wstring&& name,
                   std::wstring&& FOM) :
        HLA::BaseFederate(name,L"Threading",FOM,L"Test"){
        _mode = HLA::MODELMODE::FREE_THREADING;
    }

    ThreadFederate(const std::wstring& name,
                   const std::wstring& FOM) :
        HLA::BaseFederate(name,L"Threading",FOM,L"Test"){
        _mode = HLA::MODELMODE::FREE_THREADING;
    }

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

    void AttributeProcess() override{
        std::lock_guard<std::mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            std::wcout << HLA::cast_from_rti<HLA::Wstring>(message.data.find(_AttributesMap[_ObjectClasses[L"Following"]][L"Name"])->second) << std::endl;
            std::wcout << HLA::cast_from_rti<HLA::Float64BE>(message.info) << std::endl;
            _qAttributes.pop();
        }
    }
};

#endif // THREADFEDERATE_HPP
