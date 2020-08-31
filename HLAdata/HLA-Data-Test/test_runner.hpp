#ifndef TEST_RUNNER_HPP
#define TEST_RUNNER_HPP

#include <sstream>
#include <stdexcept>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <array>
#include<unordered_map>

using namespace std;


ostream& operator << (ostream& os, const vector<std::wstring>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    //os << x;
  }
  return os << L"}";
}

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <unsigned Size,class T>
ostream& operator << (ostream& os, const array<T,Size>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}
template <size_t Size>
ostream& operator << (ostream& os, const array<wstring,Size>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    std::string y(x.begin(),x.end());
    os << y;
  }
  return os << "}";
}
template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}
template <class K, class V>
ostream& operator << (ostream& os, const unordered_map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}
template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (!(t == u)) {
    ostringstream os;
    //os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}
template<size_t Size>
void AssertEqual(const array<wstring,Size>& t, const array<wstring,Size>& u, const string& hint = {}) {
  if (!(t == u)) {
    ostringstream os;
    //os << L"Assertion failed: " << *t.data()  << L" != " << *u.data();
    if (!hint.empty()) {
        wstring whint(hint.begin(),hint.end());
       os << " hint: " << hint;
    }
    string error(os.str().begin(),os.str().end());
    throw runtime_error(error);
  }
}
template<class T, size_t Size>
void AssertEqual(const array<T,Size>& t, const array<T,Size>& u, const string& hint = {}) {
  if (!(t == u)) {
    ostringstream os;
    os << "Assertion failed: " << *t.data()  << " != " << *u.data();
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}


void AssertEqual(const std::wstring& t, const std::wstring& u, const string& hint = {}) {
  if (!(t == u)) {
    wostringstream os;
    os << L"Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
        std::wstring whint(hint.begin(),hint.end());
       os << L" hint: " << whint;
    }
    std::string error(os.str().begin(),os.str().end());
    throw runtime_error(error);
  }
}

inline void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

#define ASSERT_EQUAL(x, y) {            \
  ostringstream os;                     \
  os << #x << " != " << #y << ", "      \
    << __FILE__ << ":" << __LINE__;     \
  AssertEqual(x, y, os.str());          \
}

#define ASSERT(x) {                     \
  ostringstream os;                     \
  os << #x << " is false, "             \
    << __FILE__ << ":" << __LINE__;     \
  Assert(x, os.str());                  \
}

#define W_ASSERT_EQUAL(x, y) {            \
  wostringstream os;                     \
  os << #x << L" != " << #y << L", "      \
    << __FILE__ << L":" << __LINE__;     \
  AssertEqual(x, y, os.str());          \
}

#define W_ASSERT(x) {                     \
  wostringstream os;                     \
  os << #x << L" is false, "             \
    << __FILE__ << L":" << __LINE__;     \
  Assert(x, os.str());                  \
}

#define RUN_TEST(tr, func) \
  tr.RunTest(func, #func)

#endif // TEST_RUNNER_HPP
