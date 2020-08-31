#ifndef TESTSIMPLEDATA_HPP
#define TESTSIMPLEDATA_HPP
#include "../HLAtypes.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestInteger(){
    int16_t i16BE = 5;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE);

    int16_t i162BE = HLA::cast_from_rti<HLA::Integer16BE>(v1);
    ASSERT_EQUAL(i16BE,i162BE)

    int16_t i16LE = 99;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Integer16LE>(i16LE);
    int16_t i162LE = HLA::cast_from_rti<HLA::Integer16LE>(v2);
    ASSERT_EQUAL(i16LE,i162LE)

    int i32BE = 566;
    rti1516e::VariableLengthData v3 = HLA::cast_to_rti<HLA::Integer32BE>(i32BE);
    int i322BE = HLA::cast_from_rti<HLA::Integer32BE>(v3);
     ASSERT_EQUAL(i32BE,i322BE)

    int i32LE = 993;
    rti1516e::VariableLengthData v4 = HLA::cast_to_rti<HLA::Integer32LE>(i32LE);
    int i322LE = HLA::cast_from_rti<HLA::Integer32LE>(v4);
    ASSERT_EQUAL(i32LE,i322LE)

    int64_t i64BE = 566333;
    rti1516e::VariableLengthData v5 = HLA::cast_to_rti<HLA::Integer64BE>(i64BE);
    int64_t i642BE = HLA::cast_from_rti<HLA::Integer64BE>(v5);
    ASSERT_EQUAL(i64BE,i642BE)

    int64_t i64LE = 9932322;
    rti1516e::VariableLengthData v6 = HLA::cast_to_rti<HLA::Integer64LE>(i64LE);
    int64_t i642LE = HLA::cast_from_rti<HLA::Integer64LE>(v6);
    ASSERT_EQUAL(i64LE,i642LE)
}

void TestBool(){
    bool b1 = true;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Byte>(b1);
    bool b2 = HLA::cast_from_rti<HLA::Byte>(v1);
    ASSERT_EQUAL(b1,b2);

    bool b3 = false;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Byte>(b3);
    bool b4 = HLA::cast_from_rti<HLA::Byte>(v2);
    ASSERT_EQUAL(b3,b4);
}

void TestFloat(){
    float f1BE = 5.2;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Float32BE>(f1BE);
    float f2BE = HLA::cast_from_rti<HLA::Float32BE>(v1);
    ASSERT_EQUAL(f1BE,f2BE)

    float f1LE = 2.1;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Float32LE>(f1LE);
    float f2LE = HLA::cast_from_rti<HLA::Float32LE>(v2);
    ASSERT_EQUAL(f1LE,f2LE)
}

void TestDouble(){
    double f1BE = 123.32;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Float64BE>(f1BE);
    double f2BE = HLA::cast_from_rti<HLA::Float64BE>(v1);
    ASSERT_EQUAL(f1BE,f2BE)

    double f1LE = -222.11;
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Float64LE>(f1LE);
    double f2LE = HLA::cast_from_rti<HLA::Float64LE>(v2);
    ASSERT_EQUAL(f1LE,f2LE)
}

void TestChar(){
    char ch1 = 'a';
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Char>(ch1);
    char ch2 = HLA::cast_from_rti<HLA::Char>(v);
    ASSERT_EQUAL(ch1,ch2);
}

void TestSimpleData(){
    LOG_DURATION("Simple Data")
    TestFloat();
    TestDouble();
    TestInteger();
    TestBool();
    TestChar();
}
#endif // TESTSIMPLEDATA_HPP
