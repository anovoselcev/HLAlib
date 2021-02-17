#ifndef TESTSIMPLETYPES_HPP
#define TESTSIMPLETYPES_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestInt(){
    int a = 1;
    auto stra = HLA::Formater::PrintData(a);
    ASSERT_EQUAL(stra, "1");

    int64_t b = 112313;
    auto strb = HLA::Formater::PrintData(b);
    ASSERT_EQUAL(strb, "112313");
}

void TestFloating(){
    double a = -0.123;
    auto stra = HLA::Formater::PrintData(a);
    ASSERT_EQUAL(stra, "-0.123");

    float b = 120.4f;
    auto strb = HLA::Formater::PrintData(b);
    ASSERT_EQUAL(strb, "120.4")
}

void TestChar(){
    char a = 'a';
    auto stra = HLA::Formater::PrintData(a);
    ASSERT_EQUAL(stra, "'a'");

    wchar_t b = L'd';
    auto strb = HLA::Formater::PrintData(b);
    ASSERT_EQUAL(strb, "'d'");
}


void TestSimpleTypes(){
    LOG_DURATION("TestSimpleTypes");
    TestInt();
    TestFloating();
    TestChar();
}

#endif // TESTSIMPLETYPES_HPP
