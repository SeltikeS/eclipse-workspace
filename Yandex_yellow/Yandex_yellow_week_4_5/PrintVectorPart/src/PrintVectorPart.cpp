//============================================================================
// Name        : PrintVectorPart.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//#include "PrintVectorPart.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
	auto first_negative = find_if(begin(numbers), end(numbers), [](const int& x){return x < 0;});
	for(auto i = first_negative; i != begin(numbers);) {
		--i;
		cout << *i << " ";
	}
}
