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
    FederationManager.cpp \
    HLA-Simulink/SimFederate/SimFederate.cpp \
    HLAdata/Tools.cpp \
    ProxyFederate.cpp \
    Tools/Logger.cpp \
    ModelGuard.cpp\
    Tools/JSON.cpp

HEADERS += \
    FederationManager.hpp \
    HLA-Simulink/SimFederate/SimFederate.hpp \
    HLA-Simulink/SimFederate/Strategy.hpp \
    HLAdata/BasicTemplates.hpp \
    HLAdata/BasicTypes.hpp \
    HLAdata/HLA*.hpp\
    HLAdata/HLAvariant.hpp \
    HLAdata/NewDataTypes.hpp \
    HLAdata/Tools.hpp \
    ProxyFederate.hpp \
    Tools/Logger.hpp \
    ModelGuard.hpp \
    *Federate.hpp \
    Tools/JSON.hpp

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



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516ed

INCLUDEPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010



win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516ed

INCLUDEPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -lrtiexec
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -lrtiexecd

INCLUDEPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010


unix:!macx: LIBS += -L$$PWD/3dparty/tbb/lib/intel64/gcc4.8/ -ltbb

INCLUDEPATH += $$PWD/3dparty/tbb/include/linux/
DEPENDPATH += $$PWD/3dparty/tbb/include/linux/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/3dparty/tbb/lib/intel64/vc14/ -ltbb12
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/3dparty/tbb/lib/intel64/vc14/ -ltbb12_debug


INCLUDEPATH += $$PWD/3dparty/tbb/include/windows/
DEPENDPATH += $$PWD/3dparty/tbb/include/windows/


INCLUDEPATH += $$PWD/3dparty/magic_get-develop/include/
DEPENDPATH += $$PWD/3dparty/magic_get-develop/include/

INCLUDEPATH += $$PWD/3dparty/boost_1_74_0/
DEPENDPATH += $$PWD/3dparty/boost_1_74_0/

