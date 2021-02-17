TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -DRRTI -DFED_AMBASSADOR -DRRTI_EV  -pthread -ftemplate-depth=5000
LIBS += -pthread
SOURCES += \
        ../BaseFederate.cpp \
        ../FederationManager.cpp \
        ../HLAdata/Tools.cpp \
        ../ProxyFederate.cpp \
        ../Tools/Logger.cpp \
        ../ModelGuard.cpp \
        ../Tools/JSON.cpp \
        main.cpp

HEADERS += \
    ../BaseFederate.hpp \
    ../FederationManager.hpp \
    ../HLAdata/BasicTemplates.hpp \
    ../HLAdata/HLAarray.hpp \
    ../HLAdata/HLAdata.hpp \
    ../HLAdata/HLAenum.hpp \
    ../HLAdata/HLAfixedRecod.hpp \
    ../HLAdata/HLAstring.hpp \
    ../HLAdata/HLAtypes.hpp \
    ../HLAdata/HLAvector.hpp \
    ../HLAdata/Tools.hpp \
    ../ProxyFederate.hpp \
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

win32:LIBS += -L$$PWD/../../rrti-2.0/RRTI-2.0.0164/lib/ -llibfedtime1516e

INCLUDEPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

win32: LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -llibrti1516e

INCLUDEPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

win32: LIBS += -L$$PWD/../../../rrti-2.0/RRTI-2.0.0164/lib/ -lrtiexec

INCLUDEPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010
DEPENDPATH += $$PWD/../../../rrti-2.0/RRTI-2.0.0164/include/HLA2010

unix:!macx: LIBS += -L$$PWD/../3dparty/tbb/lib/intel64/gcc4.8/ -ltbb

INCLUDEPATH += $$PWD/../3dparty/tbb/include/linux/
DEPENDPATH += $$PWD/../3dparty/tbb/include/linux/

INCLUDEPATH += $$PWD/../3dparty/tbb/include/windows/
DEPENDPATH += $$PWD/../3dparty/tbb/include/windows/


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3dparty/tbb/lib/intel64/vc14/ -ltbb12
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3dparty/tbb/lib/intel64/vc14/ -ltbb12_debug



INCLUDEPATH += $$PWD/../3dparty/boost_1_75_0/
DEPENDPATH += $$PWD/../3dparty/boost_1_75_0/

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../3dparty/boost_1_75_0/stage/lib/ -llibboost_date_time-vc142-mt-x64-1_74
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../3dparty/boost_1_75_0/stage/lib/ -llibboost_date_time-vc142-mt-gd-x64-1_74
