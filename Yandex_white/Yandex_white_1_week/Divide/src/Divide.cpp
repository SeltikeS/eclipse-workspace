//============================================================================
// Name        : Divide.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	int a, b;
	std::cin >> a >> b;

	if(b != 0) {
		std::cout << a / b << std::endl;
	}
	else {
		std::cout << "Impossible" << std::endl;
	}


	return 0;
}
