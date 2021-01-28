#ifndef HLADATA_HPP
#define HLADATA_HPP
#include "HLAstring.hpp"
#include "HLAfixedRecod.hpp"
#include "HLAvector.hpp"
#include "HLAarray.hpp"
#include "HLAtypes.hpp"
#include "HLAenum.hpp"

namespace HLA {


//================================================================================================================================================

//          Casters for basic types, strings and structures

//================================================================================================================================================

    template<typename HLAtype>
/**
* @brief cast_to_rti
* @param HLAtype : Type in HLA representation (converter)
* @param t       : Value of user type
* Convert user-value (basic types, strings, structures) to byte-array using HLA representation
* @return Byte-array for RTI
*/
    rti1516e::VariableLengthData cast_to_rti(const typename HLAtype::type& t);

    template<typename HLAtype>
/**
* @brief cast_from_rti
* @param HLAtype : Type in HLA representation (converter)
* @param v       : Value of byte-array
* Convert byte-array from RTI to user-value (basic types, string, structures) using HLA representation
* @return User-value
*/
    typename HLAtype::type cast_from_rti(const rti1516e::VariableLengthData& v);



//================================================================================================================================================

//          Casters for std::vector

 //================================================================================================================================================

    template<typename HLAtype, unsigned OBV>
/**
* @brief cast_to_rti
* @param HLAtype : Type in HLA representation (converter)
* @param OBV     : Octet Boundinary Value (for int32 it is 4, for double is 8 ...)
* @param t       : std::vector of user-values
* Convert user-value std::vector to byte-array using HLA representation
* @return Byte-array for RTI
*/
    rti1516e::VariableLengthData cast_to_rti(const std::vector<typename HLAtype::type>& t);

    template<typename HLAtype, unsigned OBV>
/**
* @brief cast_from_rti
* @param HLAtype : Type in HLA representation (converter)
* @param OBV     : Octet Boundinary Value (for int32 it is 4, for double is 8 ...)
* @param v       : Value of byte-array
* Convert byte-array from RTI to user-value std::vector using HLA representation
* @return User-value std::vector
*/
    std::vector<typename HLAtype::type> cast_from_rti(const rti1516e::VariableLengthData& v);



//================================================================================================================================================

//          Casters for std::array

//================================================================================================================================================

    template<typename HLAtype, unsigned Size, unsigned OBV>
/**
* @brief cast_to_rti
* @param HLAtype : Type in HLA representation (converter)
* @param Size    : Size of static array
* @param OBV     : Octet Boundinary Value (for int32 it is 4, for double is 8 ...)
* @param t       : std::array of user-values
* Convert user-value std::array to byte-array using HLA representation
* @return Byte-array for RTI
*/
    rti1516e::VariableLengthData cast_to_rti(const std::array<typename HLAtype::type,Size>& t);

    template<typename HLAtype, unsigned Size, unsigned OBV>
/**
* @brief cast_from_rti
* @param HLAtype : Type in HLA representation (converter)
* @param Size    : Size of static array
* @param OBV     : Octet Boundinary Value (for int32 it is 4, for double is 8 ...)
* @param v       : Value of byte-array
* Convert byte-array from RTI to user-value std::array using HLA representation
* @return User-value std::array
 */
    typename std::array<typename HLAtype::type, Size> cast_from_rti(const rti1516e::VariableLengthData& v);
}


#endif // HLADATA_HPP
