#ifndef TESTCSTATICARRAY_HPP
#define TESTCSTATICARRAY_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"

void TestCstaticArray(){
    int ar[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    auto str = HLA::Formater::PrintData(ar);
    ASSERT_EQUAL(str, "[1, 2, 3, 4, 5, 6, 7, 8]");
}

#endif // TESTCSTATICARRAY_HPP
