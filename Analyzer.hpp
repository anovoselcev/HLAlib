#ifndef ANALYZER_HPP
#define ANALYZER_HPP 1

#include "UPIM.hpp"
#include "DataFederate.hpp"
#include "MainWindow.hpp"
#include "include_sup/BasicData.hpp"


namespace UPIM{

//Federate  for federation analysis(Widget)
    class AnalyzerFederate : public QObject, public UPIMFederate{

    Q_OBJECT

	public:
//Default constructor
		AnalyzerFederate() noexcept;

//Full-gapes lvalue constructor
		AnalyzerFederate(const std::wstring& name,
					 const std::wstring& type,
					 const std::wstring& FOMname,
					 const std::wstring& ip = L"localhost",
					 const std::wstring& fname = L"UPIM") noexcept;

//Full-gapes rvalue constructor
		AnalyzerFederate(std::wstring&& name,
					 std::wstring&& type,
					 std::wstring&& FOMname,
					 std::wstring&& ip = L"localhost",
					 std::wstring&& fname = L"UPIM") noexcept;

//Copy constructor
		AnalyzerFederate(const AnalyzerFederate& armfed) = delete;

//Move constructor
		AnalyzerFederate(AnalyzerFederate&& armfed) = delete;

//Copy assignment operator
		AnalyzerFederate& operator=(const AnalyzerFederate& armfed) = delete;

//Move assignment operator
		AnalyzerFederate& operator=(AnalyzerFederate&& armfed) = delete;

//Main federate loop
        virtual void RunFederate() override;

//Create and init widget
        virtual void SetWindow();

	protected:

        void UpdateAttributes() const override;

//Pointer to the main widget
        std::unique_ptr<GRAPH::MainWindow> _MainWindow;
//Federation info base
        std::unordered_map<std::wstring,DATA::DataFederate> _federates;
	};
}


#endif
