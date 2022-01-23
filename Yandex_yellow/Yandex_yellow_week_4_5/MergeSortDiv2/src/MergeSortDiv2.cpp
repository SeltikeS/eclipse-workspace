//============================================================================
// Name        : MergeSort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end);





template <typename RandomIt>
void MergeSort(RandomIt range_begin, RandomIt range_end) {
	auto length = range_end - range_begin;
	if(length < 2) {
		return;
	}
	vector<typename RandomIt::value_type> elements(range_begin, range_end);


	auto first_begin = begin(elements);
	auto first_end = begin(elements) + length / 2;
	auto second_begin = begin(elements) + length / 2;
	auto second_end = end(elements);

	MergeSort(first_begin, first_end);
	MergeSort(second_begin, second_end);

	merge(first_begin, first_end, second_begin, second_end, range_begin);
}






int main() {
  vector<int> v = {6, 4, 7, 6, 4, 4, 0, 1};
  MergeSort(begin(v), end(v));
  for (int x : v) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
