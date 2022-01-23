/*
 * database.cpp
 *
 *  Created on: 6 џэт. 2022 у.
 *      Author: SeltikeS
 */
#include "database.h"
//
//void Database::AddEvent(const Date& date, const string& event) {
//	data[date].insert(event);
//}
//bool Database::DeleteEvent(const Date& date, const string& event) {
//	if(data.count(date) > 0) {
//		return (data.at(date).erase(event) > 0);
//	} else {
//		return false;
//	}
//}
//int  Database::DeleteDate(const Date& date) {
//	int n = 0;
//	if(data.count(date) > 0) {
//		n = data[date].size();
//		data[date].clear();
//	}
//	return n;
//}
//
//set<string> Database::Find(const Date& date) const {
//	if(data.count(date) > 0) {
//		return data.at(date);
//	}
//	return {};
//}
//
//void Database::Print() const {
//	for(const auto& item_date : data) {
//		for(const auto& item_event : item_date.second) {
//				cout << setw(4) << setfill('0') << item_date.first.GetYear() << '-' <<
//						setw(2) << item_date.first.GetMonth() << '-' <<
//						setw(2) << item_date.first.GetDay() << ' ' << item_event << endl;
//			}
//	}
//}









ostream& operator<<(ostream& stream, const pair<Date, string>& p) {
	stream << p.first << ' ' << p.second;

	return stream;
}


void Database::Add(const Date& date, const string& event) {
	auto p = data[date].first.insert(event);
	if(p.second) {
		data[date].second.push_back(p.first);
	}
}
void Database::Print(ostream& out) const {
	for(const auto& item_date : data) {
		for(const auto& item_event : item_date.second.second) {
			out << item_date.first << ' ' << *item_event << endl;
		}
	}
}




string Database::Last(const Date& date) const {
	if(data.empty() || date < data.begin()->first) {
		throw invalid_argument("No entries");
	}
	else
	{
		string lastNode;
		ostringstream out;

		auto it = prev(data.upper_bound(date));
		out << it->first;
		lastNode += out.str() + " " + **(it->second.second.rbegin());
		return lastNode;
	}
}




