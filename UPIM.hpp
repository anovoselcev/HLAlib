#pragma once
#ifndef UPIM_HPP
#define UPIM_HPP 1


#include <RTI/RTI1516.h>
#include <RTI/RTIambassadorFactory.h>
#include <RTI/NullFederateAmbassador.h>
#include <RTI/time/HLAfloat64TimeFactory.h>
#include <RTI/time/HLAfloat64Time.h>
#include <RTI/time/HLAfloat64Interval.h>
#include <RTI/time/HLAinteger64TimeFactory.h>
#include <RTI/time/HLAinteger64Time.h>
#include <RTI/time/HLAinteger64Interval.h>
#include <RTI/encoding/BasicDataElements.h>

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <unistd.h>


namespace UPIM{



/**
* @brief The UPIMFederate class
* Basic federate of UPIM
*/
	class UPIMFederate: public rti1516e::NullFederateAmbassador{

	public:


/**
* @brief UPIMFederate
* Default constructor
*/
		UPIMFederate() noexcept;

/**
* @brief UPIMFederate
* @param name
* @param type
* @param FOMname
* @param ip
* @param fname
* Constructor with full gapes (lvalue)
*/
		UPIMFederate(const std::wstring& name,
					  const std::wstring& type,
					  const std::wstring& FOMname,
					  const std::wstring& ip = L"localhost",
					  const std::wstring& fname = L"UPIM") noexcept;


 /**
* @brief UPIMFederate
* @param name
* @param type
* @param FOMname
* @param ip
* @param fname
* Constructor with full gapes (rvalue)
*/
		UPIMFederate(std::wstring&& name,
					  std::wstring&& type,
					  std::wstring&& FOMname,
					  std::wstring&& ip = L"localhost",
					  std::wstring&& fname = L"UPIM") noexcept;


 /**
* @brief ~UPIMFederate
* Destructor of basic federate
*/
		~UPIMFederate();

/**
* @brief UPIMFederate
* Copy constructor
*/
        UPIMFederate(const UPIMFederate&) = delete;

/**
* @brief UPIMFederate
* Move constructor
*/
        UPIMFederate(UPIMFederate&&) = default;


/**
* @brief operator =
* Copy assignment operator
* @return UPIMFederate&
*/
        UPIMFederate& operator=(const UPIMFederate&) = delete;

/**
* @brief operator =
* Move assignment operator
* @return UPIMFederate&
*/
        UPIMFederate& operator=(UPIMFederate&&) = default;


/**
* @brief ConnectRRTI
* Set basic parameters for HLA federate.
* Read FOM, connect to RRTI, create/join federation.
* Call Init and Run
* Use only to lvalue class samples
*/
		void ConnectRRTI() &;

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
        virtual void SetMapOfObjectsAndAttributes(const std::unordered_map<std::wstring,std::vector<std::wstring>>&) noexcept;

/**
* @brief SetMapOfObjectsAndAttributes
* Set default map of Objects and Attribute of basic federate (rvalue version)
*/
        virtual void SetMapOfObjectsAndAttributes(std::unordered_map<std::wstring,std::vector<std::wstring>>&&) noexcept;

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
* @brief SetSyncCallbackMode
* Change Callback mode to Synchronize, default Asynchronize
*/
        virtual void SetSyncCallbackMode(bool) noexcept;


	protected:

/**
* @brief MakeRTIambassador
* @return std::unique_ptr<rti1516e::RTIambassador>
* Make RRTI-ambassador - the object for interaction with RRTI
*/
        virtual std::unique_ptr<rti1516e::RTIambassador> MakeRTIambassador() const;

/**
* @brief Init
* Call other Init.. methods
*/
		virtual void Init();


/**
* @brief InitClassesAndAttributes
* Set the _ObjectNames to _externObjectClasses
* Set the _ObjectNames to _AttributesMap
* Set the _ObjectNames to _externAttributesSet
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
* Call RRTI to subscribe on Objects and Attributes from _externAttributesSet
*/
		virtual void SubscribeAttributes();

/**
* @brief PublishAttributes
* Call RRTI to publish the _MyClass with his attributes
*/
		virtual void PublishAttributes();

/**
* @brief SubscribeParameters
* Call RRTI to subscribe on Interactions and Parameters from _ParametersMap
*/
		virtual void SubscribeParameters();

/**
* @brief PublishParameters
* Call RRTI to publish the Interactions and Parameters from _ParametersMap
*/
		virtual void PublishParameters();

/**
* @brief RegisterName
* Call RRTI to reserve and register federate name - _federate_name and init this object as _MyInstanceID
*/
		virtual void RegisterName();

/**
* @brief MakeTime
* Call RRTI to create and set time parameters
*/
		virtual void MakeTime();

/**
* @brief RunFederate
* The main loop of federate
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


		virtual void objectInstanceNameReservationSucceeded (
							         std::wstring const & theObjectInstanceName)
							         throw (
							        rti1516e::FederateInternalError);

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
* Determining parameters of federate
* @brief _federate_name
* Name of federate
* @brief _federate_type
* Type of federate
* @brief _FOMname
* Path to FOM
* @brief _host_IP_address
* IP address of CRC
* @brief _federation_name
* Name of Federation
*/
		std::wstring _federate_name;
		std::wstring _federate_type;
		std::wstring _FOMname;
		std::wstring _host_IP_address;
		std::wstring _federation_name;

/** Federate work flags
 * @brief _f_name_reserve
 * Flag of succes name reservation
 * @brief _f_connect
 * Flag of succes connect to RTI
 * @brief _f_time
 * Flag of succes time set up
 * @brief _f_start
 * Flag of succes start
 * @brief _callback_mode
 * RTI mode
*/
		bool _f_name_reserve = false;
		bool _f_connect      = false;
		bool _f_time         = false;
		bool _f_start        = false;
		rti1516e::CallbackModel _callback_mode = rti1516e::HLA_IMMEDIATE;

/**
* @brief _rtiAmbassador
* Pointer for RTI-ambassador object
*/
		mutable std::unique_ptr<rti1516e::RTIambassador> _rtiAmbassador;

/**
* Self Object Class and Object Instance
* @brief _MyClass
* @brief _MyInstanceID
*/
		rti1516e::ObjectClassHandle _MyClass;
		rti1516e::ObjectInstanceHandle _MyInstanceID;

/**
* @brief _externObjectClasses
* Hash-map of extern Object Classes [ClassName,ClassID]
*/
		std::unordered_map<std::wstring,rti1516e::ObjectClassHandle> _externObjectClasses;

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
		//AttributeHandleSet _aSubscribeSetId;

/**
* @brief _aPublishSetId
* Attribute Set of Self Attributes
*/
		rti1516e::AttributeHandleSet _aPublishSetId;

/**
* @brief _aMapId
* Attribute Map of Self Attributes
*/
		mutable rti1516e::AttributeHandleValueMap _aMapId;

/**
* @brief _pMapId
* Parameter Map of Self Parameters
*/
		mutable rti1516e::ParameterHandleValueMap _pMapId;

/**
* Time Regulation Parameters
* @brief _TimeFactory
* @brief _Time
* @brief _TimeInterval
*/
		mutable std::unique_ptr<rti1516e::LogicalTimeFactory> _TimeFactory;
		rti1516e::HLAfloat64Time      _Time;
		rti1516e::HLAfloat64Interval  _TimeInterval;

/**
*Configs for Objects and Interaction Maps
* @brief _ObjectsNames
* @brief _InteractionsNames
*/
		mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _ObjectsNames;
		mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _InteractionsNames;
	};
}
#endif
