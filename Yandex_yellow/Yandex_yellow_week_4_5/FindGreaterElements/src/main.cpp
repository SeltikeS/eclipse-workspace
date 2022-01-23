/*
 * main.cpp
 *
 *  Created on: 27 дек. 2021 г.
 *      Author: SeltikeS
 */


#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
	auto it = upper_bound(begin(elements), end(elements), border);

	return {it, end(elements)};
}

int main() {
  for (int x : FindGreaterElements(set<int>{1, 5, 7, 8}, 5)) {
    cout << x << " ";
  }
  cout << endl;

  string to_find = "Python";
  cout << FindGreaterElements(set<string>{"C", "C++"}, to_find).size() << endl;
  return 0;
}


