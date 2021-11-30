//============================================================================
// Name        : LectureTitle.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

struct Specialization {
	string m_value;
	explicit Specialization(const string& value) : m_value(value) {}
};

struct Course {
	string m_value;
	explicit Course(const string& value) : m_value(value) {}
};

struct Week {
	string m_value;
	explicit Week(const string& value) : m_value(value) {}
};

struct LectureTitle {
	string specialization;
	string course;
	string week;

	LectureTitle(const Specialization& specification, const Course& course, const Week& week) :
		specialization(specification.m_value), course(course.m_value), week(week.m_value) {}
};



int main() {

	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);

	return 0;
}
