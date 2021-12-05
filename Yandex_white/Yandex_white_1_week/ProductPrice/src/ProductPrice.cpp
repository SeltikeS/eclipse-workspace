//============================================================================
// Name        : ProductPrice.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	double n, a, b, x, y;
	std::cin >> n >> a >> b >> x >> y;

	if(n > b) {
		std::cout << n * (1 - y/100);
	} else if(n > a) {
		std::cout << n * (1 - x/100);
	} else {
		std::cout << n;
	}

	return 0;
}
