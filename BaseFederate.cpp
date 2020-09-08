#include "BaseFederate.hpp"
#include "Logger.hpp"
#include <chrono>


namespace HLA{

    using namespace std;
    using namespace rti1516e;


/**
 * @brief BaseFederate::BaseFederate
 * Default constructor, initialization nothing specific
 */
    BaseFederate::BaseFederate() noexcept{}

/**
* @brief BaseFederate::BaseFederate
* @param name       Name of Federate
* @param type       Type of federate, which match object in FOM
* @param FOMname    Path to FOM file
* @param fname      Name of Federation
* @param ip         IP - address of CRC
* Full-gapes constructor with lvalue, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
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


/**
* @brief BaseFederate::BaseFederate
* @param name       Name of Federate
* @param type       Type of federate, which match object in FOM
* @param FOMname    Path to FOM file
* @param fname      Name of Federation
* @param ip         IP - address of CRC
* Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
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

/**
* @brief BaseFederate::BaseFederate
* @param file JSON file with necessary parameters:
* Name           : Name of Federate
* Type           : Type of federate, which match object in FOM
* FOMpath        : Path to FOM file
* FederationName : Name of Federation
* Address        : IP - address of CRC
* Constructor for JSON file with lvalue reference
*/
    BaseFederate::BaseFederate(const JSON& file) noexcept :
                                          _federate_name(file.GetRoot()->AsMap().at(L"Name")->AsWstring()),
                                          _federate_type(file.GetRoot()->AsMap().at(L"Type")->AsWstring()),
                                          _FOMname(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring()),
                                          _federation_name(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring()),
                                          _host_IP_address(file.GetRoot()->AsMap().at(L"Address")->AsWstring()){}

/**
* @brief BaseFederate::BaseFederate
* @param file JSON file with necessary parameters:
* Name           : Name of Federate
* Type           : Type of federate, which match object in FOM
* FOMpath        : Path to FOM file
* FederationName : Name of Federation
* Address        : IP - address of CRC
* Constructor for JSON file with rvalue reference
*/
    BaseFederate::BaseFederate(JSON&& file) noexcept:
                                          _federate_name(move(file.GetRoot()->AsMap().at(L"Name")->AsWstring())),
                                          _federate_type(move(file.GetRoot()->AsMap().at(L"Type")->AsWstring())),
                                          _FOMname(move(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring())),
                                          _federation_name(move(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring())),
                                          _host_IP_address(move(file.GetRoot()->AsMap().at(L"Address")->AsWstring())){}
/**
* @brief BaseFederate::~BaseFederate
* Destructor of basic federate, which set Federate State to EXIT
*/
    BaseFederate::~BaseFederate(){
        _f_modeling = false;                // Change flag to finish modeling
        if(_mode == ModelMode::THREADING)
            _modeling_thread.join();        // Wait for end of thread
        lock_guard<mutex> guard(_smutex);   // Lock state mutex
        _state = State::EXIT;               // Set federate mutex to EXIT
        Logger log(_log_filename);          // Create log writer
        log << L"INFO:"                     // Write INFO message about disconnect
            << _federate_name
            << L"disconnect from"
            << _host_IP_address
            << Logger::Flush();
    }

/**
* @brief BaseFederate::MakeRTIambassador
* @return std::unique_ptr<rti1516e::RTIambassador>
* Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
*/
    unique_ptr<RTIambassador> BaseFederate::MakeRTIambassador() const &{
        unique_ptr<RTIambassadorFactory> rtiAmbassadorFactory = std::make_unique<RTIambassadorFactory>(); // Create Factory for RTIambassador
        unique_ptr<RTIambassador> _RtiAmbassador(rtiAmbassadorFactory->createRTIambassador());            // Create RTIambassador
        return _RtiAmbassador;
    }

/**
* @brief BaseFederate::ConnectRTI
* Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist) and join there. After that federate initialized in RTI and go to the his main loop. Use only to lvalue class samples
* @return flag of success execution
*/
    bool BaseFederate::ConnectRTI() & {

        Logger log(_log_filename);                // Create log writer
        try{
            _rtiAmbassador = MakeRTIambassador(); // Initialized rtiAmbassador to call RTI servecies (look HLA::MakeRTIambassador)
        }
        catch(RTIinternalError& e){               // Catch RTI runtime error
            log << L"ERROR:"                      // Write ERROR message about runtime error
                << _federate_name
                << L"Can't create RTIambassador"
                << e.what()
                << Logger::Flush();
            return false;
        }

        try{
            if(_host_IP_address == L"localhost")                                               // Check the CRC address
                _rtiAmbassador->connect(*this,_callback_mode);                                 // Using rtiAmbassador connect this federate to RTI from localhost
            else
                _rtiAmbassador->connect(*this,_callback_mode,L"crcAddress="+_host_IP_address); // Using rtiAmbassador connect this federate to RTI from _host_IP_address
        }
        catch(...){                                                                            // Catch some error
            log << L"ERROR:"                                                                   // Write ERROR message about error
                << _federate_name
                << L"Cant connect"
                << Logger::Flush();
            return false;
        }


        try{
            _rtiAmbassador->createFederationExecution(_federation_name, _FOMname); // Try to create federation with name (_federation_name) and rules in FOM (look _FOMname)
        }
        catch(FederationExecutionAlreadyExists&){}                                 // If federation already exist we catch exception(FederationExecutionAlreadyExists) and do nothing

        catch(ErrorReadingFDD& e){                                                 // Catch FOM reading runtime error
            log << L"ERROR:"                                                       // Write ERROR message about FOM reading
                << _federate_name
                << L"Cant read FOM"
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(CouldNotOpenFDD& e ){                                                // Catch FOM opening runtime error
            log << L"ERROR:"                                                       // Write ERROR message about FOM opening
                << _federate_name
                << L"Cant open FOM"
                << e.what()
                << Logger::Flush();
            return false;
        }

        catch(...){                                                                // Catch some error
            log << L"ERROR:"                                                       // Write ERROR message about error
                << _federate_name
                << L"Cant create federation"
                << Logger::Flush();
            return false;
        }

    // This waste 1 seconds, it's the biggest comand in this function (more than 50ths)
        try{
            _rtiAmbassador->joinFederationExecution(_federate_name,_federation_name); // After connect and create/find federation with name (_federation_name) we join to it with name (_federate_name)
            log << L"INFO:"                                                           // Write INFO message about successfully connection
                << L"Connect of"
                << _federate_name
                <<  L"done"
                 << Logger::Flush();
        }
        catch(...){                                                                  // Catch some error
            log << L"ERROR:"                                                         // Write ERROR message about error
                << _federate_name
                << L"Can't join"
                << Logger::Flush();
            return false;
        }

        _state = State::CONNECTED;          // If all connect steps finished we set connect flag to true value

        try{
            Init();                         // Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate

            log << L"INFO:"                 // Write INFO message about successfull join
                << L"Init of"
                << _federate_name
                << L"done"
                << Logger::Flush();
        }
        catch(RTIinternalError& e){         // Catch RTI runtime error
            log << L"ERROR:"                // Write ERROR message about runtime error
                << _federate_name
                << L"Error in Init() with"
                << e.what()
                << Logger::Flush();
            return false;
        }

        try{
            _f_modeling = true;                                                                     // Run the main loop of federate
            if(_mode == ModelMode::THREADING)
                _modeling_thread = std::thread(&BaseFederate::Modeling<ModelMode::THREADING>,this); // Run Modeling Thread
            else if(_mode == ModelMode::FOLLOWING)
                _last_time = chrono::steady_clock::now();// Save last clock time
            else if(_mode == ModelMode::MANAGING){
                //pass
            }
            RunFederate();                                                          // Run the Federate main function (can be empty)
        }
        catch(RTIinternalError& e){                                                 // Catch RTI runtime error
            log << L"ERROR:"                                                        // Write ERROR message about runtime error
                << _federate_name
                << L"Error in Run() with"
                << e.what()
                << Logger::Flush();
            return false;
        }
        return true;
    }

/**
* @brief BaseFederate::operator ()
* @param step Modeling Step in milliseconds
* Operator that run federate with modeling_step in milliseconds = step like functional object
* @return flag of success execution
*/
    bool BaseFederate::operator()(int step) {
        _modeling_step = step; // Set modeling step
        return ConnectRTI();   // Call ConnecrRTI, look at ConnectRTI()
    }

/**
* @brief BaseFederate::Init
* Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate.
*/
    void BaseFederate::Init(){

        unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash> subscribeAttributesSet; // Hash table for subscribe objects and their attributes

        AttributeHandleSet                                                  PublishSet;             // Set for publish attributes

        unordered_set<InteractionClassHandle, InteractionClassHash>         SubscribeInteractionSet;// Set for subscribe interactions

        unordered_set<InteractionClassHandle, InteractionClassHash>         PublishInteractionSet;  // Set for publish interactions

        InitClassesAndAttributes(subscribeAttributesSet, PublishSet);                  // Initializerd federate object and his attributes and environmental objects and attributes indicated in FOM

        SubscribeAttributes(subscribeAttributesSet);                                    // Send to RTI set of attributes which federate want to recive

        PublishAttributes(PublishSet);                                                  // Send to RTI set of attributes which federate publish

        InitInteractionsAndParameters(SubscribeInteractionSet, PublishInteractionSet); // Initializerd Interactions and there parameters indicated in FOM

        SubscribeInteractions(SubscribeInteractionSet);                                 // Send to RTI set of interactions which federate want to recive

        PublishInteractions(PublishInteractionSet);                                     // Send to RTI set of interactions which federate publish

        RegisterName();                                                                  // Register _federate_name in RTI

        _state = State::STARTED;                                                         // Set state flag to started state (ready to do)
    }

/**
* @brief BaseFederate::InitClassesAndAttributes
* @param _subscribeAttributesSet Hash table for subscribe objects and their attributes
* @param _PublishSet Set for publish attributes
* Initializerd federate object and his attributes and environmental objects and attributes indicated in _ObjectNames
*/
    void BaseFederate::InitClassesAndAttributes(unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash>& subscribeAttributesSet,
                                                AttributeHandleSet& PublishSet){

        _MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type); //Initializerd our federate object(_MyClass) from FOM refer to _federate_type

        for(const auto& Attribute:_AttributeNames){

            _AttributesMap[_MyClass][Attribute] = _rtiAmbassador->getAttributeHandle(_MyClass,Attribute); // Set table(_AttributesMap) of this object attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]

            PublishSet.insert(_AttributesMap[_MyClass][Attribute]);                                       // Insert federate attributes to Publish Set(_aPublishSetId)
        }

        for(const auto&Object:_ObjectsNames){ // Initializerd environmental objects and attributes indicated in _ObjectNames and attributes of it federate

            const auto& objectName = Object.first;                                                       // Cache of Object Name

            const auto& objectId =
                    _ObjectClasses[objectName] = _rtiAmbassador->getObjectClassHandle(objectName);       // Set table(_ObjectClasses) of objects like [TypeName, HLAobjectClass(something like link to FOM)] and Cache Object ID

            for(const auto&Attribute:Object.second){

                _AttributesMap[objectId][Attribute] =_rtiAmbassador->getAttributeHandle(objectId,Attribute); // Set table(_AttributesMap) of object's attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]

                subscribeAttributesSet[objectId].insert(_AttributesMap[objectId][Attribute]);                // Insert extern attributes to Subscribe Set(_externAttributeSet)

            }
        }
    }


/**
* @brief BaseFederate::InitInteractionsAndParameters
* @param sub
* @param pub
* Initializerd federate interactions and his parameters and environmental interactions and parameters indicated in _InteractionNames
*/
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
    void BaseFederate::SubscribeInteractions(unordered_set<InteractionClassHandle, InteractionClassHash>& sub){
        for(const auto&x:sub)
        //Send to RTI request to subscribe on Interaction x
        //It get opportunity to recive information about updates of interaction's parameter set in reflectParameterValues
            _rtiAmbassador->subscribeInteractionClass(x);
    }

//Send to RTI set of parameters which federate publish
    void BaseFederate::PublishInteractions(unordered_set<InteractionClassHandle, InteractionClassHash>& pub){
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

    template<>
    void BaseFederate::Modeling<ModelMode::THREADING>(){
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

    template<>
    void BaseFederate::Modeling<ModelMode::FOLLOWING>(){
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

    template<>
    void BaseFederate::Modeling<ModelMode::MANAGING>(){

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
        SetLogFileName(node->AsMap().at(L"LogFileName")->AsString());
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
        SetLogFileName(node->AsMap().at(L"LogFileName")->AsString());
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
