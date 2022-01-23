//============================================================================
// Name        : build_expression.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <deque>
using namespace std;




void BuildExpression(deque<string>& d) {
	char sign;
	int num;
	cin >> sign >> num;
	if(sign == '+') {
		d.push_front("(");
		d.push_back(")");
		d.push_back(" + ");
		d.push_back(to_string(num));
	} else if(sign == '-') {
		d.push_front("(");
		d.push_back(")");
		d.push_back(" - ");
		d.push_back(to_string(num));
	} else if(sign == '*') {
		d.push_front("(");
		d.push_back(")");
		d.push_back(" * ");
		d.push_back(to_string(num));
	} else if(sign == '/') {
		d.push_front("(");
		d.push_back(")");
		d.push_back(" / ");
		d.push_back(to_string(num));
	}

}






int main() {
	int num, queries;
	cin >> num >> queries;

	deque<string> expression;
	expression.push_back(to_string(num));

	for(int i = 0; i < queries; ++i) {
		BuildExpression(expression);
	}

	for(const auto& item : expression) {
		cout << item;
	}




	return 0;
}
