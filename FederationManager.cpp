#include "FederationManager.hpp"
#include "RTI/time/HLAfloat64Time.h"
#include <cstring>
#include <algorithm>
#include "HLAdata/HLAdata.hpp"

namespace HLA {

    using namespace std;
    using namespace rti1516e;

    FederationManager::FederationManager(const JSON& file) noexcept :
                                                           BaseFederate(file){}

    FederationManager::FederationManager(JSON&& file) noexcept:
                                                      BaseFederate(std::move(file)){}

    FederationManager::~FederationManager(){
        lock_guard<mutex> guard(_smutex);

        if(_state >= STATE::CONNECTED){
            try{
                _rtiAmbassador->resignFederationExecution(ResignAction::DELETE_OBJECTS);
                _rtiAmbassador->destroyFederationExecution(_federation_name);
            }
            catch(...){
                *logger << Logger::MSG::ERRORR                      // Write ERROR message about runtime error
                    << _federate_name
                    << L"Can't destroy federation"
                    << Logger::Flush();
            }
        }

    }

    void FederationManager::SetNumberOfFederates(size_t num){
        std::lock_guard<std::mutex> guard(_smutex);
        _total_number = num;
    }


    void FederationManager::RunFederate(){
        _is_runing = true;
    }

    void FederationManager::SendGoTimeStamp(){


        { bool is_total = false;
            if(_total_number <= _federates_map.size() && _total_number != 0) is_total = true;
            if(!_is_runing || !is_total)
                return;
        }
        HLAfloat64Time UselessStamp;



        if(_federates_map.size() != _federates_count)
            throw std::runtime_error("Number of Federates is invalid");

        lock_guard<mutex> guard1(_amutex);           // Lock queue of recived interactions
        while(!_qAttributes.empty()){               // If queue isn't empty
            auto& message = _qAttributes.front();   // Take first message in queue
            AttributeProcess(message.handle, message.data, message.info);
            _qAttributes.pop();                     // Delete first message in queue
        }
        lock_guard<mutex> guard2(_pmutex);           // Lock queue of recived interactions
        while(!_qParameters.empty()){               // If queue isn't empty
            auto& message = _qParameters.front();   // Take first message in queue
            ParameterProcess(message.handle, message.data, message.info);
            _qParameters.pop();                     // Delete first message in queue
        }

        _ready_federates = 0;


        _rtiAmbassador->sendInteraction(_InteractionClasses.at(L"GO"), ParameterHandleValueMap(), _MyInstanceID.encode(), UselessStamp);




        for(auto& federate : _federates_stamps)
            federate.second = TIMESTAMP::GO;
    }

    void FederationManager::UpdateAttributes() const{}

    void FederationManager::SendParameters() const{}

    void FederationManager::AttributeProcess(rti1516e::ObjectClassHandle&,
                                             rti1516e::AttributeHandleValueMap&,
                                             rti1516e::VariableLengthData& info){
        if(info.size()){
        }
    }

    void FederationManager::ParameterProcess(rti1516e::InteractionClassHandle&,
                                             rti1516e::ParameterHandleValueMap&,
                                             rti1516e::VariableLengthData& info) {

        if(info.size()){
        }

    }

    void FederationManager::pause(){
        std::lock_guard<std::mutex> guard(_smutex);
        _is_runing = !_is_runing;

        if(_is_runing) SendGoTimeStamp();
    }





    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    wstring const & theObjectInstanceName)
                                                    throw (FederateInternalError){

        lock_guard<mutex> guard(_smutex);
        if(!_federates_stamps.count(theObjectInstanceName)){
            ++_federates_count;
            _federates_map[theObject] = theObjectInstanceName;
            _federates_hash[static_cast<size_t>(theObject.hash())] = theObject;
            _federates_stamps[theObjectInstanceName] = TIMESTAMP::READY;
             if(_ready_federates == _federates_count)
                     SendGoTimeStamp();
        }
    }

    void FederationManager::discoverObjectInstance (ObjectInstanceHandle theObject,
                                                    ObjectClassHandle theObjectClass,
                                                    std::wstring const & theObjectInstanceName,
                                                    FederateHandle producingFederate)
                                                    throw (FederateInternalError){

        lock_guard<mutex> guard(_smutex);
        if(!_federates_stamps.count(theObjectInstanceName)){
            ++_federates_count;
            _federates_map[theObject] = theObjectInstanceName;
            _federates_hash[static_cast<size_t>(theObject.hash())] = theObject;
            _federates_stamps[theObjectInstanceName] = TIMESTAMP::READY;
            if(_ready_federates == _federates_count)
                    SendGoTimeStamp();
        }
    }

    void FederationManager::removeObjectInstance (ObjectInstanceHandle theObject,
                                                  VariableLengthData const & theUserSuppliedTag,
                                                  OrderType sentOrder,
                                                  SupplementalRemoveInfo theRemoveInfo)
                                                  throw (FederateInternalError) {
        lock_guard<mutex> guard(_smutex);
        --_federates_count;
        const auto& name = _federates_map[theObject];
        if(_federates_stamps[name] == TIMESTAMP::READY)
            _ready_federates--;
        _federates_stamps.erase(name);
        _federates_map.erase(theObject);
        _federates_hash.erase(static_cast<size_t>(theObject.hash()));

        if(_total_number > 1) --_total_number;

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


        if(theInteraction == _InteractionClasses[L"READY"] && _state >= STATE::STARTED){
            lock_guard<mutex> guard(_smutex);
            auto hash = HLA::cast_from_rti<HLA::Unsigned32BE>(theUserSuppliedTag);
            if(!_federates_hash[static_cast<size_t>(hash)].isValid()){
                hash = HLA::cast_from_rti<HLA::Unsigned32LE>(theUserSuppliedTag);
            }
            try{
                _ready_federates++;
                _federates_stamps[_federates_map.at(_federates_hash[hash])] = TIMESTAMP::READY;

                if(_ready_federates == _federates_count)
                        SendGoTimeStamp();
            }
            catch(std::out_of_range){}
        }
    }

    size_t FederationManager::ObjectInstanceClassHash::operator()(const rti1516e::ObjectInstanceHandle &obj) const noexcept{
        return static_cast<size_t>(obj.hash());
    }
}
