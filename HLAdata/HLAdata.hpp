#ifndef HLADATA_HPP
#define HLADATA_HPP
#include "HLAstring.hpp"
#include "HLAfixedRecod.hpp"
#include "HLAvector.hpp"
#include "HLAarray.hpp"
#include "HLAtypes.hpp"
#include "HLAenum.hpp"

namespace HLA {

    template<typename HLAtype>
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);

    template<typename HLAtype, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t);

    template<typename HLAtype, unsigned OBV>
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v);

    template<typename HLAtype, unsigned Size, unsigned OBV>
    rti1516e::VariableLengthData cast_to_rti(const std::array<typename HLAtype::type,Size>& t);

    template<typename HLAtype, unsigned Size, unsigned OBV>
    typename std::array<typename HLAtype::type, Size> cast_from_rti(const rti1516e::VariableLengthData& v);
}


#endif // HLADATA_HPP
