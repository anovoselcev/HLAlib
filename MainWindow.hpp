#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <memory>
#include <unordered_map>
#include "DataFederate.hpp"
#include <QPushButton>
#include <QGridLayout>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
namespace UPIM{

    namespace GRAPH{

        class MainWindow : public QMainWindow
        {
            Q_OBJECT

        public:
            MainWindow(QWidget *parent = nullptr);

            void SetTree() noexcept;

            void SetInitialMap(const std::unordered_map<std::wstring, DATA::DataFederate>&) noexcept;

            ~MainWindow();

        private:
            std::unique_ptr<Ui::MainWindow>                                                                                      _ui;
            std::unordered_map<QString, std::unique_ptr<QTreeWidgetItem>,DATA::QStringHash>                                      _typesMap;
            std::unordered_map<QString, std::unique_ptr<QTreeWidgetItem>,DATA::QStringHash>                                      _namesMap;
            std::unordered_map<QTreeWidgetItem*, std::unique_ptr<QTreeWidget>>                                                   _windowMap;
            std::unordered_map<QTreeWidgetItem*, std::unique_ptr<QPushButton>>                                                   _buttonsMap;
            std::unordered_map<QTreeWidgetItem*, std::unordered_map<QString,std::unique_ptr<QTreeWidgetItem>,DATA::QStringHash>> _attribMap;
            int _width = 550;
            int _height = 600;
        };
    }
}
#endif // MAINWINDOW_H
