#ifndef JSON_HPP
#define JSON_HPP

#include <istream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>

namespace HLA {
/**
* @brief The Node class
*/
    class Node {
    public:
/**
* @brief Node
* @param array
*/
      explicit Node(std::vector<std::shared_ptr<Node>> array);
/**
* @brief Node
* @param map
*/
      explicit Node(std::unordered_map<std::wstring, std::shared_ptr<Node>> map);
/**
* @brief Node
* @param value
*/
      explicit Node(int value);
/**
* @brief Node
* @param value
 */
      explicit Node(std::wstring value);
/**
* @brief Node
* @param value
*/
      explicit Node(std::string value);

/**
* @brief AsVector
* @return
*/
      const std::vector<std::shared_ptr<Node>>& AsVector() const;

/**
* @brief AsMap
* @return
*/
      const std::unordered_map<std::wstring, std::shared_ptr<Node>>& AsMap() const;

/**
* @brief AsInt
* @return
*/
      int AsInt() const;

/**
* @brief AsWstring
* @return
*/
      const std::wstring& AsWstring() const;

/**
* @brief AsString
* @return
*/
      const std::string& AsString() const;

    private:
/**
* @brief as_array
*/
      std::vector<std::shared_ptr<Node>> as_array;
/**
* @brief as_map
*/
      std::unordered_map<std::wstring, std::shared_ptr<Node>> as_map;
/**
* @brief as_int
*/
      int as_int;
/**
* @brief as_wstring
*/
      std::wstring as_wstring;
/**
* @brief as_string
*/
      std::string as_string;
    };

/**
* @brief The JSON class
*/
    class JSON {
    public:
/**
* @brief JSON
* @param root
*/
      explicit JSON(std::shared_ptr<Node> root);

/**
* @brief MakeJSON
* @return
*/
      static JSON MakeJSON(std::wstring);

/**
* @brief GetRoot
* @return
*/
      const std::shared_ptr<Node> GetRoot() const;

/**
* @brief ToMap
* @return
*/
      static std::unordered_map<std::wstring, std::vector<std::wstring>> ToMap(std::shared_ptr<Node>);

/**
* @brief ToVector
* @return
*/
      static std::vector<std::wstring> ToVector(std::shared_ptr<Node>);

    private:
/**
* @brief Load
* @param input
* @return
*/
      static JSON Load(std::wistream& input);
/**
* @brief root
*/
      std::shared_ptr<Node> root;
    };


}


#endif // JSON_HPP
