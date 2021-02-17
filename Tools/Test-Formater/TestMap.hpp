#ifndef TESTMAP_HPP
#define TESTMAP_HPP


#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestMapIntInt(){
    std::map<int, int> m1 = {{1, 2}, {3, 4}};
    auto str = HLA::Formater::PrintData(m1);
    ASSERT_EQUAL(str, "{{1: 2}, {3: 4}}");

    std::unordered_map<int, int> m2 = {{1, 2}, {3, 4}};
    auto str2 = HLA::Formater::PrintData(m1);
    ASSERT_EQUAL(str2, "{{1: 2}, {3: 4}}");
//    std::wstring dd = L"dd";
//    std::cout << HLA::JSON::TieData(dd, m1) << std::endl;
//    std::cout << HLA::JSON::TieData(dd, m1, m2) << std::endl;
}


void TestMapStringString(){
    std::map<std::string, std::string> m = {{"dd", "dsa"}, {"ee", "aa"}};
    auto str = HLA::Formater::PrintData(m);
    ASSERT_EQUAL(str, "{{\"dd\": \"dsa\"}, {\"ee\": \"aa\"}}");
}

void TestMap(){
    LOG_DURATION("TestMap");
    TestMapIntInt();
    TestMapStringString();
}

#endif // TESTMAP_HPP
