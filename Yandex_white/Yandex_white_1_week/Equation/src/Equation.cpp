//============================================================================
// Name        : Aquation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;


int main() {
	double a, b, c;
	std::cin >> a >> b >> c;

	if(a == 0){
		if(b != 0) {
			std::cout << -1*c/b;
		}
	}
	else {
		double d = b*b - 4*a*c;

		if(d > 0) {
			double x1 = (-1*b + sqrt(d)) / (2*a);
			double x2 = (-1*b - sqrt(d)) / (2*a);
			std::cout << x1 << ' ' << x2;
		}
		else if(d == 0) {
			double x = -1*b / (2*a);
			std::cout << x;
		}
	}

	return 0;
}
