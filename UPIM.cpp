#include "UPIM.hpp"
#include <QDebug>
#include "profile.hpp"

namespace UPIM{
	using namespace std;
	using namespace rti1516e;


/**
* @brief UPIMFederate::UPIMFederate
* Default constructor, initialization nothing
*/
	UPIMFederate::UPIMFederate() noexcept{}


/**
* @brief UPIMFederate::UPIMFederate
* @param name
* @param type
* @param FOMname
* @param ip
* @param fname
* Full-gapes copy constructor, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
*/
	UPIMFederate::UPIMFederate(const wstring& name,
								  const wstring& type,
								  const wstring& FOMname,
								  const wstring& ip,
								  const wstring& fname) noexcept:
										_federate_name(name),
										_federate_type(type),
										_FOMname(FOMname),
										_host_IP_address(ip),
										_federation_name(fname){}

/**
* @brief UPIMFederate::UPIMFederate
* @param name
* @param type
* @param FOMname
* @param ip
* @param fname
* Full-gapes move constructor, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
*/
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


/**
* @brief UPIMFederate::~UPIMFederate
* Destructor
*/
	UPIMFederate::~UPIMFederate(){
        qDebug()<<"UPIM destructor"<<endl;
        //qDebug()<<">>"<<_federate_name<<" disconnect from "<<_host_IP_address<<endl;
	}

/**
* @brief UPIMFederate::MakeRTIambassador
* Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
*/
    unique_ptr<RTIambassador>UPIMFederate::MakeRTIambassador() const{
        LOG_DURATION("Make Ambassador")
        unique_ptr<RTIambassadorFactory> rtiAmbassadorFactory = make_unique<RTIambassadorFactory>();
        unique_ptr<RTIambassador> _rtiAmbassador(rtiAmbassadorFactory->createRTIambassador());
        return _rtiAmbassador;
	}

//Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist)
// and join there. After that federate initialized in RTI and go to the his main loop.
//Use only to lvalue class samples
	void UPIMFederate::ConnectRRTI() &{
        LOG_DURATION("Total")

//Vector that keep path to FOM
		vector<wstring> FOMmoduleUrls;
		FOMmoduleUrls.push_back(_FOMname);

//Initialized rtiAmbassador to call RTI servecies (look UPIM::MakeRTIambassador)
        _rtiAmbassador = MakeRTIambassador();
        {LOG_DURATION("Connect")

//Check the CRC address and callback RTI mode (sync, async) and using rtiAmbassador connect this federate to RTI
        if(_host_IP_address == L"localhost")
            _rtiAmbassador->connect(*this,_callback_mode);
        else
            _rtiAmbassador->connect(*this,_callback_mode,L"crcAddress="+_host_IP_address);
        }
        {LOG_DURATION("Create and join")
		try{

//Try to create federation with name (_federation_name) and rules in FOM (look _FOMname)
			_rtiAmbassador->createFederationExecution(_federation_name, FOMmoduleUrls);
		}

//If federation already exist we catch exception(FederationExecutionAlreadyExists) and do nothing
		catch(FederationExecutionAlreadyExists&){}

//After connect and create/find federation with name (_federation_name) we join to it with name (_federate_name)
		_rtiAmbassador->joinFederationExecution(_federate_name,_federation_name);
        }
        qDebug()<<"Connect done"<<endl;

//If all connect steps finished we set connect flag to true value
		_f_connect = true;
		try{
//Initialized federate (it's object type in FOM and attributes), environment in federation
// (other types and attributes indicated in _ObjectsNames) and their connections for this federate
			Init();

            qDebug()<<"Init done"<<endl;
		}
		catch(RTIinternalError& e){
			wcerr<<L"Error in Init() with "<<e.what()<<endl;
        }
		try{

//Run the main loop of federate
			RunFederate();
		}
		catch(RTIinternalError& e){
			wcerr<<L"Error in Run() with "<<e.what()<<endl;
		}
	}

//Initialized federate (it's object type in FOM and attributes), environment in federation
// (other types and attributes indicated in _ObjectsNames) and their connections for this federate
	void UPIMFederate::Init(){
        LOG_DURATION("Init")

//Initializerd federate object and his attributes and environmental objects and attributes indicated in FOM
		InitClassesAndAttributes();

//Send to RTI set of attributes which federate want to recive
		SubscribeAttributes();

//Send to RTI set of attributes which federate publish
		PublishAttributes();


		InitInteractionsAndParameters();

		SubscribeParameters();

		PublishParameters();

		RegisterName();

		MakeTime();

		_f_start = true;
	}

//Initializerd federate object and his attributes and environmental objects and attributes indicated in _ObjectNames
	void UPIMFederate::InitClassesAndAttributes(){

//Initializerd our federate object(_MyClass) from FOM refer to _federate_type
		_MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type);

//Initializerd environmental objects and attributes indicated in _ObjectNames and attributes of it federate
		for(auto&x:_ObjectsNames){

//Set table(_externObjectClasses) of objects like [TypeName, HLAobjectClass(something like link to FOM)]
			_externObjectClasses[x.first] = _rtiAmbassador->getObjectClassHandle(x.first);

			for(auto&y:x.second){
//Set table(_AttributesMap) of object's attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]
				_AttributesMap[_externObjectClasses[x.first]][y] =_rtiAmbassador->getAttributeHandle(_externObjectClasses[x.first],y);

//If type(x.first) equal federate type(_federate_type)
                if(x.first == _federate_type){

//Insert federate attributes to Publish Set(_aPublishSetId)
                    _aPublishSetId.insert(_AttributesMap[_externObjectClasses[x.first]][y]);

                }
//Insert extern attributes to Subscribe Set(_externAttributeSet)
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

//Send to RTI set of attributes which federate want to recive
	void UPIMFederate::SubscribeAttributes(){
		for(const auto& x:_externAttributesSet)

//Send to RTI request to subscribe on Object(x.first) and his Attribute Set (x.second)
//It get opportunity to recive information about updates of object's attribute set in reflectAttributeValues
			_rtiAmbassador->subscribeObjectClassAttributes(x.first,x.second);
	}

//Send to RTI set of attributes which federate publish
	void UPIMFederate::PublishAttributes(){

//Send to RTI request to publish attributes (_aPublishSetId) of this federate with object _MyClass
//After that federate can provide information about updates of his attributes in RTI using UpdateAttributes
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
