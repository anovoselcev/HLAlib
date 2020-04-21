#include "BaseFederate.hpp"
#include <iostream>
#include <chrono>

namespace HLA{

    using namespace std;
    using namespace rti1516e;


//Default constructor, initialization nothing
    BaseFederate::BaseFederate() noexcept{}

    BaseFederate::BaseFederate(const wstring& name,
                                     const wstring& type,
                                     const wstring& FOMname,
                                     const wstring& fname,
                                     const wstring& ip) noexcept:
                                           _federate_name(name),
                                           _federate_type(type),
                                           _FOMname(FOMname),
                                           _host_IP_address(ip),
                                           _federation_name(fname){}


   //Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
       BaseFederate::BaseFederate(wstring&& name,
                                     wstring&& type,
                                     wstring&& FOMname,
                                     wstring&& fname,
                                     wstring&& ip) noexcept:
                                            _federate_name(move(name)),
                                            _federate_type(move(type)),
                                            _FOMname(move(FOMname)),
                                            _host_IP_address(move(ip)),
                                            _federation_name(move(fname)){}
//Destructor
    BaseFederate::~BaseFederate(){
        _f_modeling = false;
        _modeling_thread.join();
        wcout << L">>" << _federate_name << L" disconnect from " << _host_IP_address << endl;

    }

//Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
    unique_ptr<RTIambassador>BaseFederate::MakeRTIambassador() const{
        unique_ptr<RTIambassadorFactory> rtiAmbassadorFactory = std::make_unique<RTIambassadorFactory>();
        unique_ptr<RTIambassador> _rtiAmbassador(rtiAmbassadorFactory->createRTIambassador());
        return _rtiAmbassador;
    }

//Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist)
// and join there. After that federate initialized in RTI and go to the his main loop.
//Use only to lvalue class samples
    void BaseFederate::ConnectRTI() &{
    //Initialized rtiAmbassador to call RTI servecies (look HLA::MakeRTIambassador)
        try{
            _rtiAmbassador = MakeRTIambassador();
        }
        catch(RTIinternalError){
            wcout << L"Can't create RTIambassador" << endl;
            return;
        }

        try{

    //Check the CRC address and callback RTI mode (sync, async) and using rtiAmbassador connect this federate to RTI
            if(_host_IP_address == L"localhost")
                _rtiAmbassador->connect(*this,_callback_mode);
            else
                _rtiAmbassador->connect(*this,_callback_mode,L"crcAddress="+_host_IP_address);
        }
        catch(Exception&){
            wcout << L"Cant connect" << endl;
            return;
        }

        try{
    //Try to create federation with name (_federation_name) and rules in FOM (look _FOMname)
            _rtiAmbassador->createFederationExecution(_federation_name, _FOMname);
        }
    //If federation already exist we catch exception(FederationExecutionAlreadyExists) and do nothing
        catch(FederationExecutionAlreadyExists&){}

        try{
    //After connect and create/find federation with name (_federation_name) we join to it with name (_federate_name)
            _rtiAmbassador->joinFederationExecution(_federate_name,_federation_name);
            wcout << L"Connect done" << endl;
        }
        catch(Exception&){wcout << L"Can't join" << endl; return;}

    //If all connect steps finished we set connect flag to true value
        _f_connect = true;
        try{
    //Initialized federate (it's object type in FOM and attributes), environment in federation
    // (other types and attributes indicated in _ObjectsNames) and their connections for this federate
            Init();

            wcout << L"Init done" << endl;
        }
        catch(RTIinternalError& e){
            wcout << L"Error in Init() with " << endl;
        }

        try{

    //Run the main loop of federate
            _f_modeling = true;
            _modeling_thread = std::thread(&BaseFederate::Modeling,this);
            RunFederate();
        }
        catch(RTIinternalError& e){
            wcout << L"Error in Run() with " << e.what() << endl;
        }
    }

    void BaseFederate::operator()(int step) &{
        _modeling_step = step;
        ConnectRTI();
    }

//Initialized federate (it's object type in FOM and attributes), environment in federation
// (other types and attributes indicated in _ObjectsNames) and their connections for this federate
    void BaseFederate::Init(){

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

        _f_start = true;
    }

//Initializerd federate object and his attributes and environmental objects and attributes indicated in _ObjectNames
    void BaseFederate::InitClassesAndAttributes(){

    //Initializerd our federate object(_MyClass) from FOM refer to _federate_type
        _MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type);

        for(const auto& Attribute:_AttributeNames){
        //Set table(_AttributesMap) of this object attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]
            _AttributesMap[_MyClass][Attribute] = _rtiAmbassador->getAttributeHandle(_MyClass,Attribute);

        //Insert federate attributes to Publish Set(_aPublishSetId)
            _aPublishSet.insert(_AttributesMap[_MyClass][Attribute]);
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
    void BaseFederate::InitInteractionsAndParameters(){

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
    void BaseFederate::SubscribeAttributes(){
        for(const auto& x:_externAttributesSet)

    //Send to RTI request to subscribe on Object(x.first) and his Attribute Set (x.second)
    //It get opportunity to recive information about updates of object's attribute set in reflectAttributeValues
            _rtiAmbassador->subscribeObjectClassAttributes(x.first,x.second);

        _externAttributesSet.clear();
    }

//Send to RTI set of attributes which federate publish
    void BaseFederate::PublishAttributes(){

    //Send to RTI request to publish attributes (_aPublishSetId) of this federate with object _MyClass
    //After that federate can provide information about updates of his attributes in RTI using UpdateAttributes
        _rtiAmbassador->publishObjectClassAttributes(_MyClass,_aPublishSet);
    }

//Send to RTI set of partameters which federate want to recive
    void BaseFederate::SubscribeParameters(){
        for(const auto&x:_ParametersMap)
        //Send to RTI request to subscribe on Interaction(x.first) and his Parameter Set (x.second)
        //It get opportunity to recive information about updates of interaction's parameter set in reflectParameterValues
            _rtiAmbassador->subscribeInteractionClass(x.first);
    }

//Send to RTI set of parameters which federate publish
    void BaseFederate::PublishParameters(){
        for(const auto&x:_ParametersMap)
        //Send to RTI request to publish parameters (_ParametersMap) of this federate
        //After that federate can provide information about updates of his parameters in RTI using sendInteraction
            _rtiAmbassador->publishInteractionClass(x.first);
    }

    void BaseFederate::RegisterName(){
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);
        auto start = chrono::steady_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-start).count();
        while(!_f_name_reserve || dur<=3000){
            dur = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now()-start).count();
        }
          _MyInstanceID = _rtiAmbassador->registerObjectInstance(_MyClass, _federate_name);
    }

    void BaseFederate::RunFederate(){}

    void BaseFederate::UpdateAttributes() const{}

    void BaseFederate::SendParameters() const{}

    void BaseFederate::Modeling(){
        while(_f_modeling){
            {
                lock_guard<mutex> guard(_smutex);
                _f_state = true;
            }
            _cond.notify_one();
            std::this_thread::sleep_for(std::chrono::milliseconds(_modeling_step));
            thread AttributeTread(&BaseFederate::AttributeProcess,this);
            thread ParametersThread(&BaseFederate::ParameterProcess,this);
            ParametersThread.detach();
            AttributeTread.join();
            UpdateAttributes();
        }
    }

    void BaseFederate::AttributeProcess(){
        lock_guard<mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            //...some processing
            _qAttributes.pop();
        }
    }

    void BaseFederate::ParameterProcess(){
        lock_guard<mutex> guard(_pmutex);
        while(!_qParameters.empty()){
            auto& message = _qParameters.front();
            //...some processing
            _qParameters.pop();
        }
    }

    wstring BaseFederate::GetName() const noexcept {return _federate_name;}

    wstring BaseFederate::GetType() const noexcept {return _federate_type;}

    wstring BaseFederate::GetFederation() const noexcept{return _federation_name;}

    wstring BaseFederate::GetFOMpath() const noexcept{return _FOMname;}

    wstring BaseFederate::GetIP() const noexcept{return _host_IP_address;}

    wstring BaseFederate::GetCallbackMode() const noexcept{
        if(_callback_mode == HLA_IMMEDIATE)
            return L"HLA_IMMEDIATE";
        return L"HLA_EVOKED";
    }

    void BaseFederate::SetSubscribeMapOfObjectsAndAttributes(const unordered_map<wstring,vector<wstring>>& _map) noexcept{
        _ObjectsNames = _map;
    }

    void BaseFederate::SetSubscribeMapOfObjectsAndAttributes(unordered_map<wstring,vector<wstring>>&& _map) noexcept{
        _ObjectsNames = _map;
    }

    void BaseFederate::SetPublishListOfAttributes(const vector<wstring>& attr) noexcept{
        _AttributeNames = attr;
    }

    void BaseFederate::SetPublishListOfAttributes(vector<wstring> &&attr) noexcept{
        _AttributeNames = attr;
    }

    void BaseFederate::SetMapOfInteractionsAndParameters(const unordered_map<wstring,vector<wstring>>& _map) noexcept{
        _InteractionsNames = _map;
    }

    void BaseFederate::SetMapOfInteractionsAndParameters(unordered_map<wstring,vector<wstring>>&& _map) noexcept{
        _InteractionsNames = _map;
    }

    void BaseFederate::SetSyncCallbackMode(bool f) noexcept{
        if(f && !_f_connect)
            _callback_mode = HLA_EVOKED;
    }

    void BaseFederate::SetModelingStep(int _step) noexcept{
        _modeling_step = _step;
    }

    void BaseFederate::objectInstanceNameReservationSucceeded(std::wstring const & theObjectInstanceName)
    throw (FederateInternalError){
        _f_name_reserve = true;
    }

    void BaseFederate::reflectAttributeValues(ObjectInstanceHandle theObject,
                                        const AttributeHandleValueMap &theAttributeValues,
                                        const VariableLengthData &theUserSuppliedTag,
                                        OrderType sentOrder,
                                        TransportationType theType,
                                        SupplementalReflectInfo theReflectInfo)
    throw (FederateInternalError){
        if(_f_start){
            lock_guard<mutex> guard(_amutex);
            _qAttributes.push(theAttributeValues);
        }
    }

    void BaseFederate::receiveInteraction (InteractionClassHandle theInteraction,
                                     ParameterHandleValueMap const & theParameterValues,
                                     VariableLengthData const & theUserSuppliedTag,
                                     OrderType sentOrder,
                                     TransportationType theType,
                                     SupplementalReceiveInfo theReceiveInfo)
    throw (FederateInternalError){
        if(_f_start){
            lock_guard<mutex> guard(_pmutex);
            _qParameters.push(theParameterValues);
        }
    }
}
