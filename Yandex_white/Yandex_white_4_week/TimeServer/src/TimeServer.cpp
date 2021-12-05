//============================================================================
// Name        : TimeServer.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

string AskTimeServer() {
	throw runtime_error("1111");
}

class TimeServer {
public:
  string GetCurrentTime() {
	  try {
		  last_fetched_time = AskTimeServer();
		  return last_fetched_time;
	  } catch (system_error& e) {
		  return last_fetched_time;
	  }

  }
private:
  string last_fetched_time = "00:00:00";
};

int main() {
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
	return 0;
}
