#ifndef SIMFEDERATE_HPP
#define SIMFEDERATE_HPP
#include "BaseFederate.hpp"
#include "HLAdata/HLAdata.hpp"
#include "Tools/Formater.hpp"

namespace HLA {
    
    enum Appoitment{
        ON_OFF,
        DO_NOTHING
    };
    
	struct Button{
		int push = 0;
		int button_id;
		int bulb_id;
		std::wstring model_name;
        Appoitment action = Appoitment::DO_NOTHING;
	};

	struct Tumbler{
		int state = 0;
		std::string tumbler_id;
	};
    

    class SimFederate : public BaseFederate{
    public:

					  
        SimFederate(const HLA::JSON& file) noexcept;
		
        SimFederate(HLA::JSON&& file) noexcept;
        
        void SendDataToRTI(const std::unordered_map<std::wstring, rti1516e::VariableLengthData>& output_data,
						   const std::string& info);
        
        std::unordered_map<std::wstring, rti1516e::VariableLengthData>& getData();

    protected:

        struct Strategy{
            Strategy(SimFederate* ptr);
            virtual void Action(const rti1516e::ParameterHandleValueMap& data) = 0;
            virtual ~Strategy() = default;
            SimFederate* _ptr = nullptr;
        };

        struct TurnModel : public Strategy{
            using Strategy::Strategy;
            void Action(const rti1516e::ParameterHandleValueMap &data) override;
        };

        struct SwitchTumbler : public Strategy{
            void Action(const rti1516e::ParameterHandleValueMap &data) override;
        };

        std::unique_ptr<Strategy> MakeStrategy(const rti1516e::InteractionClassHandle& handle);

    private:
        
        bool active_mode = true;
	
		void SendBulbFlashSignal(int&);

        void AttributeProcess(rti1516e::ObjectClassHandle &handle,
                              rti1516e::AttributeHandleValueMap &data,
                              rti1516e::VariableLengthData &info) override;

        void ParameterProcess(rti1516e::InteractionClassHandle &handle,
                              rti1516e::ParameterHandleValueMap &data,
                              rti1516e::VariableLengthData &info) override;

        void SendParameters() const override;
		
		void UpdateAttributes() const override;
		
		void RunFederate() override;
        
        std::unordered_map<std::wstring, rti1516e::VariableLengthData> inpt;

		friend Strategy;
		friend TurnModel;
	};
}
#endif // TRANSFER_HPP
