#ifndef BASEFEDERATE_HPP
#define BASEFEDERATE_HPP
#include <RTI/RTI1516.h>
#include <RTI/RTIambassadorFactory.h>
#include <RTI/NullFederateAmbassador.h>

#include <unordered_map>
#include <vector>
#include <memory>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>

namespace HLA{
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
        virtual void ConnectRTI() &;

/**
* @brief operator ()
* @param step
* Operator that run federate with modelin_step in milliseconds = step like functional object
*/
        virtual void operator()(int step=100) &;

/**
* @brief GetName
* @return std::wstring
*/
        virtual std::wstring GetName() const noexcept;

/**
* @brief GetType
* @return std::wstring
*/
        virtual std::wstring GetType() const noexcept;

/**
* @brief GetFederation
* @return std::wstring
*/
        virtual std::wstring GetFederation() const noexcept;

/**
* @brief GetFOMpath
* @return std::wstring
*/
        virtual std::wstring GetFOMpath() const noexcept;

/**
* @brief GetIP
* @return std::wstring
*/
        virtual std::wstring GetIP() const noexcept;

/**
* @brief GetCallbackMode
* @return std::wstring
*/
        virtual std::wstring GetCallbackMode() const noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* Set default map of Objects and Attribute of basic federate (lvalue version)
*/
        virtual void SetSubscribeMapOfObjectsAndAttributes(const std::unordered_map<std::wstring,std::vector<std::wstring>>&) noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* Set default map of Objects and Attribute of basic federate (rvalue version)
*/
        virtual void SetSubscribeMapOfObjectsAndAttributes(std::unordered_map<std::wstring,std::vector<std::wstring>>&&) noexcept;

/**
* @brief SetPublishListOfAttributes
* Set list of attributes for publish (lvalue version)
*/
        virtual void SetPublishListOfAttributes(const std::vector<std::wstring>&) noexcept;

/**
* @brief SetPublishListOfAttributes
* Set list of attributes for publish (rvalue version)
*/
        virtual void SetPublishListOfAttributes(std::vector<std::wstring>&&) noexcept;


/**
* @brief SetMapOfInteractionsAndParameters
* Set default map of Interactions and Parameters of basic federate (lvalue version)
*/
        virtual void SetMapOfInteractionsAndParameters(const std::unordered_map<std::wstring,std::vector<std::wstring>>&) noexcept;

/**
* @brief SetMapOfInteractionsAndParameters
* Set default map of Interactions and Parameters of basic federate (rvalue version)
*/
        virtual void SetMapOfInteractionsAndParameters(std::unordered_map<std::wstring,std::vector<std::wstring>>&&) noexcept;

/**
* @brief SetModelingStep
* @param _step
* Set modeling step in milliseconds
*/
        virtual void SetModelingStep(int _step) noexcept;

/**
* @brief SetSyncCallbackMode
* Change Callback mode to Synchronize, default Asynchronize
*/
        virtual void SetSyncCallbackMode(bool) noexcept;


    protected:

/**
* @brief MakeRTIambassador
* @return std::unique_ptr<rti1516e::RTIambassador>
* Create RTIambassador pointer(unique_ptr) object, that provide access to RTI services
*/
        virtual std::unique_ptr<rti1516e::RTIambassador> MakeRTIambassador() const;

/**
* @brief Init
* Initialized federate (it's object type in FOM and attributes), environment in federation (other types and attributes indicated in _ObjectsNames) and their connections for this federate.
*/
        virtual void Init();


/**
* @brief InitClassesAndAttributes
* Initializerd federate object and his attributes indicated in _AttributeNames and environmental objects and attributes indicated in _ObjectNames
*/
        virtual void InitClassesAndAttributes();


/**
* @brief InitInteractionsAndParameters
* Set the _InteractionsNames to _InteractionClasses
* Set the _InteractionsNames to _ParametersMap
*/
        virtual void InitInteractionsAndParameters();

/**
* @brief SubscribeAttributes
* Call RTI to subscribe on Objects and Attributes from _externAttributesSet
*/
        virtual void SubscribeAttributes();

/**
* @brief PublishAttributes
* Call RTI to publish the _MyClass with his attributes
*/
        virtual void PublishAttributes();

/**
* @brief SubscribeParameters
* Call RTI to subscribe on Interactions and Parameters from _ParametersMap
*/
        virtual void SubscribeParameters();

/**
* @brief PublishParameters
* Call RTI to publish the Interactions and Parameters from _ParametersMap
*/
        virtual void PublishParameters();

/**
* @brief RegisterName
* Call RTI to reserve and register federate name - _federate_name and init this object as _MyInstanceID
*/
        virtual void RegisterName();


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
        virtual void Modeling();

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
/** @brief _host_IP_address
* IP address of CRC
*/
        const std::wstring _host_IP_address;
/** @brief _federation_name
* Name of Federation
*/
        const std::wstring _federation_name;





//Federate work flags
/** @brief _f_name_reserve
* Flag of succes name reservation
*/
        bool _f_name_reserve = false;
/** @brief _f_connect
* Flag of succes connect to RTI
*/
        bool _f_connect      = false;
/** @brief _f_time
* Flag of succes time set up
*/
        bool _f_time         = false;
/** @brief _f_start
* Flag of succes start
*/
        bool _f_start        = false;
/**
* @brief _f_modeling
* Flag of modeling execution
*/
        bool _f_modeling     = false;

/**
* @brief _f_state
* Flag of launch main thread if ModelMutex using
*/

        bool _f_state        = false;

/** @brief _callback_mode
* RTI sync run mode
*/
        rti1516e::CallbackModel _callback_mode = rti1516e::HLA_IMMEDIATE;

/**
* @brief _cond
* Condition variable that check _f_state and launch main thread if ModelMutex using
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
* @brief _externAttributesSet
* Hash-map of extern Object Classes and their Attributes Hash-set [ClassID,AttributeSet]
*/
        std::unordered_map<rti1516e::ObjectClassHandle,rti1516e::AttributeHandleSet,ObjectClassHash> _externAttributesSet;

/**
* @brief _aPublishSetId
* Attribute Set of Self Attributes
*/
        rti1516e::AttributeHandleSet _aPublishSet;

/**
* @brief _qAttributes
* Queue of reflected attributes
*/
        std::queue<rti1516e::AttributeHandleValueMap> _qAttributes;
/**
* @brief _qParameters
* Queue of recived parameters
*/
        std::queue<rti1516e::ParameterHandleValueMap> _qParameters;
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
