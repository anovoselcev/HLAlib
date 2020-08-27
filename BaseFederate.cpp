#include "BaseFederate.hpp"
#include "Logger.hpp"
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
                                        _federation_name(fname),
                                        _host_IP_address(ip){}


   //Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), IP addres of CRC(_host_IP_address) and name of federation (_federation_name)
    BaseFederate::BaseFederate(wstring&& name,
                               wstring&& type,
                               wstring&& FOMname,
                               wstring&& fname,
                               wstring&& ip) noexcept:
                                      _federate_name(move(name)),
                                      _federate_type(move(type)),
                                      _FOMname(move(FOMname)),
                                      _federation_name(move(fname)),
                                      _host_IP_address(move(ip)){}

    BaseFederate::BaseFederate(const JSON& file) :
                                          _federate_name(file.GetRoot()->AsMap().at(L"Name")->AsWstring()),
                                          _federate_type(file.GetRoot()->AsMap().at(L"Type")->AsWstring()),
                                          _FOMname(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring()),
                                          _federation_name(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring()),
                                          _host_IP_address(file.GetRoot()->AsMap().at(L"Address")->AsWstring()){}

    BaseFederate::BaseFederate(JSON&& file) :
                                          _federate_name(move(file.GetRoot()->AsMap().at(L"Name")->AsWstring())),
                                          _federate_type(move(file.GetRoot()->AsMap().at(L"Type")->AsWstring())),
                                          _FOMname(move(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring())),
                                          _federation_name(move(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring())),
                                          _host_IP_address(move(file.GetRoot()->AsMap().at(L"Address")->AsWstring())){}
//Destructor
    BaseFederate::~BaseFederate(){
        _f_modeling = false;
        if(_mode == ModelMode::THREADING)
            _modeling_thread.join();
        lock_guard<mutex> guard(_smutex);
        _state = State::EXIT;
        Logger log(_log_filename);
        log << L"INFO:"<< _federate_name << L"disconnect from" << _host_IP_address << Logger::Flush();
    }

//Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
    unique_ptr<RTIambassador> BaseFederate::MakeRTIambassador() const &{
        unique_ptr<RTIambassadorFactory> rtiAmbassadorFactory = std::make_unique<RTIambassadorFactory>();
        unique_ptr<RTIambassador> _RtiAmbassador(rtiAmbassadorFactory->createRTIambassador());
        return _RtiAmbassador;
    }

//Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist)
// and join there. After that federate initialized in RTI and go to the his main loop.
//Use only to lvalue class samples
    bool BaseFederate::ConnectRTI() {
    //Initialized rtiAmbassador to call RTI servecies (look HLA::MakeRTIambassador)
        Logger log(_log_filename);
        try{
            _rtiAmbassador = MakeRTIambassador();
        }
        catch(RTIinternalError){
            log << L"ERROR:" << _federate_name << L"Can't create RTIambassador" << Logger::Flush();
            return false;
        }

        try{
    //Check the CRC address and callback RTI mode (sync, async) and using rtiAmbassador connect this federate to RTI
            if(_host_IP_address == L"localhost")
                _rtiAmbassador->connect(*this,_callback_mode);
            else
                _rtiAmbassador->connect(*this,_callback_mode,L"crcAddress="+_host_IP_address);
        }
        catch(...){
            log << L"ERROR:" << _federate_name << L"Cant connect" << Logger::Flush();
            return false;
        }


        try{
    //Try to create federation with name (_federation_name) and rules in FOM (look _FOMname)
            _rtiAmbassador->createFederationExecution(_federation_name, _FOMname);
        }
    //If federation already exist we catch exception(FederationExecutionAlreadyExists) and do nothing
        catch(FederationExecutionAlreadyExists&){}

        catch(ErrorReadingFDD&){
            log << L"ERROR:" << _federate_name << L"Cant read FOM" << Logger::Flush();
            return false;
        }
        catch(CouldNotOpenFDD&){
            log << L"ERROR:" << _federate_name << L"Cant open FOM" << Logger::Flush();
            return false;
        }

        catch(...){
            log << L"ERROR:" << _federate_name << L"Cant create federation" << Logger::Flush();
            return false;
        }

    //This waste 1 seconds, it's the biggest comand in this function (more than 50ths)
        try{
    //After connect and create/find federation with name (_federation_name) we join to it with name (_federate_name)
            _rtiAmbassador->joinFederationExecution(_federate_name,_federation_name);
            log << L"INFO:" << L"Connect of" << _federate_name <<  L"done" << Logger::Flush();
        }
        catch(...){
            log << L"ERROR:" << _federate_name << L"Can't join" << Logger::Flush();
            return false;
        }

        _state = State::CONNECTED;    //If all connect steps finished we set connect flag to true value

        try{
    //Initialized federate (it's object type in FOM and attributes), environment in federation
    // (other types and attributes indicated in _ObjectsNames) and their connections for this federate
            Init();

            log << L"INFO:" << L"Init of" << _federate_name << L"done" << Logger::Flush();
        }
        catch(RTIinternalError& e){
            log << L"ERROR:" << _federate_name << L"Error in Init() with" << e.what() << Logger::Flush();
            return false;
        }

        try{
            _f_modeling = true;//Run the main loop of federate
            if(_mode == ModelMode::THREADING)
                _modeling_thread = std::thread(&BaseFederate::ThreadModeling,this);
            else
                _last_time = chrono::steady_clock::now();
            RunFederate();
        }
        catch(RTIinternalError& e){
            log << L"ERROR:" << _federate_name << L"Error in Run() with" << e.what() << Logger::Flush();
            return false;
        }
        return true;
    }

    bool BaseFederate::operator()(int step) {
        _modeling_step = step;
        return ConnectRTI();
    }

//Initialized federate (it's object type in FOM and attributes), environment in federation
// (other types and attributes indicated in _ObjectsNames) and their connections for this federate
    void BaseFederate::Init(){

        unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash> _externAttributesSet;

        AttributeHandleSet _aPublishSet;

        unordered_set<InteractionClassHandle, InteractionClassHash> _SubscribeInteractionSet;

        unordered_set<InteractionClassHandle, InteractionClassHash> _PublishInteractionSet;

    //Initializerd federate object and his attributes and environmental objects and attributes indicated in FOM
        InitClassesAndAttributes(_externAttributesSet, _aPublishSet);

    //Send to RTI set of attributes which federate want to recive
        SubscribeAttributes(_externAttributesSet);

    //Send to RTI set of attributes which federate publish
        PublishAttributes(_aPublishSet);

    //Initializerd Interactions and there parameters indicated in FOM
        InitInteractionsAndParameters(_SubscribeInteractionSet, _PublishInteractionSet);

        SubscribeParameters(_SubscribeInteractionSet);

        PublishParameters(_PublishInteractionSet);

        RegisterName();

        _state = State::STARTED;
    }

//Initializerd federate object and his attributes and environmental objects and attributes indicated in _ObjectNames
    void BaseFederate::InitClassesAndAttributes(unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash>& _externAttributesSet,
                                                AttributeHandleSet& _aPublishSet){

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
            //Cache of Object ID
            auto& objectId = _ObjectClasses[objectName] = _rtiAmbassador->getObjectClassHandle(objectName);

            for(const auto&Attribute:Object.second){

            //Set table(_AttributesMap) of object's attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]
                _AttributesMap[objectId][Attribute] =_rtiAmbassador->getAttributeHandle(objectId,Attribute);

            //Insert extern attributes to Subscribe Set(_externAttributeSet)
                _externAttributesSet[objectId].insert(_AttributesMap[objectId][Attribute]);

            }
        }
    }

//Initializerd federate interactions and his parameters and environmental interactions and parameters indicated in _InteractionNames
    void BaseFederate::InitInteractionsAndParameters(unordered_set<InteractionClassHandle, InteractionClassHash>& sub,
                                                     unordered_set<InteractionClassHandle, InteractionClassHash>& pub){

        sub.reserve(_InteractionsNames.size());
        pub.reserve(_MyInteractionsNames.size());
        for(const auto&Interaction:_InteractionsNames){
        //Cache of Interaction Name
            auto& interactionName = Interaction.first;

        //Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)]
              //Cache of InteractionId
            auto& interactionId = _InteractionClasses[interactionName] = _rtiAmbassador->getInteractionClassHandle(interactionName);

            sub.insert(interactionId);

            for(const auto&Parameter:Interaction.second)
            //Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter);
        }

        for(const auto&Interaction:_MyInteractionsNames){
        //Cache of Interaction Name
            auto& interactionName = Interaction.first;

        //Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)]
        //Cache of InteractionId
            auto& interactionId = _InteractionClasses[interactionName] = _rtiAmbassador->getInteractionClassHandle(interactionName);
            pub.insert(interactionId);

            for(const auto&Parameter:Interaction.second)
            //Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter);
        }
    }

//Send to RTI set of attributes which federate want to recive
    void BaseFederate::SubscribeAttributes(unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash>& _externAttributesSet){
        for(const auto& x:_externAttributesSet)

    //Send to RTI request to subscribe on Object(x.first) and his Attribute Set (x.second)
    //It get opportunity to recive information about updates of object's attribute set in reflectAttributeValues
            _rtiAmbassador->subscribeObjectClassAttributes(x.first,x.second);
    }

//Send to RTI set of attributes which federate publish
    void BaseFederate::PublishAttributes(AttributeHandleSet& _aPublishSet){

    //Send to RTI request to publish attributes (_aPublishSetId) of this federate with object _MyClass
    //After that federate can provide information about updates of his attributes in RTI using UpdateAttributes
        _rtiAmbassador->publishObjectClassAttributes(_MyClass,_aPublishSet);
    }

//Send to RTI set of partameters which federate want to recive
    void BaseFederate::SubscribeParameters(unordered_set<InteractionClassHandle, InteractionClassHash>& sub){
        for(const auto&x:sub)
        //Send to RTI request to subscribe on Interaction x
        //It get opportunity to recive information about updates of interaction's parameter set in reflectParameterValues
            _rtiAmbassador->subscribeInteractionClass(x);
    }

//Send to RTI set of parameters which federate publish
    void BaseFederate::PublishParameters(unordered_set<InteractionClassHandle, InteractionClassHash>& pub){
        for(const auto&x:pub)
        //Send to RTI request to publish parameters (_ParametersMap) of this federate
        //After that federate can provide information about updates of his parameters in RTI using sendInteraction
            _rtiAmbassador->publishInteractionClass(x);
    }

    void BaseFederate::RegisterName(){
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);
        auto start = chrono::steady_clock::now();
        auto dur = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-start).count();
        while(_state!=State::NAMERESERVED || dur<=1000){
            dur = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now()-start).count();
        }
          _MyInstanceID = _rtiAmbassador->registerObjectInstance(_MyClass, _federate_name);
    }

    void BaseFederate::RunFederate(){}

    void BaseFederate::UpdateAttributes() const{}

    void BaseFederate::SendParameters() const{}

    void BaseFederate::ThreadModeling(){
        while(_f_modeling){
            Logger log(_log_filename);
            {
                lock_guard<mutex> guard(_smutex);
                _state = State::DOING;
                log << L"INFO:" << _federate_name << L"Begin of threading modeling step - doing" << Logger::Flush();
            }
            _cond.notify_one();
            this_thread::sleep_for(chrono::milliseconds(_modeling_step));
            log << L"INFO:" << _federate_name << L"End of threading modeling step - proccessing" << Logger::Flush();
            UpdateAttributes();
            thread ParametersThread(&BaseFederate::ParameterProcess,this);
            ParametersThread.detach();
            AttributeProcess();
        }
    }

    void BaseFederate::FollowModeling(){
        Logger log(_log_filename);
        auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now()-_last_time);
        auto step = chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(_modeling_step));
        if((step - dur).count()>0)
            this_thread::sleep_for(chrono::milliseconds(step - dur));
        log << L"INFO:" << _federate_name << L"End of following modeling step - proccessing" << Logger::Flush();
        UpdateAttributes();
        ParameterProcess();
        AttributeProcess();
        _state = State::DOING;
        log << L"INFO:" << _federate_name << L"Begin of following modeling step - doing" << Logger::Flush();
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

    const wstring BaseFederate::GetName() const noexcept {return _federate_name;}

    const wstring BaseFederate::GetType() const noexcept {return _federate_type;}

    const wstring BaseFederate::GetFederation() const noexcept{return _federation_name;}

    const wstring BaseFederate::GetFOMpath() const noexcept{return _FOMname;}

    const wstring BaseFederate::GetIP() const noexcept{return _host_IP_address;}

    CallbackModel BaseFederate::GetCallbackMode() const noexcept{return _callback_mode;}

    ModelMode BaseFederate::GetModelMode() const noexcept {return _mode;}

    State BaseFederate::GetState() const noexcept {return _state;}

    BaseFederate& BaseFederate::LoadSOMFromJSON(const JSON& file){
        const auto node         = file.GetRoot();
        SetPublishListOfAttributes                (JSON::ToVector(node->AsMap().at(L"PublishAttributes")));
        SetSubscribeMapOfObjectsAndAttributes     (JSON::ToMap(node->AsMap().at(L"SubscribeAttributes")));
        SetPublishMapOfInteractionAndParameters   (JSON::ToMap(node->AsMap().at(L"PublishInteractions")));
        SetSubscribeMapOfInteractionsAndParameters(JSON::ToMap(node->AsMap().at(L"SubscribeInteractions")));
        SetModelingStep(node->AsMap().at(L"ModelingStep")->AsInt());
        SetSyncCallbackMode(node->AsMap().at(L"CallbackMode")->AsInt());
        SetModelMode(ModelMode(node->AsMap().at(L"ModelingMode")->AsInt()));
        return *this;
    }

    BaseFederate& BaseFederate::LoadSOMFromJSON(JSON&& file){
        const auto node         = file.GetRoot();
        SetPublishListOfAttributes                (JSON::ToVector(node->AsMap().at(L"PublishAttributes")));
        SetSubscribeMapOfObjectsAndAttributes     (JSON::ToMap(node->AsMap().at(L"SubscribeAttributes")));
        SetPublishMapOfInteractionAndParameters   (JSON::ToMap(node->AsMap().at(L"PublishInteractions")));
        SetSubscribeMapOfInteractionsAndParameters(JSON::ToMap(node->AsMap().at(L"SubscribeInteractions")));
        SetModelingStep(node->AsMap().at(L"ModelingStep")->AsInt());
        SetSyncCallbackMode(node->AsMap().at(L"CallbackMode")->AsInt());
        SetModelMode(ModelMode(node->AsMap().at(L"ModelingMode")->AsInt()));
        return *this;
    }

    BaseFederate& BaseFederate::SetSubscribeMapOfObjectsAndAttributes(const NameMap& _map) noexcept{
        _ObjectsNames = _map;
        return *this;
    }

    BaseFederate& BaseFederate::SetSubscribeMapOfObjectsAndAttributes(NameMap&& _map) noexcept{
        _ObjectsNames = move(_map);
        return *this;
    }

    BaseFederate& BaseFederate::SetPublishListOfAttributes(const NameList& attr)  noexcept{
        _AttributeNames = attr;
        return *this;
    }

    BaseFederate& BaseFederate::SetPublishListOfAttributes(NameList &&attr)  noexcept{
        _AttributeNames = move(attr);
        return *this;
    }

    BaseFederate& BaseFederate::SetSubscribeMapOfInteractionsAndParameters(const NameMap& _map)  noexcept{
        _InteractionsNames = _map;
        return *this;
    }

    BaseFederate& BaseFederate::SetSubscribeMapOfInteractionsAndParameters(NameMap&& _map)  noexcept{
        _InteractionsNames = move(_map);
        return *this;
    }


    BaseFederate& BaseFederate::SetPublishMapOfInteractionAndParameters(const NameMap& map) noexcept{
        _MyInteractionsNames = map;
    }

    BaseFederate& BaseFederate::SetPublishMapOfInteractionAndParameters(NameMap&& map) noexcept{
        _MyInteractionsNames = move(map);
    }

    BaseFederate& BaseFederate::SetSyncCallbackMode(bool f)  noexcept{
        if(f && _state < State::STARTED)
            _callback_mode = HLA_EVOKED;
        return *this;
    }

    BaseFederate& BaseFederate::SetModelingStep(int _step)  noexcept{
        _modeling_step = _step;
        return *this;
    }

    BaseFederate& BaseFederate::SetModelMode(ModelMode mode)  noexcept{
        _mode = mode;
        return *this;
    }

    BaseFederate& BaseFederate::SetLogFileName(const std::string& filename) noexcept{
        _log_filename = filename;
        return *this;
    }

    BaseFederate& BaseFederate::SetLogFileName(std::string&& filename) noexcept{
        _log_filename = move(filename);
        return *this;
    }

    void BaseFederate::objectInstanceNameReservationSucceeded(wstring const & name)
    throw (FederateInternalError){
        Logger log(_log_filename);
        log << L"INFO:" << _federate_name << L"Reserved" << name << Logger::Flush();
        _state = State::NAMERESERVED;
    }

    void BaseFederate::objectInstanceNameReservationFailed(const wstring & name)
    throw (FederateInternalError){
        Logger log(_log_filename);
        log << L"ERROR:" << _federate_name << L"Can't Reserved" << name << Logger::Flush();
        _state = State::EXIT;
    }


    void BaseFederate::reflectAttributeValues(ObjectInstanceHandle,
                                              const AttributeHandleValueMap &theAttributeValues,
                                              const VariableLengthData & info,
                                              OrderType ,
                                              TransportationType ,
                                              SupplementalReflectInfo)
    throw (FederateInternalError){
        if(_state >= State::STARTED){
            lock_guard<mutex> guard(_amutex);
            _qAttributes.push({info,theAttributeValues});
        }
    }

    void BaseFederate::receiveInteraction (InteractionClassHandle,
                                     ParameterHandleValueMap const & theParameterValues,
                                     VariableLengthData const & info,
                                     OrderType,
                                     TransportationType,
                                     SupplementalReceiveInfo)
    throw (FederateInternalError){
        if(_state >= State::STARTED){
            lock_guard<mutex> guard(_pmutex);
            _qParameters.push({info,theParameterValues});
        }
    }
}
