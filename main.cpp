//#include "mainwindow.h"
#include "Analyzer.hpp"
#include "MainWindow.hpp"
#include <QApplication>
#include <QMenuBar>
#include <QTreeWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UPIM::AnalyzerFederate an(L"fe",L"Laser",L"../FOMS/TimeModel.xml");
    an.SetMapOfObjectsAndAttributes({{L"Aircraft",{L"Speed",L"Name"}},{L"Laser",{L"Angle"}}});
    an.SetMapOfInteractionsAndParameters({{L"Communication",{L"Message"}}});
    an.ConnectRRTI();
    return a.exec();
}
