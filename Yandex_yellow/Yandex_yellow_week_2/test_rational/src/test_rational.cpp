#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <numeric>

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

//class Rational {
//public:
//	Rational() : m_numerator(0), m_denominator(1) {}
//	Rational(int numerator, int denominator) :
//			m_numerator(numerator / gcd(numerator, denominator)),
//			m_denominator(denominator / gcd(numerator, denominator)) {
//		if(m_numerator == 0) {
//			m_denominator = 1;
//		} else {
//			if(m_denominator < 0) {
//				m_numerator *= -1;
//				m_denominator *= -1;
//			}
//		}
//	}
//
//	int Numerator() const {
//		return m_numerator;
//	}
//	int Denominator() const {
//		return m_denominator;
//	}
//
//	void SetNumerator(int a) {
//		m_numerator = a;
//	}
//	void SetDenominator(int a) {
//		m_denominator = a;
//	}
//
//	friend istringstream& operator>>(istringstream& stream, Rational& a);
//
//private:
//	int m_numerator;
//	int m_denominator;
//};
//
//bool operator==(const Rational& a, const Rational& b) {
//		if((a.Numerator() == b.Numerator())
//				&& (a.Denominator() == b.Denominator())) {
//			return true;
//		} else {
//			return false;
//		}
//	}
//Rational operator+(const Rational& a, const Rational& b) {
//	return {a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
//}
//Rational operator-(const Rational& a, const Rational& b) {
//	return {a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
//}
//
//Rational operator*(const Rational& a, const Rational& b) {
//	return {a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator()};
//}
//Rational operator/(const Rational& a, const Rational& b) {
//	return {a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator()};
//}
//
//ostream& operator<<(ostream& stream, const Rational& a) {
//	stream << a.Numerator() << '/' << a.Denominator();
//	return stream;
//}
//istringstream& operator>>(istringstream& stream, Rational& a) {
//	char ch;
//	int num, den;
//	stream >> num;
//	if(stream.good()) {
//		stream >> ch;
//		if(ch == '/') {
//			stream >> den;
//			if(!stream.fail()) {
//				Rational b(num, den);
//				a = b;
//			}
//		}
//	}
//	return stream;
//}
//
//bool operator<(const Rational& a, const Rational& b) {
//	if(a.Numerator() * b.Denominator() < b.Numerator() * a.Denominator()) {
//		return 1;
//	} else {
//		return 0;
//	}
//}
//
//
//


// TESTs

void TestDefault()
{
	Rational r;
	AssertEqual(r.Numerator(), 0, "Test default Numerator");
	AssertEqual(r.Denominator(), 1, "Test default Denominator");
}

void TestFractionReduction()
{
	Rational r(4, 6);
	AssertEqual(r.Numerator(), 2, "Test fraction reduction Numerator");
	AssertEqual(r.Denominator(), 3, "Test fraction reduction Denominator");
}

void TestNegativeNumbers()
{
	Rational r1(-4, 6);
	AssertEqual(r1.Numerator(), -2, "Test negative Numerator with positive Denominator");
	AssertEqual(r1.Denominator(), 3, "Test positive Denominator with negative Numerator");

	Rational r2(6, -8);
	AssertEqual(r2.Numerator(), -3, "Test positive Numerator with negative Denominator");
	AssertEqual(r2.Denominator(), 4, "Test negative Denominator with positive Numerator");

	Rational r3(-10, -12);
	AssertEqual(r3.Numerator(), 5, "Test negative Numerator with negative Denominator");
	AssertEqual(r3.Denominator(), 6, "Test negative Denominator with negative Numerator");

}

void TestZero()
{
	Rational r(0, 5);
	AssertEqual(r.Numerator(), 0, "Test zero Numerator");
	AssertEqual(r.Denominator(), 1, "Test Denominator with zero Numerator");
}







// Test All

void TestAll(TestRunner& tr)
{
	tr.RunTest(TestDefault, "TestDefault");
	tr.RunTest(TestFractionReduction, "TestFractionReduction");
	tr.RunTest(TestNegativeNumbers, "TestNegativeNumbers");
	tr.RunTest(TestZero, "TestZero");
}








// Main function
int main() {
  TestRunner runner;
  // добавьте сюда свои тесты
  TestAll(runner);


  return 0;
}
