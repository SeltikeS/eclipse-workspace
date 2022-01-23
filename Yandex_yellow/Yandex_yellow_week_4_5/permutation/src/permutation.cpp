//============================================================================
// Name        : permutation.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;


ostream& operator<<(ostream& s, const vector<int>& v) {
	for(size_t i = 0; i < v.size(); ++i) {
		s << v[i] << ' ';
	}
	return s;
}

void Permutations(const int& n) {
	vector<int> s(n);
	iota(s.rbegin(), s.rend(), 1);

	do {
		cout << s << endl;
	} while(prev_permutation(s.begin(), s.end()));
}




int main() {
	int N;
	cin >> N;
	Permutations(N);
	return 0;
}
