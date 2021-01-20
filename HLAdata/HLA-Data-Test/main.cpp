#include <iostream>
#include "test_runner.hpp"
#include "TetsRTIfixedRecord.hpp"
#include "TestBaseRTIstring.hpp"
#include "TestRTIvector.hpp"
#include "TestSimpleData.hpp"
#include "TestRTIarray.hpp"
#include "TestHLAenum.hpp"
#include "TestOperator.hpp"
#include "TestHLAvariant.hpp"
#include "TestForManual.hpp"
#include "NewTest.hpp"
#include <thread>
using namespace std;

int main()
{
    TestRunner tr;
    RUN_TEST(tr, TestSimpleData);
    RUN_TEST(tr, TestfixedRecord);
    RUN_TEST(tr, Teststring);
    RUN_TEST(tr, Testvector);
    RUN_TEST(tr, Testarray);
    RUN_TEST(tr, TestEnum);
    RUN_TEST(tr, TestOperator);
    RUN_TEST(tr, TestVariant);
    //RUN_TEST(tr, Test);

   // RUN_TEST(tr, NewTest);
    return 0;
}
