//============================================================================
// Name        : NewLine.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Input{
	string comand;
	int number;
};

void Worry(vector<bool>& v, const int& n){
	v[n] = 1;
}

void Quiet(vector<bool>& v, const int& n){
	v[n] = 0;
}

void Come(vector<bool>& v, const int& n){
	v.resize(v.size() + n);
}

int WorryCount(const vector<bool>& v){
	int count = 0;
	for(auto i : v){
		if(i == 1){
			++count;
		}
	}
	return count;
}

void doComand(vector<bool>& v, const string& s, int& n){

	if(s == "WORRY"){
		Worry(v, n);
	} else if(s == "QUIET"){
		Quiet(v, n);
	} else if(s == "COME"){
		Come(v, n);
	} else if(s == "WORRY_COUNT"){
		cout << WorryCount(v) << endl;
	}
}


int main() {

	int q;

	cin >> q;

	vector<bool> line;

	vector<Input> comands(q);

	for(auto& i : comands){
		cin >> i.comand;
		if(i.comand != "WORRY_COUNT"){
			cin >> i.number;
		};

		doComand(line, i.comand, i.number);
	}

	return 0;
}






