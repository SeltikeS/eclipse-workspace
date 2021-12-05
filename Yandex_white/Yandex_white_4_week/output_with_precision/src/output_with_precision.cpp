//============================================================================
// Name        : output_with_precision.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {

	ifstream input("input.txt");
	double number;

	cout << fixed << setprecision(3);

	input >> number;
	while(input) {
		cout << number << endl;
		input >> number;
	}

	return 0;
}
