//============================================================================
// Name        : BusStops.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int q;
    cin >> q;

    map<string, vector<string>> buses;
    map<string, vector<string>> stops;

    for(int i = 0; i < q; ++i){
        string command;
        cin >> command;

        if(command == "NEW_BUS"){
            string bus;
            int stop_count;
            cin >> bus >> stop_count;

            for(int j = 0; j < stop_count; ++j){
                string stop;
                cin >> stop;
                buses[bus].push_back(stop);
                stops[stop].push_back(bus);
            }
        } else if(command == "BUSES_FOR_STOP"){
            string stop;
            cin >> stop;
            if(stops.count(stop) == 0){
                cout << "No stop" << endl;
            } else {
                for(const auto& bus_item : stops[stop]){
                    cout << bus_item << ' ';
                }
                cout << endl;
            }
        } else if(command == "STOPS_FOR_BUS"){
        	string bus;
        	cin >> bus;
        	if(buses.count(bus) == 0){
        		cout << "No bus" << endl;
        	} else {
        		for(const auto& stop_item : buses[bus]){
        			cout << "Stop " << stop_item << ": ";
        			for(const auto& bus_item : stops[stop_item]){
        				if(stops[stop_item].size() > 1){
        					if(bus_item != bus){
        						cout << bus_item << ' ';
        					}
        				} else {
        					cout << "no interchange";
        				}
        			}
        			cout << endl;
        		}
        	}
        } else if(command == "ALL_BUSES"){
        	if(buses.size() == 0){
        		cout << "No buses" << endl;
        	} else {
        		for(const auto& bus_item : buses){
        			cout << "Bus " << bus_item.first << ": ";
        			for(const auto& stop_item : bus_item.second){
        				cout << stop_item << ' ';
        			}
        			cout << endl;
        		}
        	}
        }


    }

    return 0;
}
