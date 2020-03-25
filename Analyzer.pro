QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    MainWindow.cpp \
    main.cpp \
    Analyzer.cpp\
    ../UPIM/UPIM.cpp\
    DataAttribute.cpp\
    DataFederate.cpp\
    ../HLA-Data/src/*

HEADERS += \
    Analyzer.hpp\
    MainWindow.hpp \
    ../UPIM/UPIM.hpp\
    DataAttribute.hpp\
    DataFederate.hpp \
    ../HLA-Data/include/*\
    profile.hpp \

FORMS += mainwindow.ui\

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/release/ -lrti1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/debug/ -lrti1516e
else:unix: LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lrti1516e

INCLUDEPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/release/ -lfedtime1516e
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/debug/ -lfedtime1516e
else:unix: LIBS += -L$$PWD/../../../Desktop/RRTI/rrti-2.0.0164/bin/ -lfedtime1516e

INCLUDEPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../Desktop/RRTI/rrti-2.0.0164/include/HLA2010
