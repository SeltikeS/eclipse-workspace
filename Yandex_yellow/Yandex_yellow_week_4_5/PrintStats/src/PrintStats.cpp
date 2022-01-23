//============================================================================
// Name        : PrintStats.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include "Person.h"


using namespace std;

void PrintStats(vector<Person> persons);

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end);



void PrintStats(vector<Person> persons) {
	cout << "Median age = " << ComputeMedianAge(begin(persons), end(persons)) << endl;


	auto genderIt = partition(begin(persons), end(persons), [](Person p){ return p.gender == Gender::FEMALE; });
	cout << "Median age for females = " << ComputeMedianAge(begin(persons), genderIt) << endl;
	cout << "Median age for males = " << ComputeMedianAge(genderIt, end(persons)) << endl;

	auto employedFemalesIt = partition(begin(persons), genderIt, [](Person p){ return p.is_employed == true; });
	cout << "Median age for employed females = " << ComputeMedianAge(begin(persons), employedFemalesIt) << endl;
	cout << "Median age for unemployed females = " << ComputeMedianAge(employedFemalesIt, genderIt) << endl;

	auto employedMalesIt = partition(genderIt, end(persons), [](Person p){ return p.is_employed == true; });
	cout << "Median age for employed males = " << ComputeMedianAge(genderIt, employedMalesIt) << endl;
	cout << "Median age for unemployed males = " << ComputeMedianAge(employedMalesIt, end(persons)) << endl;

}






int main() {
  vector<Person> persons = {
      {31, Gender::MALE, false},
      {40, Gender::FEMALE, true},
      {24, Gender::MALE, true},
      {20, Gender::FEMALE, true},
      {80, Gender::FEMALE, false},
      {78, Gender::MALE, false},
      {10, Gender::FEMALE, false},
      {55, Gender::MALE, true},
  };
  PrintStats(persons);
  return 0;
}
