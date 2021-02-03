#ifndef FEDERATIONMANAGER_HPP
#define FEDERATIONMANAGER_HPP

#include "BaseFederate.hpp"

namespace HLA{

/**
* @brief The FederationManager class
* Federate for managing in HLAlib, which provide easy API for control federation execution and sync step of federation
*/
    class FederationManager final: public BaseFederate{

//================================================================================================================================================

//          Public API

//================================================================================================================================================

    public:


/**
* @brief FederationManager
* @param file : file JSON file with necessary parameters
* Constructor of FederationManager do the same things as BaseFederate
*/
        FederationManager(const JSON& file) noexcept;


/**
* @brief FederationManager
* @param file : file JSON file with necessary parameters
* Constructor of FederationManager do the same things as BaseFederate
*/
        FederationManager(JSON&& file) noexcept;

/**
* @brief ~FederationManager
* Destructor of FederationManager, which resign federation and destroy it
*/
        ~FederationManager() override;

//================================================================================================================================================

//          Private Methods and structures

//================================================================================================================================================

    private:

        struct ObjectInstanceClassHash{
            size_t operator()(const rti1516e::ObjectInstanceHandle& obj) const noexcept;
        };

        void SendGoTimeStamp();


        void discoverObjectInstance (rti1516e::ObjectInstanceHandle theObject,
                                     rti1516e::ObjectClassHandle theObjectClass,
                                     std::wstring const & theObjectInstanceName)
                                     throw (rti1516e::FederateInternalError) override;

        void discoverObjectInstance (rti1516e::ObjectInstanceHandle theObject,
                                     rti1516e::ObjectClassHandle theObjectClass,
                                     std::wstring const & theObjectInstanceName,
                                     rti1516e::FederateHandle producingFederate)
                                     throw (rti1516e::FederateInternalError) override;

        void removeObjectInstance (rti1516e::ObjectInstanceHandle theObject,
                                   rti1516e::VariableLengthData const & theUserSuppliedTag,
                                   rti1516e::OrderType sentOrder,
                                   rti1516e::SupplementalRemoveInfo theRemoveInfo)
                                   throw (rti1516e::FederateInternalError) override;

        void receiveInteraction (rti1516e::InteractionClassHandle theInteraction,
                                 rti1516e::ParameterHandleValueMap const & theParameterValues,
                                 rti1516e::VariableLengthData const & theUserSuppliedTag,
                                 rti1516e::OrderType sentOrder,
                                 rti1516e::TransportationType theType,
                                 rti1516e::LogicalTime const & theTime,
                                 rti1516e::OrderType receivedOrder,
                                 rti1516e::SupplementalReceiveInfo theReceiveInfo)
                                 throw (rti1516e::FederateInternalError) override;



    protected:

        void RunFederate() override;

        void UpdateAttributes() const override;

        void SendParameters() const override;

        void AttributeProcess() override;

        void ParameterProcess() override;

        std::unordered_map<rti1516e::ObjectInstanceHandle, std::wstring, ObjectInstanceClassHash> _federates_map;

        std::unordered_map<std::wstring, TIMESTAMP> _federates_stamps;

        std::unordered_map<std::wstring, std::unordered_map<std::wstring, rti1516e::VariableLengthData>> _federates_values;

        size_t _federates_count = 0;

        size_t _ready_federates = 0;
    };

}

#endif // FEDERATIONMANAGER_HPP
