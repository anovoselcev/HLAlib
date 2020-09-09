#ifndef FOLLOWFEDERATE_HPP
#define FOLLOWFEDERATE_HPP
#include "../BaseFederate.hpp"
#include "../HLAdata/HLAdata.hpp"
#include <iostream>

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

    void AttributeProcess() override{
        std::lock_guard<std::mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            //std::wcout << L"I recive" << std::endl;
            auto& message = _qAttributes.front();
            //std::wcout << HLA::cast_from_rti<HLA::Wstring>(message.data.find(_AttributesMap[_ObjectClasses[L"Threading"]][L"Name"])->second).size() << std::endl;
            auto str = HLA::cast_from_rti<HLA::Wstring>(message.info);
            std::wstring wstr;
            wstr.assign(str.begin(), str.end());
            std::wcout << str << std::endl;
            _qAttributes.pop();
        }
    }

};

#endif // FOLLOWINGFEDERATE_HPP
