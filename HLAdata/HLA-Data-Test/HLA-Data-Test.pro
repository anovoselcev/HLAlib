TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -DRRTI -DFED_AMBASSADOR -DRRTI_EV
SOURCES += main.cpp \
    ../BasicException.cpp \
    ../Tools.cpp
HEADERS+= \
    ../BasicException.hpp \
    ../BasicTemplates.hpp \
    ../HLAarray.hpp \
    ../HLAdata.hpp \
    ../HLAenum.hpp \
    ../HLAfixedRecod.hpp \
    ../HLAstring.hpp \
    ../HLAtypes.hpp \
    ../HLAvector.hpp \
    ../Tools.hpp \
    TestBaseRTIstring.hpp \
    TestHLAenum.hpp \
    TestRTIarray.hpp \
    TestRTIvector.hpp \
    TestSimpleData.hpp \
    TetsRTIfixedRecord.hpp \
    profile.hpp \
    test_runner.hpp

unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target




unix:!macx: LIBS += -L$$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
