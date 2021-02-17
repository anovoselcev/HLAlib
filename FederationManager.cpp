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
    static auto start =  std::chrono::steady_clock::now();
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
        auto end = std::chrono::steady_clock::now();
        //std::wcout << L"dt = " << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << std::endl;
        start = std::chrono::steady_clock::now();

        for(auto& federate : _federates_stamps)
            federate.second = TIMESTAMP::GO;
        std::wcout << L"Do new step" << std::endl;
    }

    void FederationManager::UpdateAttributes() const{}

    void FederationManager::SendParameters() const{}

    void FederationManager::AttributeProcess(rti1516e::ObjectClassHandle &handle, rti1516e::AttributeHandleValueMap &data, rti1516e::VariableLengthData &info){
       BaseFederate::UpdateAttributes({{_AttributesMap[_MyClass][L"Value"], data.begin()->second}});
    }

    void FederationManager::ParameterProcess(rti1516e::InteractionClassHandle &handle, rti1516e::ParameterHandleValueMap &data, rti1516e::VariableLengthData &info){}


    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    wstring const & theObjectInstanceName)
                                                    throw (FederateInternalError){
        lock_guard<mutex> guard(_smutex);
        _federates_map[theObject] = theObjectInstanceName;
        _federates_hash[static_cast<size_t>(theObject.hash())] = theObject;
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
        _federates_count++;
        std::wcout << L"I see new" << std::endl;

    }

    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    std::wstring const & theObjectInstanceName,
                                                    FederateHandle producingFederate)
                                                    throw (FederateInternalError){
        lock_guard<mutex> guard(_smutex);
        _federates_map[theObject] = theObjectInstanceName;
        _federates_hash[static_cast<size_t>(theObject.hash())] = theObject;
        _federates_stamps[theObjectInstanceName] = TIMESTAMP::GO;
        _federates_count++;
        std::wcout << L"I see new" << std::endl;
    }

    void FederationManager::removeObjectInstance (ObjectInstanceHandle theObject,
                                                  VariableLengthData const & ,
                                                  OrderType ,
                                                  SupplementalRemoveInfo )
                                                  throw (FederateInternalError) {

        lock_guard<mutex> guard(_smutex);

        const auto& name = _federates_map[theObject];
        if(_federates_stamps[name] == TIMESTAMP::READY)
            _ready_federates--;
        _federates_stamps.erase(name);
        _federates_map.erase(theObject);
        _federates_hash.erase(static_cast<size_t>(theObject.hash()));
        _federates_count--;
        if(_ready_federates == _federates_count)
            SendGoTimeStamp();
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

        lock_guard<mutex> guard(_smutex);
        if(theInteraction == _InteractionClasses[L"READY"] && _state >= STATE::STARTED){
            auto hash = HLA::cast_from_rti<HLA::Unsigned32BE>(theUserSuppliedTag);
            if(!_federates_hash[static_cast<size_t>(hash)].isValid()){
                hash = HLA::cast_from_rti<HLA::Unsigned32LE>(theUserSuppliedTag);
            }

            _federates_stamps[_federates_map[_federates_hash[hash]]] = TIMESTAMP::READY;

            _ready_federates++;

            if(_ready_federates == _federates_count)
                    SendGoTimeStamp();
        }
    }

    size_t FederationManager::ObjectInstanceClassHash::operator()(const rti1516e::ObjectInstanceHandle &obj) const noexcept{
        return static_cast<size_t>(obj.hash());
    }
}
