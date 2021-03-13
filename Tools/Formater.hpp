#ifndef FORMATER_HPP
#define FORMATER_HPP

#include <type_traits>
#include <string>
#include <sstream>
#include <iomanip>

#define BOOST_PFR_USE_CPP17 0
#define BOOST_PFR_USE_LOOPHOLE  1
#include <boost/pfr.hpp>

namespace std {
    template <typename Key, typename Value, typename Comparator, typename Allocator>
    class map;

    template <typename Key, typename Value, typename Hash, typename Comparator, typename Allocator>
    class unordered_map;
}

namespace HLA {

struct Formater {

    struct StringValueFormat{};

    struct StringValueNotFormat{};

    template<typename T>
    static std::string PrintData(const T& data){
        return Print(data);
    }

    template<typename ...T>
    static std::string PrintData(const T& ...data){
        return Print(data...);
    }

    template<typename ValueFormat, typename Name, typename Type, typename ...Types>
    static std::enable_if_t<(std::is_same<Name, std::string>::value || std::is_same<Name, std::wstring>::value) && std::is_same<ValueFormat, StringValueNotFormat>::value, std::string>
    TieData(const Name& name,
            const Type& value,
            const Types& ...other){
        std::stringstream ss;
        ss << "{";
        ss << Print(name);
        ss << ": {";
        ss << PrintWithoutFormat(value);
        if(sizeof (std::tuple<Types...>))
            ss << ", " << Print(other...);

        ss << "}}";
        return ss.str();
    }


    template<typename ValueFormat, typename Name, typename Data>
    static std::enable_if_t<(std::is_same<Name, std::string>::value || std::is_same<Name, std::wstring>::value) && std::is_same<ValueFormat, StringValueNotFormat>::value, std::string>
    TieData(const Name& name,
            const Data& value){
        std::stringstream ss;
        ss << "{";
        ss << Print(name);
        ss << ": ";
        ss << PrintWithoutFormat(value);
        ss << "}";
        return ss.str();
    }

    template<typename ValueFormat = StringValueFormat, typename Name, typename Type, typename ...Types>
    static std::enable_if_t<(std::is_same<Name, std::string>::value || std::is_same<Name, std::wstring>::value) && std::is_same<ValueFormat, StringValueFormat>::value, std::string>
    TieData(const Name& name,
            const Type& value,
            const Types& ...other){
        std::stringstream ss;
        ss << "{";
        ss << Print(name);
        ss << ": {";
        ss << Print(value);
        if(sizeof (std::tuple<Types...>))
            ss << ", " << Print(other...);

        ss << "}}";
        return ss.str();
    }


    template<typename ValueFormat = StringValueFormat, typename Name, typename Data>
    static std::enable_if_t<(std::is_same<Name, std::string>::value || std::is_same<Name, std::wstring>::value) && std::is_same<ValueFormat, StringValueFormat>::value, std::string>
    TieData(const Name& name,
            const Data& value){
        std::stringstream ss;
        ss << "{";
        ss << Print(name);
        ss << ": ";
        ss << Print(value);
        ss << "}";
        return ss.str();
    }


private:

    template<typename Type, typename ...Types>
    static std::string Print(const Type& data,
                             const Types& ...other){
        std::stringstream ss;
        ss << Print(data);
        if(sizeof (std::tuple<Types...>))
            ss << ", " << Print(other...);
        return ss.str();
    }




    template<typename T>
    static std::enable_if_t<std::is_enum<T>::value, std::string>
    Print(const T& value){
        std::stringstream ss;
        ss <<static_cast<int>(value);
        return  ss.str();
    }

    static std::string Print(const std::string& value){return "\"" + value + "\"";}

    static std::string Print(const std::wstring& value){
        std::string str;
        str.assign(value.begin(), value.end());
        return "\"" + str + "\"";
    }

    static std::string Print(wchar_t value){
        std::string str{char(value)};
        return "'" + str + "'";
    }
    static std::string Print(char value){
        std::string str{char(value)};
        return "'" + str + "'";
    }
    template<typename T>
    static std::enable_if_t<(!std::is_enum<T>::value && !std::is_floating_point<T>::value && !std::is_integral<T>::value && !std::is_same<T, std::string>::value && !std::is_same<T, std::wstring>::value),std::string>
    Print(const T& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "{";
        boost::pfr::for_each_field(value,[&sep, &ss](const auto& field){
            ss << std::exchange(sep, ", ");
            ss << Print(field);
        });
        ss << "}";
        return ss.str();
    }

    template<typename T>
    static std::enable_if_t<(std::is_floating_point<T>::value || std::is_integral<T>::value) && !std::is_enum<T>::value, std::string>
    Print(const T& value){
        std::stringstream ss;
        ss << boost::pfr::io(value);
        return  ss.str();
    }



    template<typename T, typename Allocator = std::allocator<T>, template<typename, typename> class Container>
    static std::string Print(const Container<T, Allocator>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }



    template<typename T, size_t N, template<typename, size_t> class Container>
    static std::string Print(const Container<T, N>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }

    template<typename T, size_t N>
    static std::string Print(const T(&value)[N]){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }

    template<typename T, size_t N>
    static std::string Print(const T* value[N]){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }


    template<typename T, typename Comparator = std::less<T>, typename Allocator = std::allocator<T>, template<typename, typename, typename> class Container>
    static std::string Print(const Container<T, Comparator, Allocator>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }



    template<typename T, typename Hash = std::hash<T>, typename Comparator = std::equal_to<T>, typename Allocator = std::allocator<T>, template<typename, typename, typename, typename> class Container>
    static std::string Print(const Container<T, Hash, Comparator, Allocator>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "[";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << Print(el);
        }
        ss << "]";
        return ss.str();
    }



    template<typename Key, typename Value, typename Comparator = std::less<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
    static std::string Print(const std::map<Key, Value, Comparator, Allocator>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "{";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << "{";
            ss << Print(el.first);
            ss << ": ";
            ss << Print(el.second);
            ss << "}";
        }
        ss << "}";
        return ss.str();
    }

    template<typename Key, typename Value, typename Hash = std::hash<Key>, typename Comparator = std::equal_to<Key>, typename Allocator = std::allocator<std::pair<const Key, Value>>>
    static std::string Print(const std::unordered_map<Key, Value, Hash, Comparator, Allocator>& value){
        std::stringstream ss;
        const char* sep = "";
        ss << "{";
        for(const auto& el : value){
            ss << std::exchange(sep, ", ");
            ss << "{";
            ss << Print(el.first);
            ss << ": ";
            ss << Print(el.second);
            ss << "}";
        }
        ss << "}";
        return ss.str();
    }

    static std::string PrintWithoutFormat(const std::string& value) {return value;}

    static std::string PrintWithoutFormat(const std::wstring& value){
        std::string str;
        str.assign(value.begin(), value.end());
        return str;
    }

    template<typename T>
    static std::string PrintWithoutFormat(const T& value){return PrintData(value);}

};

}


#endif // FORMATER_HPP
