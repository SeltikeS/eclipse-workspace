//============================================================================
// Name        : MoveStrings.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void MoveStrings(vector<string>& sourse, vector<string>& destination) {
	for(auto s : sourse){
		destination.push_back(s);
	}
	sourse.clear();
}

int main() {

	vector<string> source = {"a", "b", "c"};
	vector<string> destination = {"z"};
	MoveStrings(source, destination);
	// source ������ ��������� ������
	// destination ������ ��������� ������ "z", "a", "b", "c" ������ � ����� �������

//	for(auto s : source){
//		std::cout << s;
//	}
//
//	std::cout << endl;
//
//	for(auto s : destination){
//			std::cout << s;
//		}

	return 0;
}
