//============================================================================
// Name        : GetRefStrict.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
using namespace std;




template<typename K, typename T>
T& GetRefStrict(map<K, T>&, K);


template<typename K, typename T>
T& GetRefStrict(map<K, T>& m, K k)
{
	if(m.count(k) == 0)
	{
		throw runtime_error("");
	}

	return m.at(k);
}



int main()
{
	map<int, string> m = {{0, "value"}};
	string& item = GetRefStrict(m, 0);
	item = "newvalue";
	cout << m[0] << endl; // выведет newvalue
	return 0;
}
