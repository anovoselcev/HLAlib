#include"Analyzer.hpp"

namespace UPIM{

	using namespace std;
	using namespace rti1516e;

	AnalyzerFederate::AnalyzerFederate() noexcept{}


	AnalyzerFederate::AnalyzerFederate(const wstring& name,
						 const wstring& type,
						 const wstring& FOMname,
						 const wstring& ip,
						 const wstring& fname) noexcept :
								 UPIMFederate(name,type,FOMname,ip,fname) {}


	AnalyzerFederate::AnalyzerFederate(wstring&& name,
						 wstring&& type,
						 wstring&& FOMname,
						 wstring&& ip,
						 wstring&& fname) noexcept :
                                 UPIMFederate(std::move(name),std::move(type),std::move(FOMname),std::move(ip),std::move(fname)){}


	void AnalyzerFederate::RunFederate(){
        SetWindow();
	}

	void AnalyzerFederate::SetWindow(){
        _federates[L"First"] = DATA::DataFederate("First","Tank","Test");
        _federates[L"Second"] = DATA::DataFederate("Second","Tank","Test2");
        _federates[L"First"].AddAttribute(DATA::DataAttribute("Position","First",13.5));
        _federates[L"Second"].AddAttribute(DATA::DataAttribute("Position","Second",-0.33));
        _federates[L"Third"] = DATA::DataFederate("Third","Ship","Test3");
        _federates[L"Third"].AddAttribute(DATA::DataAttribute("Position","Third",-33));
        _MainWindow = make_unique<GRAPH::MainWindow>();
        _MainWindow->SetTree();
        _MainWindow->show();
        _MainWindow->SetInitialMap(_federates);
	}

}
