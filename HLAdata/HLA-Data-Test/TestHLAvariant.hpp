#ifndef TESTHLAVARIANT_HPP
#define TESTHLAVARIANT_HPP

#include "../HLAvariant.hpp"
#include "../HLAtypes.hpp"

void TestIntDouble(){
    boost::variant<int, double> var1 = 1;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Integer32BE, HLA::Float64BE>(var1);
}

void TestVariant(){
    TestIntDouble();
}

#endif // TESTHLAVARIANT_HPP
