//============================================================================
// Name        : Concerns.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {

	//	Days in every month
	vector<int> month = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//	Month counter. January = 0
	int counter = 0;

	//	Daily deals
	vector<vector<string>> days(month[counter]);

	//	Number of commands
	int q;
	cin >> q;

	//	Start doing commands
	for(int k = 0; k < q; ++k){
		string command;
		cin >> command;

		//	ADD daily deal with name "s" to day "i"
		if(command == "ADD"){
			string s;
			int i;
			cin >> i >> s;

			days[i-1].push_back(s);

		//	DUMP all deals of "i" day of month
		} else if(command == "DUMP"){
			int i;
			cin >> i;
			cout << days[i-1].size() << ' ';
			for(auto c : days[i-1]){
				cout << c << ' ';
			}
			cout << endl;

		//	NEXT month
		} else if(command == "NEXT"){

			int pre_counter = counter;

			// If December - next January
			if(counter >= 11){
				counter = 0;
			} else {
				++counter;
			}

			// If next month have less days then last we push_back all deals to last day of next month
			if(month[counter] < month[pre_counter]){
				for(int j = month[counter]; j < month[pre_counter]; ++j){
					for(auto c : days[j]){
						days[month[counter]-1].push_back(c);
					}
				}
			}

			days.resize(month[counter]);
		}
	}

	return 0;
}
