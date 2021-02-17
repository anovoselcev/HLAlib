#ifndef TESTSTRINGS_HPP
#define TESTSTRINGS_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

void TestString(){
    std::string str1 = "asdafgzccasdasadsacadac";
    auto strj1 = HLA::Formater::PrintData(str1);
    ASSERT_EQUAL(strj1, "\"asdafgzccasdasadsacadac\"");

    std::string str2 = "asdafgzccasdasadsacad dfaasdadadadsdvfs sdad d 3434342423c";
    auto strj2 = HLA::Formater::PrintData(str2);
    ASSERT_EQUAL(strj2, "\"asdafgzccasdasadsacad dfaasdadadadsdvfs sdad d 3434342423c\"");
}

void TestWstring(){
    std::wstring str1 = L"asdafgzccasdasadsacadac";
    auto strj1 = HLA::Formater::PrintData(str1);
    ASSERT_EQUAL(strj1, "\"asdafgzccasdasadsacadac\"");

    std::wstring str2 = L"asdafgzccasdasadsacad dfaasdadadadsdvfs sdad d 3434342423c";
    auto strj2 = HLA::Formater::PrintData(str2);
    ASSERT_EQUAL(strj2, "\"asdafgzccasdasadsacad dfaasdadadadsdvfs sdad d 3434342423c\"");
}


void TestStrings(){
    LOG_DURATION("TestStrings");
    TestString();
    TestWstring();
}
#endif // TESTSTRINGS_HPP
