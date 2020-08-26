#include "JSON.hpp"

namespace HLA {

    using namespace std;

    Node::Node(vector<shared_ptr<Node>> array) : as_array(move(array)) {
    }

    Node::Node(unordered_map<wstring, shared_ptr<Node>> map) : as_map(move(map)){
    }

    Node::Node(int value) : as_int(value) {
    }

    Node::Node(wstring value) : as_wstring(move(value)) {
    }

    const vector<shared_ptr<Node>>& Node::AsVector() const {
      return as_array;
    }

    const unordered_map<wstring, shared_ptr<Node>>& Node::AsMap() const {
      return as_map;
    }

    int Node::AsInt() const {
      return as_int;
    }

    const wstring& Node::AsWstring() const {
      return as_wstring;
    }

    JSON::JSON(shared_ptr<Node> root) : root(move(root)) {
    }

    const shared_ptr<Node> JSON::GetRoot() const {
      return root;
    }

    shared_ptr<Node> LoadNode(wistream& input);

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

    shared_ptr<Node> LoadInt(wistream& input) {
      int result = 0;
      while (isdigit(input.peek())) {
        result *= 10;
        result += input.get() - '0';
      }
      return make_shared<Node>(result);
    }

    shared_ptr<Node> LoadWstring(wistream& input) {
      wstring line;
      getline(input, line, L'"');
      return make_shared<Node>(move(line));
    }

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

    JSON Load(wistream& input) {
      return JSON{LoadNode(input)};
    }

    vector<wstring> JSON::ToVector(shared_ptr<Node> node){
        vector<wstring> result;
        auto vect = node->AsVector();
        size_t size = vect.size();
        result.resize(size);
        for(size_t i = 0; i < size; ++i)
            result[i] = vect[i]->AsWstring();
        return result;
    }

    unordered_map<wstring, vector<wstring>> JSON::ToMap(shared_ptr<Node> node){
        unordered_map<wstring, vector<wstring>> result;
        auto map = node->AsMap();

        for(auto& p:map)
            result[p.first] = ToVector(p.second);

        return result;
    }

    JSON JSON::MakeJSON(wstring filename){
        std::string str;
        str.assign(filename.begin(), filename.end());
        wfstream file(move(str));
        return Load(file);
    }
}

