#include "SimFederate.hpp"

namespace HLA {
    using namespace  rti1516e;


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
									
    SimFederate::SimFederate(const HLA::JSON& file) noexcept : BaseFederate(file){}
		
    SimFederate::SimFederate(HLA::JSON&& file) noexcept : BaseFederate(std::move(file)){}
	
    void SimFederate::ParameterProcess(){
        std::lock_guard<std::mutex> guard(_pmutex);
        while(!_qParameters.empty()){
            auto& message = _qParameters.front();
            _qParameters.pop();
        }
    }

    void SimFederate::AttributeProcess(){}

    void SimFederate::SendParameters() const{

    }

    void SimFederate::UpdateAttributes() const{
        rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(_federate_name);
        int i = 20;
        rti1516e::VariableLengthData type = HLA::cast_to_rti<HLA::Integer32BE>(i);
        rti1516e::AttributeHandleValueMap map;
        map[_AttributesMap.at(_MyClass).at(L"Name")] = v;
        _rtiAmbassador->updateAttributeValues(_MyInstanceID,map,type);
    }

}
