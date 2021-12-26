//============================================================================
// Name        : sum_reverse_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "sum_reverse_sort.h"

#include <iostream>
#include <algorithm>

using namespace std;

int Sum(int x, int y) {
	return x + y;
}

string Reverse(string s) {
	reverse(s.begin(), s.end());
	return s;
}

void Sort(vector<int>& nums) {
	sort(nums.begin(), nums.end());
}


//int main() {
//
//	cout << Sum(1, 2) << endl;
//	cout << Reverse("Max") << endl;
//	vector<int> v = {1, 3, 2, 4, 5, 8, 7, 6};
//	Sort(v);
//	for(const auto& i : v) {
//		cout << i;
//	}
//
//
//	return 0;
//}
