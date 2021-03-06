//============================================================================
// Name        : Synonyms.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

void Add(map<string, set<string>>& dictionary, const string& s1, const string& s2){
	dictionary[s1].insert(s2);
	dictionary[s2].insert(s1);
}

void Count(map<string, set<string>>& dictionary, const string& s){
	int count_synonyms;

	if(dictionary.count(s)){
		count_synonyms = dictionary[s].size();
		cout << count_synonyms << endl;
	} else {
		cout << '0' << endl;
	}

}

void Check(map<string, set<string>>& dictionary, const string& s1, const string& s2){
	if(dictionary.count(s1)){
		if(dictionary[s1].count(s2)){
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	} else {
		cout << "NO" << endl;
	}
}

int main() {

	int q;
	cin >> q;

	map<string, set<string>> dictionary;

	for(int i = 0; i < q; ++i){
		string command;
		cin >> command;

		if(command == "ADD"){
			string s1, s2;
			cin >> s1 >> s2;

			Add(dictionary, s1, s2);

		} else if(command == "COUNT") {
			string s;
			cin >> s;

			Count(dictionary, s);

		} else if(command == "CHECK") {
			string s1, s2;
			cin >> s1 >> s2;

			Check(dictionary, s1, s2);
		}
	}

	return 0;
}
