#ifndef TESTOPERATOR_HPP
#define TESTOPERATOR_HPP

#include "../HLAdata.hpp"
#include "test_runner.hpp"
#include <cassert>
#include <boost/functional/hash.hpp>


inline bool operator==(const rti1516e::VariableLengthData& lhs, const rti1516e::VariableLengthData& rhs){
   if(lhs.size() == rhs.size()){
       HLA::byte* lhs_ptr = const_cast<HLA::byte*>(static_cast<const HLA::byte*>(lhs.data()));
       HLA::byte* rhs_ptr = const_cast<HLA::byte*>(static_cast<const HLA::byte*>(rhs.data()));
       for(size_t i = 0; i < lhs.size(); ++i){
           if(*(lhs_ptr + i) != *(rhs_ptr + i))
               return false;
       }
   }
   else
       return false;
   return true;
}

struct VariableLengthDataHash{
    size_t operator()(const rti1516e::VariableLengthData& data) const noexcept{
        std::vector<HLA::byte> vec(data.size());
        memcpy(vec.data(), data.data(), data.size());
        return boost::hash_value(vec);
    }
};

void TestInt(){
    int16_t i16BE = 5;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE);
    rti1516e::VariableLengthData v2 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE);

    assert(v1 == v2);
    assert(v1 == v1);
    assert(v2 == v2);

    int16_t i16BE2 = 5;
    rti1516e::VariableLengthData v3 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE2);

    assert(v1 == v3);
    assert(v2 == v3);

    int16_t i16BE3 = 12;
    rti1516e::VariableLengthData v4 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE3);
    assert(!(v3 == v4));

}

void TestHashInt(){
    int16_t i16BE = 5;
    rti1516e::VariableLengthData v1 = HLA::cast_to_rti<HLA::Integer16BE>(i16BE);
    VariableLengthDataHash hasher;
}

void TestOperator(){
    TestInt();
    TestHashInt();
}
#endif // TESTOPERATOR_HPP
