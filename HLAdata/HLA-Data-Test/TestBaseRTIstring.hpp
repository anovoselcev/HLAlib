#ifndef TESTBASERTISTRING_HPP
#define TESTBASERTISTRING_HPP
#include "test_runner.hpp"
#include "../include/RTIstring.hpp"

void TestString(){
    std::string str1 = "Hello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::RTIstring>(str1);
    std::string str2 = HLA::cast_from_rti<HLA::RTIstring>(v);
    ASSERT_EQUAL(str1,str2);
}

void TestWstring(){
    std::wstring wstr1 = L"Hello World";
    rti1516e::VariableLengthData v = HLA::cast_to_rti<HLA::RTIwstring>(wstr1);
    std::wstring wstr2 = HLA::cast_from_rti<HLA::RTIwstring>(v);
    ASSERT_EQUAL(wstr1,wstr2);
}

void TestRTIstring(){
    TestString();
    TestWstring();
}
#endif // TESTBASERTISTRING_HPP
