CONFIG -= qt

TEMPLATE = lib
CONFIG+= staticlib
DEFINES += HLATYPES_LIBRARY

CONFIG += c++14
CONFIG += WIN32
QMAKE_CXXFLAGS += -DRRTI -DRRTI_EV -DFED_AMBASSADOR
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
    BasicException.cpp \
    Tools.cpp

HEADERS += \
    BasicException.hpp \
    BasicTemplates.hpp \
    HLA*.hpp\
    Tools.hpp

# Default rules for deployment.
unix {
    target.path = /usr/lib
}
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/rrti-2.0.0164/lib/ -llibrti1516e
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/rrti-2.0.0164/lib/ -llibrti1516ed

INCLUDEPATH += C:/rrti-2.0.0164/include/HLA2010
DEPENDPATH += C:/rrti-2.0.0164/include/HLA2010

win32:CONFIG(release, debug|release): LIBS += -LC:/rrti-2.0.0164/lib/ -llibfedtime1516e
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/rrti-2.0.0164/lib/ -llibfedtime1516ed

INCLUDEPATH += C:/rrti-2.0.0164/include/HLA2010
DEPENDPATH += C:/rrti-2.0.0164/include/HLA2010
