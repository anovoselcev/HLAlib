#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <cstring>
#include <algorithm>
#include "HLAdata/HLAdata.hpp"
#include <iostream> // To delete

namespace HLA {

    using namespace std;
    using namespace rti1516e;

struct Some{        // To delete
    double value1;
    int value2;
    int16_t value3;
};

using HLAsome = Struct_wrapper<Some, 2, Float64LE, Integer32LE, Integer16LE>;


    FederationManager::FederationManager(const JSON& file) noexcept :
                                                           BaseFederate(file){}

    FederationManager::FederationManager(JSON&& file) noexcept:
                                                      BaseFederate(std::move(file)){}

    FederationManager::~FederationManager(){

        lock_guard<mutex> guard(_smutex);

        try{
            _rtiAmbassador->resignFederationExecution(ResignAction::NO_ACTION);
            _rtiAmbassador->destroyFederationExecution(_federation_name);
        }
        catch(...){
            *logger << Logger::MSG::ERRORR                      // Write ERROR message about runtime error
                << _federate_name
                << L"Can't destroy federation"
                << Logger::Flush();
        }
    }


    void FederationManager::RunFederate(){
        std::wcout << L"In RUN" << std::endl; // To delete
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

    void FederationManager::UpdateAttributes() const{}

    void FederationManager::SendParameters() const{}

    void FederationManager::AttributeProcess(){
        lock_guard<mutex> guard(_amutex);
        std::wcout << L"Here" << std::endl;
        while(!_qAttributes.empty()){
            auto& message = _qAttributes.front();
            Some value = HLA::cast_from_rti<HLAsome>(message.data.begin()->second);                         // To delete
            std::wcout << value.value1 << L"    " << value.value2 << L"   " << value.value3 << std::endl;   // To delete
//            for(const auto& object : _ObjectClasses){
//                for(const auto& attributte : _AttributesMap[object.second]){
//                    auto value = move(message.data.find(attributte.second)->second);
//                    if(value.size())
//                        _federates_values[object.first][attributte.first] = move(value);
//                }
//            }
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

    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    std::wstring const & theObjectInstanceName,
                                                    FederateHandle producingFederate)
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
            long hash;
            memcpy(&hash, theUserSuppliedTag.data(), sizeof (long));
            auto fed = std::find_if(_federates_map.begin(), _federates_map.end(), [&hash](const auto& value){
                return value.first.hash() == hash;
            });

            _federates_stamps[fed->second] = TIMESTAMP::READY;

            _ready_federates++;

            if(_ready_federates == _federates_count)
                    SendGoTimeStamp();
        }
    }

    size_t FederationManager::ObjectInstanceClassHash::operator()(const rti1516e::ObjectInstanceHandle &obj) const noexcept{
        return static_cast<size_t>(obj.hash());
    }
}
