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






// TESTing class

//class Person {
//public:
//    void ChangeFirstName(int year, const string& first_name) {
//        // Add fact of change First Name in Year
//        if(m_first_names.count(year) == 0) {
//            m_first_names[year] = first_name;
//        }
//    }
//
//    void ChangeLastName(int year, const string& last_name) {
//        // Add fact of change Last Name in Year
//        if(m_last_names.count(year) == 0) {
//            m_last_names[year] = last_name;
//        }
//    }
//
//    string GetFullName(int year) {
//        // Take First and Last Names in Year
//        string this_year_first_name;
//        string this_year_last_name;
//
//        for(const auto& item : m_first_names) {
//            if(item.first > year) break;
//            this_year_first_name = item.second;
//        }
//
//        for(const auto& item : m_last_names) {
//            if(item.first > year) break;
//            this_year_last_name = item.second;
//        }
//
//        if(this_year_first_name.length() > 0) {
//
//            if(this_year_last_name.length() > 0) {
//                return  this_year_first_name + ' ' + this_year_last_name;
//            } else {
//                return this_year_first_name + " with unknown last name";
//            }
//        } else {
//            if(this_year_last_name.length() > 0) {
//                return  this_year_last_name + " with unknown first name";
//            } else {
//                return "Incognito";
//            }
//        }
//    }
//
//private:
//    map<int, string> m_first_names;
//    map<int, string> m_last_names;
//};






// TESTs
void TestChangeFirstName()
{
	Person p;
	p.ChangeFirstName(1990, "Polina");
	AssertEqual(p.GetFullName(1990), "Polina with unknown last name", "Test add new First Name");

//	p.ChangeFirstName(1990, "Polia");
//	AssertEqual(p.GetFullName(1990), "Polina with unknown last name", "Test second change First Name");

	p.ChangeLastName(1991, "Frolova");
	AssertEqual(p.GetFullName(1991), "Polina Frolova", "Test history details First Name");

}

void TestChangeLastName()
{
	Person p;
	p.ChangeLastName(1990, "Frolova");
	AssertEqual(p.GetFullName(1990), "Frolova with unknown first name", "Test add new Last Name");

//	p.ChangeLastName(1990, "Frol");
//	AssertEqual(p.GetFullName(1990), "Frolova with unknown first name", "Test second change Last Name");

	p.ChangeFirstName(1991, "Polina");
	AssertEqual(p.GetFullName(1991), "Polina Frolova", "Test history details Last Name");
}

void TestGetFullName()
{
	Person p;
	AssertEqual(p.GetFullName(1990), "Incognito", "Test zero Person");
	p.ChangeFirstName(1991, "Polina");
	AssertEqual(p.GetFullName(1990), "Incognito", "Test add after this year First Name");
	AssertEqual(p.GetFullName(1991), "Polina with unknown last name", "Test add this year First Name");
	p.ChangeLastName(1992, "Frolova");
	AssertEqual(p.GetFullName(1991), "Polina with unknown last name", "Test add after this year Last Name");
	AssertEqual(p.GetFullName(1992), "Polina Frolova", "Test add after this year Last Name");
	AssertEqual(p.GetFullName(1993), "Polina Frolova", "Test GetFullName");
}






// Test All

void TestAll(TestRunner& tr)
{
	tr.RunTest(TestChangeFirstName, "TestChangeFirstName");
	tr.RunTest(TestChangeLastName, "TestChangeLastName");
	tr.RunTest(TestGetFullName, "TestGetFullName");
}







// Main function

int main() {
	TestRunner runner;
	// добавьте сюда свои тесты
	TestAll(runner);

	return 0;
}
