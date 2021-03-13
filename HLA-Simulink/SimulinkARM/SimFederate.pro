TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SimFederate.cpp \
        main.cpp



HEADERS += \
    SimFederate.hpp

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516ed

INCLUDEPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010/
DEPENDPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516ed

INCLUDEPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010/
DEPENDPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010/

win32: LIBS += -L$$PWD/../../../build-HLAlib-Desktop_Qt_5_14_1_MSVC2017_64bit-Release/release/ -lHLAlib

INCLUDEPATH += $$PWD/../../
DEPENDPATH += $$PWD/../../
