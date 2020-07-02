#ifndef BASEFEDERATE_HPP
#define BASEFEDERATE_HPP
#include <RTI/RTI1516.h>
#include <RTI/NullFederateAmbassador.h>

#include <unordered_map>
#include <thread>
#include <queue>
#include <condition_variable>

namespace HLA{

    enum class ModelMode{
        FOLLOWING = 0,
        THREADING = 1
    };

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
* Basic federate
*/
    class BaseFederate: public rti1516e::NullFederateAmbassador{

    public:


/**
* @brief BaseFederate
* Default constructor, initialization nothing
*/
        BaseFederate() noexcept;

/**
* @brief BaseFederate
* @param name
* @param type
* @param FOMname
* @param fname
* @param ip
* Full-gapes constructor with lvalue, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
        BaseFederate(const std::wstring& name,
                     const std::wstring& type,
                     const std::wstring& FOMname,
                     const std::wstring& fname,
                     const std::wstring& ip = L"localhost") noexcept;


 /**
* @brief BaseFederate
* @param name
* @param type
* @param FOMname
* @param ip
* @param fname
* Full-gapes constructor with move, initialization name(_federate_name) and type(_federate_type) of federate, path to FOM(_FOMname), name of federation (_federation_name) and IP addres of CRC(_host_IP_address)
*/
        BaseFederate(std::wstring&& name,
                     std::wstring&& type,
                     std::wstring&& FOMname,
                     std::wstring&& fname,
                     std::wstring&& ip = L"localhost") noexcept;

 /**
* @brief ~BaseFederate
* Destructor of basic federate
*/
        virtual ~BaseFederate() override;

/**
* @brief BaseFederate
* Copy constructor
*/
        BaseFederate(const BaseFederate&) = delete;

/**
* @brief BaseFederate
* Move constructor
*/
        BaseFederate(BaseFederate&&) = delete;


/**
* @brief operator =
* Copy assignment operator
* @return BaseFederate&
*/
        BaseFederate& operator=(const BaseFederate&) = delete;

/**
* @brief operator =
* Move assignment operator
* @return BaseFederate&
*/
        BaseFederate& operator=(BaseFederate&&) = delete;


/**
* @brief ConnectRRTI
* Connect to RTI. In order to connect we need to create federation based on FOM (isn't nessary, if federation already exist) and join there. After that federate initialized in RTI and go to the his main loop. Use only to lvalue class samples
*/
         bool ConnectRTI();

/**
* @brief operator ()
* @param step
* Operator that run federate with modelin_step in milliseconds = step like functional object
*/
        virtual bool operator()(int step=100);

/**
* @brief GetName
* @return std::wstring
*/
        const std::wstring GetName() const noexcept;

/**
* @brief GetType
* @return std::wstring
*/
        const std::wstring GetType() const noexcept;

/**
* @brief GetFederation
* @return std::wstring
*/
        const std::wstring GetFederation() const noexcept;

/**
* @brief GetFOMpath
* @return std::wstring
*/
        const std::wstring GetFOMpath() const noexcept;

/**
* @brief GetIP
* @return std::wstring
*/
        const std::wstring GetIP() const noexcept;

/**
* @brief GetCallbackMode
* @return rti1516e::CallbackModel
*/
        rti1516e::CallbackModel GetCallbackMode() const noexcept;

/**
* @brief GetModelMode
* @return ModelMode
*/
        ModelMode GetModelMode() const noexcept;

/**
* @brief GetState
* @return State
*/
        State GetState() const noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* Set default map of Objects and Attribute of basic federate (lvalue version)
*/
        BaseFederate& SetSubscribeMapOfObjectsAndAttributes(const std::unordered_map<std::wstring,std::vector<std::wstring>>& objects_attributes_map) noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* Set default map of Objects and Attribute of basic federate (rvalue version)
*/
        BaseFederate& SetSubscribeMapOfObjectsAndAttributes(std::unordered_map<std::wstring,std::vector<std::wstring>>&& objects_attributes_map) noexcept;

/**
* @brief SetPublishListOfAttributes
* Set list of attributes for publish (lvalue version)
*/
        BaseFederate& SetPublishListOfAttributes(const std::vector<std::wstring>& attribute_list) noexcept;

/**
* @brief SetPublishListOfAttributes
* Set list of attributes for publish (rvalue version)
*/
        BaseFederate& SetPublishListOfAttributes(std::vector<std::wstring>&& attribute_list) noexcept;


/**
* @brief SetMapOfInteractionsAndParameters
* Set default map of Interactions and Parameters of basic federate (lvalue version)
*/
        BaseFederate& SetMapOfInteractionsAndParameters(const std::unordered_map<std::wstring,std::vector<std::wstring>>& interations_parameters_map) noexcept;

/**
* @brief SetMapOfInteractionsAndParameters
* Set default map of Interactions and Parameters of basic federate (rvalue version)
*/
        BaseFederate& SetMapOfInteractionsAndParameters(std::unordered_map<std::wstring,std::vector<std::wstring>>&& interations_parameters_map) noexcept;

/**
* @brief SetModelingStep
* @param _step
* Set modeling step in milliseconds
*/
        BaseFederate& SetModelingStep(int step) noexcept;

/**
* @brief SetModelMode
* @param mode
* @return
*/
        BaseFederate& SetModelMode(ModelMode mode) noexcept;
/**
* @brief SetSyncCallbackMode
* Change Callback mode to Synchronize, default Asynchronize
*/
         BaseFederate& SetSyncCallbackMode(bool is_sync) noexcept;

/**
* @brief SetLogFileName
* @param log_filename
* @return
*/
         BaseFederate& SetLogFileName(const std::string& log_filename) noexcept;

/**
* @brief SetLogFileName
* @param log_filenmae
* @return
*/
         BaseFederate& SetLogFileName(std::string&& log_filenmae) noexcept;


    private:
/**
* @brief The ObjectClassHash struct
* Hash for Object Class
*/
        struct ObjectClassHash{
            size_t operator()(const rti1516e::ObjectClassHandle& _Object) const noexcept{
                return _Object.hash();
            }
        };

/**
* @brief The InteractionClassHash struct
* Hash for Interaction Class
*/
        struct InteractionClassHash{
            size_t operator()(const rti1516e::InteractionClassHandle& _Interaction) const noexcept{
                return _Interaction.hash();
            }
        };
/**
* @brief The CallbackInformation struct
*/
        template<typename T>
        struct CallbackInformation{
            rti1516e::VariableLengthData info;
            T data;
        };

        using CallbackAttributesInformation = CallbackInformation<rti1516e::AttributeHandleValueMap>;
        using CallbackParametersInformation = CallbackInformation<rti1516e::ParameterHandleValueMap>;

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
* Set the _InteractionsNames to _InteractionClasses
* Set the _InteractionsNames to _ParametersMap
*/
        void InitInteractionsAndParameters();

/**
* @brief SubscribeAttributes
* Call RTI to subscribe on Objects and Attributes from _externAttributesSet
*/
        void SubscribeAttributes(std::unordered_map<rti1516e::ObjectClassHandle,rti1516e::AttributeHandleSet,ObjectClassHash>&);

/**
* @brief PublishAttributes
* Call RTI to publish the _MyClass with his attributes
*/
        void PublishAttributes(rti1516e::AttributeHandleSet&);

/**
* @brief SubscribeParameters
* Call RTI to subscribe on Interactions and Parameters from _ParametersMap
*/
        void SubscribeParameters();

/**
* @brief PublishParameters
* Call RTI to publish the Interactions and Parameters from _ParametersMap
*/
        void PublishParameters();

/**
* @brief RegisterName
* Call RTI to reserve and register federate name - _federate_name and init this object as _MyInstanceID
*/
        void RegisterName();


    protected:
/**
* @brief RunFederate
* The main loop of federate ( default: empty method without loop)
*/
        virtual void RunFederate();

/**
* @brief UpdateAttributes
* Update attribute map
*/
        virtual void UpdateAttributes() const;

/**
* @brief SendParameters
* Update parameter map
*/
        virtual void SendParameters() const;

 /**
 * @brief Modeling
 * Main function of modeling that sleep for modeling step and after that process queue of attributes and parameters and update attributes
 */
        virtual void ThreadModeling();

/**
* @brief FollowModeling
*/

        virtual void FollowModeling();

 /**
 * @brief AttributeProcess
 * Function that process queue of reflected attributes step by step in time order
 */
        virtual void AttributeProcess();

/**
* @brief ParameterProcess
* Function that process queue of recived parameters of interactions step by step in time order
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
* @brief reflectAttributeValues
* @param theObject
* @param theAttributeValues
* @param theUserSuppliedTag
* @param sentOrder
* @param theType
* @param theReflectInfo
* Callback function from RTI. Call when subscribed federate update his attributes.
* Data of updated attributes in theAttributeValues
*/
        virtual void reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                            const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                            const rti1516e::VariableLengthData &theUserSuppliedTag,
                                            rti1516e::OrderType sentOrder,
                                            rti1516e::TransportationType theType,
                                            rti1516e::SupplementalReflectInfo theReflectInfo)
        throw (rti1516e::FederateInternalError) override;

/**
* @brief receiveInteraction
* @param theInteraction
* @param theParameterValues
* @param theUserSuppliedTag
* @param sentOrder
* @param theType
* @param theReceiveInfo
* Callback function from RTI. Call when subscribed interation with his parameters  sends.
* Data of sended parameters in theParameterValues
*/
        virtual void receiveInteraction (rti1516e::InteractionClassHandle theInteraction,
                                         rti1516e::ParameterHandleValueMap const & theParameterValues,
                                         rti1516e::VariableLengthData const & theUserSuppliedTag,
                                         rti1516e::OrderType sentOrder,
                                         rti1516e::TransportationType theType,
                                         rti1516e::SupplementalReceiveInfo theReceiveInfo)
        throw (rti1516e::FederateInternalError) override;



//Determining parameters of federate
/** @brief _federate_name
* Name of federate
*/
        const std::wstring _federate_name;
/** @brief _federate_type
* Type of federate
*/
        const std::wstring _federate_type;
/** @brief _FOMname
* Path to FOM
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
*/
        std::string _log_filename = "LogFile";

/**
* @brief _state
*/
        State _state = State::PREPARE;

/**
* @brief _mode
*/
        ModelMode _mode = ModelMode::THREADING;
/**
* @brief _f_modeling
* Flag of modeling execution
*/
        bool _f_modeling     = false;


/** @brief _callback_mode
* RTI sync run mode
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
        std::unordered_map<std::wstring,rti1516e::ObjectClassHandle> _ObjectClasses;

/**
* @brief _InteractionClasses
* Hash-map of all Interaction Classes [ClassName,ClassID]
*/
        std::unordered_map<std::wstring,rti1516e::InteractionClassHandle> _InteractionClasses;

/**
* @brief _AttributesMap
* Hash-map of all used Object Classes and their Attributes Hash-map [ClassID,[AttributeName,AttributeID]]
*/
        std::unordered_map<rti1516e::ObjectClassHandle,std::unordered_map<std::wstring,rti1516e::AttributeHandle>,ObjectClassHash> _AttributesMap;

//
/**
* @brief _ParametersMap
* Hash-map of all used Interaction Classes and their Parameters Hash-map [ClassID,[ParameterName,ParameterID]]
*/
        std::unordered_map<rti1516e::InteractionClassHandle,std::unordered_map<std::wstring,rti1516e::ParameterHandle>,InteractionClassHash> _ParametersMap;

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
* Mutex for _f_state when ModelMutex using
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

        std::chrono::time_point<std::chrono::steady_clock> _last_time;

/**
*Configs for Objects and Interaction Maps
* @brief _ObjectsNames
* @brief _InteractionsNames
*/
        mutable std::vector<std::wstring> _AttributeNames;
        mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _ObjectsNames;
        mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _InteractionsNames;

        friend class ModelGuard;
    };


}
#endif // BASEFEDERATE_HPP
