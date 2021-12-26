/*
 * bus_manager.h
 *
 *  Created on: 26 ���. 2021 �.
 *      Author: SeltikeS
 */

#pragma once

#include "responses.h"
#include <string>
#include <vector>
#include <map>

using namespace std;

class BusManager {
public:
	void AddBus(const string& bus, const vector<string>& stops);
	BusesForStopResponse GetBusesForStop(const string& stop) const;
	StopsForBusResponse GetStopsForBus(const string& bus) const;
	AllBusesResponse GetAllBuses() const;

private:
	map<string, vector<string>> buses_to_stops;
	map<string, vector<string>> stops_to_buses;
};

