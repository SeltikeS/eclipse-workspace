/*
 * date.cpp
 *
 *  Created on: 6 џэт. 2022 у.
 *      Author: SeltikeS
 */

#include "date.h"

Date::Date(const int& year, const int& month, const int& day) : m_year(year), m_month(month), m_day(day), summary(year * 372 + (month * 31 - 31) + day) {
	if(m_month < 1 || m_month > 12) {
		throw invalid_argument("Month value is invalid: " + to_string(m_month));
	} else if(m_day < 1 || m_day > 31) {
		throw invalid_argument("Day value is invalid: " + to_string(m_day));
	}
}


bool operator<(const Date& lhs, const Date& rhs) {
	return lhs.summary < rhs.summary;
}

bool operator==(const Date& lhs, const Date& rhs) {
	return lhs.summary == rhs.summary;
}

bool operator>(const Date& lhs, const Date& rhs) {
	return lhs.summary > rhs.summary;
}

bool operator<=(const Date& lhs, const Date& rhs) {
	return lhs.summary <= rhs.summary;
}

bool operator>=(const Date& lhs, const Date& rhs) {
	return lhs.summary >= rhs.summary;
}

bool operator!=(const Date& lhs, const Date& rhs) {
	return lhs.summary != rhs.summary;
}



istream& operator>>(istream& stream, Date& date) {
	int year;
	int month;
	int day;

	string s;
	stream >> s;
	istringstream ss(s);

	ss >> year;
	if(ss.peek() != '-') {
		throw invalid_argument("Wrong date format: " + s);
	}
	ss.ignore();

	ss >> month;
	if(ss.peek() != '-') {
		throw invalid_argument("Wrong date format: " + s);
	}
	ss.ignore();

	ss >> day;
	if(ss.fail()) {
		throw invalid_argument("Wrong date format: " + s);
	}
	if(!ss.eof()){
		throw invalid_argument("Wrong date format: " + s);
	}

	Date d(year, month, day);
	date = d;

	return stream;
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-' <<
			setw(2) << date.GetMonth() << '-' <<
			setw(2) << date.GetDay();

	return stream;
}


Date ParseDate(istream& is) {
	Date d;
	is >> d;

	return d;
}
