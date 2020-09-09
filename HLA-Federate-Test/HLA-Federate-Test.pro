TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -DRRTI -DFED_AMBASSADOR -DRRTI_EV -pthread
LIBS += -pthread
SOURCES += \
        ../BaseFederate.cpp \
        ../HLAdata/BasicException.cpp \
        ../HLAdata/Tools.cpp \
        ../Tools/Logger.cpp \
        ../ModelGuard.cpp \
        ../Tools/JSON.cpp \
        main.cpp

HEADERS += \
    ../BaseFederate.hpp \
    ../HLAdata/BasicException.hpp \
    ../HLAdata/BasicTemplates.hpp \
    ../HLAdata/HLAarray.hpp \
    ../HLAdata/HLAdata.hpp \
    ../HLAdata/HLAenum.hpp \
    ../HLAdata/HLAfixedRecod.hpp \
    ../HLAdata/HLAstring.hpp \
    ../HLAdata/HLAtypes.hpp \
    ../HLAdata/HLAvector.hpp \
    ../HLAdata/Tools.hpp \
    ../Tools/Logger.hpp \
    ../ModelGuard.hpp \
    ../Tools/JSON.hpp \
    FollowFederate.hpp \
    ThreadFederate.hpp
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
