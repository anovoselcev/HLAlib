#include "SimFederate.hpp"
#include "HLAdata/HLAdata.hpp"
#include "Tools/Logger.hpp"

namespace HLA {
    using namespace  rti1516e;
    
    extern std::unique_ptr<Logger> logger;
    
    using HLAButton = Struct_wrapper<HLA::Button, 8, Integer32LE, Integer32LE, Integer32LE, Wstring, Enum<Appoitment>>;

									
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
	
    
    void SimFederate::ParameterProcess(rti1516e::InteractionClassHandle &handle,
                                       rti1516e::ParameterHandleValueMap &data,
                                       rti1516e::VariableLengthData &info){
			auto strategy = MakeStrategy(handle);
			strategy->Action(data);
        }
    
    void SimFederate::AttributeProcess(rti1516e::ObjectClassHandle &handle,
                                       rti1516e::AttributeHandleValueMap &data,
                                       rti1516e::VariableLengthData &info){
                                           if(active_mode){}
        }

	
	std::unique_ptr<SimFederate::Strategy> SimFederate::MakeStrategy(const rti1516e::InteractionClassHandle& handle){
		if(_InteractionClasses[L"TurnModel"] == handle) return std::make_unique<SimFederate::TurnModel>(this);
	}
	
    SimFederate::Strategy::Strategy(SimFederate* ptr) : _ptr(ptr) {}
	
    void SimFederate::TurnModel::Action(const rti1516e::ParameterHandleValueMap &data){
        Button button = HLA::cast_from_rti<HLAButton>(data.at(_ptr->_ParametersMap[_ptr->_InteractionClasses[L"TurnModel"]][L"PushButton"]));
        *logger << L"INFO:" << _ptr->_federate_name << L" Recive button with name " << button.model_name << Logger::Flush();
        if(button.model_name == _ptr->_federate_name && button.action == Appoitment::ON_OFF){
             _ptr->active_mode = !_ptr->active_mode;
             _ptr->SendBulbFlashSignal(button.bulb_id);
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
