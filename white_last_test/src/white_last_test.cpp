// –еализуйте функции и методы классов и при необходимости добавьте свои

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

class Date {
public:
	Date(const int& year, const int& month, const int& day) : m_year(year), m_month(month), m_day(day) {
		if(m_month < 1 || m_month > 12) {
			throw invalid_argument("Month value is invalid: " + to_string(m_month));
		} else if(m_day < 1 || m_day > 31) {
			throw invalid_argument("Day value is invalid: " + to_string(m_day));
		}
	}
	Date() : m_year(0), m_month(0), m_day(0) {

	}
	int GetYear() const {
		return m_year;
	}
	int GetMonth() const {
		return m_month;
	}
	int GetDay() const {
		return m_day;
	}

private:
	int m_year;
	int m_month;
	int m_day;
};

bool operator<(const Date& lhs, const Date& rhs) {
	bool is_less_then;
	if(lhs.GetYear() < rhs.GetYear())
	{
		is_less_then = true;
	}
	else if(lhs.GetYear() > rhs.GetYear())
	{
		is_less_then = false;
	}
	else if(lhs.GetMonth() < rhs.GetMonth())
	{
		is_less_then = true;
	}
	else if(lhs.GetMonth() > rhs.GetMonth())
	{
		is_less_then = false;
	}
	else if(lhs.GetDay() < rhs.GetDay())
	{
		is_less_then = true;
	}
	else
	{
		is_less_then = false;
	}

	return is_less_then;
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

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		data[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if(data.count(date) > 0) {
			return (data.at(date).erase(event) > 0);
		} else {
			return false;
		}
	}
	int  DeleteDate(const Date& date) {
		int n = 0;
		if(data.count(date) > 0) {
			n = data[date].size();
			data[date].clear();
		}
		return n;
	}

	set<string> Find(const Date& date) const {
		if(data.count(date) > 0) {
			return data.at(date);
		}
		return {};
	}

  	void Print() const {
  		for(const auto& item_date : data) {
  			for(const auto& item_event : item_date.second) {
  					cout << setw(4) << setfill('0') << item_date.first.GetYear() << '-' <<
							setw(2) << item_date.first.GetMonth() << '-' <<
							setw(2) << item_date.first.GetDay() << ' ' << item_event << endl;
  				}
  		}
  	}

private:
  	map<Date, set<string>> data;
};

int main() {
	Database db;

	string command;
//	stringstream ggwp("Add 0-12-04 event1");
	while (getline(cin, command)) {
	// —читайте команды с потока ввода и обработайте каждую
		try {
			stringstream stream(command);
			string com, event;
			Date date;

			stream >> com;

			if(com == "Add") {
				stream >> date >> event;
				db.AddEvent(date, event);
			} else if(com == "Del") {
				stream >> date;
				if(stream >> event) {
					if(db.DeleteEvent(date, event)) {
						cout << "Deleted successfully" << endl;
					} else {
						cout << "Event not found" << endl;
					}
				} else {
					cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
				}
			} else if(com == "Find") {
				stream >> date;
				for(const auto& item : db.Find(date)) {
					cout << item << endl;
				}
			} else if(com == "Print") {
				db.Print();
			} else if(com.size() == 0){

			} else {
				throw invalid_argument("Unknown command: " + com);
			}
		} catch(exception& e) {
			cout << e.what() << endl;
		}
	}

	return 0;
}
