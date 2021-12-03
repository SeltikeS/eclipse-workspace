//============================================================================
// Name        : rational_part_2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
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

	friend bool operator==(const Rational& a, const Rational& b);
	friend Rational operator+(const Rational& a, const Rational& b);
	friend Rational operator-(const Rational& a, const Rational& b);

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


int main() {
	const Rational r = Rational(1, 2) + Rational(1, 3) - Rational(1, 4);
	if (r == Rational(7, 12)) {
	  cout << "equal";
	}

	return 0;
}
