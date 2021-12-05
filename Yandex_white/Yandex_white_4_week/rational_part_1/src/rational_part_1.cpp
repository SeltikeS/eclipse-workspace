//============================================================================
// Name        : rational_part_1.cpp
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

private:
	int m_numerator;
	int m_denominator;
};


int main() {

	return 0;
}
