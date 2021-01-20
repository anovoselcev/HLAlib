#ifndef SIMPLEDATA_HPP
#define SIMPLEDATA_HPP

#include "RTI/RTI1516.h"
#include <memory.h>
#include <cassert>
#include <iostream>

template < typename T>
class SD{
    public:

    rti1516e::VariableLengthData encode(const T& value){

        rti1516e::VariableLengthData Vdata;
        Vdata.setData(&value, sizeof(T));
        return Vdata;
    }

    T decode(const rti1516e::VariableLengthData& Vdata){
        T value;
        memcpy(&value, Vdata.data(), sizeof(T));
        return value;
    }
};

template <typename StringType,
          typename symb = typename std::conditional<std::is_same<StringType,std::string>::value,char,wchar_t>::type,
          int OBV = sizeof (symb)>
class String{
public:

    rti1516e::VariableLengthData encode(const StringType& value){
        size_t lenth = value.length();
        str = StringType(reinterpret_cast<symb*>(&lenth), 4);
        str += value;
        rti1516e::VariableLengthData Vdata;
        Vdata.setData(reinterpret_cast<symb*>(&str[0]), str.size() * OBV);
        return Vdata;
    }

    StringType decode(const rti1516e::VariableLengthData& Vdata){
        size_t iq = Vdata.size();
        str = StringType(reinterpret_cast<const symb*>(Vdata.data()),iq / OBV);
        return StringType(&str[4], str.size() - 4);
    }
private:
    StringType str;
};

void Test(){
    int a = 1;
    SD<int> c;
    auto v = c.encode(a);
    int b = c.decode(v);
    assert(a == b);
    std::string str = "2232";
    String<std::string> f;
    v = f.encode(str);
    std::string u = f.decode(v);
    assert(str == u);
    std::wstring wstr = L"dsds";
    String<std::wstring> wf;
    v = wf.encode(wstr);
    std::wstring wstr2 = wf.decode(v);
    assert(wstr  == wstr2);
    std::wcout << wstr << wstr2 << std::endl;

}

#endif
