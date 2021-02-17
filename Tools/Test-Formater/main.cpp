#include "EmptyStruct.hpp"
#include "TestSimpleTypes.hpp"
#include "TestStrings.hpp"
#include "TestSimpleStruct.hpp"
#include "TestVector.hpp"
#include "TestCstaticArray.hpp"
#include "TestComplexStructure.hpp"
#include "TestMap.hpp"
#include "TestTieData.hpp"
#include <cstring>
#include <cmath>

int main(){
    TestRunner tr;
    RUN_TEST(tr, TestEmpty);
    RUN_TEST(tr, TestSimpleTypes);
    RUN_TEST(tr, TestStrings);
    RUN_TEST(tr, TestSimpleStruct);
    RUN_TEST(tr, TestVector);
    RUN_TEST(tr, TestCstaticArray);
    RUN_TEST(tr, TestMap);
    RUN_TEST(tr, TestComplexStructure);
    RUN_TEST(tr, TestTieData);

    return 0;
}
