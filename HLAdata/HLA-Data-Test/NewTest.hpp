#ifndef NEWTEST_HPP
#define NEWTEST_HPP
#include "../NewDataTypes.hpp"
#include <cassert>

void TestVector(){
    std::vector<int> vec1 = {0 , 1, 2, 3};
    auto va = NewVector<NewSimpleData<int>>().encode(vec1);
    auto vec2 = NewVector<NewSimpleData<int>>().decode(va);
    for(const auto& x : vec2)
        std::cerr << x << std::endl;
    assert(vec1[0] == vec2[0]);
    std::cerr << sizeof (std::string) << std::endl;
    std::vector<std::string> vec3 = {"ee", "eeed", "mmm"};
    auto vb = NewVector<NewBaseString<std::string>>().encode(vec3);
    auto vec4 = NewVector<NewBaseString<std::string>>().decode(vb);
    for(const auto& x : vec4)
        std::cerr << x << std::endl;
}

struct Point{
    double x,y;
    std::vector<int> iv;
};

void TestStruct(){
   // Point p1{1,33.2, {1, 2, 3}};
    //auto v = New_Struct_wrapper<Point>().encode(p1);
   // Point p2 = New_Struct_wrapper<Point>().decode(v);
   /* assert(p1.x == p2.x);
    assert(p1.y == p2.y);
    for(const auto& x : p2.iv)
        std::cerr <<  x << std::endl;*/
}

void NewTest(){
    TestVector();
    TestStruct();
}

#endif // NEWTEST_HPP
