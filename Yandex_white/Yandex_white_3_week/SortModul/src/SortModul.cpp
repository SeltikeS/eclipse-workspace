//============================================================================
// Name        : SortModul.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

void ModulSort(vector<int>& numbers){
	for(int i = 0; i < numbers.size(); ++i){
		for(int j = i+1; j < numbers.size(); ++j){
			if(abs(numbers[i]) > abs(numbers[j])){
				swap(numbers[i], numbers[j]);
			}
		}
	}
}

int main() {

	int n;
	cin >> n;

	vector<int> numbers;

	for(int i = 0; i < n; ++i){
		int number;
		cin >> number;

		numbers.push_back(number);
	}

	ModulSort(numbers);

	for(const auto& item : numbers){
		cout << item << ' ';
	}

	return 0;
}
