//============================================================================
// Name        : BusStops3.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main() {

	int q;
	cin >> q;

	map<set<string>, int> buses;

	for(int j = 0; j < q; ++j){
		int n;
		cin >> n;
		set<string> stops;
		for(int k = 0; k < n; ++k){
			string stop;
			cin >> stop;
			stops.insert(stop);
		}

		bool is_exist = 0;
		for(const auto& bus_item : buses){
			if(bus_item.first == stops) {
				is_exist = 1;
				cout << "Already exists for " << bus_item.second << endl;
			}
		}
		if(!is_exist){
			int new_bus = buses.size() + 1;
			buses[stops] = new_bus;
			cout << "New bus " << new_bus << endl;
		}

	}

	return 0;
}
