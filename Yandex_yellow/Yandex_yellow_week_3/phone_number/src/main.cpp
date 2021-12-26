/*
 * main.cpp
 *
 *  Created on: 25 дек. 2021 г.
 *      Author: SeltikeS
 */

#include <iostream>
#include "phone_number.h"

using namespace std;

int main() {
	PhoneNumber pn("+7-1233");
	cout << pn.GetCityCode() << endl;
	cout << pn.GetCountryCode() << endl;
	cout << pn.GetInternationalNumber() << endl;
	cout << pn.GetLocalNumber() << endl;
	return 0;
}
