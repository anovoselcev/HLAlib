#ifndef HLAVARIANT_HPP
#define HLAVARIANT_HPP

#include "BasicTemplates.hpp"
#include <boost/variant.hpp>
#include <iostream>

namespace HLA {


template<typename ...HLAtypes>
rti1516e::VariableLengthData cast_to_rti(const boost::variant<typename HLAtypes::type...>& data);

template<typename ...HLAtypes>
boost::variant<typename HLAtypes::type...> cast_from_rti(const rti1516e::VariableLengthData& data);

template <typename T>
void Helper(T);

template<>
void Helper<int>(int){
    std::wcout << L"Im int" << std::endl;
}

    template<typename ...HLAtypes>
    class Variant {
    public:
        using assertion_type = boost::variant<typename HLAtypes::type...>;

        Variant() = default;

        Variant(Variant&& obj) = default;

        void get(boost::variant<typename HLAtypes::type...> const &obj) {
            _which = obj.which();
            Visitor<HLAtypes...> vis;

           // _conv = get_type<0, _which, HLAtypes...>();

           boost::apply_visitor(vis, obj);
           //std::get<decltype (boost::apply_visitor(vis, obj))>(_conv).get(boost::get<typename decltype (boost::apply_visitor(vis, obj))::type>(obj));
           // std::get<0>(_conv).get(boost::get<0>(obj));
            rti1516e::VariableLengthData v;
          //  boost::get<this->_which>(_conv).setDataToRTI(v);
            if(ptrData)
                delete [] ptrData;

            _size = v.size();

            ptrData = new HLA::byte[_size + 4];
            memcpy(ptrData, &_which, 4);
            memcpy(ptrData + 4, v.data(), _size);
        }

        void getDataFromRTI(rti1516e::VariableLengthData const &obj){
            if(ptrData)
                delete [] ptrData;
            _size = obj.size() - 4;
            ptrData = new HLA::byte[obj.size()];
            memcpy(ptrData, obj.data(), obj.size());
            memcpy(&_which, ptrData, 4);
            rti1516e::VariableLengthData v;
            memcpy(v.data(), ptrData + 4, _size);
            boost::get<this->_which>(_conv).getDataFromRTI(v);
        }

        void getData(void* input_data, unsigned long size){
        }


        void getDataMax(void* ptrSource, unsigned long inSize)
        {
        }

        void get(boost::variant<typename HLAtypes::type...>& obj){
        }

        void setDataToRTI(rti1516e::VariableLengthData &obj){
            if (ptrData)  {
              obj.setData(ptrData, _size + 4);
            }
            else {
              ExceptionForRTI ex(L"HLAvariant.setDataToRTI. NULL pointer.");
              throw ex;
            }
        }

        void setData(void* ptrDest, unsigned long inSize){
        }

        unsigned setData(void* ptrDest){

        }

        void set(boost::variant<typename HLAtypes::type...>& data) {
            boost::get<this->_which>(_conv).set(boost::get<this->_which>(data));
        }

       // unsigned getsize() {return sizeof(T);}


    private:

        template<size_t curr,
                 size_t idx,
                 typename T,
                 typename ...U>
        struct get_type : public get_type<curr + 1, idx, U...>{
            std::enable_if_t<curr == idx, T> operator()(){return T();}
        };


        template<size_t curr,
                 size_t idx,
                 typename T>
        struct get_type<curr, idx, T> {
            std::enable_if_t<curr == idx, T> operator()(){return T();}
        };


        template<typename T, typename ...U>
        struct Visitor :  public Visitor<U...>{
            T operator()(typename T::type) const  noexcept{
                return T();
            }
        };

        template<typename T>
        struct Visitor<T> {
            T operator()(typename T::type) const noexcept{
                return T();
            }
        };



        int _which;
        uint32_t _size = 0;
        boost::variant<typename HLAtypes::type...> _data;
        boost::variant<HLAtypes...> _conv;
        byte* ptrData = nullptr;
    };

    template<typename ...HLAtypes>
    rti1516e::VariableLengthData cast_to_rti(const boost::variant<typename HLAtypes::type...>& data){
        Variant<HLAtypes...> conv;
        rti1516e::VariableLengthData v;
        conv.get(data);
        conv.setDataToRTI(v);
        return v;
    }

    template<typename ...HLAtypes>
    boost::variant<typename HLAtypes::type...> cast_from_rti(const rti1516e::VariableLengthData& data){
        Variant<HLAtypes...> conv;
        boost::variant<typename HLAtypes::type...> t;
        conv.getDataFromRTI(data);
        conv.set(t);
        return t;
    }

}


#endif // HLAVARIANT_HPP
