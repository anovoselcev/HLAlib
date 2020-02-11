#include "MainWindow.hpp"
#include <QPushButton>
#include <QDebug>

namespace UPIM {

    namespace GRAPH {

        MainWindow::MainWindow() noexcept{
            resize(_width,_height);
        }

        MainWindow::MainWindow(int w, int h) noexcept : _width(w), _height(h) {
            resize(_width,_height);
        }

        void MainWindow::SetTree() noexcept{
            _mainTree = std::make_unique<QTreeWidget>(this);
            _mainTree->resize(this->_width,this->_height);
            _mainTree->setColumnCount(5);
            _mainTree->setHeaderLabels(QStringList() << "Type" << "Name" << "Number Attributes" << "Semantic" <<"" );
            _mainTree->setColumnWidth(2,120);
            //_mainTree->setItemWidget(chld,4,new QPushButton("Click Me"));
        }

        void MainWindow::SetInitialMap(const std::unordered_map<std::wstring, DATA::DataFederate>& _federates) noexcept{
            for(const auto& fed:_federates){
                QString type = fed.second.GetType();
                QString name = QString::fromStdWString(fed.first);
                if(_typesMap[type]==nullptr){
                    _typesMap[type] = std::make_unique<QTreeWidgetItem>();
                    _typesMap[type]->setText(0,type);
                    _mainTree->addTopLevelItem( _typesMap[type].get());
                }
                _namesMap[name] = std::make_unique<QTreeWidgetItem>();
                _namesMap[name]->setText(1,name);
                _namesMap[name]->setText(2,QString::fromStdString(std::to_string(fed.second.GetAttributes().size())));
                _namesMap[name]->setText(3,fed.second.GetSemantic());
                auto target = _namesMap[name].get();
                _windowMap[target] = std::make_unique<QTreeWidget>();
                _windowMap[target]->setColumnCount(4);
                _windowMap[target]->setHeaderLabels(QStringList() << "Name" << "Value" << "Owner" << "Semantic");
                _windowMap[target]->setAttribute( Qt::WA_QuitOnClose, false );
                connect(this,&QMainWindow::destroyed,_windowMap[target].get(),&QTreeWidget::close);
                _typesMap[type]->addChild(_namesMap[name].get());
                _buttonsMap[_namesMap[name].get()] = std::make_unique<QPushButton>("Attributes");
                _mainTree->setItemWidget(_namesMap[name].get(),4,_buttonsMap[_namesMap[name].get()].get());
                connect(_buttonsMap[_namesMap[name].get()].get(), &QPushButton::clicked, _windowMap[target].get(), &QTreeWidget::show);
                for(const auto& attr:fed.second.GetAttributes()){
                    auto name = attr.GetName();
                    _attribMap[target][name] = std::make_unique<QTreeWidgetItem>();
                    _attribMap[target][name]->setText(0,name);
                    _attribMap[target][name]->setText(1,QString(attr.GetValue().toString()));
                    _attribMap[target][name]->setText(2,attr.GetOwner());
                    _attribMap[target][name]->setText(3,attr.GetSemantic());
                    _windowMap[target]->addTopLevelItem(_attribMap[target][name].get());
                }
            }
        }


    }

}
