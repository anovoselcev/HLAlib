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


//Basic federate of UPIM
	class UPIMFederate: public rti1516e::NullFederateAmbassador{

	public:

//Default constructor
		UPIMFederate() noexcept;
//Constructor with full gapes (lvalue)
		UPIMFederate(const std::wstring& name,
					  const std::wstring& type,
					  const std::wstring& FOMname,
					  const std::wstring& ip = L"localhost",
					  const std::wstring& fname = L"UPIM") noexcept;

//Constructor with full gapes (rvalue)
		UPIMFederate(std::wstring&& name,
					  std::wstring&& type,
					  std::wstring&& FOMname,
					  std::wstring&& ip = L"localhost",
					  std::wstring&& fname = L"UPIM") noexcept;

//Destructor of basic federate
		~UPIMFederate();

//Copy constructor
        UPIMFederate(const UPIMFederate&) = delete;

//Move constructor
        UPIMFederate(UPIMFederate&&) = default;

//Copy assignment operator
        UPIMFederate& operator=(const UPIMFederate&) = delete;

//Move assignment operator
        UPIMFederate& operator=(UPIMFederate&&) = default;

//Set basic parameters for HLA federate.
//Read FOM, connect to RRTI, create/join federation.
//Call Init and Run
		void ConnectRRTI() &;

//Update attribute map
		virtual void UpdateAttributes() const;

//Update parameter map
		virtual void SendParameters() const;

//Disconnect from RRTI

		virtual std::wstring GetName() const noexcept;

		virtual std::wstring GetType() const noexcept;

		virtual std::wstring GetFederation() const noexcept;

		virtual std::wstring GetFOMpath() const noexcept;

		virtual std::wstring GetIP() const noexcept;

		virtual std::wstring GetCallbackMode() const noexcept;

//Set default map of Objects and Attribute of basic federate (lvalue version)
        virtual void SetMapOfObjectsAndAttributes(const std::unordered_map<std::wstring,std::vector<std::wstring>>&) noexcept;

//Set default map of Objects and Attribute of basic federate (rvalue version)
        virtual void SetMapOfObjectsAndAttributes(std::unordered_map<std::wstring,std::vector<std::wstring>>&&) noexcept;

//Set default map of Interactions and Parameters of basic federate (lvalue version)
        virtual void SetMapOfInteractionsAndParameters(const std::unordered_map<std::wstring,std::vector<std::wstring>>&) noexcept;

//Set default map of Interactions and Parameters of basic federate (rvalue version)
        virtual void SetMapOfInteractionsAndParameters(std::unordered_map<std::wstring,std::vector<std::wstring>>&&) noexcept;

//Change Callback mode to Synchronize, default Asynchronize
		virtual void SetSyncCallbackMode(bool f) noexcept;


	protected:

//Make RRTI-ambassador - the object for interaction with RRTI
                virtual std::unique_ptr<rti1516e::RTIambassador> MakeRTIambassador() const;

//Call other Init.. methods
		virtual void Init();

//Set the _ObjectNames to _externObjectClasses
//Set the _ObjectNames to _AttributesMap
//Set the _ObjectNames to _externAttributesSet
		virtual void InitClassesAndAttributes();

//Set the _InteractionsNames to _InteractionClasses
//Set the _InteractionsNames to _ParametersMap
		virtual void InitInteractionsAndParameters();

//Call RRTI to subscribe on Objects and Attributes from _externAttributesSet
		virtual void SubscribeAttributes();

//Call RRTI to publish the _MyClass with his attributes
		virtual void PublishAttributes();

//Call RRTI to subscribe on Interactions and Parameters from _ParametersMap
		virtual void SubscribeParameters();

//Call RRTI to publish the Interactions and Parameters from _ParametersMap
		virtual void PublishParameters();

//Call RRTI to reserve and register federate name - _federate_name and init this object as _MyInstanceID
		virtual void RegisterName();

//Call RRTI to create and set time parameters
		virtual void MakeTime();

//The main loop of federate
		virtual void RunFederate();

		virtual void objectInstanceNameReservationSucceeded (
							         std::wstring const & theObjectInstanceName)
							         throw (
							        rti1516e::FederateInternalError);

//Hash for Object Class
		struct ObjectClassHash{
            size_t operator()(const rti1516e::ObjectClassHandle& _Object) const noexcept{
				return _Object.hash();
			}
		};

//Hash for Interaction Class
		struct InteractionClassHash{
            size_t operator()(const rti1516e::InteractionClassHandle& _Interaction) const noexcept{
				return _Interaction.hash();
			}
		};

//Determining parameters of federate
		std::wstring _federate_name;
		std::wstring _federate_type;
		std::wstring _FOMname;
		std::wstring _host_IP_address;
		std::wstring _federation_name;

//Federate work flags
		bool _f_name_reserve = false;
		bool _f_connect      = false;
		bool _f_time         = false;
		bool _f_start        = false;
		rti1516e::CallbackModel _callback_mode = rti1516e::HLA_IMMEDIATE;

//Pointer for RTI-ambassador object
		mutable std::unique_ptr<rti1516e::RTIambassador> _rtiAmbassador;

//Self Object Class and Object Instance
		rti1516e::ObjectClassHandle _MyClass;
		rti1516e::ObjectInstanceHandle _MyInstanceID;

//Hash-map of extern Object Classes [ClassName,ClassID]
		std::unordered_map<std::wstring,rti1516e::ObjectClassHandle> _externObjectClasses;

//Hash-map of all Interaction Classes [ClassName,ClassID]
		std::unordered_map<std::wstring,rti1516e::InteractionClassHandle> _InteractionClasses;

//Hash-map of all used Object Classes and their Attributes Hash-map [ClassID,[AttributeName,AttributeID]]
		std::unordered_map<rti1516e::ObjectClassHandle,std::unordered_map<std::wstring,rti1516e::AttributeHandle>,ObjectClassHash> _AttributesMap;

//Hash-map of all used Interaction Classes and their Parameters Hash-map [ClassID,[ParameterName,ParameterID]]
		std::unordered_map<rti1516e::InteractionClassHandle,std::unordered_map<std::wstring,rti1516e::ParameterHandle>,InteractionClassHash> _ParametersMap;

//Hash-map of extern Object Classes and their Attributes Hash-set [ClassID,AttributeSet]
		std::unordered_map<rti1516e::ObjectClassHandle,rti1516e::AttributeHandleSet,ObjectClassHash> _externAttributesSet;
		//AttributeHandleSet _aSubscribeSetId;

//Attribute Set of Self Attributes
		rti1516e::AttributeHandleSet _aPublishSetId;

//Attribute Map of Self Attributes
		mutable rti1516e::AttributeHandleValueMap _aMapId;

//Parameter Map of Self Parameters
		mutable rti1516e::ParameterHandleValueMap _pMapId;

//Time Regulation Parameters
		mutable std::unique_ptr<rti1516e::LogicalTimeFactory> _TimeFactory;
		rti1516e::HLAfloat64Time      _Time;
		rti1516e::HLAfloat64Interval  _TimeInterval;

//Configs for Objects and Interaction Maps
		mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _ObjectsNames;
		mutable std::unordered_map<std::wstring,std::vector<std::wstring>> _InteractionsNames;
	};
}
#endif
