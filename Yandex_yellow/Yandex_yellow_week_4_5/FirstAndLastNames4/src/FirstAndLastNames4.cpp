//============================================================================
// Name        : FirstAndLastNames4.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;








class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
	// добавить факт изменения имени на first_name в год year
		if(m_first_names.count(year) == 0) {
			m_first_names[year] = first_name;
		}

	}
	void ChangeLastName(int year, const string& last_name) {
	// добавить факт изменения фамилии на last_name в год year
        if(m_last_names.count(year) == 0) {
            m_last_names[year] = last_name;
        }
	}
	string GetFullName(int year) {
	// получить имя и фамилию по состоянию на конец года year
	// с помощью двоичного поиска
		auto firstNameIt = m_first_names.upper_bound(year);
		auto lastNameIt = m_last_names.upper_bound(year);


		if(firstNameIt == begin(m_first_names)) {
			if(lastNameIt == begin(m_last_names)) {
				return "Incognito";
			}
			return prev(lastNameIt)->second + " with unknown first name";
		} else {
			if(lastNameIt == begin(m_last_names)) {
				return prev(firstNameIt)->second + " with unknown last name";
			}
			return prev(firstNameIt)->second + ' ' + prev(lastNameIt)->second;
		}

	}
private:
	// приватные поля
    map<int, string> m_first_names;
    map<int, string> m_last_names;
};








int main() {
  Person person;

  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }

  return 0;
}
