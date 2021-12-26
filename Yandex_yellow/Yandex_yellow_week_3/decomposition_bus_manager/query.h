/*
 * query.h
 *
 *  Created on: 26 ���. 2021 �.
 *      Author: SeltikeS
 */

#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q);



