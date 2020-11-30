#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <algorithm>
#include <boost/functional/hash.hpp>

namespace HLA {

    using namespace std;
    using namespace rti1516e;

    #ifndef WIN32
        using  byte = uint8_t;
    #else
        using  Byte = unsigned char;
    #endif

    inline bool operator==(const VariableLengthData& lhs, const VariableLengthData& rhs){
       if(lhs.size() == rhs.size()){
           byte* lhs_ptr = const_cast<byte*>(static_cast<const byte*>(lhs.data()));
           byte* rhs_ptr = const_cast<byte*>(static_cast<const byte*>(rhs.data()));
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
        _federates_map[theObjectInstanceName] = theObject.encode();
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
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

        if(theInteraction == _InteractionClasses[L"READY"] && _state >= STATE::STARTED){
            lock_guard<mutex> guard(_smutex);

            auto federate = find_if(_federates_map.begin(), _federates_map.end(),[theUserSuppliedTag](const auto& value){
                return value.second == theUserSuppliedTag;
            });

            _federates_stamps[federate->first] = TIMESTAMP::READY;

            _ready_federates++;

            if(_ready_federates == _federates_count && CheckReady())
                    SendGoTimeStamp();
        }
    }

    struct FederationManager::VariableLengthDataHash{
        size_t operator()(const rti1516e::VariableLengthData& data) const noexcept{
            std::vector<HLA::byte> vec(data.size());
            memcpy(vec.data(), data.data(), data.size());
            return boost::hash_value(vec);
        }
    };
}
