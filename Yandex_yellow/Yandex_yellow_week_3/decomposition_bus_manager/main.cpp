/*
 * main.cpp
 *
 *  Created on: 26 ???. 2021 ?.
 *      Author: SeltikeS
 */

#include "query.h"
#include "responses.h"
#include "bus_manager.h"

#include <cassert>
#include <iostream>


using namespace std;







// ?? ????? ???? ??????? main, ?????????? ??????? ? ?????? ????

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}



