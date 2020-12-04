#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <algorithm>

#include <iostream>

namespace HLA {

    using namespace std;
    using namespace rti1516e;
using byte = uint8_t;
inline bool operator==(const rti1516e::VariableLengthData& lhs, const rti1516e::VariableLengthData& rhs){
   if(lhs.size() == rhs.size()){
       HLA::byte* lhs_ptr = const_cast<HLA::byte*>(static_cast<const HLA::byte*>(lhs.data()));
       HLA::byte* rhs_ptr = const_cast<HLA::byte*>(static_cast<const HLA::byte*>(rhs.data()));
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
        _rtiAmbassador->resignFederationExecution(ResignAction::CANCEL_THEN_DELETE_THEN_DIVEST);
        _rtiAmbassador->destroyFederationExecution(_federation_name);
    }


    size_t FederationManager::GetFederatesCount() const noexcept{
        return _federates_count;
    }

    void FederationManager::RunFederate(){
    }

    void FederationManager::SendGoTimeStamp(){

        std::wcout << L"I prepare to send GO" << std::endl;

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
        std::wcout << L"I see new" << std::endl;
        lock_guard<mutex> guard(_smutex);
        std::wcout << theObject.toString() << std::endl;
        _federates_map[theObject] = theObjectInstanceName;
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
        _federates_count++;

    }

    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    std::wstring const & theObjectInstanceName,
                                                    FederateHandle producingFederate)
                                                    throw (FederateInternalError){
        std::wcout << L"I see new" << std::endl;
        lock_guard<mutex> guard(_smutex);
        std::wcout << theObject.toString() << std::endl;
        _federates_map[theObject] = theObjectInstanceName;
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
        _federates_count++;
    }

    void FederationManager::removeObjectInstance (ObjectInstanceHandle theObject,
                                                  VariableLengthData const & theUserSuppliedTag,
                                                  OrderType sentOrder,
                                                  SupplementalRemoveInfo theRemoveInfo)
                                                  throw (FederateInternalError) {

        std::wcout << L"One less" << std::endl;
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
           // std::wcout << L"I recive ready" << std::endl;
            lock_guard<mutex> guard(_smutex);
            long hash;
            memcpy(&hash, theUserSuppliedTag.data(), sizeof (long));
            auto fed = std::find_if(_federates_map.begin(), _federates_map.end(), [&hash](const auto& value){
                return value.first.hash() == hash;
            });
            std::wcout << fed->second << std::endl;

            _federates_stamps[fed->second] = TIMESTAMP::READY;

            _ready_federates++;

            std::wcout << L"Num of Federates = " << _federates_count << std::endl;
            std::wcout << L"Num of Ready Federates = " << _ready_federates << std::endl;

            if(CheckReady())
                    SendGoTimeStamp();
        }
    }

    size_t FederationManager::ObjectInstanceClassHash::operator()(const rti1516e::ObjectInstanceHandle &obj) const noexcept{
        return static_cast<size_t>(obj.hash());
    }
}
