//============================================================================
// Name        : ToBinary.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

using namespace std;

int main() {

	int n;
	std::cin >> n;

	std::vector<int> binary_number;

	while(n >= 1){
		binary_number.push_back(n%2);
		n /= 2;
	}


	for(int i = binary_number.size()-1; i >= 0; --i){
		std::cout << binary_number[i];
	}

	return 0;
}
