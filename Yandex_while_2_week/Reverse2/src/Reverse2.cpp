//============================================================================
// Name        : Reverse2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> Reversed(vector<int> v) {
	vector<int> buffer = v;
	v.clear();
	for(int i = buffer.size() - 1; i >= 0; --i){
		v.push_back(buffer[i]);
	}

	return v;
}

int main() {

	vector<int> numbers = {1, 5, 3, 4, 2};
	numbers = Reversed(numbers);
	// numbers ������ ��������� ����� {2, 4, 3, 5, 1}

		for(auto s : numbers){
			std::cout << s;
		}

	return 0;
}
