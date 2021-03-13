TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SimFederate.cpp \
        main.cpp



HEADERS += \
    SimFederate.hpp


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516ed

INCLUDEPATH += $$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516ed

INCLUDEPATH += $$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../3dparty/tbb/lib/intel64/vc14/ -ltbb12
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../3dparty/tbb/lib/intel64/vc14/ -ltbb12d

INCLUDEPATH += $$PWD/../../../3dparty/tbb/include/windows
DEPENDPATH += $$PWD/../../../3dparty/tbb/include/windows

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../lib/windows/ -lHLAlib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../lib/windows/ -lHLAlibd

INCLUDEPATH += $$PWD/../../../
DEPENDPATH += $$PWD/../../../

INCLUDEPATH += $$PWD/../../../3dparty/magic_get-develop/include
DEPENDPATH += $$PWD/../../../3dparty/magic_get-develop/include
