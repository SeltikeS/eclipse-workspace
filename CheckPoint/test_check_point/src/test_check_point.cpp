//============================================================================
// Name        : test_check_point.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <set>
#include <vector>
using namespace std;


int solution(vector<int> A) {
    // write your code in C++14 (g++ 6.2.0)

    int min = 1;
    set<int> nums;

    for(const int& i : A)
    {
        nums.insert(i);
    }

    for(const int& i : nums)
    {
        if(i > min)
        {
            break;
        }
        else if (i > 0)
        {
            ++min;
        }
    }

    return min;

}


int main() {
	cout << solution({1, 3, 6, 4, 1, 2}) << endl; // prints !!!Hello World!!!
	return 0;
}
