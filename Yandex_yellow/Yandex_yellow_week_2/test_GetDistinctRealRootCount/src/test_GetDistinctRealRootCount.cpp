#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <cmath>

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




// Work function

int GetDistinctRealRootCount(double a, double b, double c) {
  // Вы можете вставлять сюда различные реализации функции,
  // чтобы проверить, что ваши тесты пропускают корректный код
  // и ловят некорректный
	int count = 0;

	if(a == 0){
		if(b != 0) {
//			std::cout << -1*c/b;
			++count;
		}
	}
	else {
		double d = b*b - 4*a*c;

		if(d > 0) {
//			double x1 = (-1*b + sqrt(d)) / (2*a);
			++count;
//			double x2 = (-1*b - sqrt(d)) / (2*a);
			++count;
//			std::cout << x1 << ' ' << x2;
		}
		else if(d == 0) {
//			double x = -1*b / (2*a);
			++count;
//			std::cout << x;
		}
	}

	return count;


}



// TESTs

void TestZeroA()
{
	AssertEqual(GetDistinctRealRootCount(0, 1, 1), 1, "Test zero A pos B pos C");
}
void TestZeroAZeroB()
{
	AssertEqual(GetDistinctRealRootCount(0, 0, 1), 0, "Test zero A zero B pos C");
}
void TestZeroAZeroC()
{
	AssertEqual(GetDistinctRealRootCount(0, 1, 0), 1, "Test zero A pos B zero C");
}

void TestZeroD()
{
	AssertEqual(GetDistinctRealRootCount(1, 2, 1), 1, "Test zero D");
}
void TestPosD()
{
	AssertEqual(GetDistinctRealRootCount(1, 3, 1), 2, "Test zero D");
}
void TestNegD()
{
	AssertEqual(GetDistinctRealRootCount(1, 1, 1), 0, "Test zero D");
}




// Run all TESTs

void TestAll(TestRunner& tr)
{
	tr.RunTest(TestZeroA, "TestZeroA");
	tr.RunTest(TestZeroAZeroB, "TestZeroAZeroB");
	tr.RunTest(TestZeroAZeroC, "TestZeroAZeroC");

	tr.RunTest(TestZeroD, "TestZeroD");
	tr.RunTest(TestPosD, "TestPosD");
	tr.RunTest(TestNegD, "TestNegD");
}




int main() {
	TestRunner runner;
	TestAll(runner);

	return 0;
}
