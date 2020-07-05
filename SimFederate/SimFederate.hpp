#ifndef SIMFEDERATE_HPP
#define SIMFEDERATE_HPP
#include "BaseFederate.hpp"
#include "HLAdata/HLAdata.hpp"
namespace HLA {


    class SimFederate : public BaseFederate{
    public:
        SimFederate() noexcept;

        SimFederate(const std::wstring& name,
                      const std::wstring& type,
                      const std::wstring& FOMname,
                      const std::wstring& fname,
                      const std::wstring& ip = L"localhost") noexcept;

        SimFederate(std::wstring&& name,
                      std::wstring&& type,
                      std::wstring&& FOMname,
                      std::wstring&& fname,
                      std::wstring&& ip = L"localhost") noexcept;

        void SendToRTI(double value);
    private:

        void ParameterProcess();

        void reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                                      const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                                      const rti1516e::VariableLengthData &theUserSuppliedTag,
                                                      rti1516e::OrderType sentOrder,
                                                      rti1516e::TransportationType theType,
                                                      rti1516e::SupplementalReflectInfo theReflectInfo)
        throw (rti1516e::FederateInternalError);

         void receiveInteraction (
           rti1516e::InteractionClassHandle theInteraction,
           rti1516e::ParameterHandleValueMap const & theParameterValues,
           rti1516e::VariableLengthData const & theUserSuppliedTag,
           rti1516e::OrderType sentOrder,
           rti1516e::TransportationType theType,
           rti1516e::SupplementalReceiveInfo theReceiveInfo)
           throw (
              rti1516e::FederateInternalError);
    };


    class Staff{
    public:
        bool b = true;
        double f = 1.1;
        int i = 1;
        std::string s = "abds";
        char c = '-';
    };
//    class RTIStaff : public HLA::BaseFixedRecord<Staff,8>{
//    public:
//        // Получить данные из источника. Есть максимальный размер данных. (из RTI)
//        void getDataMax(void* ptrSource, unsigned long uiMaxSize);
//        //Получить из модельного новое RTI значение
//        void get(Staff const &obj);
//        //Получить из RTI-представления его модельное значение
//        void set(Staff &obj);
//    };
}
#endif // TRANSFER_HPP
