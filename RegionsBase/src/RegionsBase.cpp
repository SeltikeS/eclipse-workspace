//============================================================================
// Name        : RegionsBase.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <string>
using namespace std;

//enum class Lang {
//	DE, FR, IT
//};

//struct Region {
//	string std_name;
//	string parent_std_name;
//	map<Lang, string> names;
//	int64_t population;
//};
//
bool operator<(const Region& a, const Region& b) {
	return tie(a.std_name, a.parent_std_name, a.names, a.population) <
		   tie(b.std_name, b.parent_std_name, b.names, b.population);
}

int FindMaxRepetitionCount(const vector<Region>& regions) {
		int count = 0;
		map<Region, int> s;
		for(const auto& item : regions) {
			++s[item];
		}

		for(const auto& item : s) {
			if(item.second > count) {
				count = item.second;
			}
		}

		return count;
}

//int main() {
//  cout << FindMaxRepetitionCount({
//      {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      },
//  }) << endl;
//
//  cout << FindMaxRepetitionCount({
//      {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Russia",
//          "Eurasia",
//          {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Toulouse",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          89
//      }, {
//          "Moscow",
//          "Russia",
//          {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
//          31
//      },
//  }) << endl;
//
//  return 0;
//}
