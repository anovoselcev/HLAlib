#ifndef SIMFEDERATE_HPP
#define SIMFEDERATE_HPP
#include "BaseFederate.hpp"
#include "HLAdata/HLAdata.hpp"
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

    private:
        
        bool active_mode = false;
	
		void SendBulbFlashSignal(int&);

        void ParameterProcess() override;

        void AttributeProcess() override;

        void SendParameters() const override;
		
		void UpdateAttributes() const override;


	};
}
#endif // TRANSFER_HPP
