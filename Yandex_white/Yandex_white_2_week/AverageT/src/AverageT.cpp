//============================================================================
// Name        : AverageT.cpp
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
	cin >> n;

	vector<int> v(n);

	int sum = 0;

	for(auto& i : v){
		cin >> i;
		sum += i;
	}

	int average = sum / v.size();

	vector<int> k;

	for(int i = 0; i < v.size(); ++i){
		if(v[i] > average){
			k.push_back(i);
		}
	}

	cout << k.size() << endl;

	for(auto i : k){
		cout << i << ' ';
	}

	return 0;
}
