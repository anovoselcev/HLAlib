#ifndef ANALYZER_HPP
#define ANALYZER_HPP 1

#include "../UPIM/UPIM.hpp"
#include "DataFederate.hpp"
#include "MainWindow.hpp"
#include "../HLA-Data/include/BasicData.hpp"


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

        void Update(double value=0);

	protected:

        void UpdateAttributes() const override;

        void reflectAttributeValues(rti1516e::ObjectInstanceHandle theObject,
                                                      const rti1516e::AttributeHandleValueMap &theAttributeValues,
                                                      const rti1516e::VariableLengthData &theUserSuppliedTag,
                                                      rti1516e::OrderType sentOrder,
                                                      rti1516e::TransportationType theType,
                                                      rti1516e::SupplementalReflectInfo theReflectInfo)
        throw (rti1516e::FederateInternalError);

//Pointer to the main widget
        std::unique_ptr<GRAPH::MainWindow> _MainWindow;
//Federation info base
        std::unordered_map<std::wstring,DATA::DataFederate> _federates;
	};
}


#endif
