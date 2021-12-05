//============================================================================
// Name        : rational_part_5.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
#include <sstream>
#include <cctype>
#include <vector>
#include <set>
#include <map>
using namespace std;

class Rational {
public:
	Rational() : m_numerator(0), m_denominator(1) {}
	Rational(int numerator, int denominator) :
			m_numerator(numerator / gcd(numerator, denominator)),
			m_denominator(denominator / gcd(numerator, denominator)) {
		if(m_numerator == 0) {
			m_denominator = 1;
		} else {
			if(m_denominator < 0) {
				m_numerator *= -1;
				m_denominator *= -1;
			}
		}
	}

	int Numerator() const {
		return m_numerator;
	}
	int Denominator() const {
		return m_denominator;
	}

	void SetNumerator(int a) {
		m_numerator = a;
	}
	void SetDenominator(int a) {
		m_denominator = a;
	}

	friend istringstream& operator>>(istringstream& stream, Rational& a);

private:
	int m_numerator;
	int m_denominator;
};

bool operator==(const Rational& a, const Rational& b) {
		if((a.Numerator() == b.Numerator())
				&& (a.Denominator() == b.Denominator())) {
			return true;
		} else {
			return false;
		}
	}
Rational operator+(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Denominator() + b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
}
Rational operator-(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Denominator() - b.Numerator() * a.Denominator(), a.Denominator() * b.Denominator()};
}

Rational operator*(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Numerator(), a.Denominator() * b.Denominator()};
}
Rational operator/(const Rational& a, const Rational& b) {
	return {a.Numerator() * b.Denominator(), a.Denominator() * b.Numerator()};
}

ostream& operator<<(ostream& stream, const Rational& a) {
	stream << a.Numerator() << '/' << a.Denominator();
	return stream;
}
istringstream& operator>>(istringstream& stream, Rational& a) {
	char ch;
	int num, den;
	stream >> num;
	if(stream.good()) {
		stream >> ch;
		if(ch == '/') {
			stream >> den;
			if(!stream.fail()) {
				Rational b(num, den);
				a = b;
			}
		}
	}
	return stream;
}

bool operator<(const Rational& a, const Rational& b) {
	if(a.Numerator() * b.Denominator() < b.Numerator() * a.Denominator()) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	{
	        const set<Rational> rs = {{1, 2}, {1, 25}, {3, 4}, {3, 4}, {1, 2}};
	        if (rs.size() != 3) {
	            cout << "Wrong amount of items in the set" << endl;
	            return 1;
	        }

	        vector<Rational> v;
	        for (auto x : rs) {
	            v.push_back(x);
	        }
	        if (v != vector<Rational>{{1, 25}, {1, 2}, {3, 4}}) {
	            cout << "Rationals comparison works incorrectly" << endl;
	            return 2;
	        }
	    }

	    {
	        map<Rational, int> count;
	        ++count[{1, 2}];
	        ++count[{1, 2}];

	        ++count[{2, 3}];

	        if (count.size() != 2) {
	            cout << "Wrong amount of items in the map" << endl;
	            return 3;
	        }
	    }

	    cout << "OK" << endl;
	return 0;
}
