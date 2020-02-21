#include "UPIM.hpp"
#include <QDebug>
#include "profile.hpp"
#include <chrono>

namespace UPIM{
	using namespace std;
	using namespace rti1516e;


//Default constructor, initialization nothing
	UPIMFederate::UPIMFederate() noexcept{}



//Full-gapes constructor with copy, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
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


//Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
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



//Destructor
	UPIMFederate::~UPIMFederate(){
        qDebug()<<"UPIM destructor"<<endl;
        qDebug()<<">>"<<QString::fromStdWString(_federate_name)<<" disconnect from "<<QString::fromStdWString(_host_IP_address)<<endl;
	}

//Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
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
            qDebug()<<"Error in Init() with "<<endl;
        }
		try{

    //Run the main loop of federate
			RunFederate();
		}
		catch(RTIinternalError& e){
            qDebug()<<"Error in Run() with "<<endl;
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

    //Initializerd Interactions and there parameters indicated in FOM
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

        for(const auto& Attribute:_AttributeNames){
        //Set table(_AttributesMap) of this object attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]
            _AttributesMap[_MyClass][Attribute] = _rtiAmbassador->getAttributeHandle(_MyClass,Attribute);

        //Insert federate attributes to Publish Set(_aPublishSetId)
            _aPublishSetId.insert(_AttributesMap[_MyClass][Attribute]);
        }

    //Initializerd environmental objects and attributes indicated in _ObjectNames and attributes of it federate
        for(const auto&Object:_ObjectsNames){

        //Cache of Object Name
            auto& objectName = Object.first;

        //Set table(_ObjectClasses) of objects like [TypeName, HLAobjectClass(something like link to FOM)]
            _ObjectClasses[objectName] = _rtiAmbassador->getObjectClassHandle(objectName);

            for(const auto&Attribute:Object.second){
            //Cache of Object ID
                auto& objectId = _ObjectClasses[objectName];

            //Set table(_AttributesMap) of object's attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]
                _AttributesMap[objectId][Attribute] =_rtiAmbassador->getAttributeHandle(objectId,Attribute);

            //Insert extern attributes to Subscribe Set(_externAttributeSet)
                _externAttributesSet[objectId].insert(_AttributesMap[objectId][Attribute]);

			}
		}
	}

//Initializerd federate interactions and his parameters and environmental interactions and parameters indicated in _InteractionNames
	void UPIMFederate::InitInteractionsAndParameters(){

        for(const auto&Interaction:_InteractionsNames){
        //Cache of Interaction Name
            auto& interactionName = Interaction.first;

        //Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)]
            _InteractionClasses[interactionName] = _rtiAmbassador->getInteractionClassHandle(interactionName);

            for(const auto&Parameter:Interaction.second){
            //Cache of InteractionId
                auto& interactionId = _InteractionClasses[Interaction.first];

            //Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter);
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

//Send to RTI set of partameters which federate want to recive
	void UPIMFederate::SubscribeParameters(){
		for(const auto&x:_ParametersMap)
        //Send to RTI request to subscribe on Interaction(x.first) and his Parameter Set (x.second)
        //It get opportunity to recive information about updates of interaction's parameter set in reflectParameterValues
			_rtiAmbassador->subscribeInteractionClass(x.first);
	}

//Send to RTI set of parameters which federate publish
	void UPIMFederate::PublishParameters(){
		for(const auto&x:_ParametersMap)
        //Send to RTI request to publish parameters (_ParametersMap) of this federate
        //After that federate can provide information about updates of his parameters in RTI using sendInteraction
			_rtiAmbassador->publishInteractionClass(x.first);
	}

	void UPIMFederate::RegisterName(){
        LOG_DURATION("Register Name")
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);
        auto start = chrono::steady_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-start).count();
        while(!_f_name_reserve || dur<=3000){
            dur = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now()-start).count();
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

    void UPIMFederate::SetSubscribeMapOfObjectsAndAttributes(const unordered_map<wstring,vector<wstring>>& _map) noexcept{
		_ObjectsNames = _map;
	}

    void UPIMFederate::SetSubscribeMapOfObjectsAndAttributes(unordered_map<wstring,vector<wstring>>&& _map) noexcept{
		_ObjectsNames = _map;
	}

    void UPIMFederate::SetPublishMapOfAttributes(const vector<wstring>& attr) noexcept{
        _AttributeNames = attr;
    }

    void UPIMFederate::SetPublishMapOfAttributes(vector<wstring> &&attr) noexcept{
        _AttributeNames = attr;
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
