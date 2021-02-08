#ifndef SIMFEDERATE_HPP
#define SIMFEDERATE_HPP
#include "BaseFederate.hpp"
#include "HLAdata/HLAdata.hpp"
namespace HLA {
    
    
    class SimFederate : public BaseFederate{
    public:

        SimFederate() = delete;
        
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
        
        SimFederate(const HLA::JSON& file) noexcept;
        
        SimFederate(HLA::JSON&& file) noexcept;
        
        void SendDataToRTI();
        
        std::unordered_map<std::wstring, rti1516e::VariableLengthData>& getInputData();
        
        std::unordered_map<std::wstring, rti1516e::VariableLengthData>& getOutputData();
        
        
    private:

        struct Strategy{
            virtual void Action(const rti1516e::ParameterHandleValueMap& data) = 0;
            virtual ~Strategy() = default;
        };

        struct PushButton : public Strategy{
            void Action(const rti1516e::ParameterHandleValueMap &data) override;
        };

        struct SwitchTumbler : public Strategy{
            void Action(const rti1516e::ParameterHandleValueMap &data) override;
        };

        std::unique_ptr<Strategy> MakeStrategy(const rti1516e::InteractionClassHandle& handle);

        void AttributeProcess(rti1516e::ObjectClassHandle &handle,
                              rti1516e::AttributeHandleValueMap &data,
                              rti1516e::VariableLengthData &info) override;

        void ParameterProcess(rti1516e::InteractionClassHandle &handle,
                              rti1516e::ParameterHandleValueMap &data,
                              rti1516e::VariableLengthData &info) override;
        
        
        void SendParameters() const override;
        
        void UpdateAttributes() const override;
        
        std::unordered_map<std::wstring, rti1516e::VariableLengthData> input;
        std::unordered_map<std::wstring, rti1516e::VariableLengthData> output;
        
    };
}
#endif // TRANSFER_HPP
