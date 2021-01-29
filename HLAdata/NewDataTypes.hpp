#ifndef NEWDATATYPES_HPP
#define NEWDATATYPES_HPP

#include <RTI/RTI1516.h>
#include <memory.h>
#include <type_traits>

template <typename T>
struct DataElement{

    virtual rti1516e::VariableLengthData encode(const T& data) = 0;

    virtual T decode(const rti1516e::VariableLengthData& vdata) = 0;

// Скорее всего не нужна, но нужна будет удобная замена, типа memcpy с проверкой
    virtual void getMaxData(void* ptrSource) = 0;

    virtual size_t getSize() const noexcept = 0;

    virtual const T& getValue() const noexcept = 0;
};

template < typename T>
struct NewSimpleData final: public DataElement<T>{

    using type = T;

    rti1516e::VariableLengthData encode(const T& value) override{
        rti1516e::VariableLengthData Vdata;
        Vdata.setData(&value, sizeof(T));
        return Vdata;
    }

    T decode(const rti1516e::VariableLengthData& Vdata) override{
        T value;
        memcpy(&value, Vdata.data(), sizeof(T));
        return value;
    }

    void getMaxData(void* ptrSource) override{
        size_t current_size = getSize();
        memcpy(&value, ptrSource, current_size);
    }

    size_t getSize() const noexcept override{
        return sizeof (T);
    }

    const T& getValue() const noexcept override{
        return value;
    }

private:
    T value;
};

template <typename StringType,
          typename symb = typename std::conditional<std::is_same<StringType,std::string>::value,char,wchar_t>::type,
          int OBV = sizeof (symb)>
struct NewBaseString final: public DataElement<StringType>{

    using type = StringType;

    NewBaseString(const StringType& str) noexcept : _str(str){}

    rti1516e::VariableLengthData encode(const StringType& value){
        size_t lenth = value.length();
        StringType str;
        str = StringType(reinterpret_cast<symb*>(&lenth), 8);
        str += value;
        rti1516e::VariableLengthData Vdata;
        Vdata.setData(reinterpret_cast<symb*>(&str[0]), str.size() * OBV);
        return Vdata;
    }

    StringType decode(const rti1516e::VariableLengthData& Vdata){
        size_t iq = Vdata.size();
        StringType str = StringType(reinterpret_cast<const symb*>(Vdata.data()),iq / OBV);
        return StringType(&str[8], str.size() - 8);
    }

    void getMaxData(void* ptrSource) override{
        size_t _size;
        memcpy(&_size, ptrSource, 8);
        _str = StringType(reinterpret_cast<symb*>(ptrSource), _size);
    }

    size_t getSize() const noexcept override{
        return _str.size() * OBV + 8;
    }

    const StringType& getValue() const noexcept override{
        return _str;
    }

private:
    StringType _str;

};

template <typename HLAtype, unsigned m_OBV = 1, typename Type = typename HLAtype::type>
struct NewVector final: public DataElement<std::vector<Type>>{

    using type = Type;
    using assertion_type = std::vector<type>;

    virtual ~NewVector() {
        if (_ptr) {
            delete[] _ptr;
            _ptr = nullptr;
        }
    }

    rti1516e::VariableLengthData encode(const std::vector<Type>& value) override{
        size_t size = 8;
        size_t vec_size = value.size();
        if(vec_size)
            //size += vec_size * HLAtype().getSize();
        delete [] _ptr;

        _ptr = new uint8_t[size];

        memcpy(_ptr, &vec_size, 8);
        size_t last = 8;
        rti1516e::VariableLengthData vdata;
        for(size_t idx = 0; idx < vec_size; ++idx){
            //vdata = HLAtype().encode(value[idx]);
            //size_t bound = vdata.size();

            //memcpy(_ptr + last, vdata.data(), bound);
           // last += bound;
        }
        //memcpy(_ptr + 8, value.data(), size - 8);
        rti1516e::VariableLengthData v;
        v.setData(_ptr, size);
        return v;
    }

    std::vector<Type> decode(const rti1516e::VariableLengthData& vdata) override{
        size_t size;
        delete [] _ptr;
        _ptr = new uint8_t[vdata.size()];
        memcpy(_ptr, vdata.data(), vdata.size());
        memcpy(&size, _ptr, 8);
        std::vector<Type> v(size);
        size_t last = 8;
        for(size_t idx = 0; idx < size; ++idx){
            //HLAtype t;
           // t.getMaxData(_ptr + last);
          //  v[idx] = t.getValue();
        }
        //memcpy(reinterpret_cast<Type*>(&v[0]), _ptr + 8, vdata.size() - 8);
        return v;
    }

    void getMaxData(void* ptrSource) override{
    }

    size_t getSize() const noexcept override{
        return sizeof (Type);
    }

    const std::vector<Type>& getValue() const noexcept override{

    }

private:
    uint8_t* _ptr = nullptr;

};

template< typename Struct>
struct New_Struct_wrapper final : public DataElement<Struct>{

    rti1516e::VariableLengthData encode(const Struct& obj) override{
        rti1516e::VariableLengthData v;
        v.setData(&obj, sizeof (Struct));
        return v;
    }

    Struct decode(const rti1516e::VariableLengthData& vdata) override{
        Struct result;
        memcpy(&result, vdata.data(), sizeof (Struct));
        return result;
    }

    void getMaxData(void* ptrSource, size_t inSize, const Struct& value) override{
    }

    size_t getSize() const noexcept override{
        return sizeof (Struct);
    }

private:
    uint8_t* _ptr = nullptr;
};

#endif // NEWDATATYPES_HPP
