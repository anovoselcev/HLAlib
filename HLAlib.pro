CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++14

QMAKE_CXXFLAGS += -DRRTI -DFED_AMBASSADOR -DRRTI_EV -pthread
LIBS += -pthread

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BaseFederate.cpp \
    HLAdata/BasicException.cpp \
    HLAdata/Tools.cpp \
    ModelMutex.cpp

HEADERS += \
    BaseFederate.hpp \
    HLAdata/BasicException.hpp \
    HLAdata/BasicTemplates.hpp \
    HLAdata/BasicTypes.hpp \
    HLAdata/HLAdata.hpp \
    HLAdata/RTIarray.hpp \
    HLAdata/RTIenum.hpp \
    HLAdata/RTIfixedRecod.hpp \
    HLAdata/RTIstring.hpp \
    HLAdata/RTItypes.hpp \
    HLAdata/RTIvector.hpp \
    HLAdata/Tools.hpp \
    ModelMutex.hpp

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target

unix:!macx: LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
