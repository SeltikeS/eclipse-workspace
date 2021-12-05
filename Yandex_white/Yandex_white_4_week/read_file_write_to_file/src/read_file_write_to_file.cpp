//============================================================================
// Name        : read_file_write_to_file.cpp
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
	const string input_file_name = "input.txt";
	ifstream input(input_file_name);
	const string output_file_name = "output.txt";
	ofstream output(output_file_name);

	string line;

	if(input) {
		while(getline(input, line)) {
			output << line << endl;
		}
	}




	return 0;
}
