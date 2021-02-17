#ifndef TESTSIMPLESTRUCT_HPP
#define TESTSIMPLESTRUCT_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

struct S1{
    int a;
    int b;
};

void TestSimpleStruct1(){
    S1 s1{2, 4};
    auto str1 = HLA::Formater::PrintData(s1);
    ASSERT_EQUAL(str1, "{2, 4}");

    S1 s2{-102, 3331};
    auto str2 = HLA::Formater::PrintData(s2);
    ASSERT_EQUAL(str2, "{-102, 3331}");
}

struct S2{
    double a;
    double b;
};

void TestSimpleStruct2(){
    S2 s1{2.001, 4.2232};
    auto str1 = HLA::Formater::PrintData(s1);
    ASSERT_EQUAL(str1, "{2.001, 4.2232}");

    S2 s2{-102.111, 3331.08};
    auto str2 = HLA::Formater::PrintData(s2);
    ASSERT_EQUAL(str2, "{-102.111, 3331.08}");
}

struct S3{
    std::string a;
    std::string b;
};

void TestSimpleStruct3(){
    S3 s1{"dadad", "gfgfg"};
    auto str1 = HLA::Formater::PrintData(s1);
    ASSERT_EQUAL(str1, "{\"dadad\", \"gfgfg\"}");

    S3 s2{"dadddadadwdbhfgbdad", "gfgfgdegregrgrg"};
    auto str2 = HLA::Formater::PrintData(s2);
    ASSERT_EQUAL(str2, "{\"dadddadadwdbhfgbdad\", \"gfgfgdegregrgrg\"}");
}

struct S4{
    double a;
    std::string b;
    int c;
};

void TestSimpleStruct4(){
    S4 s1{0.11, "sds", 2};
    auto str1 = HLA::Formater::PrintData(s1);
    ASSERT_EQUAL(str1, "{0.11, \"sds\", 2}");
}

void TestSimpleStruct(){
    LOG_DURATION("TestSimpleStruct");
    TestSimpleStruct1();
    TestSimpleStruct2();
    TestSimpleStruct3();
    TestSimpleStruct4();
}

#endif // TESTSIMPLESTRUCT_HPP
