//============================================================================
// Name        : Reverse.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void Reverse(vector<int>& v) {
	vector<int> buffer = v;
	v.clear();
	for(int i = buffer.size() - 1; i >= 0; --i){
		v.push_back(buffer[i]);
	}
}

int main() {

	vector<int> numbers = {1, 5, 3, 4, 2};
	Reverse(numbers);
	// numbers ?????? ????????? ????? {2, 4, 3, 5, 1}

		for(auto s : numbers){
			std::cout << s;
		}

	return 0;
}
