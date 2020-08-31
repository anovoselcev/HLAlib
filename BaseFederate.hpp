//=========================================================================================
/*
 * Written by Novoseltsev Artemy
 * This program is free software.
 * This program is distributed in the hope that it will be useful.
*/
//=========================================================================================

#ifndef BASEFEDERATE_HPP
#define BASEFEDERATE_HPP
#include <RTI/RTI1516.h>
#include <RTI/NullFederateAmbassador.h>

#include <thread>
#include <queue>
#include <condition_variable>
#include <unordered_set>

#include "Tools/JSON.hpp"

namespace HLA{

/**
* @brief The ModelMode enum
* Set of Model Modes:
* Following : Do modeling process and federate time control in the thread, which connect federate to RTI
* Threading : Do modeling process and federate time control in the new thread
* Managing  : Do modeling process ................................................................
*/
    enum class ModelMode{
        FOLLOWING = 0,
        THREADING = 1,
        MANAGING  = 2
    };

/**
* @brief The State enum
* Set of Federate States:
* Prepare      : Initial federate state
* NameReserved : Federate state after succesfull name reservation in RTI
* Connected    : Federate state after succesfull connect to RTI
* Started      : Federate state after succesfull initializaton
* Processing   : Federate state during data processing
* Doing        : Federate state during time control
* Exit         : Federate state in the end of simulation
*/
    enum class State{
        PREPARE      = 0,
        NAMERESERVED = 1,
        CONNECTED    = 2,
        STARTED      = 3,
        PROCESSING   = 4,
        DOING        = 5,
        EXIT         = -1
    };

/**
* @brief The BaseFederate class
* Basic federate of HLAlib, which provide easy API for Quick Federate Developing, based on NullFederateAmbassador (provided by HLA)
*/
    class BaseFederate: public rti1516e::NullFederateAmbassador{

//=========================================================================================

//          Public API

//=========================================================================================

    public:

/**
* @brief BaseFederate
* Default constructor, initialization nothing specific
*/
        BaseFederate() noexcept;

/**
* @brief BaseFederate
* @param name       Name of Federate
* @param type       Type of federate, which match object in FOM
* @param FOMname    Path to FOM file
* @param fname      Name of Federation
* @param ip         IP - address of CRC
* Full-gapes constructor with lvalue, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
        BaseFederate(const std::wstring& name,
                     const std::wstring& type,
                     const std::wstring& FOMname,
                     const std::wstring& fname,
                     const std::wstring& ip = L"localhost") noexcept;


/**
* @brief BaseFederate
* @param name       Name of Federate
* @param type       Type of federate, which match object in FOM
* @param FOMname    Path to FOM file
* @param fname      Name of Federation
* @param ip         IP - address of CRC
* Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
        BaseFederate(std::wstring&& name,
                     std::wstring&& type,
                     std::wstring&& FOMname,
                     std::wstring&& fname,
                     std::wstring&& ip = L"localhost") noexcept;

/**
* @brief BaseFederate
* @param file JSON file with necessary parameters:
* Name           : Name of Federate
* Type           : Type of federate, which match object in FOM
* FOMpath        : Path to FOM file
* FederationName : Name of Federation
* Address        : IP - address of CRC
* Constructor for JSON file with lvalue reference
*/
        BaseFederate(const JSON& file) noexcept;

/**
* @brief BaseFederate
* @param file JSON file with necessary parameters:
* Name           : Name of Federate
* Type           : Type of federate, which match object in FOM
* FOMpath        : Path to FOM file
* FederationName : Name of Federation
* Address        : IP - address of CRC
* Constructor for JSON file with rvalue reference
*/
        BaseFederate(JSON&& file) noexcept;

 /**
* @brief ~BaseFederate
* Destructor of basic federate, which set Federate State to EXIT
*/
        virtual ~BaseFederate() override;

/**
* @brief BaseFederate
* Copy constructor of Federate deleted, only unique entity can exist
*/
        BaseFederate(const BaseFederate&) = delete;

/**
* @brief BaseFederate
* Move constructor of Federate deleted, only unique entity can exist
*/
        BaseFederate(BaseFederate&&) = delete;


/**
* @brief operator =
* Copy assignment operator of Federate deleted, only unique entity can exist
* @return BaseFederate&
*/
        BaseFederate& operator=(const BaseFederate&) = delete;

/**
* @brief operator =
* Move assignment operator of Federate deleted, only unique entity can exist
* @return BaseFederate&
*/
        BaseFederate& operator=(BaseFederate&&) = delete;


/**
* @brief ConnectRRTI
* Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist) and join there. After that federate initialized in RTI and go to the his main loop. Use only to lvalue class samples
* @return flag of success execution
*/
         bool ConnectRTI() &;

/**
* @brief operator ()
* @param step Modeling Step in milliseconds
* Operator that run federate with modelin_step in milliseconds = step like functional object
*/
        virtual bool operator()(int step=100);

/**
* @brief GetName
* Return name of Federate
* @return std::wstring
*/
        const std::wstring GetName() const noexcept;

/**
* @brief GetType
* Return type of Federate, which match object in FOM
* @return std::wstring
*/
        const std::wstring GetType() const noexcept;

/**
* @brief GetFederation
* Return name of Federation
* @return std::wstring
*/
        const std::wstring GetFederation() const noexcept;

/**
* @brief GetFOMpath
* Return Path to FOM
* @return std::wstring
*/
        const std::wstring GetFOMpath() const noexcept;

/**
* @brief GetIP
* return IP - address of CRC
* @return std::wstring
*/
        const std::wstring GetIP() const noexcept;

/**
* @brief GetCallbackMode
* Return current Callback mode :
* HLA_IMMEDIATE : Asynchronous Mode
* HLA_EVOKED    : Synchronous Mode, requires requests to RTI for every call
* @return rti1516e::CallbackModel
*/
        rti1516e::CallbackModel GetCallbackMode() const noexcept;

/**
* @brief GetModelMode
* Return current Federate Mode
* @return ModelMode
*/
        ModelMode GetModelMode() const noexcept;

/**
* @brief GetState
* Return current Federate State
* @return State
*/
        State GetState() const noexcept;

/**
* @brief LoadSOMFromJSON
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
        BaseFederate& LoadSOMFromJSON(const JSON& file);

/**
* @brief LoadSOMFromJSON
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
        BaseFederate& LoadSOMFromJSON(JSON&& file);

//=========================================================================================

//          Private Methods, structures and alias

//=========================================================================================

private:

/**
* @brief NameMap
* Alias for data structure std::unordered_map<std::wstring, std::vector<std::wstring>>
*/
        using NameMap = std::unordered_map<std::wstring, std::vector<std::wstring>>;

/**
* @brief NameList
* Alias for data structure std::vector<std::wstring>
*/
        using NameList = std::vector<std::wstring>;

/**
* @brief SetModelingStep
* @param step in milliseconds
* Setup Federate Modeling step (_step) to step value
* @return Sample reference of current Federate
*/
        BaseFederate& SetModelingStep(int step) noexcept;

/**
* @brief SetModelMode
* @param mode Value of Model Mode
* Setup Modeling Mode parameter, look ModelMode enumeration class
* @return Sample reference of current Federate
*/
        BaseFederate& SetModelMode(ModelMode mode) noexcept;

/**
* @brief SetSyncCallbackMode
* @param is_sync Boolean value for setup Synchronous mode
* Change Callback mode to Synchronize if is_sync = true, default Asynchronize
* @return Sample reference of current Federate
*/
       BaseFederate& SetSyncCallbackMode(bool is_sync) noexcept;

/**
* @brief SetLogFileName
* @param log_filename FileName of log-file
* Setup Log FileName
* @return Sample reference of current Federate
*/
       BaseFederate& SetLogFileName(const std::string& log_filename) noexcept;

/**
* @brief SetLogFileName
* @param log_filename FileName of log-file
* Setup Log FileName
* @return Sample reference of current Federate
*/
        BaseFederate& SetLogFileName(std::string&& log_filenmae) noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* @param objects_attributes_map Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* Set map of Objects and Attribute, which federate subscribe (lvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetSubscribeMapOfObjectsAndAttributes(const NameMap& objects_attributes_map) noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* @param objects_attributes_map Hash Map of objects and their attributes (matches with FOM), which federate want to subscribe ({{"Object1", {"Attribute1", "Attribute2",....}}....})
* Set map of Objects and Attribute, which federate subscribe (rvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetSubscribeMapOfObjectsAndAttributes(NameMap&& objects_attributes_map) noexcept;

/**
* @brief SetPublishListOfAttributes
* @param attribute_list List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* Set list of Attributes, which federate publish (lvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetPublishListOfAttributes(const NameList& attribute_list) noexcept;

/**
* @brief SetPublishListOfAttributes
* @param attribute_list List of attributes (matches with FOM), which federate want to publish ({"Attribute1", "Attribute2",....})
* Set list of Attributes, which federate publish (rvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetPublishListOfAttributes(NameList&& attribute_list) noexcept;


/**
* @brief SetMapOfInteractionsAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want subscribe (lvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetSubscribeMapOfInteractionsAndParameters(const NameMap& interations_parameters_map) noexcept;

/**
* @brief SetMapOfInteractionsAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to subscribe ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want subscribe (rvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetSubscribeMapOfInteractionsAndParameters(NameMap&& interations_parameters_map) noexcept;

/**
* @brief SetMapOfInteractionsAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want publish (lvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetPublishMapOfInteractionAndParameters(const NameMap& interations_parameters_map) noexcept;

/**
* @brief SetMapOfInteractionsAndParameters
* @param interations_parameters_map Hash Map of interactions and their parameters (matches with FOM), which federate want to publish ({{"Interaction1", {"Parameter1", "Parameter2",....}}....})
* Set map of Interactions and Parameters, which federate want publish (rvalue version)
* @return Sample reference of current Federate
*/
        BaseFederate& SetPublishMapOfInteractionAndParameters(NameMap&& interations_parameters_map) noexcept;

/**
* @brief The ObjectClassHash struct
* Hash for Object Class, it necessary for hash structures
*/
        struct ObjectClassHash{
            size_t operator()(const rti1516e::ObjectClassHandle& _Object) const noexcept{
                return _Object.hash();
            }
        };

/**
* @brief The InteractionClassHash struct
* Hash for Interaction Class, it necessary for hash structures
*/
        struct InteractionClassHash{
            size_t operator()(const rti1516e::InteractionClassHandle& _Interaction) const noexcept{
                return _Interaction.hash();
            }
        };
/**
* @brief The CallbackInformation struct
* Data structure for Callback Message {info, data}
* info : Some mark, using for differ identifiers
* data : Map of data with VariableLengthData (ByteArray)
*/
        template<typename T>
        struct CallbackInformation{
            rti1516e::VariableLengthData info;
            T data;
        };

/**
* @brief CallbackAttributesInformation
* CallbackInformation struct with data = AttributeHandleValueMap
*/
        using CallbackAttributesInformation = CallbackInformation<rti1516e::AttributeHandleValueMap>;

/**
* @brief CallbackParametersInformation
* CallbackInformation struct with data = ParameterHandleValueMap
*/
        using CallbackParametersInformation = CallbackInformation<rti1516e::ParameterHandleValueMap>;

/**
* @brief ObjectHandleMap
* Alias for data structure std::unordered_map<std::wstring, rti1516e::ObjectClassHandle>
*/
        using ObjectHandleMap = std::unordered_map<std::wstring, rti1516e::ObjectClassHandle>;

/**
* @brief InteractionHandleMap
* Alias for data structure std::unordered_map<std::wstring, rti1516e::InteractionClassHandle>
*/
        using InteractionHandleMap = std::unordered_map<std::wstring, rti1516e::InteractionClassHandle>;

/**
* @brief AttributeHandleMap
* Alias for data structure std::unordered_map<rti1516e::ObjectClassHandle, std::unordered_map<std::wstring, rti1516e::AttributeHandle>, ObjectClassHash>
*/
        using AttributeHandleMap = std::unordered_map<rti1516e::ObjectClassHandle, std::unordered_map<std::wstring, rti1516e::AttributeHandle>, ObjectClassHash>;

/**
* @brief AttributeHandleMap
* Alias for data structure std::unordered_map<rti1516e::InteractionClassHandle, std::unordered_map<std::wstring, rti1516e::ParameterHandle>, InteractionClassHash>
*/
        using ParameterHandleMap = std::unordered_map<rti1516e::InteractionClassHandle, std::unordered_map<std::wstring, rti1516e::ParameterHandle>, InteractionClassHash>;


/**
* @brief MakeRTIambassador
* @return std::unique_ptr<rti1516e::RTIambassador>
* Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
*/
        std::unique_ptr<rti1516e::RTIambassador> MakeRTIambassador() const &;

/**
* @brief Init
* Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate.
*/
        void Init();


/**
* @brief InitClassesAndAttributes
* Initializerd federate object and his attributes indicated in _AttributeNames and environmental objects and attributes indicated in _ObjectNames
*/
        void InitClassesAndAttributes(std::unordered_map<rti1516e::ObjectClassHandle,rti1516e::AttributeHandleSet,ObjectClassHash>&,
                                              rti1516e::AttributeHandleSet&);


/**
* @brief InitInteractionsAndParameters
* Initializerd federate interactions and their parameters indicated in _MyInteractionsNames and environmental interactions and paramters indicated in _InteractionsNames
*/
        void InitInteractionsAndParameters(std::unordered_set<rti1516e::InteractionClassHandle, InteractionClassHash>&,
                                           std::unordered_set<rti1516e::InteractionClassHandle, InteractionClassHash>&);

/**
* @brief SubscribeAttributes
* Call RTI to subscribe on Objects and Attributes from _ObjectNames
*/
        void SubscribeAttributes(std::unordered_map<rti1516e::ObjectClassHandle,rti1516e::AttributeHandleSet,ObjectClassHash>&);

/**
* @brief PublishAttributes
* Call RTI to publish the _MyClass with attributes from _AttributeNames
*/
        void PublishAttributes(rti1516e::AttributeHandleSet&);

/**
* @brief SubscribeParameters
* Call RTI to subscribe on Interactions and Parameters from _MyInteractionsNames
*/
        void SubscribeParameters(std::unordered_set<rti1516e::InteractionClassHandle, InteractionClassHash>&);

/**
* @brief PublishParameters
* Call RTI to publish the Interactions and Parameters from _InteractionsNames
*/
        void PublishParameters(std::unordered_set<rti1516e::InteractionClassHandle, InteractionClassHash>&);

/**
* @brief RegisterName
* Call RTI to reserve and register federate name (_federate_name) and init this object as _MyInstanceID
*/
        void RegisterName();

//=========================================================================================

//          Protected API and fields

//=========================================================================================

    protected:
/**
* @brief RunFederate
* The main loop of federate ( default: empty method without loop)
*/
        virtual void RunFederate();

/**
* @brief UpdateAttributes
* Update VariableLengthData Map of federate values to RTI, should be override
* Convert data of federate and send map of byte arrays to RTI
*/
        virtual void UpdateAttributes() const;

/**
* @brief SendParameters
* Update VariableLengthData Map of federate interactions to RTI, should be override
* Convert data of federate and send map of byte arrays to RTI
*/
        virtual void SendParameters() const;

 /**
 * @brief Modeling
 * Main function of modeling that sleep in sub-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
 */
        virtual void ThreadModeling();

/**
* @brief FollowModeling
* Main function of modeling that sleep in call-thread for modeling step and after that process queue of attributes and parameters and update attributes and send interactions
*/

        virtual void FollowModeling();

 /**
 * @brief AttributeProcess
 * Function that process queue of reflected attributes step by step in time order, should be override
 */
        virtual void AttributeProcess();

/**
* @brief ParameterProcess
* Function that process queue of recived parameters of interactions step by step in time order, should be override
*/
        virtual void ParameterProcess();

/**
* @brief objectInstanceNameReservationSucceeded
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is successful
*/
        virtual void objectInstanceNameReservationSucceeded (std::wstring const & theObjectInstanceName)
        throw (rti1516e::FederateInternalError) override;

/**
* @brief objectInstanceNameReservationFailed
* @param theObjectInstanceName
* Callback function from RTI. Call when name registration in RegisterName is failed
*/
        virtual void objectInstanceNameReservationFailed(const std::wstring &theObjectInstanceName)
        throw (rti1516e::FederateInternalError) override;

/**
* @brief reflectAttributeValues
* @param theObject          : Instanse Handle of Federate sender (something like id)
* @param theAttributeValues : Map of VariableLengthData (byte arrays)
* @param theUserSuppliedTag : Mark of message
* Callback function from RTI. Call when subscribed federate update his attributes.
* Info of reflected attributes in theUserSuppliedTag
* Data of reflected attributes in theAttributeValues
*/
        virtual void reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                            const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                            const rti1516e::VariableLengthData &theUserSuppliedTag,
                                            rti1516e::OrderType ,
                                            rti1516e::TransportationType,
                                            rti1516e::SupplementalReflectInfo)
        throw (rti1516e::FederateInternalError) override;

/**
* @brief receiveInteraction
* @param theInteraction     : Handle of received interaction
* @param theParameterValues : Map of VariableLengthData (byte arrays)
* @param theUserSuppliedTag : Mark of message
* Callback function from RTI. Call when subscribed interation with his parameters sends.
* Info of recived interaction in theUserSuppliedTag
* Data of reflected interaction in theParameterValues
*/
        virtual void receiveInteraction (rti1516e::InteractionClassHandle theInteraction,
                                         rti1516e::ParameterHandleValueMap const & theParameterValues,
                                         rti1516e::VariableLengthData const & theUserSuppliedTag,
                                         rti1516e::OrderType sentOrder,
                                         rti1516e::TransportationType theType,
                                         rti1516e::SupplementalReceiveInfo theReceiveInfo)
        throw (rti1516e::FederateInternalError) override;



/** @brief _federate_name
* Name of federate
*/
        const std::wstring _federate_name;

/** @brief _federate_type
* Type of federate, must be matched with FOM
*/
        const std::wstring _federate_type;

/** @brief _FOMname
* Path to FOM file
*/
        const std::wstring _FOMname;

/** @brief _federation_name
* Name of Federation
*/
        const std::wstring _federation_name;

/** @brief _host_IP_address
* IP address of CRC
*/
        const std::wstring _host_IP_address;

/**
* @brief _log_filename
* Name of Log file
*/
        std::string _log_filename = "LogFile";

/**
* @brief _state
* State of Federate, look at enumeration class State
*/
        State _state = State::PREPARE;

/**
* @brief _mode
* Model Mode of Federate, look at enumeration class ModelMode
*/
        ModelMode _mode = ModelMode::THREADING;
/**
* @brief _f_modeling
* Flag of modeling execution
*/
        bool _f_modeling     = false;


/** @brief _callback_mode
* RTI Callback mode :
* HLA_IMMEDIATE : Asynchronous Mode
* HLA_EVOKED    : Synchronous Mode, requires requests to RTI for every call
*/
        rti1516e::CallbackModel _callback_mode = rti1516e::HLA_IMMEDIATE;

/**
* @brief _cond
* Condition variable that check _state and launch main thread if ModelGuard using
*/

        std::condition_variable _cond;


/**
* @brief _rtiAmbassador
* Pointer for RTI-ambassador object
*/
        mutable std::unique_ptr<rti1516e::RTIambassador> _rtiAmbassador;

/**
* Self Object Class and Object Instance
* @brief _MyClass
* Self object class of federate
*/

        rti1516e::ObjectClassHandle _MyClass;
/**
* @brief _MyInstanceID
* Self instance class of federate with registered federate name in RTI (something like ID in RTI)
*/
        rti1516e::ObjectInstanceHandle _MyInstanceID;

/**
* @brief _ObjectClasses
* Hash-map of extern Object Classes [ClassName,ClassID]
*/
        ObjectHandleMap _ObjectClasses;

/**
* @brief _InteractionClasses
* Hash-map of all Interaction Classes [ClassName,ClassID]
*/
        InteractionHandleMap _InteractionClasses;

/**
* @brief _AttributesMap
* Hash-map of all used Object Classes and their Attributes Hash-map [ClassID,[AttributeName,AttributeID]]
*/
        AttributeHandleMap _AttributesMap;

//
/**
* @brief _ParametersMap
* Hash-map of all used Interaction Classes and their Parameters Hash-map [ClassID,[ParameterName,ParameterID]]
*/
        ParameterHandleMap _ParametersMap;

/**
* @brief _qAttributes
* Queue of reflected attributes with transport information
*/
        std::queue<CallbackAttributesInformation> _qAttributes;

/**
* @brief _qParameters
* Queue of recived parameters with transport information
*/
        std::queue<CallbackParametersInformation> _qParameters;

/**
* @brief _amutex
* Mutex for attributes queue
*/
        mutable std::mutex _amutex;

/**
* @brief _pmutex
* Mutex for parameters queue
*/
        mutable std::mutex _pmutex;

/**
* @brief _smutex
* Mutex for _f_state when ModelGuard using
*/

        mutable std::mutex _smutex;

/**
* @brief _modeling_thread
* Thread of modeling that process all HLA interface
*/
        std::thread _modeling_thread;

/**
* @brief _modeling_step
* Value of modeling step in milliseconds
*/
        int _modeling_step = 100;

/**
* @brief _last_time
* Last time mark for ModelGuard in FollowModeling mode
*/
        std::chrono::time_point<std::chrono::steady_clock> _last_time;

/**
* @brief _AttributeNames
* List of attributes for publish
*/
        NameList _AttributeNames;

/**
* @brief _ObjectsNames
* Hash map of objects and attributes for subscribe
*/
        NameMap _ObjectsNames;

/**
* @brief _MyInteractions
* Hash map of interactions and parameters for publish
*/
        NameMap _MyInteractionsNames;

/**
* @brief _InteractionsNames
* Hash map of onteractions and parameters for subscribe
*/
        NameMap _InteractionsNames;

/**
* @brief ModelGuard
* Class for time control using RAII
*/
        friend class ModelGuard;
    };
}
#endif // BASEFEDERATE_HPP
