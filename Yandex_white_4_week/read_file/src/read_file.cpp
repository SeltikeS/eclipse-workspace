//============================================================================
// Name        : read_file.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main() {
	const string file_name = "input.txt";
	ifstream input(file_name);
	string line;
	while(getline(input, line)) {
		cout << line << endl;
	}

	return 0;
}
