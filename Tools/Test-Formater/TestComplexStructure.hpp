#ifndef TESTCOMPLEXSTRUCTURE_HPP
#define TESTCOMPLEXSTRUCTURE_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

struct Sub1{
    int a;
    int b;
};

struct Sub2{
    double a;
    double b;
};

struct Data1{
    Sub1 a;
    Sub2 b;
};

void TestComplexStructure1(){
    Data1 d1{{4, 7}, {0.11, -8.3}};
    auto str1 = HLA::Formater::PrintData(d1);
    ASSERT_EQUAL(str1, "{{4, 7}, {0.11, -8.3}}");
}

struct Data2{
    std::vector<Sub1> a;
    std::vector<Sub2> b;
};

void TestComplexStructure2(){
    Data2 d1{{{3, 1}, {5, 8}}, {{1.1, 4.2}, {-0.9, -89.1}}};
    auto str1 = HLA::Formater::PrintData(d1);
    ASSERT_EQUAL(str1, "{[{3, 1}, {5, 8}], [{1.1, 4.2}, {-0.9, -89.1}]}");
}

void TestComplexStructure(){
    LOG_DURATION("TestComplexStructure");
    TestComplexStructure1();
    TestComplexStructure2();
}

#endif // TESTCOMPLEXSTRUCTURE_HPP
