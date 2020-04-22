#ifndef BASICTYPES_HPP
#define BASICTYPES_HPP

#ifdef WIN32
#pragma warning(disable: 4251)
#pragma warning(disable: 4786)
#pragma warning(disable: 4290)
#pragma warning(disable: 4482)
#endif

#include <string.h>
#include <stdio.h>
#include <vector>
#include <array>

#include <RTI/RTI1516.h>
namespace HLA {
#ifndef WIN32
    using Integer16BE = int16_t;
    using Integer32BE = int32_t;
    using Integer64BE = int64_t;
    using OctetPairBE = uint16_t;
    using Float32BE   = float;
    using Float64BE   = double;

    using Octet         = uint8_t;
    using Byte          = bool;
    using Integer16LE   = int16_t;
    using Integer32LE   = int32_t;
    using Integer64LE   = int64_t;
    using OctetPairLE   = uint16_t;
    using Float32LE     = float;
    using Float64LE     = double;
    using UnsignedShort = uint16_t;
    using Unsigned32LE  = uint32_t;
    using Unsigned64LE  = uint64_t;

    using Unsignedinteger16BE = uint16_t;
    using Unsignedinteger32BE = uint32_t;
    using Unsignedinteger64BE = uint64_t;
    #else
    using Integer16BE = __int16;
    using Integer32BE = __int32;
    using Integer64BE = __int64;
    using OctetPairBE = unsigned __int16 ;
    using Float32BE = float;
    using Float64BE = double;

    using Octet = unsigned char;
    using Byte = bool;
    using Integer16LE = __int16;
    using Integer32LE = __int32;
    using Integer64LE = __int64;
    using OctetPairLE = unsigned __int16;
    using Float32LE = float;
    using Float64LE = double;
    using UnsignedShort = unsigned __int16;
    using Unsigned32LE = unsigned __int32;
    using Unsigned64LE = unsigned __int64;

    using Unsignedinteger16BE = unsigned __int16;
    using Unsignedinteger32BE = unsigned __int32;
    using Unsignedinteger64BE = unsigned __int64;
    #endif


    using ASCIIchar     = Octet;
    using Char          = char;
    using unicodeChar   = OctetPairBE;
    using Integer64Time = Integer64BE;
    using Float64Time   = Float64BE;

    using String = std::string;
    using Wstring = std::wstring;
    template<typename T>
    using Vector = std::vector<T>;
    template<typename T, unsigned size>
    using Array = std::array<T,size>;

    enum Boolean : Integer32BE {
      HLAfalse = 0,
      HLAtrue = 1
    };
}
#endif // BASICTYPES_HPP
