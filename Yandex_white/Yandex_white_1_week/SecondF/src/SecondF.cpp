//============================================================================
// Name        : SecondF.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {

	std::string s;
	std::cin >> s;

	int f_counter = 0;
	int f_placement = -2;

	for(int i = 0; i < s.size(); ++i){
		if(s[i] == 'f'){
			++f_counter;
			++f_placement;
			if(f_placement >= 0){
				f_placement = i;
			}
			if(f_counter == 2){
				break;
			}
		}
	}

	std::cout << f_placement << std::endl;

	return 0;
}
