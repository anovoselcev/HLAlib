#ifndef TESTVECTOR_HPP
#define TESTVECTOR_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestIntVector(){
    std::vector<int> v1 = {1, 4, 21};
    auto str1 = HLA::Formater::PrintData(v1);
    ASSERT_EQUAL(str1, "[1, 4, 21]");

    v1 = {-1, 33, 11, 66, 12};
    auto str2 = HLA::Formater::PrintData(v1);
    ASSERT_EQUAL(str2, "[-1, 33, 11, 66, 12]")
}

void TestVectorString(){
    std::vector<std::string> v1 = {"sdad", "232", "2132dd"};
    auto str1 = HLA::Formater::PrintData(v1);
    ASSERT_EQUAL(str1, "[\"sdad\", \"232\", \"2132dd\"]");
}

void TestVectorVectorInt(){
    std::vector<std::vector<int>> v1 = {{1, 3, 5}, {5, 7, 8}};
    auto str1 = HLA::Formater::PrintData(v1);
    ASSERT_EQUAL(str1, "[[1, 3, 5], [5, 7, 8]]");
}

void TestVectorVectorVectorInt(){
    std::vector<std::vector<std::vector<int>>> v1 = {{{1, 3, 5}, {5, 7, 8}}, {{6, 7, 8}, {89, 13, 11}}};
    auto str1 = HLA::Formater::PrintData(v1);
    ASSERT_EQUAL(str1, "[[[1, 3, 5], [5, 7, 8]], [[6, 7, 8], [89, 13, 11]]]");
}

void TestVector(){
    LOG_DURATION("TestVector")
    TestIntVector();
    TestVectorString();
    TestVectorVectorInt();
    TestVectorVectorVectorInt();
}

#endif // TESTVECTOR_HPP
