//============================================================================
// Name        : PalindromFilter.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool IsPalindrom(std::string s){
	int i = 0;
	int j = s.size() - 1;

	while(i < j){
		if(s[i] != s[j]){
			return 0;
		}

		++i;
		--j;
	}

	return 1;
}

std::vector<std::string> PalindromFilter(std::vector<std::string> words, int minLength){
	std::vector<std::string> palinoms;

	for(auto i : words){
		if((static_cast<int>(i.length()) >= minLength) && IsPalindrom(i)) {
			palinoms.push_back(i);
		}
	}

	return palinoms;
}

int main() {
	std::vector<std::string> w = { "weew", "bro", "code" };
	int ml = 4;

	std::vector<std::string> p = PalindromFilter(w, ml);

	for(auto i : p){
		std::cout << i << ", ";
	}

	return 0;
}
