CONFIG -= qt

TEMPLATE = lib
#CONFIG += staticlib

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
    HLA-Simulink/HLAblock_grt_rtw/HLAblock.cpp \
    HLA-Simulink/HLAblock_grt_rtw/HLAblock_data.cpp \
    HLA-Simulink/SimFederate/SimFederate.cpp \
    HLA-Simulink/SimFederate/main.cpp \
    HLA-Simulink/TransferBlock.cpp \
    HLA-Simulink/TransferBlock_wrapper.cpp \
    HLAdata/BasicException.cpp \
    HLAdata/Tools.cpp \
    Logger.cpp \
    ModelGuard.cpp

HEADERS += \
    HLA-Simulink/HLAblock_grt_rtw/HLAblock.h \
    HLA-Simulink/HLAblock_grt_rtw/HLAblock_private.h \
    HLA-Simulink/HLAblock_grt_rtw/HLAblock_types.h \
    HLA-Simulink/HLAblock_grt_rtw/multiword_types.h \
    HLA-Simulink/HLAblock_grt_rtw/rtmodel.h \
    HLA-Simulink/HLAblock_grt_rtw/rtwtypes.h \
    HLA-Simulink/SimFederate/SimFederate.hpp \
    HLAdata/BasicException.hpp \
    HLAdata/BasicTemplates.hpp \
    HLAdata/BasicTypes.hpp \
    HLAdata/HLA*.hpp\
    HLAdata/Tools.hpp \
    Logger.hpp \
    ModelGuard.hpp \
    *Federate.hpp

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

DISTFILES += \
    HLA-Simulink/HLAblock \
    HLA-Simulink/HLAblock.slx \
    HLA-Simulink/HLAblock.slxc \
    HLA-Simulink/HLAblock_grt_rtw/HLAblock.mk \
    HLA-Simulink/HLAblock_grt_rtw/buildInfo.mat \
    HLA-Simulink/HLAblock_grt_rtw/build_exception.mat \
    HLA-Simulink/HLAblock_grt_rtw/codeInfo.mat \
    HLA-Simulink/HLAblock_grt_rtw/codedescriptor.dmr \
    HLA-Simulink/HLAblock_grt_rtw/compileInfo.mat \
    HLA-Simulink/HLAblock_grt_rtw/defines.txt \
    HLA-Simulink/HLAblock_grt_rtw/html/BaseFederate_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/BasicException_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_codegen_rpt.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_contents.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_data_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_interface.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_private_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_reducedblocks.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_subsystems.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_survey.html \
    HLA-Simulink/HLAblock_grt_rtw/html/HLAblock_types_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/Logger_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/SimFederate_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/Tools_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/TransferBlock_wrapper_cpp.html \
    HLA-Simulink/HLAblock_grt_rtw/html/css/coder_app.css \
    HLA-Simulink/HLAblock_grt_rtw/html/define.js \
    HLA-Simulink/HLAblock_grt_rtw/html/hilite_warning.png \
    HLA-Simulink/HLAblock_grt_rtw/html/inspect.html \
    HLA-Simulink/HLAblock_grt_rtw/html/js/coder_app.js \
    HLA-Simulink/HLAblock_grt_rtw/html/multiword_types_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/nav.html \
    HLA-Simulink/HLAblock_grt_rtw/html/navToolbar.html \
    HLA-Simulink/HLAblock_grt_rtw/html/rtmodel_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwhilite.js \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwmsg.html \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwreport.css \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwreport_utils.js \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwshrink.js \
    HLA-Simulink/HLAblock_grt_rtw/html/rtwtypes_h.html \
    HLA-Simulink/HLAblock_grt_rtw/html/search.js \
    HLA-Simulink/HLAblock_grt_rtw/html/spinner.gif \
    HLA-Simulink/HLAblock_grt_rtw/modelsources.txt \
    HLA-Simulink/HLAblock_grt_rtw/rtw_proj.tmw \
    HLA-Simulink/HLAblock_grt_rtw/rtwtypeschksum.mat \
    HLA-Simulink/HLAblock_grt_rtw/tmwinternal/simulink_cache.xml \
    HLA-Simulink/LogFile \
    HLA-Simulink/SFB__TransferBlock__SFB.mat \
    HLA-Simulink/TransferBlock.mexa64 \
    HLA-Simulink/TransferBlock.tlc \
    HLA-Simulink/lrc_20200705_161414.671.log \
    HLA-Simulink/rtwmakecfg.m \
    HLA-Simulink/slprj/grt/HLAblock/tmwinternal/CompileInfo.xml \
    HLA-Simulink/slprj/grt/HLAblock/tmwinternal/binfo.mat \
    HLA-Simulink/slprj/grt/HLAblock/tmwinternal/minfo.mat \
    HLA-Simulink/slprj/grt/_sharedutils/shared_file.dmr \
    HLA-Simulink/slprj/modeladvisor/com_2emathworks_2ecgo_2egroup_/HLAblock/model_diagnose_custom.html \
    HLA-Simulink/slprj/modeladvisor/com_2emathworks_2ecgo_2egroup_/HLAblock/report.html \
    HLA-Simulink/slprj/modeladvisor/com_2emathworks_2ecgo_2egroup_/HLAblock/report_1.html \
    HLA-Simulink/slprj/sl_proj.tmw

SUBDIRS += \
    HLA-Simulink/SimFederate/SimFederate.pro
