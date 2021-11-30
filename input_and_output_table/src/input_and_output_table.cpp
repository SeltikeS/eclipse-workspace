//============================================================================
// Name        : input_and_output_table.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int main() {

	ifstream input("input.txt");

	int n, m;
	input >> n >> m;
	vector<vector<int>> table;

	for(int i = 0; i < n; ++i) {
		int number;
		vector<int> raw;
		for(int j = 0; j < m-1; ++j) {
			int number;
			input >> number;
			raw.push_back(number);
			input.ignore(1);
		}
		input >> number;
		raw.push_back(number);
		table.push_back(raw);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << setw(10) << table[i][j];
			if(j < m-1) {
				cout << ' ';
			}
		}
		if(i < n-1) {
			cout << endl;
		}
	}

	return 0;
}
