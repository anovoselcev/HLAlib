#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->treeWidget->setColumnCount(2);
     QList<QTreeWidgetItem *> items;
    for (int i = 0; i < 10; ++i)
    items.append(new QTreeWidgetItem((QTreeWidget*)0, QStringList(QString("item: %1").arg(i))));
    ui->treeWidget->insertTopLevelItems(0, items);
  ui->treeWidget->setItemWidget(items.value(1),1,new QPushButton("Click Me"));
//    QWidget *dualPushButtons = new QWidget();
//    QHBoxLayout *hLayout = new QHBoxLayout();
//    hLayout->addWidget(new QPushButton("Button1"));
//    hLayout->addWidget(new QPushButton("Button2"));
//    dualPushButtons->setLayout(hLayout);

 //   ui->treeWidget->setItemWidget(items.value(1),0,dualPushButtons);
//    QTreeWidgetItem *itm = new QTreeWidgetItem();

//    QTreeWidgetItem *itmb = new QTreeWidgetItem();

//        //Создание столбцов элемента дерева, первым параметром передается целочисленное
//        //значение которое указывает на индекс(номер столбца), а второй параметр
//        //присваивает текст данному столбцу верхнего уровня
//        itm->setText(0, "Столбец №1"); // При помощи метода setText мы устанавливаем индекс и текст элемента
//        itm->setText(1, "Столбец №2"); // который в дальнейшем будет использоваться для верхнего уровня
//        itm->setText(2, "Столбец №3");
//        itm->setText(3, "Столбец №4");
//        itm->setText(4, "Столбец №5");

//        // Здесь через обращение к объекту itm и метод setBackgroundColor(); мы задаем цвет фона конкретной ячейки нашего дерева.
//        //Индекс ячейки передается по аналогии с предыдущим примером
//        itm->setBackgroundColor(0, Qt::red);   // В данном примере в качестве задания
//        itm->setBackgroundColor(1, Qt::blue);  // цвета фона используется перечисление цветов из базового класса Qt
//        itm->setBackgroundColor(2, Qt::yellow);
//        itm->setBackgroundColor(3, Qt::green);
//        itm->setBackgroundColor(4, Qt::gray);

//        // В данных строках кода задается цвет самого текста по аналогии с примером где мы задавали цвет фона конкретной ячейки
//        itm->setTextColor(0, QColor(255,255,255,255));  // В данном примере мы используем для задания цвета конструктор базового класса QColor.
//        itm->setTextColor(1, QColor(255,255,255,255));  // Первые три значения от 0 до 255 задают по системе RGB интенсивность цвета
//        itm->setTextColor(2, QColor(200,0,100,255));    // Последнее четвертое значение задает прозрачность данного эффекта
//        itm->setTextColor(3, QColor(200,0,100,255));
//        itm->setTextColor(4, QColor(255,255,255,255));


//        ui->treeWidget->setColumnCount(7);  // Создаем необходимое количество столбцов. Данным методом можно скрывать не используемые столбцы

//        ui->treeWidget->addTopLevelItem(itm);   // Здесь мы устанавливаем в качестве верхнего уровня наш элемент itm

//        // Создание дочерних элементов для itm
//        QTreeWidgetItem *child = new QTreeWidgetItem();
//        QTreeWidgetItem *child2 = new QTreeWidgetItem();
//        QTreeWidgetItem *child3 = new QTreeWidgetItem();
//        QTreeWidgetItem *child4 = new QTreeWidgetItem();

//        // Задание индекса и текста дочерним элементам для верхнего уровня элемента itm
//        child->setText(0, "Текст ребенка 1 - 1 столбец");
//        child2->setText(0, "Текст ребенка 2 - 1 столбец");
//        child3->setText(1, "Текст ребенка 1 - 2 столбец");
//        child4->setText(2, "Текст ребенка 2 - 3 столбец");
//        // Присваивание фонового цвета дочерним элементам по индексу. Работает по аналогии с присваиванием цвета основному элементу
//        child->setBackgroundColor(0, Qt::blue);
//        child2->setBackgroundColor(0, Qt::yellow);
//        child3->setBackgroundColor(1, Qt::green);
//        child4->setBackgroundColor(2, Qt::gray);
//        // Привязка дочерних элементов к itm верхнего уровня
//        itm->addChild(child);
//        itm->addChild(child2);
//        itm->addChild(child3);
//        itm->addChild(child4);

//        //Второй уровень
//        QTreeWidgetItem *itm2 = new QTreeWidgetItem();

//        itm2->setText(0, "Столбец №1");
//        itm2->setText(1, "Столбец №2");
//        itm2->setText(2, "Столбец №3");
//        itm2->setText(3, "Столбец №4");
//        itm2->setText(4, "Столбец №5");

//        itm2->setBackgroundColor(0, Qt::red);
//        itm2->setBackgroundColor(1, Qt::blue);
//        itm2->setBackgroundColor(2, Qt::yellow);
//        itm2->setBackgroundColor(3, Qt::green);
//        itm2->setBackgroundColor(4, Qt::gray);

//        itm2->setTextColor(0, QColor(255,255,255,255));
//        itm2->setTextColor(1, QColor(255,255,255,255));
//        itm2->setTextColor(2, QColor(200,0,100,255));
//        itm2->setTextColor(3, QColor(200,0,100,255));
//        itm2->setTextColor(4, QColor(255,255,255,255));

//        ui->treeWidget->addTopLevelItem(itm2);

//        QTreeWidgetItem *child11 = new QTreeWidgetItem();
//        QTreeWidgetItem *child22 = new QTreeWidgetItem();
//        QTreeWidgetItem *child33 = new QTreeWidgetItem();
//        QTreeWidgetItem *child44 = new QTreeWidgetItem();

//        child11->setText(2, "Текст ребенка 2 - 2 столбец");
//        child22->setText(3, "Текст ребенка 2 - 4 столбец");

//        child33->setText(4, "Текст ребенка 2 - 5 столбец");
//        child44->setText(1, "Текст ребенка 2 - 2 столбец");

//        child11->setBackgroundColor(2, Qt::blue);
//        child22->setBackgroundColor(3, Qt::yellow);
//        child33->setBackgroundColor(4, Qt::green);
//        child44->setBackgroundColor(1, Qt::gray);

//        itm2->addChild(child11);
//        itm2->addChild(child22);
//        itm2->addChild(child33);
//        itm2->addChild(child44);
}

MainWindow::~MainWindow()
{
    delete ui;
}

