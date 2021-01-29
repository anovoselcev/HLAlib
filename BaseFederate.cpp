#include "BaseFederate.hpp"

#include "RTI/time/HLAfloat64Time.h"
#ifndef WIN32
    #include "3dparty/tbb/include/linux/tbb/parallel_invoke.h"
    #include "3dparty/tbb/include/linux/tbb/parallel_for_each.h"

#else
    #include "3dparty/tbb/include/windows/oneapi/tbb/parallel_invoke.h"
    #include "3dparty/tbb/include/windows/oneapi/tbb/parallel_for_each.h"
#endif

namespace HLA{

/**
* @brief logger
* Logger - Singlton for log inforamtion about connection, initialization and execution
*/
    std::unique_ptr<Logger> logger;

    using namespace std;
    using namespace rti1516e;


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
* LogFileName    : Prefix for log - file
* Constructor for JSON file with lvalue reference
*/
    BaseFederate::BaseFederate(const JSON& file) noexcept :
                                          _federate_name(file.GetRoot()->AsMap().at(L"Name")->AsWstring()),
                                          _federate_type(file.GetRoot()->AsMap().at(L"Type")->AsWstring()),
                                          _FOMname(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring()),
                                          _federation_name(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring()),
                                          _host_IP_address(file.GetRoot()->AsMap().at(L"Address")->AsWstring()){

        const std::wstring logfilename = file.GetRoot()->AsMap().at(L"LogFileName")->AsWstring(); // Read prefix for log from JSON
        logger = make_unique<Logger>(logfilename, _federate_name);                                // Create Logger
    }

/**
* @brief BaseFederate::BaseFederate
* @param file JSON file with necessary parameters:
* Name           : Name of Federate
* Type           : Type of federate, which match object in FOM
* FOMpath        : Path to FOM file
* FederationName : Name of Federation
* Address        : IP - address of CRC
* LogFileName    : Prefix for log - file
* Constructor for JSON file with rvalue reference
*/
    BaseFederate::BaseFederate(JSON&& file) noexcept:
                                          _federate_name(move(file.GetRoot()->AsMap().at(L"Name")->AsWstring())),
                                          _federate_type(move(file.GetRoot()->AsMap().at(L"Type")->AsWstring())),
                                          _FOMname(move(file.GetRoot()->AsMap().at(L"FOMpath")->AsWstring())),
                                          _federation_name(move(file.GetRoot()->AsMap().at(L"FederationName")->AsWstring())),
                                          _host_IP_address(move(file.GetRoot()->AsMap().at(L"Address")->AsWstring())){

        const std::wstring logfilename = file.GetRoot()->AsMap().at(L"LogFileName")->AsWstring(); // Read prefix for log from JSON
        logger = make_unique<Logger>(logfilename, _federate_name);                                // Create Logger
    }
/**
* @brief BaseFederate::~BaseFederate
* Destructor of basic federate, which set Federate State to EXIT
*/
    BaseFederate::~BaseFederate(){

        _f_modeling = false;                // Change flag to finish modeling

        if(_mode == MODELMODE::MANAGING_THREADING && _state >= STATE::CONNECTED)
            _condition.notify_one();

        if((_mode == MODELMODE::FREE_THREADING || _mode == MODELMODE::MANAGING_THREADING) && _state >= STATE::CONNECTED)
            _modeling_thread.join();        // Wait for end of thread

        lock_guard<mutex> guard(_smutex);   // Lock state mutex
        _state = STATE::EXIT;               // Set federate state to EXIT

        *logger << Logger::MSG::INFO        // Write INFO message about disconnect
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
    bool BaseFederate::ConnectRTI(const JSON& file) & {

        LoadSOMFromJSON(file);                     // Read additional information from JSON

        try{
            _rtiAmbassador = MakeRTIambassador(); // Initialized rtiAmbassador to call RTI servecies (look HLA::MakeRTIambassador)
        }
        catch(RTIinternalError& e){               // Catch RTI runtime error

            *logger << Logger::MSG::ERRORR        // Write ERROR message about runtime error
                << _federate_name
                << L"Can't create RTIambassador"
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(...){

            *logger << Logger::MSG::ERRORR        // Write ERROR message about runtime error
                << _federate_name
                << L"Can't create RTIambassador"
                << Logger::Flush();
            return false;
        }

        try{
            if(_host_IP_address == L"localhost")                                               // Check the CRC address
                _rtiAmbassador->connect(*this, _callback_mode);                                 // Using rtiAmbassador connect this federate to RTI from localhost
            else
                _rtiAmbassador->connect(*this, _callback_mode, L"crcAddress=" + _host_IP_address); // Using rtiAmbassador connect this federate to RTI from _host_IP_address
        }
        catch(...){                                                                            // Catch some error

            *logger << Logger::MSG::ERRORR                                                     // Write ERROR message about error
                << _federate_name
                << L"Cant connect"
                << Logger::Flush();
            return false;
        }

        try{
            _rtiAmbassador->createFederationExecution(_federation_name, _FOMname); // Try to create federation with name (_federation_name) and rules in FOM (look _FOMname)
        }
        catch(FederationExecutionAlreadyExists&){}                                 // If federation already exist we catch exception(FederationExecutionAlreadyExists) and do nothing

        catch(ErrorReadingFDD& e){          // Catch FOM reading runtime error

            *logger << Logger::MSG::ERRORR  // Write ERROR message about FOM reading
                << _federate_name
                << L"Cant read FOM"
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(CouldNotOpenFDD& e){          // Catch FOM opening runtime error

            *logger << Logger::MSG::ERRORR  // Write ERROR message about FOM opening
                << _federate_name
                << L"Cant open FOM"
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(...){                          // Catch some error

            *logger << Logger::MSG::ERRORR   // Write ERROR message about error
                << _federate_name
                << L"Cant create federation"
                << Logger::Flush();
            return false;
        }
        // This waste 1 seconds, it's the biggest comand in this function (more than 50ths)
        try{
            _rtiAmbassador->joinFederationExecution(_federate_name, _federate_type, _federation_name); // After connect and create/find federation with name (_federation_name) we join to it with name (_federate_name)

            *logger << Logger::MSG::INFO                                                               // Write INFO message about successfully connection
                << L"Connect of"
                << _federate_name
                <<  L"done"
                 << Logger::Flush();
        }
        catch(...){                           // Catch some error

            *logger << Logger::MSG::ERRORR    // Write ERROR message about error
                << _federate_name
                << L"Can't join"
                << Logger::Flush();
            return false;
        }

        _state = STATE::CONNECTED;          // If all connect steps finished we set connect flag to true value

        try{
            Init(file);                     // Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate

            *logger << Logger::MSG::INFO    // Write INFO message about successfull join
                << L"Init of"
                << _federate_name
                << L"done"
                << Logger::Flush();
        }
        catch(RTIinternalError& e){         // Catch RTI runtime error

            *logger << Logger::MSG::ERRORR  // Write ERROR message about runtime error
                << _federate_name
                << L"Error in Init() with"
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(NameNotFound& e){                          // Catch RTI NamedNotFound error
            *logger << Logger::MSG::ERRORR               // Write ERROR message about NamedNotFound error
                << _federate_name
                << L"In Init() Name Not Found with "
                << e.what()
                << Logger::Flush();
            return false;
        }
        catch(std::exception& e){                        // Catch RTI runtime error
            std::string str = e.what();
            std::wstring wstr;
            wstr.assign(str.begin(), str.end());
            *logger << Logger::MSG::ERRORR               // Write ERROR message about error
                << _federate_name
                << L"Error in Init() with "
                << wstr
                << Logger::Flush();
            return false;
        }
        catch(...){
            *logger << Logger::MSG::ERRORR              // Write ERROR message about error
                << _federate_name
                << L"Can't Init"
                << Logger::Flush();
            return false;
        }

        try{
            _f_modeling = true;                        // Run the main loop of federate
            if(_mode == MODELMODE::FREE_THREADING)
                _modeling_thread = std::thread(&BaseFederate::Modeling<MODELMODE::FREE_THREADING>,this); // Run Modeling Thread
            else if(_mode == MODELMODE::FREE_FOLLOWING)
                _last_time = chrono::time_point<chrono::steady_clock>(chrono::steady_clock::now());      // Save last clock time
            else if(_mode == MODELMODE::MANAGING_THREADING){
                _modeling_thread = std::thread(&BaseFederate::Modeling<MODELMODE::MANAGING_THREADING>, this);
            }

            RunFederate();                 // Run the Federate main function (can be empty)
        }

        catch(RTIinternalError& e){        // Catch RTI runtime error
            *logger << Logger::MSG::ERRORR // Write ERROR message about runtime error
                << _federate_name
                << L"Error in Run() with"
                << e.what()
                << Logger::Flush();
            return false;
        }

        catch(...){
            *logger << Logger::MSG::ERRORR // Write ERROR message about runtime error
                << _federate_name
                << L"Error in Run() with"
                << Logger::Flush();
            return false;
        }

        return true;
    }

/**
* @brief BaseFederate::isActive
* Method notifying about the status of the federate
* @return flag of active execution
*/
    bool BaseFederate::isActive() const & noexcept{
        std::lock_guard<std::mutex> guard(_smutex);       // Lock federate state
        return _state >= STATE::CONNECTED && _f_modeling;
    }

/**
* @brief BaseFederate::operator ()
* @param step Modeling Step in milliseconds
* Operator that run federate with modeling_step in milliseconds = step like functional object
* @return flag of success execution
*/
    bool BaseFederate::operator()(const JSON& file) {
        return ConnectRTI(file);   // Call ConnecrRTI, look at ConnectRTI()
    }

/**
* @brief BaseFederate::Init
* Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate.
*/
    void BaseFederate::Init(const JSON& file){

        unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash> subscribeAttributesSet; // Hash table for subscribe objects and their attributes

        AttributeHandleSet                                                  PublishSet;             // Set for publish attributes

        unordered_set<InteractionClassHandle, InteractionClassHash>         SubscribeInteractionSet;// Set for subscribe interactions

        unordered_set<InteractionClassHandle, InteractionClassHash>         PublishInteractionSet;  // Set for publish interactions

        const auto& node = file.GetRoot()->AsMap(); // Open JSON - file root

        NameList AttributeNames;           // List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})

        NameMap ObjectsNames,              // Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
                MyInteractionsNames,       // Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
                InteractionsNames;         // Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})

        tbb::parallel_invoke(
                    // Read list of attributes for publish
                    [&node, &AttributeNames](){
                       AttributeNames = JSON::ToVector(node.at(L"PublishAttributes"));
                    },
                    // Read hash-map of objects and their attributes for subscribe
                    [&node, &ObjectsNames](){
                       ObjectsNames = JSON::ToMap(node.at(L"SubscribeAttributes"));
                    },
                    // Read hash-map of interactions and their parameters for publish
                    [&node, &MyInteractionsNames](){
                        MyInteractionsNames = JSON::ToMap(node.at(L"PublishInteractions"));
                    },
                    // Read hash-map of interactions and their parameters for subscribe
                    [&node, &InteractionsNames](){
                        InteractionsNames = JSON::ToMap(node.at(L"SubscribeInteractions"));
                }
        );


        tbb::parallel_invoke(
                    // Initializerd federate object and his attributes and environmental objects and attributes indicated in FOM
                    [this, &AttributeNames, &ObjectsNames, &subscribeAttributesSet, &PublishSet](){
                        this->InitClassesAndAttributes(AttributeNames, ObjectsNames, subscribeAttributesSet, PublishSet);
                    },
                    // Initializerd Interactions and there parameters indicated in FOM
                    [this, &InteractionsNames, &MyInteractionsNames, &SubscribeInteractionSet, &PublishInteractionSet](){
                        this->InitInteractionsAndParameters(InteractionsNames, MyInteractionsNames, SubscribeInteractionSet, PublishInteractionSet);
                    }
        );


        tbb::parallel_invoke(
                    // Send to RTI set of attributes which federate want to recive
                    [this, &subscribeAttributesSet](){
                        this->SubscribeAttributes(subscribeAttributesSet);
                    },
                    // Send to RTI set of attributes which federate publish
                    [this, &PublishSet](){
                        this->PublishAttributes(PublishSet);
                    },
                    // Send to RTI set of interactions which federate want to recive
                    [this, &SubscribeInteractionSet](){
                        this->SubscribeInteractions(SubscribeInteractionSet);
                    },
                    // Send to RTI set of interactions which federate publish
                    [this, &PublishInteractionSet](){
                        this->PublishInteractions(PublishInteractionSet);
                     }
        );


        RegisterName(); // Register _federate_name in RTI

        _state = STATE::STARTED; // Set state flag to started state (ready to do)
    }


/**
* @brief BaseFederate::InitClassesAndAttributes
* @param AttributeNames          : List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* @param ObjectsNames            : Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* @param _subscribeAttributesSet : Hash table for subscribe objects and their attributes in handle representation
* @param _PublishSet             : Set for publish attributes in handle representation
* Initializerd federate object and his attributes and environmental objects and attributes indicated in _ObjectNames
*/
    void BaseFederate::InitClassesAndAttributes(const NameList& AttributeNames,
                                                const NameMap& ObjectsNames,
                                                unordered_map<ObjectClassHandle, AttributeHandleSet, ObjectClassHash>& subscribeAttributesSet,
                                                AttributeHandleSet& PublishSet){

       _MyClass = _rtiAmbassador->getObjectClassHandle(_federate_type);                                   //Initializerd our federate object(_MyClass) from FOM refer to _federate_type

        for(const auto& Attribute:AttributeNames){

            _AttributesMap[_MyClass][Attribute] = _rtiAmbassador->getAttributeHandle(_MyClass,Attribute); // Set table(_AttributesMap) of this object attributes like [HLAobjectClass(something like link to FOM), [AttributeName, HLAattribute(something like a link to FOM]]

            PublishSet.insert(_AttributesMap[_MyClass][Attribute]);                                       // Insert federate attributes to Publish Set(_aPublishSetId)
        }


        for(const auto&Object:ObjectsNames){                                                            // Initializerd environmental objects and attributes indicated in _ObjectNames and attributes of it federate

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
* @param InteractionsNames   : Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* @param MyInteractionsNames : Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* @param sub                 : Hash table for subscribe interactions and their parameters in handle representation
* @param pub                 : Hash table for publish interactions and their parameters in handle representation
* Initializerd federate interactions and his parameters and environmental interactions and parameters indicated in _InteractionNames
*/
    void BaseFederate::InitInteractionsAndParameters(const NameMap& InteractionsNames,
                                                     const NameMap& MyInteractionsNames,
                                                     unordered_set<InteractionClassHandle, InteractionClassHash>& sub,
                                                     unordered_set<InteractionClassHandle, InteractionClassHash>& pub){

        sub.reserve(InteractionsNames.size() + 1);      // Firstly reserve nessesary size
        pub.reserve(MyInteractionsNames.size() + 1);

        for(const auto&Interaction:InteractionsNames){

            auto& interactionName = Interaction.first;                             // Cache of Interaction Name

            auto& interactionId = _InteractionClasses[interactionName]
                    = _rtiAmbassador->getInteractionClassHandle(interactionName);  // Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)] and Cache Interaction ID

            sub.insert(interactionId);                                             // Insert InteractionHandle to subscribe set

            for(const auto&Parameter:Interaction.second)

                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter); // Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
        }



        for(const auto&Interaction:MyInteractionsNames){

            auto& interactionName = Interaction.first;                             // Cache of Interaction Name

            auto& interactionId = _InteractionClasses[interactionName]
                    = _rtiAmbassador->getInteractionClassHandle(interactionName); // Set table(_InteractionClasses) of interactions like [InteractionTypeName, HLAInteractionClass(something like link to FOM)] and Cahce InteractionID

            pub.insert(interactionId);                                            // Insert InteractionHandle to publish set

            for(const auto&Parameter:Interaction.second)

                _ParametersMap[interactionId][Parameter] =_rtiAmbassador->getParameterHandle(interactionId,Parameter); // Set table(_ParametersMap) of interaction's parameters like [HLAInteractionClass(something like link to FOM), [ParametersName, HLAparameter(something like a link to FOM]]
        }

        try{
            // If federate was a slave-federate
            if(_mode >= MODELMODE::MANAGING_FOLLOWING){
                _InteractionClasses[L"GO"] = _rtiAmbassador->getInteractionClassHandle(L"GO"); // Federate want to recive GO
                sub.insert(_InteractionClasses[L"GO"]);
                _InteractionClasses[L"READY"] = _rtiAmbassador->getInteractionClassHandle(L"READY"); // Federate want to send READY
                pub.insert(_InteractionClasses[L"READY"]);
            }
            // If federate was a master-federate
            else{
                _InteractionClasses[L"READY"] = _rtiAmbassador->getInteractionClassHandle(L"READY"); // Federate want to recive READY
                sub.insert(_InteractionClasses[L"READY"]);
                _InteractionClasses[L"GO"] = _rtiAmbassador->getInteractionClassHandle(L"GO");  // Federate want to send GO
                pub.insert(_InteractionClasses[L"GO"]);
            }
        }
        catch(...){} // If all federates are masters and it is not nessesary to send GO and recive READY

    }

/**
* @brief BaseFederate::SubscribeAttributes
* @param _externAttributesSet : Hash Map of objects and their attributes handles, which federate want to subscribe ({{"HandleObj1", {"AttributeHandle1", "AttributeHandle2",....}}....})
* Call RTI to subscribe on Objects and Attributes from _ObjectNames
*/
    void BaseFederate::SubscribeAttributes(const unordered_map<ObjectClassHandle,AttributeHandleSet,ObjectClassHash>& _externAttributesSet) const{

        tbb::parallel_for_each(_externAttributesSet,[this](const auto& value){          // Send to RTI request to subscribe on Object(x.first) and his Attribute Set (x.second)
            _rtiAmbassador->subscribeObjectClassAttributes(value.first, value.second);  // It get opportunity to recive information about updates of object's attribute set in reflectAttributeValues
        });
    }

/**
* @brief BaseFederate::PublishAttributes
* @param _aPublishSet : List of attributes handles, which federate want to publish ({"AttributeHandle1", "AttributeHandle2",....})
* Call RTI to publish the _MyClass with attributes from _AttributeNames
*/
    void BaseFederate::PublishAttributes(const AttributeHandleSet& _aPublishSet) const{

        _rtiAmbassador->publishObjectClassAttributes(_MyClass, _aPublishSet);// Send to RTI request to publish attributes (_aPublishSetId) of this federate with object _MyClass
                                                                             // After that federate can provide information about updates of his attributes in RTI using UpdateAttributes
    }

/**
* @brief BaseFederate::SubscribeInteractions
* @param sub : Hash Map of interactions and their parameters handles , which federate want to subscribe ({{"InteractionHandle1", {"ParameterHandle1", "ParameterHandle2",....}}....})
* Call RTI to subscribe on Interactions and Parameters from _MyInteractionsNames
*/
    void BaseFederate::SubscribeInteractions(const unordered_set<InteractionClassHandle, InteractionClassHash>& sub) const{

        tbb::parallel_for_each(sub, [this](const auto& value){ // Send to RTI request to subscribe on Interaction value
            _rtiAmbassador->subscribeInteractionClass(value);  // It get opportunity to recive information about updates of interaction's parameter set in reciveInteraction
        });
    }

/**
* @brief BaseFederate::PublishInteractions
* @param pub : Hash Map of interactions and their parameters handles, which federate want to publish ({{"InteractionHandle1", {"ParameterHandle1", "ParameterHandle2",....}}....})
* Call RTI to publish the Interactions and Parameters from _InteractionsNames
*/
    void BaseFederate::PublishInteractions(const unordered_set<InteractionClassHandle, InteractionClassHash>& pub) const{

        tbb::parallel_for_each(pub, [this](const auto& value){ // Send to RTI request to publish parameters (_ParametersMap) of this federate
             _rtiAmbassador->publishInteractionClass(value);   // After that federate can provide information about updates of his parameters in RTI using sendInteraction
        });
    }

/**
* @brief BaseFederate::RegisterName
* Call RTI to reserve and register federate name (_federate_name) and init this object as _MyInstanceID
*/
    void BaseFederate::RegisterName(){
        _rtiAmbassador->reserveObjectInstanceName(_federate_name);                                             // Reserve _federate_name in RTI like unique ID
        auto start = chrono::steady_clock::now();                                                              // Start wait timer
        auto dur = chrono::duration_cast<chrono::microseconds>(chrono::steady_clock::now() - start).count();     // Create time interval
        while(_state!=STATE::NAMERESERVED || dur <= 1000){                                                       // While _federate_name not reserve or time interval less than 1 millsecond
            dur = chrono::duration_cast<std::chrono::microseconds>(chrono::steady_clock::now() - start).count(); // Update time interval
        }
          _MyInstanceID = _rtiAmbassador->registerObjectInstance(_MyClass, _federate_name);                    // Get specific ID for federate from RTI
    }

/**
* @brief BaseFederate::ReadyToGo
* Method that sends the FederationManager a stamp that the federate is ready for the next modeling step
*/
    void BaseFederate::ReadyToGo() const{
        HLAfloat64Time UselessStamp;        // Create some useless stamp
        long hash = _MyInstanceID.hash();   // Hash federate ID
        rti1516e::VariableLengthData v;
        v.setData(&hash, sizeof (hash));   // Convert hash to byte-array
        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"READY"), ParameterHandleValueMap(), v, UselessStamp); // Send READY time-stamp
    }

/**
* @brief BaseFederate::CacheID
* @param ID of extern federate
* Method caching the handle of the resulting object class by the hash of the class id
*/
    void BaseFederate::CacheID(const rti1516e::ObjectInstanceHandle& ID) const{

        if(_CacheID[static_cast<size_t>(ID.hash())]) // Check is id in cache
            return;

        ObjectClassHandle objch = _rtiAmbassador->getKnownObjectClassHandle(ID); // Get ObjectClassHandle of extern federate
        _CacheID[static_cast<size_t>(ID.hash())] = &_ObjectClasses.at(_rtiAmbassador->getObjectClassName(objch)); // Cache object class of extern federate
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
* @brief BaseFederate::Modeling<ModelMode::FREE_THREADING>
* Main function of modeling that sleep in sub-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
*/

    void BaseFederate::Modeling<MODELMODE::FREE_THREADING>(){
        while(_f_modeling){                       // while modeling execute
            {
                lock_guard<mutex> guard(_smutex); // Lock state mutex
                _state = STATE::DOING;            // Change federate state to execute(doing) state without HLA
            }
            _condition.notify_one();                                      // Notify conditional variable in ModelGuard
            this_thread::sleep_for(chrono::milliseconds(_modeling_step)); // Sleep for modeling step

            tbb::parallel_invoke([this](){
                // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
                this->UpdateAttributes();
            },
                // Call SendParameters method to send interaction with parameters to RTI, look more at SendParameters()
                                 [this](){
                this->SendParameters();
            });

            tbb::parallel_invoke([this](){
                // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
                this->ParameterProcess();
            },
                // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
                                 [this](){
                this->AttributeProcess();
            });
        }
    }

    template<>
/**
* @brief BaseFederate::Modeling<MODELMODE::MANAGING_THREADING>
* Main function of modeling that wait for time-stamp GO from FederationManager in sub-thread and after that start process queue of attributes and parameters and update attributes and send interactions
*/
    void BaseFederate::Modeling<MODELMODE::MANAGING_THREADING>(){

        while(_f_modeling){ // while modeling execute

           std::unique_lock<std::mutex> lock(_smutex);  // lock federate state
           _state = STATE::READY;                       // Set state to READY
           ReadyToGo();                                 // Send time-stamp READY

           _condition.wait(lock,[this]{                      // Wait for GO federate state, federate notify ModelGuard about state change _OR_ when execution finished
                return _state == STATE::PROCESSING || !_f_modeling;
            });

           tbb::parallel_invoke([this](){
               // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
               this->UpdateAttributes();
           },
               // Call SendParameters method to send interaction with parameters to RTI, look more at SendParameters()
                                [this](){
               this->SendParameters();
           });

           tbb::parallel_invoke([this](){
               // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
               this->ParameterProcess();
           },
               // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
                                [this](){
               this->AttributeProcess();
           });
        }
    }

    template<>
/**
* @brief BaseFederate::Modeling<ModelMode::FREE_FOLLOWING>
* Main function of modeling that sleep in call-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
*/
    void BaseFederate::Modeling<MODELMODE::FREE_FOLLOWING>(){                                                                      // Create log writer
        auto dur = chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - _last_time);  // Create time interval
        auto step = chrono::duration_cast<chrono::milliseconds>(chrono::milliseconds(_modeling_step));   // Convert modeling step to time interval
        if((step - dur).count()>0)                                                                       // If dur less than modeling step
            this_thread::sleep_for(chrono::milliseconds(step - dur));                                    // Sleep for difference betwen step and dur

        tbb::parallel_invoke([this](){
            // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
            this->UpdateAttributes();
        },
            // Call SendParameters method to send interaction with parameters to RTI, look more at SendParameters()
                             [this](){
            this->SendParameters();
        });

        tbb::parallel_invoke([this](){
            // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
            this->ParameterProcess();
        },
            // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
                             [this](){
            this->AttributeProcess();
        });

        _state = STATE::DOING;                                         // Change federate state to execute(doing) state without HLA
    }

    template<>
/**
* @brief BaseFederate::Modeling<ModelMode::MANAGING_FOLLOWING>
*
*/
    void BaseFederate::Modeling<MODELMODE::MANAGING_FOLLOWING>(){

        tbb::parallel_invoke([this](){
           // Call UpdateAttributes method to send attributes to RTI, look more at UpdateAttributes()
            this->UpdateAttributes();
        },
           // Call SendParameters method to send interaction with parameters to RTI, look more at SendParameters()
                             [this](){
            this->SendParameters();
        });

        tbb::parallel_invoke([this](){
            // Call ParameterProcess method to proccess interactions from RTI, look more at ParameterProcess()
            this->ParameterProcess();
        },
            // Call AttributeProcess method to proccess attributes from RTI, look more at AttributeProcess()
                             [this](){
            this->AttributeProcess();
        });

       _state = STATE::DOING;
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
    MODELMODE BaseFederate::GetModelMode() const noexcept {return _mode;}

/**
* @brief BaseFederate::GetState
* Return current Federate State
* @return State
*/
    STATE BaseFederate::GetState() const noexcept {return _state;}

/**
* @brief BaseFederate::LoadSOMFromJSON
* @param file file JSON file with necessary parameters:
* ModelingStep          : Step of Modeling in milliseconds
* CallbackMode          : Asynchronous/Synchronous mode match 0/1
* ModelingMode          : Modeling Mode parameter, look ModelMode enumeration class
* Method for JSON file with lvalue reference
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::LoadSOMFromJSON(const JSON& file){
        const auto node         = file.GetRoot()->AsMap();                                         // Open the main node of file like hash map
        SetModelingStep(node.at(L"ModelingStep")->AsInt());                                        // Read modeling step
        SetSyncCallbackMode(node.at(L"CallbackMode")->AsInt());                                    // Read callback mode
        SetModelMode(MODELMODE(node.at(L"ModelingMode")->AsInt()));                                // Read modeling mode
        return *this;
    }

/**
* @brief BaseFederate::LoadSOMFromJSON
* @param file file JSON file with necessary parameters:
* ModelingStep          : Step of Modeling in milliseconds
* CallbackMode          : Asynchronous/Synchronous mode match 0/1
* ModelingMode          : Modeling Mode parameter, look ModelMode enumeration class
* Method for JSON file with rvalue reference
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::LoadSOMFromJSON(JSON&& file){
        const auto node         = file.GetRoot()->AsMap();                                         // Open the main node of file like hash map
        SetModelingStep(node.at(L"ModelingStep")->AsInt());                                        // Read modeling step
        SetSyncCallbackMode(node.at(L"CallbackMode")->AsInt());                                    // Read callback mode
        SetModelMode(MODELMODE(node.at(L"ModelingMode")->AsInt()));                                // Read modeling mode
        return *this;
    }

/**
* @brief BaseFederate::SetSyncCallbackMode
* @param f Boolean value for setup Synchronous mode
* Change Callback mode to Synchronize if is_sync = true, default Asynchronize
* @return Sample reference of current Federate
*/
    BaseFederate& BaseFederate::SetSyncCallbackMode(bool f)  noexcept{
        if(f && _state < STATE::STARTED) // If federate not started and setup sync mode
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
    BaseFederate& BaseFederate::SetModelMode(MODELMODE mode)  noexcept{
        _mode = mode;
        return *this;
    }

/**
* @brief BaseFederate::connectionLost
* @param faultDescription
*/

    void BaseFederate::connectionLost(const wstring &faultDescription)
                                      throw (FederateInternalError){

        _f_modeling = false;                // Change flag to finish modeling
        if((_mode == MODELMODE::FREE_THREADING || _mode == MODELMODE::MANAGING_THREADING) && _state >= STATE::CONNECTED)
            _modeling_thread.join();        // Wait for end of thread
        lock_guard<mutex> guard(_smutex);   // Lock state mutex
        _state = STATE::EXIT;               // Set federate state to EXIT

        *logger << Logger::MSG::INFO                // Write message about connection lost
                << _federate_name
                << L" connection to RTI lost, because"
                << faultDescription
                << Logger::Flush();
    }

/**
* @brief BaseFederate::objectInstanceNameReservationSucceeded
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is successful
*/
    void BaseFederate::objectInstanceNameReservationSucceeded(wstring const & name)
                                                              throw (FederateInternalError){

        *logger << Logger::MSG::INFO            // Write INFO message about proccessing part of modeling
            << _federate_name
            << L"Reserved name"
            << Logger::Flush();

        lock_guard<mutex> guard(_smutex);
        _state = STATE::NAMERESERVED; // Change federate state to name reservation successfuly
    }

/**
* @brief BaseFederate::objectInstanceNameReservationFailed
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is failed
*/
    void BaseFederate::objectInstanceNameReservationFailed(const wstring &)
                                                           throw (FederateInternalError){

        *logger << Logger::MSG::ERRORR          // Write ERROR message about name reservation failed
            << _federate_name
            << L"Can't Reserved name"
            << Logger::Flush();

        lock_guard<mutex> guard(_smutex);
        _state = STATE::EXIT;   // Change federate state to exit
    }


/**
* @brief BaseFederate::reflectAttributeValues
* @param theObject          : Instanse Handle of Federate sender (something like id)
* @param theAttributeValues : Map of VariableLengthData (byte arrays)
* @param info : Mark of message
* Callback function from RTI. Call when subscribed federate update his attributes.
* Info of reflected attributes in theUserSuppliedTag
* Data of reflected attributes in theAttributeValues
* Handle of reflected object
*/
    void BaseFederate::reflectAttributeValues(ObjectInstanceHandle handle,
                                              const AttributeHandleValueMap &theAttributeValues,
                                              const VariableLengthData & info,
                                              OrderType ,
                                              TransportationType ,
                                              SupplementalReflectInfo)
    throw (FederateInternalError){
        if(_state >= STATE::STARTED){                       // If federate start modeling
            lock_guard<mutex> guard(_amutex);               // Lock queue of reflected attributes
            CacheID(handle);
            _qAttributes.push({info,theAttributeValues, *_CacheID[static_cast<size_t>(handle.hash())]});   // Add new message {information or tag in byte array, map of attributes}
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
* Handle of recived interaction
*/
    void BaseFederate::receiveInteraction (InteractionClassHandle handle,
                                     ParameterHandleValueMap const & theParameterValues,
                                     VariableLengthData const & info,
                                     OrderType,
                                     TransportationType,
                                     SupplementalReceiveInfo)
    throw (FederateInternalError){
        if(_state >= STATE::STARTED){                       // If federate start modeling
            lock_guard<mutex> guard(_pmutex);               // Lock queue of recived interactions
            _qParameters.push({info, theParameterValues, handle});   // Add new message {information or tag in byte array, map of interactions}
        }
    }

/**
* @brief BaseFederate::receiveInteraction
* @param theInteraction : Handle of recived interaction (default GO/READY)
* @param theTime        : Time stamp, using for separate queue of interactions and managing tools
* Callback function from RTI with time stamp. Call when federate send stamp READY or when FederationManager send GO
*/
    void BaseFederate::receiveInteraction (InteractionClassHandle theInteraction,
                                           ParameterHandleValueMap const & ,
                                           VariableLengthData const & ,
                                           OrderType ,
                                           TransportationType ,
                                           LogicalTime const & ,
                                           OrderType ,
                                           SupplementalReceiveInfo )
    throw (FederateInternalError){
        if(theInteraction == _InteractionClasses[L"GO"] && _state >= STATE::STARTED){ // If slave federate recive GO time-stamp
            lock_guard<mutex> guard(_smutex);
            _state = STATE::PROCESSING;       // Change state to processing
            _condition.notify_one();          // Start processing
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
