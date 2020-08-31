#include "JSON.hpp"

namespace HLA {

    using namespace std;

/**
* @brief Node::Node
* @param array
*/
    Node::Node(vector<shared_ptr<Node>> array) : as_array(move(array)) {}

/**
* @brief Node::Node
* @param map
*/
    Node::Node(unordered_map<wstring, shared_ptr<Node>> map) : as_map(move(map)){}

/**
* @brief Node::Node
* @param value
*/
    Node::Node(int value) : as_int(value) {}

/**
* @brief Node::Node
* @param value
*/
    Node::Node(wstring value) : as_wstring(move(value)) {}

/**
* @brief Node::AsVector
* @return
*/
    const vector<shared_ptr<Node>>& Node::AsVector() const {
      return as_array;
    }

/**
* @brief Node::AsMap
* @return
*/
    const unordered_map<wstring, shared_ptr<Node>>& Node::AsMap() const {
      return as_map;
    }

/**
* @brief Node::AsInt
* @return
*/
    int Node::AsInt() const {
      return as_int;
    }

/**
* @brief Node::AsWstring
* @return
*/
    const wstring& Node::AsWstring() const {
      return as_wstring;
    }

/**
* @brief Node::AsString
* @return
*/
    const std::string& Node::AsString() const{
        return as_string;
    }

/**
* @brief JSON::JSON
* @param root
*/
    JSON::JSON(shared_ptr<Node> root) : root(move(root)) {
    }

/**
* @brief JSON::GetRoot
* @return
*/
    const shared_ptr<Node> JSON::GetRoot() const {
      return root;
    }

/**
* @brief LoadNode
* @param input
* @return
*/
    shared_ptr<Node> LoadNode(wistream& input);

/**
* @brief LoadArray
* @param input
* @return
*/
    shared_ptr<Node> LoadArray(wistream& input) {
      vector<shared_ptr<Node>> result;

      for (wchar_t c; input >> c && c != L']'; ) {
        if (c != L',') {
          input.putback(c);
        }
        result.push_back(LoadNode(input));
      }

      return make_shared<Node>(move(result));
    }

/**
* @brief LoadInt
* @param input
* @return
*/
    shared_ptr<Node> LoadInt(wistream& input) {
      int result = 0;
      while (isdigit(input.peek())) {
        result *= 10;
        result += input.get() - '0';
      }
      return make_shared<Node>(result);
    }

/**
* @brief LoadWstring
* @param input
* @return
*/
    shared_ptr<Node> LoadWstring(wistream& input) {
      wstring line;
      getline(input, line, L'"');
      return make_shared<Node>(move(line));
    }

/**
* @brief LoadDict
* @param input
* @return
*/
    shared_ptr<Node> LoadDict(wistream& input) {
      unordered_map<wstring, shared_ptr<Node>> result;

      for (wchar_t c; input >> c && c != L'}'; ) {
        if (c == ',') {
          input >> c;
        }

        wstring key = LoadWstring(input)->AsWstring();
        input >> c;
        result.insert({move(key), LoadNode(input)});
      }

      return make_shared<Node>(move(result));
    }

/**
* @brief LoadNode
* @param input
* @return
*/
    shared_ptr<Node> LoadNode(wistream& input) {
      wchar_t c;
      input >> c;

      if (c == L'[') {
        return LoadArray(input);
      } else if (c == L'{') {
        return LoadDict(input);
      } else if (c == L'"') {
        return LoadWstring(input);
      } else {
        input.putback(c);
        return LoadInt(input);
      }
    }

/**
* @brief Load
* @param input
* @return
*/
    JSON Load(wistream& input) {
      return JSON{LoadNode(input)};
    }

/**
* @brief JSON::ToVector
* @param node
* @return
*/
    vector<wstring> JSON::ToVector(shared_ptr<Node> node){
        vector<wstring> result;
        auto vect = node->AsVector();
        size_t size = vect.size();
        result.resize(size);
        for(size_t i = 0; i < size; ++i)
            result[i] = vect[i]->AsWstring();
        return result;
    }

/**
* @brief JSON::ToMap
* @param node
* @return
*/
    unordered_map<wstring, vector<wstring>> JSON::ToMap(shared_ptr<Node> node){
        unordered_map<wstring, vector<wstring>> result;
        auto map = node->AsMap();

        for(auto& p:map)
            result[p.first] = ToVector(p.second);

        return result;
    }

/**
* @brief JSON::MakeJSON
* @param filename
* @return
*/
    JSON JSON::MakeJSON(wstring filename){
        std::string str;
        str.assign(filename.begin(), filename.end());
        wfstream file(move(str));
        return Load(file);
    }
}

