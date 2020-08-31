#ifndef TESTBASESTRING_HPP
#define TESTBASESTRING_HPP
#include "test_runner.hpp"
#include "profile.hpp"
#include "../HLAstring.hpp"
#include "../HLAtypes.hpp"

void TestString(){
    std::string str1 = "Hello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::String>(str1);
    std::string str2 = HLA::cast_from_rti<HLA::String>(v);
    ASSERT_EQUAL(str1,str2);
}

void TestWstring(){
    std::wstring wstr1 = L"Hello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(wstr1);
    std::wstring wstr2 = HLA::cast_from_rti<HLA::Wstring>(v);
    ASSERT_EQUAL(wstr1,wstr2);
}

void TestBigString(){
    std::string str1 = "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                       "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                       "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                       "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                       "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                       "Hello WorldHello WorldHello WorldHello WorldHello WorldHello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::String>(str1);
    std::string str2 = HLA::cast_from_rti<HLA::String>(v);
    ASSERT_EQUAL(str1,str2);
}

void TestBigWstring(){
    std::wstring wstr1 = L"Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                         "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                         "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                         "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                         "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World"
                         "Hello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello WorldHello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::Wstring>(wstr1);
    std::wstring wstr2 = HLA::cast_from_rti<HLA::Wstring>(v);
    ASSERT_EQUAL(wstr1,wstr2);
}

void Teststring(){
    LOG_DURATION("Strings")
    TestString();
    TestWstring();
    TestBigString();
    TestBigWstring();
}
#endif // TESTBASESTRING_HPP
