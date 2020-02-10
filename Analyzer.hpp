#ifndef ANALYZER_HPP
#define ANALYZER_HPP 1

#include "UPIM.hpp"
//#include "MenuBar.hpp"
#include "DataFederate.hpp"
#include "MainWindow.hpp"
//#include "mainwindow.h"
#include <QTreeWidget>
#include <map>


namespace UPIM{

	class Data;
    class AnalyzerFederate : public QObject, public UPIMFederate{

    Q_OBJECT

	public:
		AnalyzerFederate() noexcept;


		AnalyzerFederate(const std::wstring& name,
					 const std::wstring& type,
					 const std::wstring& FOMname,
					 const std::wstring& ip = L"localhost",
					 const std::wstring& fname = L"UPIM") noexcept;


		AnalyzerFederate(std::wstring&& name,
					 std::wstring&& type,
					 std::wstring&& FOMname,
					 std::wstring&& ip = L"localhost",
					 std::wstring&& fname = L"UPIM") noexcept;

		~AnalyzerFederate();

		AnalyzerFederate(const AnalyzerFederate& armfed) = delete;

		AnalyzerFederate(AnalyzerFederate&& armfed) = delete;

		AnalyzerFederate& operator=(const AnalyzerFederate& armfed) = delete;

		AnalyzerFederate& operator=(AnalyzerFederate&& armfed) = delete;

		void foo() noexcept;

		void Run() noexcept;

        virtual void RunFederate() override;

        virtual void SetWindow();

        virtual void SetListBox();

	protected:

        std::unique_ptr<GRAPH::MainWindow> _MainWindow;
        //std::unique_ptr<QTreeWidget>
        std::unordered_map<std::wstring,DATA::DataFederate> _federates;
		std::map<std::wstring,unsigned> _typesMap;
	};
}


#endif
