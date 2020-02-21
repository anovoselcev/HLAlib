#include"Analyzer.hpp"
#include <QDebug>
#include <random>
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
//        std::default_random_engine e;
//        std::uniform_int_distribution<int> dU(0,10);
//        std::normal_distribution<double> dN(0,100);
//        std::mt19937 mt(e());
//        //e.seed(1212);
//        auto randomU = [&mt,&dU](){
//            return dU(mt);
//        };
//        auto randomN = [&mt,&dN](){
//            return dN(mt);
//        };
//        double t = randomN();
//        qDebug() << t << " " <<endl;
//        for(int i = 0;i<1000;i++){
//            wstring wname = to_wstring(i);
//            QString qname = QString(i);
//            _federates[wname] = DATA::DataFederate(qname,QString::fromStdString(to_string(randomU())),QString::fromStdString(to_string(randomU())));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i),qname,randomN()));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i+1),qname,randomN()));
//            _federates[wname].AddAttribute(DATA::DataAttribute(QString(i+1),qname,QString(i)+" "+qname));
//        }
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
////        qDebug() <<"Load factor = "<< _federates.load_factor() << endl;
       _MainWindow->SetInitialMap(_federates);
	}

}
