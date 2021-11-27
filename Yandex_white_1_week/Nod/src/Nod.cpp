//============================================================================
// Name        : Nod.cpp
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

	while(a > 0 && b > 0){
		if(a > b){
			a %= b;
		}
		else {
			b %= a;
		}
	}

	std::cout << a+b << std::endl;

	return 0;
}
