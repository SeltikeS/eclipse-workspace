//============================================================================
// Name        : UpgradeIfGreater.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void UpdateIfGreater(int first, int& second) {
	if(first > second){
		second = first;
	}
}

int main() {

	int a = 4;
	int b = 2;
	UpdateIfGreater(a, b);

	std::cout << b;

	return 0;
}
