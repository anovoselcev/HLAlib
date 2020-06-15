#ifndef TESTHLAENUM_HPP
#define TESTHLAENUM_HPP
#include "../HLAenum.hpp"
#include "test_runner.hpp"


enum class Bin{
    YES = 1,
    NO = 0
};


void TestBin(){
    Bin b1 = Bin::YES;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Enum<Bin>>(b1);
    Bin b2 = HLA::cast_from_rti<HLA::Enum<Bin>>(v1);
    ASSERT_EQUAL(b1,b2)
    Bin b3 = Bin::NO;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Enum<Bin>>(b3);
    Bin b4 = HLA::cast_from_rti<HLA::Enum<Bin>>(v2);
    ASSERT_EQUAL(b3,b4)
}

enum class Compare{
    BIGGER = 0,
    SMALLER = 1,
    EQUAL = 2
};


void TestCompare(){
    Compare c1 = Compare::BIGGER;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Enum<Compare>>(c1);
    Compare c2 = HLA::cast_from_rti<HLA::Enum<Compare>>(v1);
    ASSERT_EQUAL(c1,c2)
    Compare c3 = Compare::SMALLER;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Enum<Compare>>(c3);
    Compare c4 = HLA::cast_from_rti<HLA::Enum<Compare>>(v2);
    ASSERT_EQUAL(c3,c4)
    Compare c5 = Compare::EQUAL;
    rti1516e::VariableLengthData v3 = HLA::cast_to_rti<HLA::Enum<Compare>>(c5);
    Compare c6 = HLA::cast_from_rti<HLA::Enum<Compare>>(v3);
    ASSERT_EQUAL(c5,c6)
}

enum class  Taste{
    CLASSIC = 0,
    STRAWBERRY = 1,
    CHOCKOLATE = 2,
    ORANGE = 3
};

void TestTaste(){
    Taste t1 = Taste::CLASSIC;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Enum<Taste>>(t1);
    Taste t2 = HLA::cast_from_rti<HLA::Enum<Taste>>(v1);
    ASSERT_EQUAL(t1,t2)
    Taste t3 = Taste::STRAWBERRY;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Enum<Taste>>(t3);
    Taste t4 = HLA::cast_from_rti<HLA::Enum<Taste>>(v2);
    ASSERT_EQUAL(t3,t4)
    Taste t5 = Taste::CHOCKOLATE;
    rti1516e::VariableLengthData v3 = HLA::cast_to_rti<HLA::Enum<Taste>>(t5);
    Taste t6 = HLA::cast_from_rti<HLA::Enum<Taste>>(v3);
    ASSERT_EQUAL(t5,t6)
    Taste t7 = Taste::ORANGE;
    rti1516e::VariableLengthData v4 = HLA::cast_to_rti<HLA::Enum<Taste>>(t7);
    Taste t8 = HLA::cast_from_rti<HLA::Enum<Taste>>(v4);
    ASSERT_EQUAL(t7,t8)
}

enum class EXIT_CODE{
    GOOD = 0,
    SIGFALL = 255,
    UNBEHAVIOR = -1,
    BADALLOC = 122

};

void TestExitCode(){
    EXIT_CODE e1 = EXIT_CODE::GOOD;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Enum<EXIT_CODE>>(e1);
    EXIT_CODE e2 = HLA::cast_from_rti<HLA::Enum<EXIT_CODE>>(v1);
    ASSERT_EQUAL(e1,e2)
    EXIT_CODE e3 = EXIT_CODE::SIGFALL;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Enum<EXIT_CODE>>(e3);
    EXIT_CODE e4 = HLA::cast_from_rti<HLA::Enum<EXIT_CODE>>(v2);
    ASSERT_EQUAL(e3,e4)
    EXIT_CODE e5 = EXIT_CODE::UNBEHAVIOR;
    rti1516e::VariableLengthData v3 = HLA::cast_to_rti<HLA::Enum<EXIT_CODE>>(e5);
    EXIT_CODE e6 = HLA::cast_from_rti<HLA::Enum<EXIT_CODE>>(v3);
    ASSERT_EQUAL(e5,e6)
    EXIT_CODE e7 = EXIT_CODE::BADALLOC;
    rti1516e::VariableLengthData v4 = HLA::cast_to_rti<HLA::Enum<EXIT_CODE>>(e7);
    EXIT_CODE e8 = HLA::cast_from_rti<HLA::Enum<EXIT_CODE>>(v4);
    ASSERT_EQUAL(e7,e8)
}

void TestEnum(){
    TestBin();
    TestCompare();
    TestTaste();
    TestExitCode();
}
#endif // TESTHLAENUM_HPP
