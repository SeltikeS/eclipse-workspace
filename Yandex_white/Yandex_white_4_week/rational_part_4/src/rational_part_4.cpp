//============================================================================
// Name        : rational_part_4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <numeric>
#include <sstream>
#include <cctype>
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

int main() {
	{
	        ostringstream output;
	        output << Rational(-6, 8);
	        if (output.str() != "-3/4") {
	            cout << "Rational(-6, 8) should be written as \"-3/4\"" << endl;
	            return 1;
	        }
	    }

	    {
	        istringstream input("5/7");
	        Rational r;
	        input >> r;
	        bool equal = r == Rational(5, 7);
	        if (!equal) {
	            cout << "5/7 is incorrectly read as " << r << endl;
	            return 2;
	        }
	    }

	    {
	        istringstream input("");
	        Rational r;
	        bool correct = !(input >> r);
	        if (!correct) {
	            cout << "Read from empty stream works incorrectly" << endl;
	            return 3;
	        }
	    }

	    {
	        istringstream input("5/7 10/8");
	        Rational r1, r2;
	        input >> r1 >> r2;
	        bool correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
	        if (!correct) {
	            cout << "Multiple values are read incorrectly: " << r1 << " " << r2 << endl;
	            return 4;
	        }

	        input >> r1;
	        input >> r2;
	        correct = r1 == Rational(5, 7) && r2 == Rational(5, 4);
	        if (!correct) {
	            cout << "Read from empty stream shouldn't change arguments: " << r1 << " " << r2 << endl;
	            return 5;
	        }
	    }

	    {
	        istringstream input1("1*2"), input2("1/"), input3("/4");
	        Rational r1, r2, r3;
	        input1 >> r1;
	        input2 >> r2;
	        input3 >> r3;
	        bool correct = r1 == Rational() && r2 == Rational() && r3 == Rational();
	        if (!correct) {
	            cout << "Reading of incorrectly formatted rationals shouldn't change arguments: "
	                 << r1 << " " << r2 << " " << r3 << endl;

	            return 6;
	        }
	    }

	    cout << "OK" << endl;
	return 0;
}
