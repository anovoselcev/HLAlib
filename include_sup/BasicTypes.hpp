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
#include <ios>
#include <iostream>
#include <fstream>
#ifndef WIN32
#include <sys/time.h>
#endif

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
    using Byte          = uint8_t;
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
    typedef __int16 Integer16BE;
    typedef __int32 Integer32BE;
    typedef __int64 Integer64BE;
    typedef unsigned __int16 OctetPairBE;
    typedef float Float32BE;
    typedef double Float64BE;

    typedef unsigned char Octet;
    typedef unsigned char Byte;
    typedef __int16 Integer16LE;
    typedef __int32 Integer32LE;
    typedef __int64 Integer64LE;
    typedef unsigned __int16 OctetPairLE;
    typedef float Float32LE;
    typedef double Float64LE;
    typedef unsigned __int16 UnsignedShort;
    typedef unsigned __int32 Unsigned32LE;
    typedef unsigned __int64 Unsigned64LE;

    typedef unsigned __int16 Unsignedinteger16BE;
    typedef unsigned __int32 Unsignedinteger32BE;
    typedef unsigned __int64 Unsignedinteger64BE;
    #endif


    using ASCIIchar     = Octet;
    using Char          = char;
    using unicodeChar   = OctetPairBE;
    using Integer64Time = Integer64BE;
    using Float64Time   = Float64BE;

    using ASCIIstring = std::string;
    using String = std::string;

    enum Boolean : Integer32BE {
      HLAfalse = 0,
      HLAtrue = 1
    };
    void initializeStep(int64_t step);

    void initializeMOD(Octet&);
    void initializeMOD(Integer16LE&);
    void initializeMOD(Integer32LE&);
    void initializeMOD(Integer64LE&);
    void initializeMOD(UnsignedShort&);
    void initializeMOD(Unsignedinteger32BE&);
    void initializeMOD(Unsignedinteger64BE&);
    void initializeMOD(Float32LE&);
    void initializeMOD(Float64LE&);
    void initializeMOD(Boolean&data);
    void initializeMOD(ASCIIstring& data);


    std::ostream& operator << (std::ostream& outStream, Octet dat);
    std::ostream& operator << (std::ostream& outStream, Boolean dat);

    std::istream& operator >> (std::istream &StreamInput, Octet & obj);

    int readMOD(std::ifstream &File, char* data, size_t size);
    int readMOD(std::ifstream &File, Byte &data);
    int readMOD(std::ifstream &File, Integer16LE &data);
    int readMOD(std::ifstream &File, Integer32LE &data);
    int readMOD(std::ifstream &File, Integer64LE &data);
    int readMOD(std::ifstream &File, Float32LE &data);
    int readMOD(std::ifstream &File, Float64LE &data);
    int readMOD(std::ifstream &File, UnsignedShort &data);
    int readMOD(std::ifstream &File, Unsignedinteger32BE &data);
    int readMOD(std::ifstream &File, Unsignedinteger64BE &data);
    int readMOD(std::ifstream &File, ASCIIstring &data);

    int writeMOD(std::ofstream &File, const Octet& data);
    int writeMOD(std::ofstream &File, Integer16LE const &data);
    int writeMOD(std::ofstream &File, Integer32LE const &data);
    int writeMOD(std::ofstream &File, Integer64LE const &data);
    int writeMOD(std::ofstream &File, Float32LE const &data);
    int writeMOD(std::ofstream &File, Float64LE const &data);
    int writeMOD(std::ofstream &File, UnsignedShort const &data);
    int writeMOD(std::ofstream &File, Unsignedinteger32BE const &data);
    int writeMOD(std::ofstream &File, Unsignedinteger64BE const &data);
    int writeMOD(std::ofstream &File, ASCIIstring const & data);

    enum UPDATE_TYPE_BASE {
      UPDATE_TYPE_UNKNOWN     = -1,
      UPDATE_TYPE_STATIC      = 0,
      UPDATE_TYPE_CONDITIONAL = 1,
      UPDATE_TYPE_PERIODIC	  = 2
    };

    std::wstring getUPDATE_TYPE_Name(UPDATE_TYPE_BASE en);
}
#endif // BASICTYPES_HPP
