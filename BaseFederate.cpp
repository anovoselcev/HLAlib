//================================================================================================================================================
/*
 * Written by Novoseltsev Artemy
 * This program is free software.
 * This program is distributed in the hope that it will be useful.
*/
//================================================================================================================================================

#include "BaseFederate.hpp"
#include "Tools/Logger.hpp"

#include "RTI/time/HLAfloat64Time.h"


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
        _state = State::EXIT;               // Set federate state to EXIT
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
                _last_time = make_unique<chrono::time_point<chrono::steady_clock>>(chrono::steady_clock::now());                                           // Save last clock time
            else if(_mode == ModelMode::MANAGING){
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

        _MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type);                                   //Initializerd our federate object(_MyClass) from FOM refer to _federate_type

        for(const auto& Attribute:_AttributeNames){

            _AttributesMap[_MyClass][Attribute] = _rtiAmbassador->getAttributeHandle(_MyClass,Attribute); // Set table(_AttributesMap) of this object attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]

            PublishSet.insert(_AttributesMap[_MyClass][Attribute]);                                       // Insert federate attributes to Publish Set(_aPublishSetId)
        }

        for(const auto&Object:_ObjectsNames){                                                            // Initializerd environmental objects and attributes indicated in _ObjectNames and attributes of it federate

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

        sub.reserve(_InteractionsNames.size() + 1);
        pub.reserve(_MyInteractionsNames.size() + 1);

        for(const auto&Interaction:_InteractionsNames){

            auto& interactionName = Interaction.first;                             // Cache of Interaction Name

            auto& interactionId = _InteractionClasses[interactionName]
                    = _rtiAmbassador->getInteractionClassHandle(interactionName);  // Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)] and Cache Interaction ID

            sub.insert(interactionId);                                             // Insert InteractionHandle to subscribe set

            for(const auto&Parameter:Interaction.second)

                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter); // Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
        }
        try{
            _InteractionClasses[L"GO"] = _rtiAmbassador->getInteractionClassHandle(L"GO");
            sub.insert(_InteractionClasses[L"GO"]);
        }
        catch(...){}

        for(const auto&Interaction:_MyInteractionsNames){

            auto& interactionName = Interaction.first;                             // Cache of Interaction Name

            auto& interactionId = _InteractionClasses[interactionName]
                    = _rtiAmbassador->getInteractionClassHandle(interactionName); // Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)] and Cahce InteractionID

            pub.insert(interactionId);                                            // Insert InteractionHandle to publish set

            for(const auto&Parameter:Interaction.second)

                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter); // Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
        }
        try{
            _InteractionClasses[L"READY"] = _rtiAmbassador->getInteractionClassHandle(L"READY");
            pub.insert(_InteractionClasses[L"READY"]);
        }
        catch(...){}
    }

/**
* @brief BaseFederate::SubscribeAttributes
* @param _externAttributesSet
* Call RTI to subscribe on Objects and Attributes from _ObjectNames
*/
    void BaseFederate::SubscribeAttributes(unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash>& _externAttributesSet){
        for(const auto& x:_externAttributesSet)

            _rtiAmbassador->subscribeObjectClassAttributes(x.first,x.second);// Send to RTI request to subscribe on Object(x.first) and his Attribute Set (x.second)
                                                                             // It get opportunity to recive information about updates of object's attribute set in reflectAttributeValues
    }

/**
* @brief BaseFederate::PublishAttributes
* @param _aPublishSet
* Call RTI to publish the _MyClass with attributes from _AttributeNames
*/
    void BaseFederate::PublishAttributes(AttributeHandleSet& _aPublishSet){

        _rtiAmbassador->publishObjectClassAttributes(_MyClass,_aPublishSet);// Send to RTI request to publish attributes (_aPublishSetId) of this federate with object _MyClass
                                                                            // After that federate can provide information about updates of his attributes in RTI using UpdateAttributes
    }

/**
* @brief BaseFederate::SubscribeInteractions
* @param sub
* Call RTI to subscribe on Interactions and Parameters from _MyInteractionsNames
*/
    void BaseFederate::SubscribeInteractions(unordered_set<InteractionClassHandle, InteractionClassHash>& sub){
        for(const auto&x:sub)

            _rtiAmbassador->subscribeInteractionClass(x);// Send to RTI request to subscribe on Interaction x
                                                         // It get opportunity to recive information about updates of interaction's parameter set in reflectParameterValues
    }

/**
* @brief BaseFederate::PublishInteractions
* @param pub
* Call RTI to publish the Interactions and Parameters from _InteractionsNames
*/
    void BaseFederate::PublishInteractions(unordered_set<InteractionClassHandle, InteractionClassHash>& pub){
        for(const auto&x:pub)

            _rtiAmbassador->publishInteractionClass(x);// Send to RTI request to publish parameters (_ParametersMap) of this federate
                                                       // After that federate can provide information about updates of his parameters in RTI using sendInteraction
    }

/**
* @brief BaseFederate::RegisterName
* Call RTI to reserve and register federate name (_federate_name) and init this object as _MyInstanceID
*/
    void BaseFederate::RegisterName(){
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);                                             // Reserve _federate_name in RTI like unique ID
        auto start = chrono::steady_clock::now();                                                              // Start wait timer
        auto dur = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now()-start).count();     // Create time interval
        while(_state!=State::NAMERESERVED || dur<=1000){                                                       // While _federate_name not reserve or time interval less than 1 millsecond
            dur = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now()-start).count(); // Update time interval
        }
          _MyInstanceID = _rtiAmbassador->registerObjectInstance(_MyClass, _federate_name);                    // Get specific ID for federate from RTI
    }

    void BaseFederate::ReadyToGo() const{
        HLAfloat64Time UselessStamp;
        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"READY"), ParameterHandleValueMap(), VariableLengthData(), UselessStamp);
    }

/**
* @brief BaseFederate::RunFederate
* The main loop of federate ( default: empty method without loop)
*/
    void BaseFederate::RunFederate(){}

/**
* @brief BaseFederate::UpdateAttributes
* Update VariableLengthData Map of federate values to RTI, should be override
* Convert data of federate and send map of byte arrays to RTI
*/
    void BaseFederate::UpdateAttributes() const{}

/**
* @brief BaseFederate::SendParameters
* Update VariableLengthData Map of federate interactions to RTI, should be override
* Convert data of federate and send map of byte arrays to RTI
*/
    void BaseFederate::SendParameters() const{}

    template<>
/**
* @brief BaseFederate::Modeling<ModelMode::THREADING>
* Main function of modeling that sleep in sub-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
*/
    void BaseFederate::Modeling<ModelMode::THREADING>(){
        Logger log(_log_filename);                // Create log writer
        while(_f_modeling){                       // while modeling execute
            {
                lock_guard<mutex> guard(_smutex); // Lock state mutex
                _state = State::DOING;            // Change federate state to execute(doing) state without HLA

                log << L"INFO:"                   // Write INFO message about doing part of modeling
                    << _federate_name
                    << L"Begin of threading modeling step - doing"
                    << Logger::Flush();
            }
            _cond.notify_one();                                           // Notify conditional variable in ModelGuard
            this_thread::sleep_for(chrono::milliseconds(_modeling_step)); // Sleep for modeling step

            log << L"INFO:"                                               // Write INFO message about proccessing part of modeling
                << _federate_name
                << L"End of threading modeling step - proccessing"
                << Logger::Flush();

            UpdateAttributes();                                            // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
            thread ParametersThread(&BaseFederate::ParameterProcess,this); // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
            ParametersThread.detach();
            AttributeProcess();                                            // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
        }
    }

    template<>
/**
* @brief BaseFederate::Modeling<ModelMode::FOLLOWING>
* Main function of modeling that sleep in call-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
*/
    void BaseFederate::Modeling<ModelMode::FOLLOWING>(){
        Logger log(_log_filename);                                                                       // Create log writer
        auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - *_last_time);  // Create time interval
        auto step = chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(_modeling_step));   // Convert modeling step to time interval
        if((step - dur).count()>0)                                                                       // If dur less than modeling step
            this_thread::sleep_for(chrono::milliseconds(step - dur));                                    // Sleep for difference betwen step and dur

        log << L"INFO:"                                                 // Write INFO message about proccessing part of modeling
            << _federate_name
            << L"End of following modeling step - proccessing"
            << Logger::Flush();

        UpdateAttributes();                                            // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
        ParameterProcess();                                            // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
        AttributeProcess();                                            // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
        _state = State::DOING;                                         // Change federate state to execute(doing) state without HLA

        log << L"INFO:"                                                // Write INFO message about doing part of modeling
            << _federate_name
            << L"Begin of following modeling step - doing"
            << Logger::Flush();
    }

    template<>
/**
* @brief BaseFederate::Modeling<ModelMode::MANAGING>
*/
    void BaseFederate::Modeling<ModelMode::MANAGING>(){
       Logger log(_log_filename);                                     // Create log writer
       UpdateAttributes();                                            // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
       thread ParametersThread(&BaseFederate::ParameterProcess,this); // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
       ParametersThread.detach();
       AttributeProcess();                                            // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
       lock_guard<mutex> guard(_smutex);
       _state = State::DOING;
    }

/**
* @brief BaseFederate::AttributeProcess
* Function that process queue of reflected attributes step by step in time order, should be override
*/
    void BaseFederate::AttributeProcess(){
        lock_guard<mutex> guard(_amutex);           // Lock queue of recived attributes
        while(!_qAttributes.empty()){               // If queue isn't empty
            auto& message = _qAttributes.front();   // Take first message in queue
            //...some processing
            _qAttributes.pop();                     // Delete first message in queue
        }
    }

/**
* @brief BaseFederate::ParameterProcess
* Function that process queue of recived parameters of interactions step by step in time order, should be override
*/
    void BaseFederate::ParameterProcess(){
        lock_guard<mutex> guard(_pmutex);           // Lock queue of recived interactions
        while(!_qParameters.empty()){               // If queue isn't empty
            auto& message = _qParameters.front();   // Take first message in queue
            //...some processing
            _qParameters.pop();                     // Delete first message in queue
        }
    }

/**
* @brief BaseFederate::GetName
* Return name of Federate
* @return std::wstring
*/
    const wstring BaseFederate::GetName() const noexcept {return _federate_name;}

/**
* @brief BaseFederate::GetType
* Return type of Federate, which match object in FOM
* @return std::wstring
*/
    const wstring BaseFederate::GetType() const noexcept {return _federate_type;}

/**
* @brief BaseFederate::GetFederation
* Return name of Federation
* @return std::wstring
*/
    const wstring BaseFederate::GetFederation() const noexcept{return _federation_name;}   

/**
* @brief BaseFederate::GetFOMpath
* Return Path to FOM
* @return std::wstring
*/
    const wstring BaseFederate::GetFOMpath() const noexcept{return _FOMname;}

/**
* @brief BaseFederate::GetIP
* return IP - address of CRC
* @return std::wstring
*/
    const wstring BaseFederate::GetIP() const noexcept{return _host_IP_address;}

/**
* @brief BaseFederate::GetCallbackMode
* Return current Callback mode :
* HLA_IMMEDIATE : Asynchronous Mode
* HLA_EVOKED    : Synchronous Mode, requires requests to RTI for every call
* @return rti1516e::CallbackModel
*/
    CallbackModel BaseFederate::GetCallbackMode() const noexcept{return _callback_mode;}

/**
* @brief BaseFederate::GetModelMode
* Return current Federate Mode
* @return ModelMode
*/
    ModelMode BaseFederate::GetModelMode() const noexcept {return _mode;}

/**
* @brief BaseFederate::GetState
* Return current Federate State
* @return State
*/
    State BaseFederate::GetState() const noexcept {return _state;}

/**
* @brief BaseFederate::LoadSOMFromJSON
* @param file file JSON file with necessary parameters:
* ModelingStep          : Step of Modeling in milliseconds
* CallbackMode          : Asynchronous/Synchronous mode match 0/1
* ModelingMode          : Modeling Mode parameter, look ModelMode enumeration class
* LogFileName           : Name of file for log info
* PublishAttributes     : List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* SubscribeAttributes   : Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* PublishInteractions   : Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* SubscribeInteractions : Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Method for JSON file with lvalue reference
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::LoadSOMFromJSON(const JSON& file){
        const auto node         = file.GetRoot()->AsMap();                                         // Open the main node of file like hash map
        SetPublishListOfAttributes                (JSON::ToVector(node.at(L"PublishAttributes"))); // Read list of publish attributes
        SetSubscribeMapOfObjectsAndAttributes     (JSON::ToMap(node.at(L"SubscribeAttributes")));  // Read hash map of subscribe attributes
        SetPublishMapOfInteractionAndParameters   (JSON::ToMap(node.at(L"PublishInteractions")));  // Read hash map of publish interactions
        SetSubscribeMapOfInteractionsAndParameters(JSON::ToMap(node.at(L"SubscribeInteractions")));// Read hash map of subscribe interactions
        SetModelingStep(node.at(L"ModelingStep")->AsInt());                                        // Read modeling step
        SetSyncCallbackMode(node.at(L"CallbackMode")->AsInt());                                    // Read callback mode
        SetModelMode(ModelMode(node.at(L"ModelingMode")->AsInt()));                                // Read modeling mode
        SetLogFileName(node.at(L"LogFileName")->AsString());                                       // Read filename of log file
        return *this;
    }

/**
* @brief BaseFederate::LoadSOMFromJSON
* @param file file JSON file with necessary parameters:
* ModelingStep          : Step of Modeling in milliseconds
* CallbackMode          : Asynchronous/Synchronous mode match 0/1
* ModelingMode          : Modeling Mode parameter, look ModelMode enumeration class
* LogFileName           : Name of file for log info
* PublishAttributes     : List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* SubscribeAttributes   : Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* PublishInteractions   : Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* SubscribeInteractions : Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Method for JSON file with rvalue reference
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::LoadSOMFromJSON(JSON&& file){
        const auto node         = file.GetRoot()->AsMap();                                         // Open the main node of file like hash map
        SetPublishListOfAttributes                (JSON::ToVector(node.at(L"PublishAttributes"))); // Read list of publish attributes
        SetSubscribeMapOfObjectsAndAttributes     (JSON::ToMap(node.at(L"SubscribeAttributes")));  // Read hash map of subscribe attributes
        SetPublishMapOfInteractionAndParameters   (JSON::ToMap(node.at(L"PublishInteractions")));  // Read hash map of publish interactions
        SetSubscribeMapOfInteractionsAndParameters(JSON::ToMap(node.at(L"SubscribeInteractions")));// Read hash map of subscribe interactions
        SetModelingStep(node.at(L"ModelingStep")->AsInt());                                        // Read modeling step
        SetSyncCallbackMode(node.at(L"CallbackMode")->AsInt());                                    // Read callback mode
        SetModelMode(ModelMode(node.at(L"ModelingMode")->AsInt()));                                // Read modeling mode
        SetLogFileName(node.at(L"LogFileName")->AsString());                                       // Read filename of log file
        return *this;
    }

/**
* @brief BaseFederate::SetSubscribeMapOfObjectsAndAttributes
* @param _map Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* Set map of Objects and Attribute, which federate subscribe (lvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSubscribeMapOfObjectsAndAttributes(const NameMap& _map) noexcept{
        _ObjectsNames = _map;
        return *this;
    }

/**
* @brief BaseFederate::SetSubscribeMapOfObjectsAndAttributes
* @param _map Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* Set map of Objects and Attribute, which federate subscribe (rvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSubscribeMapOfObjectsAndAttributes(NameMap&& _map) noexcept{
        _ObjectsNames = move(_map);
        return *this;
    }

/**
* @brief BaseFederate::SetPublishListOfAttributes
* @param attribute_list List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* Set list of Attributes, which federate publish (lvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetPublishListOfAttributes(const NameList& attr)  noexcept{
        _AttributeNames = attr;
        return *this;
    }

/**
* @brief BaseFederate::SetPublishListOfAttributes
* @param attribute_list List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* Set list of Attributes, which federate publish (rvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetPublishListOfAttributes(NameList &&attr)  noexcept{
        _AttributeNames = move(attr);
        return *this;
    }

/**
* @brief BaseFederate::SetSubscribeMapOfInteractionsAndParameters
* @param _map Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want subscribe (lvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSubscribeMapOfInteractionsAndParameters(const NameMap& _map)  noexcept{
        _InteractionsNames = _map;
        return *this;
    }

/**
* @brief BaseFederate::SetSubscribeMapOfInteractionsAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want subscribe (rvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSubscribeMapOfInteractionsAndParameters(NameMap&& _map)  noexcept{
        _InteractionsNames = move(_map);
        return *this;
    }

/**
* @brief BaseFederate::SetPublishMapOfInteractionAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want publish (lvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetPublishMapOfInteractionAndParameters(const NameMap& map) noexcept{
        _MyInteractionsNames = map;
        return *this;
    }

/**
* @brief BaseFederate::SetPublishMapOfInteractionAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want publish (rvalue version)
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetPublishMapOfInteractionAndParameters(NameMap&& map) noexcept{
        _MyInteractionsNames = move(map);
        return *this;
    }

/**
* @brief BaseFederate::SetSyncCallbackMode
* @param f Boolean value for setup Synchronous mode
* Change Callback mode to Synchronize if is_sync = true, default Asynchronize
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSyncCallbackMode(bool f)  noexcept{
        if(f && _state < State::STARTED) // If federate not started and setup sync mode
            _callback_mode = HLA_EVOKED; // Change callback mode to sync
        return *this;
    }

/**
* @brief BaseFederate::SetModelingStep
* @param step in milliseconds
* Setup Federate Modeling step (_step) to step value
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetModelingStep(int _step)  noexcept{
        _modeling_step = _step;
        return *this;
    }

/**
* @brief BaseFederate::SetModelMode
* @param mode Value of Model Mode
* Setup Modeling Mode parameter, look ModelMode enumeration class
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetModelMode(ModelMode mode)  noexcept{
        _mode = mode;
        return *this;
    }

/**
* @brief BaseFederate::SetLogFileName
* @param log_filename FileName of log-file
* Setup Log FileName
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetLogFileName(const std::string& filename) noexcept{
        _log_filename = filename;
        return *this;
    }

/**
* @brief BaseFederate::SetLogFileName
* @param log_filename FileName of log-file
* Setup Log FileName
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetLogFileName(std::string&& filename) noexcept{
        _log_filename = move(filename);
        return *this;
    }

/**
* @brief BaseFederate::objectInstanceNameReservationSucceeded
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is successful
*/
    void BaseFederate::objectInstanceNameReservationSucceeded(wstring const & name)
    throw (FederateInternalError){
        Logger log(_log_filename); // Create log writer

        log << L"INFO:"            // Write INFO message about proccessing part of modeling
            << _federate_name
            << L"Reserved"
            << name
            << Logger::Flush();

        _state = State::NAMERESERVED; // Change federate state to name reservation successfuly
    }

/**
* @brief BaseFederate::objectInstanceNameReservationFailed
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is failed
*/
    void BaseFederate::objectInstanceNameReservationFailed(const wstring & name)
    throw (FederateInternalError){
        Logger log(_log_filename); // Create log writer

        log << L"ERROR:"          // Write ERROR message about name reservation failed
            << _federate_name
            << L"Can't Reserved"
            << name
            << Logger::Flush();

        _state = State::EXIT;   // Change federate state to exit
    }


/**
* @brief BaseFederate::reflectAttributeValues
* @param theObject          : Instanse Handle of Federate sender (something like id)
* @param theAttributeValues : Map of VariableLengthData (byte arrays)
* @param info : Mark of message
* Callback function from RTI. Call when subscribed federate update his attributes.
* Info of reflected attributes in theUserSuppliedTag
* Data of reflected attributes in theAttributeValues
*/
    void BaseFederate::reflectAttributeValues(ObjectInstanceHandle,
                                              const AttributeHandleValueMap &theAttributeValues,
                                              const VariableLengthData & info,
                                              OrderType ,
                                              TransportationType ,
                                              SupplementalReflectInfo)
    throw (FederateInternalError){
        if(_state >= State::STARTED){                       // If federate start modeling
            lock_guard<mutex> guard(_amutex);               // Lock queue of reflected attributes
            _qAttributes.push({info,theAttributeValues});   // Add new message {information or tag in byte array, map of attributes}
        }
    }

/**
* @brief BaseFederate::receiveInteraction
* @param theInteraction     : Handle of received interaction
* @param theParameterValues : Map of VariableLengthData (byte arrays)
* @param info : Mark of message
* Callback function from RTI. Call when subscribed interation with his parameters sends.
* Info of recived interaction in theUserSuppliedTag
* Data of recived interaction in theParameterValues
*/
    void BaseFederate::receiveInteraction (InteractionClassHandle,
                                     ParameterHandleValueMap const & theParameterValues,
                                     VariableLengthData const & info,
                                     OrderType,
                                     TransportationType,
                                     SupplementalReceiveInfo)
    throw (FederateInternalError){
        if(_state >= State::STARTED){                       // If federate start modeling
            lock_guard<mutex> guard(_pmutex);               // Lock queue of recived interactions
            _qParameters.push({info,theParameterValues});   // Add new message {information or tag in byte array, map of interactions}
        }
    }

    void BaseFederate::receiveInteraction (InteractionClassHandle theInteraction,
                                           ParameterHandleValueMap const & ,
                                           VariableLengthData const & ,
                                           OrderType ,
                                           TransportationType ,
                                           LogicalTime const & ,
                                           OrderType ,
                                           SupplementalReceiveInfo )
    throw (FederateInternalError){
        if(theInteraction == _InteractionClasses[L"GO"] && _state >= State::STARTED){
            lock_guard<mutex> guard(_smutex);
            _state = State::PROCESSING;
            _cond.notify_one();
        }
    }

/**
* @brief BaseFederate::ObjectClassHash::operator ()
* @param _Object
* Hash for Object Class, it necessary for hash structures
* @return
*/
    size_t BaseFederate::ObjectClassHash::operator()(const ObjectClassHandle& _Object) const noexcept{
        return static_cast<size_t>(_Object.hash());
    }

/**
* @brief BaseFederate::InteractionClassHash::operator ()
* @param _Interaction
* Hash for Interaction Class, it necessary for hash structures
* @return
*/
    size_t BaseFederate::InteractionClassHash::operator()(const rti1516e::InteractionClassHandle &_Interaction) const noexcept{
        return static_cast<size_t>(_Interaction.hash());
    }
}
