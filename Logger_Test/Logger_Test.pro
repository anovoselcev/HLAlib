TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../Tools/Logger.cpp \
        main.cpp

HEADERS += \
    ../Tools/Logger.hpp \
    Open.hpp \
    Singlton.hpp
