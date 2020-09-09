TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        SimFederate.cpp \
        main.cpp

unix:!macx: LIBS += -L$$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

INCLUDEPATH += $$PWD/../../../../../QtWork/HLA/HLAlib/
DEPENDPATH += $$PWD/../../../../../QtWork/HLA/HLAlib/

HEADERS += \
    SimFederate.hpp
