//============================================================================
// Name        : Anagrams.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> BuildCharCounters(const string& s){
	map<char, int> char_counter;
	for(const auto& item : s){
			++char_counter[item];
	}

	return char_counter;
}

int main() {

	int n;
	cin >> n;
	vector<string> pair(2);

	for(int i = 0; i < n; ++i){

		cin >> pair[0] >> pair[1];


		if(BuildCharCounters(pair[0]) == BuildCharCounters(pair[1])) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}


	return 0;
}
