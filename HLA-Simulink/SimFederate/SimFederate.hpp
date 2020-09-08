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
					  
		SimFederate(const HLA::JSON& file);
		
		SimFederate(HLA::JSON&& file);

        void SendToRTI(double value);
    private:

        void ParameterProcess();
		
		void UpdateAttributes() const override;


	};
}
#endif // TRANSFER_HPP
