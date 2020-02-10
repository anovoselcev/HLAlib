#include "UPIM.hpp"
#include <QDebug>
#include "profile.hpp"
namespace UPIM{
	using namespace std;
	using namespace rti1516e;

	UPIMFederate::UPIMFederate() noexcept{}


	UPIMFederate::UPIMFederate(const wstring& name,
								  const wstring& type,
								  const wstring& FOMname,
								  const wstring& ip,
								  const wstring& fname) noexcept:
										_federate_name(name),
										_federate_type(type),
										_FOMname(FOMname),
										_host_IP_address(ip),
										_federation_name(fname)
										{}

	UPIMFederate::UPIMFederate(wstring&& name,
								  wstring&& type,
							  	  wstring&& FOMname,
							  	  wstring&& ip,
								  wstring&& fname) noexcept:
									  	 _federate_name(move(name)),
										 _federate_type(move(type)),
										 _FOMname(move(FOMname)),
										 _host_IP_address(move(ip)),
										 _federation_name(move(fname)){}

	UPIMFederate::~UPIMFederate(){
        qDebug()<<"UPIM destructor"<<endl;
        //qDebug()<<">>"<<_federate_name<<" disconnect from "<<_host_IP_address<<endl;
	}

    unique_ptr<RTIambassador>UPIMFederate::MakeRTIambassador() const{
        unique_ptr<RTIambassadorFactory> rtiAmbassadorFactory = make_unique<RTIambassadorFactory>();
        unique_ptr<RTIambassador> _rtiAmbassador(rtiAmbassadorFactory->createRTIambassador());
        return _rtiAmbassador;
	}

	void UPIMFederate::ConnectRRTI() &{
        LOG_DURATION("Connect")
		vector<wstring> FOMmoduleUrls;
		FOMmoduleUrls.push_back(_FOMname);
        _rtiAmbassador = MakeRTIambassador();
        if(_host_IP_address == L"localhost")
            _rtiAmbassador->connect(*this,_callback_mode);
        else
            _rtiAmbassador->connect(*this,_callback_mode,L"crcAddress="+_host_IP_address);

		try{
			_rtiAmbassador->createFederationExecution(_federation_name, FOMmoduleUrls);
		}
		catch(FederationExecutionAlreadyExists&){}
		_rtiAmbassador->joinFederationExecution(_federate_name,_federation_name);
        qDebug()<<"Connect done"<<endl;
		_f_connect = true;
		try{
			Init();
            qDebug()<<"Init done"<<endl;
		}
		catch(RTIinternalError& e){
			wcerr<<L"Error in Init() with "<<e.what()<<endl;
		}
		try{
			RunFederate();
		}
		catch(RTIinternalError& e){
			wcerr<<L"Error in Run() with "<<e.what()<<endl;
		}
	}
	void UPIMFederate::Init(){
        LOG_DURATION("Init")
		InitClassesAndAttributes();

		SubscribeAttributes();

		PublishAttributes();

		InitInteractionsAndParameters();

		SubscribeParameters();

		PublishParameters();

		RegisterName();

		MakeTime();

		_f_start = true;
	}

	void UPIMFederate::InitClassesAndAttributes(){
		_MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type);
		for(auto&x:_ObjectsNames){
			_externObjectClasses[x.first] = _rtiAmbassador->getObjectClassHandle(x.first);
			for(auto&y:x.second){
				_AttributesMap[_externObjectClasses[x.first]][y] =_rtiAmbassador->getAttributeHandle(_externObjectClasses[x.first],y);
				if(x.first == _federate_type){
					_aPublishSetId.insert(_AttributesMap[_externObjectClasses[x.first]][y]);
					_externAttributesSet[_externObjectClasses[x.first]].insert(_AttributesMap[_externObjectClasses[x.first]][y]);
				}
				else
					_externAttributesSet[_externObjectClasses[x.first]].insert(_AttributesMap[_externObjectClasses[x.first]][y]);
			}
		}
	}

	void UPIMFederate::InitInteractionsAndParameters(){
		for(auto&x:_InteractionsNames){
			_InteractionClasses[x.first] = _rtiAmbassador->getInteractionClassHandle(x.first);
			for(auto&y:x.second){
				_ParametersMap[_InteractionClasses[x.first]][y] =_rtiAmbassador->getParameterHandle(_InteractionClasses[x.first],y);
			}
		}
	}

	void UPIMFederate::SubscribeAttributes(){
		for(const auto& x:_externAttributesSet)
			_rtiAmbassador->subscribeObjectClassAttributes(x.first,x.second);
	}

	void UPIMFederate::PublishAttributes(){
		_rtiAmbassador->publishObjectClassAttributes(_MyClass,_aPublishSetId);
	}

	void UPIMFederate::SubscribeParameters(){
		for(const auto&x:_ParametersMap)
			_rtiAmbassador->subscribeInteractionClass(x.first);
	}

	void UPIMFederate::PublishParameters(){
		for(const auto&x:_ParametersMap)
			_rtiAmbassador->publishInteractionClass(x.first);
	}

	void UPIMFederate::RegisterName(){
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);
        while(!_f_name_reserve){
            wcerr<<'\0';
        }
          _MyInstanceID = _rtiAmbassador->registerObjectInstance(_MyClass, _federate_name);
	}

	void UPIMFederate::MakeTime(){
		_TimeFactory = _rtiAmbassador->getTimeFactory();
		_Time= *_TimeFactory->makeInitial();
		_TimeInterval = *_TimeFactory->makeEpsilon();
	}

	void UPIMFederate::RunFederate(){
		while(true){}
	}

	void UPIMFederate::UpdateAttributes() const{
		HLAunicodeString unicodeName(_federate_name);
		_aMapId.at(_AttributesMap.at(_MyClass).at(L"Name")) = unicodeName.encode();
		_rtiAmbassador->updateAttributeValues(_MyInstanceID,_aMapId,VariableLengthData());
		//_rtiAmbassador->updateAttributeValues(_MyInstanceID,_aMapId,VariableLengthData(),_Time);
	}

	void UPIMFederate::SendParameters() const{
		wstring _some_param;
		wstring _some_inter;
		HLAunicodeString unicodeSome(_some_param);
		_pMapId.at(_ParametersMap.at(_InteractionClasses.at(_some_inter)).at(_some_param)) = unicodeSome.encode();
		_rtiAmbassador->sendInteraction(_InteractionClasses.at(_some_inter),_pMapId,VariableLengthData());
		//_rtiAmbassador->sendInteraction(_InteractionClasses[_some_inter],_pMapId,VariableLengthData(),_Time);

	}


	wstring UPIMFederate::GetName() const noexcept {return _federate_name;}

	wstring UPIMFederate::GetType() const noexcept {return _federate_type;}

	wstring UPIMFederate::GetFederation() const noexcept{return _federation_name;}

	wstring UPIMFederate::GetFOMpath() const noexcept{return _FOMname;}

	wstring UPIMFederate::GetIP() const noexcept{return _host_IP_address;}

	wstring UPIMFederate::GetCallbackMode() const noexcept{
		if(_callback_mode == HLA_IMMEDIATE)
			return L"HLA_IMMEDIATE";
		return L"HLA_EVOKED";
	}

	void UPIMFederate::SetMapOfObjectsAndAttributes(const unordered_map<wstring,vector<wstring>>& _map) noexcept{
		_ObjectsNames = _map;
	}

	void UPIMFederate::SetMapOfObjectsAndAttributes(unordered_map<wstring,vector<wstring>>&& _map) noexcept{
		_ObjectsNames = _map;
	}

	void UPIMFederate::SetMapOfInteractionsAndParameters(const unordered_map<wstring,vector<wstring>>& _map) noexcept{
		_InteractionsNames = _map;
	}

	void UPIMFederate::SetMapOfInteractionsAndParameters(unordered_map<wstring,vector<wstring>>&& _map) noexcept{
		_InteractionsNames = _map;
	}

	void UPIMFederate::SetSyncCallbackMode(bool f) noexcept{
		if(f && !_f_connect)
			_callback_mode = HLA_EVOKED;
	}
	void UPIMFederate::objectInstanceNameReservationSucceeded (
				         std::wstring const & theObjectInstanceName)
				         throw (
				            FederateInternalError){
		_f_name_reserve = true;
	}
}
