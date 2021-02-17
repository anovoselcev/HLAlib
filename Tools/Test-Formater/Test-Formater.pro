TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    ../Formater.hpp \
    EmptyStruct.hpp \
    TestComplexStructure.hpp \
    TestCstaticArray.hpp \
    TestMap.hpp \
    TestSimpleStruct.hpp \
    TestSimpleTypes.hpp \
    TestStrings.hpp \
    TestTieData.hpp \
    TestVector.hpp \
    profile.hpp \
    test_runner.hpp

INCLUDEPATH += $$PWD/../../3dparty/boost_1_75_0/
DEPENDPATH += $$PWD/../../3dparty/boost_1_75_0/
