#include "Analyzer.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UPIM::AnalyzerFederate an(L"fed2",L"Laser",L"../FOMS/TimeModel.xml");
    an.SetPublishMapOfAttributes({L"Angle", L"Aim", L"Var",L"Ar"});
    an.SetSubscribeMapOfObjectsAndAttributes({{L"Aircraft",{L"Speed",L"Name"}},{L"Laser",{L"Angle",L"Aim",L"Var",L"Ar"}}});
    an.SetMapOfInteractionsAndParameters({{L"Communication",{L"Message"}}});
    an.ConnectRRTI();
    return a.exec();
}
