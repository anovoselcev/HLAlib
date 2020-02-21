#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>
namespace UPIM {

    namespace GRAPH {

        MainWindow::MainWindow(QWidget *parent)
            : QMainWindow(parent)
            , _ui(std::make_unique<Ui::MainWindow>())
        {
            _ui->setupUi(this);
        }

        MainWindow::~MainWindow()
        {

        }

        void MainWindow::SetTree() noexcept{
              //LOG_DURATION("SET_TREE")
              _ui->_mainTree->setColumnWidth(2,150);

        }

        void MainWindow::SetInitialMap(const std::unordered_map<std::wstring, UPIM::DATA::DataFederate>&_federates) noexcept{
            for(const auto& fed:_federates){
                QString type = fed.second.GetType();
                QString name = QString::fromStdWString(fed.first);
                if(_typesMap[type]==nullptr){
                    _typesMap[type] = std::make_unique<QTreeWidgetItem>();
                    _typesMap[type]->setText(0,type);
                    _ui->_mainTree->addTopLevelItem( _typesMap[type].get());
                }
                _namesMap[name] = std::make_unique<QTreeWidgetItem>();
                _namesMap[name]->setText(1,name);
                _namesMap[name]->setData(2,0,int(fed.second.GetAttributes().size()));
                _namesMap[name]->setText(3,fed.second.GetSemantic());
                auto target = _namesMap[name].get();
                _windowMap[target] = std::make_unique<QTreeWidget>();
                _windowMap[target]->setColumnCount(4);
                _windowMap[target]->setHeaderLabels(QStringList() << "Name" << "Value" << "Owner" << "Semantic");
                _windowMap[target]->setAttribute( Qt::WA_QuitOnClose, false);
                _windowMap[target]->setSortingEnabled(true);
                connect(this,&QMainWindow::destroyed,_windowMap[target].get(),&QTreeWidget::close);
                _typesMap[type]->addChild(_namesMap[name].get());
                _buttonsMap[_namesMap[name].get()] = std::make_unique<QPushButton>("Attributes");
                _ui->_mainTree->setItemWidget(_namesMap[name].get(),4,_buttonsMap[_namesMap[name].get()].get());
                connect(_buttonsMap[_namesMap[name].get()].get(), &QPushButton::clicked, _windowMap[target].get(), &QTreeWidget::show);
                for(const auto& attr:fed.second.GetAttributes()){
                    auto name = attr.GetName();
                    _attribMap[target][name] = std::make_unique<QTreeWidgetItem>();
                    _attribMap[target][name]->setText(0,name);
                    _attribMap[target][name]->setData(1,0,attr.GetValue());
                    _attribMap[target][name]->setText(2,attr.GetOwner());
                    _attribMap[target][name]->setText(3,attr.GetSemantic());
                    _windowMap[target]->addTopLevelItem(_attribMap[target][name].get());
                }
                _ui->_mainTree->setSortingEnabled(true);
            }
        }
    }
}
