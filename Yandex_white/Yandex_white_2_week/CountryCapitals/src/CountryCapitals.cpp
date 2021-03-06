//============================================================================
// Name        : CountryCapitals.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
using namespace std;






void Dump(const map<string, string>& countries){

}

int main() {

	int q;
	cin >> q;

	map<string, string> countries;
	countries.clear();

	for(int i = 0; i < q; ++i){
		string command;
		cin >> command;

		if(command == "CHANGE_CAPITAL"){
			string country;
			string new_capital;
			cin >> country >> new_capital;

			if(countries[country].size() == 0){
				cout << "Introduce new country " << country << " with capital " <<  new_capital << endl;
				countries.erase(country);
				countries[country] = new_capital;
			} else if(countries[country] == new_capital){
				cout << "Country " << country << " hasn't changed its capital" << endl;
			} else {
				cout << "Country " << country << " has changed its capital from " << countries[country] << " to " << new_capital << endl;
				countries.erase(country);
				countries[country] = new_capital;
			}

		} else if(command == "RENAME"){
			string old_country_name;
			string new_country_name;
			cin >> old_country_name >> new_country_name;

			if(countries[old_country_name].size() == 0){
					cout << "Incorrect rename, skip" << endl;
					countries.erase(old_country_name);
				} else if((old_country_name == new_country_name) || (countries[new_country_name].size() > 0)){
					cout << "Incorrect rename, skip" << endl;
					if(countries[new_country_name].size() == 0){
						countries.erase(new_country_name);
					}
				} else {
					cout << "Country " << old_country_name << " with capital " << countries[old_country_name] << " has been renamed to " << new_country_name << endl;

					string capital = countries[old_country_name];
					countries.erase(old_country_name);
					countries[new_country_name] = capital;
				}

		} else if(command == "ABOUT"){
			string country;
			cin >> country;

			if(countries[country].size() == 0){
				cout << "Country " << country << " doesn't exist" << endl;
				countries.erase(country);
			} else {
				cout << "Country " << country << " has capital " << countries[country] << endl;
			}

		} else if(command == "DUMP"){
			if(countries.size() == 0){
				cout << "There are no countries in the world" << endl;
			} else {
				for(const auto& country : countries){
						cout << country.first << '/' << country.second << ' ';
				}
				cout << endl;
			}


		}
	}

	return 0;
}
