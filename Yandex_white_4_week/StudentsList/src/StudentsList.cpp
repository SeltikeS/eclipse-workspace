//============================================================================
// Name        : StudentsList.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Student {
	string first_name;
	string last_name;
	int day;
	int month;
	int year;
};

int main() {

	vector<Student> students;

	int n;
	cin >> n;

	for(int i = 0; i < n; ++i) {
		string new_first_name, new_last_name;
		int new_day, new_month, new_year;

		cin >> new_first_name >> new_last_name >> new_day >> new_month >> new_year;
		students.push_back({ new_first_name, new_last_name, new_day, new_month, new_year });
	}

	int m;
	cin >> m;

	for(int i = 0; i < m; ++i) {
		string request;
		int number;
		cin >> request >> number;
		--number;

		if(request == "name" && number >= 0 && number < n) {
			cout << students[number].first_name << ' ' << students[number].last_name << endl;
		} else if(request == "date" && number >= 0 && number < n) {
			cout << students[number].day << '.' << students[number].month << '.' << students[number].year << endl;
		} else {
			cout << "bad request" << endl;
		}


	}

	return 0;
}
