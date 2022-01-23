/*
 * date.h
 *
 *  Created on: 6 џэт. 2022 у.
 *      Author: SeltikeS
 */

#pragma once

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <utility>
#include <map>
#include <sstream>
#include <iomanip>

using namespace std;

class Date {
public:


	Date(const int& year, const int& month, const int& day);
	Date() : m_year(0), m_month(0), m_day(0), summary(0) {}

	int GetYear() const { return m_year; }
	int GetMonth() const { return m_month; }
	int GetDay() const { return m_day; }



private:
	int m_year;
	int m_month;
	int m_day;

public:
	int summary;
};

bool operator<(const Date& lhs, const Date& rhs);
bool operator==(const Date& lhs, const Date& rhs);
bool operator<=(const Date& lhs, const Date& rhs);
bool operator>(const Date& lhs, const Date& rhs);
bool operator>=(const Date& lhs, const Date& rhs);
bool operator!=(const Date& lhs, const Date& rhs);

Date ParseDate(istream& is);




istream& operator>>(istream& stream, Date& date);
ostream& operator<<(ostream& stream, const Date& date);







