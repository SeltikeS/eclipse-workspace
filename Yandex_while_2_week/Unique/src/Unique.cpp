//============================================================================
// Name        : Unique.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <string>
using namespace std;

int main() {
	int n;
	cin >> n;

	set<string> s;

	for(int i = 0; i < n; ++i){
		string word;
		cin >> word;
		s.insert(word);
	}

	cout << s.size();

	return 0;
}
