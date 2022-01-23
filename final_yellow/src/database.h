/*
 * database.h
 *
 *  Created on: 6 џэт. 2022 у.
 *      Author: SeltikeS
 */

#pragma once

#include "date.h"

#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include <utility>
#include <algorithm>
#include <sstream>

using namespace std;

class Database {
public:
//	void AddEvent(const Date& date, const string& event);
//	bool DeleteEvent(const Date& date, const string& event);
//	int  DeleteDate(const Date& date);
//	set<string> Find(const Date& date) const;
//	void Print() const;




	void Add(const Date& date, const string& event);
	void Print(ostream& out) const;

	string Last(const Date& date) const;

	template<typename Functor>
	vector<pair<Date, string>> FindIf(Functor functor) const
	{
		vector<pair<Date, string>> result;
		for(const auto& item_date : data) {
			for(const auto& item_event : item_date.second.second) {
				if(functor(item_date.first, *item_event)) {
					result.push_back(make_pair(item_date.first, *item_event));
				}
			}
		}
		return result;
	}

	template<typename Functor>
	int RemoveIf(Functor functor)
	{
		int result = 0;

		for(auto it = begin(data); it != end(data); ) {
			int count = it->second.first.size();
			auto itFrom = stable_partition(begin(it->second.second), end(it->second.second),
					[&](const set<string>::iterator& eventRef){
					bool res = functor(it->first, *eventRef);
					if(res) {
						it->second.first.erase(eventRef);
					}
					return !res;
			});

			count -= it->second.first.size();
			if(count) {
				result += count;
				it->second.second.erase(itFrom, end(it->second.second));

				if(!it->second.second.size()) {
					it = data.erase(it);
					continue;
				}
			}
			++it;
		}

		return result;
	}

private:
  	map<Date, pair<set<string>, vector<set<string>::iterator>>> data;

};

ostream& operator<<(ostream& stream, const pair<Date, string>& p);
