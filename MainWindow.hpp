#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QTreeWidget>
#include <memory>
#include <map>
#include <unordered_map>
#include "DataFederate.hpp"
#include <QPushButton>

namespace UPIM {

    namespace GRAPH {

//Main Widget, which shows federation state
    class MainWindow : public QMainWindow{

        Q_OBJECT

    public:

//Default constructor
        MainWindow() noexcept;

//Constructor with size
        MainWindow(int w, int h) noexcept;

//Copy constructor
        MainWindow(const MainWindow&) = delete;

//Move constructor
        MainWindow(MainWindow&&) = delete;

//Copy assigment operator
        MainWindow& operator=(const MainWindow&) = delete;

//Move assigment operator
        MainWindow& operator=(MainWindow&&) = delete;

//Init TreeWidget
        void SetTree() noexcept;

//Set initial conditional of federation and show it
        void SetInitialMap(const std::unordered_map<std::wstring, DATA::DataFederate>&) noexcept;

        //void Update() noexcept;

    protected:


        std::unique_ptr<QTreeWidget> _mainTree;
        std::map<QString, std::unique_ptr<QTreeWidgetItem>> _typesMap;
        std::map<QString, std::unique_ptr<QTreeWidgetItem>> _namesMap;
        std::unordered_map<QTreeWidgetItem*, std::unique_ptr<QTreeWidget>> _windowMap;
        std::unordered_map<QTreeWidgetItem*, std::unique_ptr<QPushButton>> _buttonsMap;
        std::unordered_map<QTreeWidgetItem*, std::map<QString,std::unique_ptr<QTreeWidgetItem>>> _attribMap;
        int _width = 550;
        int _height = 600;
    };

    }
}

#endif // MAINWINDOW_HPP
