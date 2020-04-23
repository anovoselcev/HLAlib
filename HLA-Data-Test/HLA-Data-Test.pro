TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -DRRTI -DFED_AMBASSADOR -DRRTI_EV -pthread
LIBS += -pthread
SOURCES += \
        main.cpp\
        ../src/*
HEADERS+=../include/* \
    TestBaseRTIstring.hpp \
    TestRTIarray.hpp \
    TestRTIvector.hpp \
    TestSimpleData.hpp \
    TetsRTIfixedRecord.hpp \
    test_runner.hpp

unix:!macx: LIBS += -L$$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
