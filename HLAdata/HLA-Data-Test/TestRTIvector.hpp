#ifndef TESTVECTOR_HPP
#define TESTVECTOR_HPP
#include "../HLAvector.hpp"
#include "../HLAstring.hpp"
#include "../HLAtypes.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestVectorInt16(){
    std::vector<int16_t> v1(100,2);
    rti1516e::VariableLengthData vd1 = HLA::cast_to_rti<HLA::Integer16LE,2>(v1);
    std::vector<int16_t> v2 = HLA::cast_from_rti<HLA::Integer16LE,2>(vd1);
    ASSERT_EQUAL(v1,v2)

    std::vector<int16_t> v3(200,3);
    rti1516e::VariableLengthData vd2 = HLA::cast_to_rti<HLA::Integer16BE,2>(v3);
    std::vector<int16_t> v4 = HLA::cast_from_rti<HLA::Integer16BE,2>(vd2);
    ASSERT_EQUAL(v3,v4)
}

void TestVectorInt32(){
    std::vector<int> v1(100,5);
    rti1516e::VariableLengthData vd1 = HLA::cast_to_rti<HLA::Integer32LE,4>(v1);
    std::vector<int> v2 = HLA::cast_from_rti<HLA::Integer32LE,4>(vd1);
    ASSERT_EQUAL(v1,v2)

    std::vector<int> v3(200,4);
    rti1516e::VariableLengthData vd2 = HLA::cast_to_rti<HLA::Integer32BE,4>(v3);
    std::vector<int> v4 = HLA::cast_from_rti<HLA::Integer32BE,4>(vd2);
    ASSERT_EQUAL(v3,v4)
}

void TestVectorInt64(){
    std::vector<int64_t> v1(100,5000);
    rti1516e::VariableLengthData vd1 = HLA::cast_to_rti<HLA::Integer64BE,8>(v1);
    std::vector<int64_t> v2 = HLA::cast_from_rti<HLA::Integer64BE,8>(vd1);
    ASSERT_EQUAL(v1,v2)
    std::vector<int64_t> v3(300,53443);
    rti1516e::VariableLengthData vd2 = HLA::cast_to_rti<HLA::Integer64LE,8>(v3);
    std::vector<int64_t> v4 = HLA::cast_from_rti<HLA::Integer64LE,8>(vd2);
    ASSERT_EQUAL(v3,v4)
}

void TestVectorFloat(){
    std::vector<float> v1BE(100,2.3);
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Float32BE,4>(v1BE);
    std::vector<float> v2BE = HLA::cast_from_rti<HLA::Float32BE,4>(v1);
    ASSERT_EQUAL(v1BE,v2BE)

    std::vector<float> v1LE(200,-1.2);
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Float32LE,4>(v1LE);
    std::vector<float> v2LE = HLA::cast_from_rti<HLA::Float32LE,4>(v2);
    ASSERT_EQUAL(v1LE,v2LE)
}

void TestVectorDouble(){
    std::vector<double> v1BE(100,32.32);
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Float64BE,8>(v1BE);
    std::vector<double> v2BE = HLA::cast_from_rti<HLA::Float64BE,8>(v1);
    ASSERT_EQUAL(v1BE,v2BE)

    std::vector<double> v1LE(200,-221.2);
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Float64LE,8>(v1LE);
    std::vector<double> v2LE = HLA::cast_from_rti<HLA::Float64LE,8>(v2);
    ASSERT_EQUAL(v1LE,v2LE)
}

void TestVectorBool(){
    std::vector<bool> v1 = {true,false};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Byte,1>(v1);
    std::vector<bool> v2 = HLA::cast_from_rti<HLA::Byte,1>(v);
    ASSERT_EQUAL(v1,v2);
}

void TestVectorChar(){
    std::vector<char> v1 = {'a','g','1'};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Char,1>(v1);
    std::vector<char> v2 = HLA::cast_from_rti<HLA::Char,1>(v);
    ASSERT_EQUAL(v1,v2)

}

void TestVectorString(){
    std::vector<std::string> v1 = {"Im","Name","Value","BigStringNameToTest"};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::String,4>(v1);
    std::vector<std::string> v2 = HLA::cast_from_rti<HLA::String,4>(v);
    ASSERT_EQUAL(v1,v2)
}

void TestVectorWstring(){
    std::vector<std::wstring> v1 = {L"Im",L"Name",L"Value",L"BigStringNameToTest"};
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring,4>(v1);
    std::vector<std::wstring> v2 = HLA::cast_from_rti<HLA::Wstring,4>(v);
    ASSERT_EQUAL(v1,v2)
}

void TestBigIntVector(){
    LOG_DURATION("Big_vector")
    std::vector<int> v1(100000);
    for(int i = 0; i< v1.size();i++)
        v1[i] = i;
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Integer32BE,4>(v1);
    std::vector<int> v2 = HLA::cast_from_rti<HLA::Integer32BE,4>(v);
    ASSERT_EQUAL(v1,v2)
}

void Testvector(){
   LOG_DURATION("Vector")
   TestVectorInt16();
   TestVectorInt32();
   TestVectorInt64();
   TestVectorFloat();
   TestVectorDouble();
   TestVectorBool();
   TestVectorChar();
   TestVectorString();
   TestVectorWstring();
   TestBigIntVector();
}
#endif // TESTVECTOR_HPP
