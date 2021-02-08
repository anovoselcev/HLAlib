#include "SimFederate.hpp"
#include "Tools/Logger.hpp"

namespace HLA {

    extern std::unique_ptr<Logger> log;

    using namespace  rti1516e;

									
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

    void SimFederate::ParameterProcess(rti1516e::InteractionClassHandle &handle,
                                       rti1516e::ParameterHandleValueMap &data,
                                       rti1516e::VariableLengthData &info){}
	
    void SimFederate::AttributeProcess(rti1516e::ObjectClassHandle &handle,
                                       rti1516e::AttributeHandleValueMap &data,
                                       rti1516e::VariableLengthData &info){
        for(const auto& obj : _ObjectClasses){
            for(const auto& attr_map : _AttributesMap[obj.second]){
                auto _data = data.find(attr_map.second);
                if(_data != end(data))
                    input[attr_map.first] = std::move(_data->second);
            }
        }
    }

    
    std::unordered_map<std::wstring, rti1516e::VariableLengthData>& SimFederate::getInputData() { 
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
