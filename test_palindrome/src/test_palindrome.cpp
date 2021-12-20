#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;



// TEST framework

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

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
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







// TEST function

bool IsPalindrom(const string& str) {

	for (size_t i = 0; i < str.size() / 2; ++i) {
		if (str[i] != str[str.size() - i - 1]) {
			return false;
		}
	}
	return true;

}





// TESTs

void TestEmpty() {
    string str;
    AssertEqual(IsPalindrom(str), true, "empty");
}

void TestOneChar() {
    string str("a");
    AssertEqual(IsPalindrom(str), true, "one char");
}

void TestBase() {
    string str("aa");
    AssertEqual(IsPalindrom(str), true, "aa");
    str = ("a a");
    AssertEqual(IsPalindrom(str), true, "a a");
    str = ("a a ");
    AssertEqual(IsPalindrom(str), false, "a a ");
}

void TestWrongSize() {
    string str("abza");
    AssertEqual(IsPalindrom(str), false, "abza");
    str= ("baaz");
    AssertEqual(IsPalindrom(str), false, "baaz");
    str= ("aaz");
    AssertEqual(IsPalindrom(str), false, "aaz");
    str= ("zaa");
    AssertEqual(IsPalindrom(str), false, "zaa");
    str= (" aa");
    AssertEqual(IsPalindrom(str), false, " aa");
}





// Test All

void TestAll(TestRunner& tr)
{
	tr.RunTest(TestEmpty, "TestEmpty");
	tr.RunTest(TestOneChar, "TestOneChar");
	tr.RunTest(TestBase, "TestBase");
	tr.RunTest(TestWrongSize, "TestWrongSize");
}







// Main function
int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  TestAll(runner);

  return 0;
}
