//============================================================================
// Name        : Incognizable.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Incognizable {
public:
	Incognizable() : m_x(0), m_y(1) {}
	Incognizable(const int& x) : m_x(x), m_y(1) {}
	Incognizable(const int& x, const int& y) : m_x(x), m_y(y) {}

private:
	int m_x;
	int m_y;
};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};
	return 0;
}
