#ifndef TESTTIEDATA_HPP
#define TESTTIEDATA_HPP


#include "../Formater.hpp"
#include "test_runner.hpp"
#include "profile.hpp"

using svf  = HLA::Formater::StringValueFormat;
using svnf = HLA::Formater::StringValueNotFormat;

void TestTieData1(){
    std::string name{"Atttr1"};
    std::string oname{"Obj1"};
    std::string fname{"VP"};
    std::unordered_map<int, int> m2 = {{1, 2}, {3, 4}};
    auto str = HLA::Formater::TieData<svnf>(fname, HLA::Formater::TieData<svnf>(oname,HLA::Formater::TieData(name, m2)));
    std::cout << str << std::endl;
    ASSERT_EQUAL(str, "{\"VP\": {\"Obj1\": {\"Atttr1\": {{3: 4}, {1: 2}}}}}");
}

void TestTieData2(){
    std::string Key{"key"};
    std::string Value{"value"};
    auto str = HLA::Formater::TieData(Key, Value);
    std::cout << str << std::endl;
    ASSERT_EQUAL(str, "{\"key\": \"value\"}");

}

void TestTieData(){
    LOG_DURATION("TestTieData");
    TestTieData1();
    TestTieData2();
}

#endif // TESTTIEDATA_HPP
