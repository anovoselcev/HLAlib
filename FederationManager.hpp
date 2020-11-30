#ifndef FEDERATIONMANAGER_HPP
#define FEDERATIONMANAGER_HPP

#include "BaseFederate.hpp"
#include <boost/variant.hpp>

namespace HLA{

    class FederationManager final: public BaseFederate{

    public:

        FederationManager(const JSON& file) noexcept;

        FederationManager(JSON&& file) noexcept;

        ~FederationManager() override;

    private:

        struct VariableLengthDataHash;

        void SendGoTimeStamp();

        bool CheckReady();

        void discoverObjectInstance (rti1516e::ObjectInstanceHandle theObject,
                                     rti1516e::ObjectClassHandle theObjectClass,
                                     std::wstring const & theObjectInstanceName)
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

        std::unordered_map<std::wstring, rti1516e::VariableLengthData> _federates_map;

        std::unordered_map<std::wstring, TIMESTAMP> _federates_stamps;

        std::unordered_map<std::wstring, std::unordered_map<std::wstring, rti1516e::VariableLengthData>> _federates_values;

        size_t _federates_count = 0;

        size_t _ready_federates = 0;
    };

}

#endif // FEDERATIONMANAGER_HPP
