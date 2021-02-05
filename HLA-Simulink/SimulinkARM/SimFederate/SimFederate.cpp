#include "SimFederate.hpp"
#include "HLAdata/HLAdata.hpp"
#include "Tools/Logger.hpp"

namespace HLA {
    using namespace  rti1516e;
    
    extern std::unique_ptr<Logger> logger;
    
    using HLAButton = Struct_Wrapper<HLA::Button, 8, Integer32LE, Integer32LE, Integer32LE, Wstring, Enum<Appoitment>>;


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
	
	void SimFederate::SendBulbFlashSignal(int& id){
		rti1516e::ParameterHandleValueMap map;
		rti1516e::InteractionClassHandle name(_InteractionClasses[L"MatlabCallback"]);
		map[_ParametersMap[name][L"Stamp"]] = HLA::cast_to_rti<HLA::Integer32LE>(id);
        *logger << L"INFO:" << _federate_name << L" Send " << id << Logger::Flush();
		try{
			_rtiAmbassador->sendInteraction(name,map,HLA::cast_to_rti<HLA::String>("Matlab"));
		}
		catch(...){}
			//*logger << L"ERROR:" << _federate_name << L"Can't send Interaction MatlabCallback" << Logger::Flush();
		
	}
	
    void SimFederate::ParameterProcess(){
        std::lock_guard<std::mutex> guard(_pmutex);
		//rti1516e::InteractionClassHandle name = _InteractionClasses.at(L"ARMaction");
		while(!_qParameters.empty()){
			auto& message = _qParameters.front();
            if(message.handle == _InteractionClasses[L"ARMaction"]){
                Button button = HLA::cast_from_rti<HLAButton>(message.data[_ParametersMap[name][L"PushButton"])->second);
                *logger << L"INFO:" << _federate_name << L" Recive button with name " << button.model_name << Logger::Flush();
                if(button.model_name == _federate_name && button.action == Appoitment::ON_OFF){
                    active_mode = !active_mode;
                    SendBulbFlashSignal(button.bulb_id);
                }
            }
			_qParameters.pop();
		}
    }

    void SimFederate::AttributeProcess(){
        std::lock_guard<std::mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            if(active_mode){
                
            }
            _qAttributes.pop();
        }
    }

    void SimFederate::SendParameters() const{

    }

    void SimFederate::UpdateAttributes() const{
        if(active_mode){
            rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(_federate_name);
            int i = 20;
            rti1516e::VariableLengthData type = HLA::cast_to_rti<HLA::Integer32BE>(i);
            rti1516e::AttributeHandleValueMap map;
            map[_AttributesMap.at(_MyClass).at(L"Name")] = v;
            _rtiAmbassador->updateAttributeValues(_MyInstanceID,map,type);
        }
    }

}
