#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTreeWidget>
#include <memory>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <QMenuBar>
#include "DataFederate.hpp"
#include <QPushButton>

namespace UPIM {

    namespace GRAPH {

    class MainWindow : public QMainWindow{

        Q_OBJECT

    public:

        MainWindow() noexcept;

        MainWindow(int w, int h) noexcept;

        MainWindow(const MainWindow&) = delete;

        MainWindow(MainWindow&&) = delete;

        MainWindow& operator=(const MainWindow&) = delete;

        MainWindow& operator=(MainWindow&&) = delete;

        void SetTree() noexcept;

        void SetInitialMap(const std::unordered_map<std::wstring, DATA::DataFederate>&) noexcept;


    signals:

        void closeAll();

        //void Update() noexcept;

    protected:

       // void MainWindow::closeEvent( QCloseEvent* event ) override;

        std::unique_ptr<QTreeWidget> _mainTree;
        std::map<QString, std::unique_ptr<QTreeWidgetItem>> _typesMap;
        std::map<QString, QTreeWidgetItem*> _namesMap;
        std::unordered_map<QTreeWidgetItem*, QTreeWidget*> _windowMap;
        std::unordered_map<QTreeWidgetItem*, QPushButton*> _buttonsMap;
        std::unordered_map<QTreeWidgetItem*,std::map<QString,QTreeWidgetItem*>> _attribMap;
        int _width = 550;
        int _height = 600;
        QMenuBar qm;
        QMenu m1,m2;
    };

    }
}

#endif // MAINWINDOW_HPP
