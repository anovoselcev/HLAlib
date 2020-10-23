#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <algorithm>

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
        lock_guard<mutex> guard(_smutex);
        HLAfloat64Time UselessStamp;
        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"GO"), ParameterHandleValueMap(), _MyInstanceID.encode(), UselessStamp);

        for(auto& federate : _federates_stamps)
            federate.second = TimeStamp::GO;
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


    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    wstring const & theObjectInstanceName)
                                                    throw (FederateInternalError){
        lock_guard<mutex> guard(_smutex);
        _federates_map[theObjectInstanceName] = theObject.encode();
        _federates_stamps[theObjectInstanceName] = TimeStamp::GO;
        _federates_count++;
    }

    void FederationManager::removeObjectInstance (ObjectInstanceHandle theObject,
                                                  VariableLengthData const & theUserSuppliedTag,
                                                  OrderType sentOrder,
                                                  SupplementalRemoveInfo theRemoveInfo)
                                                  throw (FederateInternalError) {
        lock_guard<mutex> guard(_smutex);
        auto federate = find_if(_federates_map.begin(), _federates_map.end(),[theObject](const auto& value){
            return value.second == theObject.encode();
        });
        const auto& name = federate->first;
        _federates_stamps.erase(name);
        _federates_map.erase(name);
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

        if(theInteraction == _InteractionClasses[L"READY"] && _state >= State::STARTED){
            lock_guard<mutex> guard(_smutex);

            auto federate = find_if(_federates_map.begin(), _federates_map.end(),[theUserSuppliedTag](const auto& value){
                return value.second == theUserSuppliedTag;
            });

            _federates_stamps[federate->first] = TimeStamp::READY;

            bool flag = all_of(_federates_map.begin(), _federates_map.end(), [](const auto& value){
               value.second == TimeStamp::READY;
            });

            if(flag)
                SendGoTimeStamp();
        }
    }
}
