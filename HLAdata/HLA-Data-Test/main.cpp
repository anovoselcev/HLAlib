#include <iostream>
#include "test_runner.hpp"
#include "TetsRTIfixedRecord.hpp"
#include "TestBaseRTIstring.hpp"
#include "TestRTIvector.hpp"
#include "TestSimpleData.hpp"
#include "TestRTIarray.hpp"
using namespace std;

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSimpleData);
    RUN_TEST(tr, TestRTIfixedRecord);
    RUN_TEST(tr, TestRTIstring);
    RUN_TEST(tr, TestRTIvector);
    RUN_TEST(tr, TestRTIarray);
    return 0;
}
