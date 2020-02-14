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
        _federates[L"A"] = DATA::DataFederate("First","A","Test");
        _federates[L"B"] = DATA::DataFederate("Second","A","Test2");
        _federates[L"A"].AddAttribute(DATA::DataAttribute("A","First",13.5));
        _federates[L"A"].AddAttribute(DATA::DataAttribute("C","First",20));
        _federates[L"A"].AddAttribute(DATA::DataAttribute("B","First","A"));
        _federates[L"B"].AddAttribute(DATA::DataAttribute("A","Second",-0.33));
        _federates[L"C"] = DATA::DataFederate("Third","B","Test3");
        _federates[L"C"].AddAttribute(DATA::DataAttribute("A","Third",-33));
        _MainWindow = make_unique<GRAPH::MainWindow>();
        _MainWindow->SetTree();
        _MainWindow->show();
        _MainWindow->SetInitialMap(_federates);
	}

}
