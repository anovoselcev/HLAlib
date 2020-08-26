#ifndef JSON_HPP
#define JSON_HPP

#include <istream>
#include <vector>
#include <unordered_map>
#include <memory>
#include <fstream>

namespace HLA {

    class Node {
    public:
      explicit Node(std::vector<std::shared_ptr<Node>> array);
      explicit Node(std::unordered_map<std::wstring, std::shared_ptr<Node>> map);
      explicit Node(int value);
      explicit Node(std::wstring value);

      const std::vector<std::shared_ptr<Node>>& AsVector() const;
      const std::unordered_map<std::wstring, std::shared_ptr<Node>>& AsMap() const;
      int AsInt() const;
      const std::wstring& AsWstring() const;

    private:
      std::vector<std::shared_ptr<Node>> as_array;
      std::unordered_map<std::wstring, std::shared_ptr<Node>> as_map;
      int as_int;
      std::wstring as_wstring;
    };

    class JSON {
    public:
      explicit JSON(std::shared_ptr<Node> root);

      static JSON MakeJSON(std::wstring);

      const std::shared_ptr<Node> GetRoot() const;

      static std::unordered_map<std::wstring, std::vector<std::wstring>> ToMap(std::shared_ptr<Node>);

      static std::vector<std::wstring> ToVector(std::shared_ptr<Node>);

    private:
      std::shared_ptr<Node> root;
    };

    JSON Load(std::wistream& input);
}


#endif // JSON_HPP
