//============================================================================
// Name        : FisrtAndLastNames2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // Add fact of change First Name in Year
        m_first_names[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        // Add fact of change Last Name in Year
        m_last_names[year] = last_name;
    }

    string GetFullName(int year) {
        // Take First and Last Names in Year
        string this_year_first_name = getThisYearName(m_first_names, year);
        string this_year_last_name = getThisYearName(m_last_names, year);

        if(this_year_first_name.length() > 0) {

            if(this_year_last_name.length() > 0) {
                return  this_year_first_name + ' ' + this_year_last_name;
            } else {
                return this_year_first_name + " with unknown last name";
            }
        } else {
            if(this_year_last_name.length() > 0) {
                return  this_year_last_name + " with unknown first name";
            } else {
                return "Incognito";
            }
        }
    }

    string GetFullNameWithHistory(int year) {
        // получить все имена и фамилии по состоянию на конец года year
    	string this_year_first_name = getThisYearName(m_first_names, year);
    	string this_year_last_name = getThisYearName(m_last_names, year);

    	string first_name_history = getNameHistory(m_first_names, year);
    	string last_name_history = getNameHistory(m_last_names, year);

    	string full_name_with_history;


    	if(this_year_first_name.length() > 0) {
    		full_name_with_history += this_year_first_name;
    		if(first_name_history.length() > 0) {
    		    full_name_with_history += " (" + first_name_history + ")";
    		}

    		if(this_year_last_name.length() > 0) {
    			full_name_with_history += " " + this_year_last_name;
    			if(last_name_history.length() > 0) {
    			    full_name_with_history += " (" + last_name_history +")";
    			}
    	    } else {
    	    	full_name_with_history += " with unknown last name";
    	    }
    	} else {
    	    if(this_year_last_name.length() > 0) {
    	    	full_name_with_history += this_year_last_name;
    	    	if(last_name_history.length() > 0) {
    	    	    full_name_with_history += " (" + last_name_history +")";
    	    	}
    	    	full_name_with_history += " with unknown first name";
    	    } else {
    	    	full_name_with_history = "Incognito";
    	    }
    	}

    	return full_name_with_history;
    }

private:
    map<int, string> m_first_names;
    map<int, string> m_last_names;

    string getThisYearName(const map<int, string>& name, const int& year) {
    	string this_year_name;
    	for(const auto& item : name) {
    		if(item.first > year) break;
    	    this_year_name = item.second;
    	}

    	return this_year_name;
    }

    string getNameHistory(const map<int, string>& names, const int& year) {
    	string names_history;
    	vector<string> names_data;
    	string name;
    	for(const auto& item : names) {
    		if(item.first > year) break;
    		names_data.push_back(item.second);
    		name = item.second;
    	}

    	for(int i = names_data.size()-1; i >= 0; --i){
    		if(name != names_data[i]){
    			if(names_history.length() > 0){
					names_history = names_history + ", " + names_data[i];
				} else {
					names_history = names_data[i];
				}
    			name = names_data[i];
    		}

    	}

    	return names_history;
    }
};




int main()
{
    Person person;

    person.ChangeFirstName(1965, "Polina");
      person.ChangeLastName(1967, "Sergeeva");
      for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

      person.ChangeFirstName(1970, "Appolinaria");
      for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

      person.ChangeLastName(1968, "Volkova");
      for (int year : {1969, 1970}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

      person.ChangeFirstName(1990, "Polina");
      person.ChangeLastName(1990, "Volkova-Sergeeva");
      cout << person.GetFullNameWithHistory(1990) << endl;

      person.ChangeFirstName(1966, "Pauline");
      cout << person.GetFullNameWithHistory(1966) << endl;

      person.ChangeLastName(1960, "Sergeeva");
      for (int year : {1960, 1967}) {
        cout << person.GetFullNameWithHistory(year) << endl;
      }

      person.ChangeLastName(1961, "Ivanova");
      cout << person.GetFullNameWithHistory(1967) << endl;

    return 0;
}
