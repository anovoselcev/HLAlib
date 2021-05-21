#ifndef FEDERATIONMANAGER_HPP
#define FEDERATIONMANAGER_HPP

#include "BaseFederate.hpp"

namespace HLA{

class FederationManager final: public BaseFederate{


public:

    FederationManager(const JSON& file) noexcept;

    FederationManager(JSON&& file) noexcept;

    ~FederationManager() override;

    void pause();

    void SetNumberOfFederates(size_t num);

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

    void AttributeProcess(rti1516e::ObjectClassHandle& handle,
                          rti1516e::AttributeHandleValueMap& data,
                          rti1516e::VariableLengthData& info) override;

    void ParameterProcess(rti1516e::InteractionClassHandle& handle,
                          rti1516e::ParameterHandleValueMap& data,
                          rti1516e::VariableLengthData& info) override;

    std::unordered_map<rti1516e::ObjectInstanceHandle, std::wstring, ObjectInstanceClassHash> _federates_map;

    std::unordered_map<size_t, rti1516e::ObjectInstanceHandle> _federates_hash;

    std::unordered_map<std::wstring, TIMESTAMP> _federates_stamps;

    size_t _federates_count = 0;

    size_t _ready_federates = 0;

    size_t _total_number    = 0;

    bool _is_runing = true;

    std::mutex _locker_attr;
    std::mutex _locker_parm;
    std::mutex _locker_go;
    std::condition_variable _cv_attr;
    std::condition_variable _cv_param;
    bool on_step = true;
};

}

#endif // FEDERATIONMANAGER_HPP
