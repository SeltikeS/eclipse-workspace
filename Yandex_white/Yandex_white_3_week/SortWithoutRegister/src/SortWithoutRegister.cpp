//============================================================================
// Name        : SortWithoutRegister.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<string> strings;

	for(int i = 0; i < n; ++i){
		string s;
		cin >> s;

		strings.push_back(s);
	}

	sort(strings.begin(), strings.end(),
		[](string l, string r){
			for(auto& item : l){
				if(item >= 65 && item <=90){
					item += 32;
				}
			}
			for(auto& item : r){
				if(item >= 65 && item <=90){
					item += 32;
				}
			}
			return l < r;
		}
	);

	for(const auto& item : strings){
		cout << item << ' ';
	}


	return 0;
}
