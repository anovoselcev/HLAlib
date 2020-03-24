#ifndef TRANSFER_HPP
#define TRANSFER_HPP
#include "UPIM.hpp"
#include "include_sup/BasicData.hpp"
namespace UPIM {


    class Transfer : public UPIMFederate{
    public:
        Transfer() noexcept;

        Transfer(const std::wstring& name,
                      const std::wstring& type,
                      const std::wstring& FOMname,
                      const std::wstring& ip = L"localhost",
                      const std::wstring& fname = L"UPIM") noexcept;

        Transfer(std::wstring&& name,
                      std::wstring&& type,
                      std::wstring&& FOMname,
                      std::wstring&& ip = L"localhost",
                      std::wstring&& fname = L"UPIM") noexcept;

        void SendToRTI(double value);
    private:
        void reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                                      const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                                      const rti1516e::VariableLengthData &theUserSuppliedTag,
                                                      rti1516e::OrderType sentOrder,
                                                      rti1516e::TransportationType theType,
                                                      rti1516e::SupplementalReflectInfo theReflectInfo)
        throw (rti1516e::FederateInternalError);
    };

    class Staff{
    public:
        HLA::Byte b = true;
        HLA::Float64BE f = 1.1;
        HLA::Integer16BE i = 1;
        HLA::String s = "abds";
        HLA::Char c = '-';
    };
    class RTIStaff : public HLA::BaseRTIFixedRecord<Staff,8>{
    public:
        // Получить данные из источника. Есть максимальный размер данных. (из RTI)
        void getDataMax(void* ptrSource, unsigned long uiMaxSize);
        //Получить из модельного новое RTI значение
        void get(Staff const &obj);
        //Получить из RTI-представления его модельное значение
        void set(Staff &obj);
    };
}
#endif // TRANSFER_HPP
