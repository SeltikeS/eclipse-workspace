//============================================================================
// Name        : MinString.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

int main()
{
	std::string s1, s2, s3;
	std::cin >> s1 >> s2 >> s3;

	if(s1 <= s2) {
	if(s1 <= s3){
			std::cout << s1;
	}
	else {
		std::cout << s3;
	}
	} else if(s2 <= s3) {
		std::cout << s2;
	} else {
		std::cout << s3;
	}

	return 0;
}
