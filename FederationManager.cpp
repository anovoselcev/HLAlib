#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <algorithm>
#include <boost/functional/hash.hpp>

namespace HLA {

    using namespace std;
    using namespace rti1516e;


    FederationManager::FederationManager(const JSON& file) noexcept :
                                                           BaseFederate(file){}

    FederationManager::FederationManager(JSON&& file) noexcept:
                                                      BaseFederate(std::move(file)){}

    FederationManager::~FederationManager(){
        lock_guard<mutex> guard(_smutex);
        _rtiAmbassador->resignFederationExecution(ResignAction::NO_ACTION);
        _rtiAmbassador->destroyFederationExecution(_federation_name);
    }


    void FederationManager::SendGoTimeStamp(){

        HLAfloat64Time UselessStamp;

        if(_federates_map.size() != _federates_count)
            throw std::runtime_error("Number of Federates is invalid");

        _ready_federates = 0;

        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"GO"), ParameterHandleValueMap(), _MyInstanceID.encode(), UselessStamp);

        for(auto& federate : _federates_stamps)
            federate.second = TIMESTAMP::GO;
    }

    bool FederationManager::CheckReady(){
        return std::all_of(_federates_stamps.begin(), _federates_stamps.end(),[](const auto& value){
            return value.second == TIMESTAMP::READY;
        });
    }

    void FederationManager::RunFederate(){}

    void FederationManager::UpdateAttributes() const{}

    void FederationManager::SendParameters() const{}

    void FederationManager::AttributeProcess(){
        lock_guard<mutex> guard(_amutex);
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            for(const auto& object : _ObjectClasses){
                for(const auto& attributte : _AttributesMap[object.second]){
                    auto value = move(message.data.find(attributte.second)->second);
                    if(value.size())
                        _federates_values[object.first][attributte.first] = move(value);
                }
            }
            _qAttributes.pop();
        }
    }

    void FederationManager::ParameterProcess(){}


    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    wstring const & theObjectInstanceName)
                                                    throw (FederateInternalError){
        lock_guard<mutex> guard(_smutex);
        _federates_map[theObject] = theObjectInstanceName;
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
        _federates_count++;
    }

    void FederationManager::removeObjectInstance (ObjectInstanceHandle theObject,
                                                  VariableLengthData const & theUserSuppliedTag,
                                                  OrderType sentOrder,
                                                  SupplementalRemoveInfo theRemoveInfo)
                                                  throw (FederateInternalError) {
        lock_guard<mutex> guard(_smutex);

        const auto& name = _federates_map[theObject];
        if(_federates_stamps[name] == TIMESTAMP::READY)
            _ready_federates--;
        _federates_stamps.erase(name);
        _federates_map.erase(theObject);
        _federates_count--;
    }


    void FederationManager::receiveInteraction (InteractionClassHandle theInteraction,
                                                ParameterHandleValueMap const &,
                                                VariableLengthData const & theUserSuppliedTag,
                                                OrderType ,
                                                TransportationType ,
                                                LogicalTime const & ,
                                                OrderType ,
                                                SupplementalReceiveInfo )
                                                throw (FederateInternalError){

        if(theInteraction == _InteractionClasses[L"READY"] && _state >= STATE::STARTED){
            lock_guard<mutex> guard(_smutex);

            rti1516e::VariableLengthData v = theUserSuppliedTag;
            rti1516e::ObjectInstanceHandle obj;
            obj.encode(v);
            _federates_stamps[_federates_map[obj]] = TIMESTAMP::READY;

            _ready_federates++;

            if(_ready_federates == _federates_count && CheckReady())
                    SendGoTimeStamp();
        }
    }

    size_t FederationManager::ObjectInstanceClassHash::operator()(const rti1516e::ObjectInstanceHandle &obj) const noexcept{
        return static_cast<size_t>(obj.hash());
    }
}
