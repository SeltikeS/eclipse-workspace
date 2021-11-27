//============================================================================
// Name        : Factorial.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int Factorial(int n){
	int f = 1;
	if(n >= 1){
		for(int i = 1; i <= n; ++i){
				f *= i;
			}
	}

	return f;
}

int main() {

	int number;
	std::cin >> number;

	std::cout << Factorial(number) << std::endl;

	return 0;
}
