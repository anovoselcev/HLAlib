#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <algorithm>

namespace HLA {

    using namespace std;
    using namespace rti1516e;

    #ifndef WIN32
        using  Byte = uint8_t;
    #else
        using  Byte = unsigned char;
    #endif

    inline bool operator==(const VariableLengthData& lhs, const VariableLengthData& rhs){
       if(lhs.size() == rhs.size()){
           Byte* lhs_ptr = const_cast<Byte*>(static_cast<const Byte*>(lhs.data()));
           Byte* rhs_ptr = const_cast<Byte*>(static_cast<const Byte*>(rhs.data()));
           for(size_t i = 0; i < lhs.size(); ++i){
               if(*(lhs_ptr + i) != *(rhs_ptr + i))
                   return false;
           }
       }
       else
           return false;

       return true;
    }

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

        if(_federates_map.size() != _federates_count)
            throw std::runtime_error("Number of Federates is invalid");

        _ready_federates = 0;

        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"GO"), ParameterHandleValueMap(), _MyInstanceID.encode(), UselessStamp);

        for(auto& federate : _federates_stamps)
            federate.second = TimeStamp::GO;
    }

    bool FederationManager::CheckReady(){

        for(const auto& fed : _federates_stamps){
            if(fed.second != TimeStamp::READY)
                return false;
        }

        return true;
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

            _ready_federates++;

            if(_ready_federates == _federates_count && CheckReady())
                    SendGoTimeStamp();
        }
    }
}
