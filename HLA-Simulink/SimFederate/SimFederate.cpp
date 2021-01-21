#include "SimFederate.hpp"
#include "Tools/Logger.hpp"

namespace HLA {

    extern std::unique_ptr<Logger> log;

    using namespace  rti1516e;

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
									
    SimFederate::SimFederate(const HLA::JSON& file) noexcept :
                                 BaseFederate(file){}
		
    SimFederate::SimFederate(HLA::JSON&& file) noexcept :
                                 BaseFederate(std::move(file)){}
                                 
    void SimFederate::SendDataToRTI(){
        rti1516e::AttributeHandleValueMap map;
        for(const auto& data: output)
            map[_AttributesMap[_MyClass][data.first]] = data.second;
        try{
            _rtiAmbassador->updateAttributeValues(_MyInstanceID,map, rti1516e::VariableLengthData());
        }
        catch(...){
            *log << Logger::MSG::ERRORR
                << _federate_name
                << L"Can't update attributes"
                << HLA::Logger::Flush();
                    
        }
    }
	
    void SimFederate::ParameterProcess(){
        std::lock_guard<std::mutex> guard(_pmutex);
        while(!_qParameters.empty()){
            auto& message = _qParameters.front();
            _qParameters.pop();
        }
    }

    void SimFederate::AttributeProcess(){
        std::lock_guard<std::mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            for(const auto& obj : _ObjectClasses){
                for(const auto& attr_map : _AttributesMap[obj.second]){
                    auto data = message.data.find(attr_map.second);
                    if(data != end(message.data))
                        input[attr_map.first] = std::move(data->second);
                }
            }
                
            _qAttributes.pop();
        }
    }
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData>& SimFederate::getInputData() { 
        this->AttributeProcess();
        return input;
    }
    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData>& SimFederate::getOutputData() { 
        return output;
    }

    void SimFederate::SendParameters() const{

    }

    void SimFederate::UpdateAttributes() const{
       
    }

}
