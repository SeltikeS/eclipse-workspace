//============================================================================
// Name        : phone_number.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "phone_number.h"
#include <sstream>
#include <exception>

using namespace std;

PhoneNumber::PhoneNumber(const string &international_number) {
	stringstream ss(international_number);
	char ch;
	int num;
	ss >> ch;
	if(ch == 43 && !ss.eof()) {
		ss >> num >> ch;
		country_code_ = to_string(num);
		if(ch == 45 && !ss.eof()) {
			ss >> num >> ch;
			city_code_ = to_string(num);
			if(ch == 45 && !ss.eof()) {
				ss >> local_number_;
			} else {
				throw invalid_argument("");
			}

		} else {
			throw invalid_argument("");
		}

	} else {
		throw invalid_argument("");
	}

}

string PhoneNumber::GetCountryCode() const {
	return country_code_;
}
string PhoneNumber::GetCityCode() const {
	return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
	return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
	string s = "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
	return s;
}
