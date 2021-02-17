#ifndef EMPTYSTRUCT_HPP
#define EMPTYSTRUCT_HPP

#include "../Formater.hpp"
#include "test_runner.hpp"

struct Empty{};

void TestEmpty(){
    Empty e;
    auto str = HLA::Formater::PrintData(e);
    ASSERT_EQUAL(str,"{}")
}

#endif // EMPTYSTRUCT_HPP
