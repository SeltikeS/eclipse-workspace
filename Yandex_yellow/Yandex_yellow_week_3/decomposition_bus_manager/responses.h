/*
 * responses.h
 *
 *  Created on: 26 дек. 2021 г.
 *      Author: SeltikeS
 */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

struct BusesForStopResponse {
	// Наполните полями эту структуру
	vector<string> buses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
	// Наполните полями эту структуру
	string bus;
	vector<pair<string, vector<string>>> stops_for_buses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
	// Наполните полями эту структуру
	map<string, vector<string>> buses_to_stops;
};

ostream& operator << (ostream& os, const AllBusesResponse& r);



