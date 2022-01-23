//============================================================================
// Name        : Refactoring.cpp
// Author      : SeltikeS
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;



class Man {
public:
	virtual void Walk(const string& destination) const {
		cout << GetInfo() << " walks to: "s << destination << endl;
	}

	virtual ~Man() {}

	string GetProfession() const { return profession_; }
	string GetName() const { return name_; }

protected:
	Man(const string& name, const string& profession) :
		name_(name), profession_(profession) {}


	string GetInfo() const { return name_ + ": "s + profession_; }

private:
	const string name_;
	const string profession_;
};








class Student : public Man{
public:
	Student(const string& name, const string& favourite_song) :
		Man(name, "Student"s), favourite_song_(favourite_song) {}

    void SingSong() const {
        cout << GetInfo() << " sings a song: "s << favourite_song_ << endl;
    }

	void Walk(const string& destination) const override {
		Man::Walk(destination);
		SingSong();
	}

    void Learn() const {
        cout << GetInfo() << " learns"s << endl;
    }

private:
	const string favourite_song_;
};


class Teacher : public Man{
public:
	Teacher(const string& name, const string& subject) :
		Man(name, "Teacher"s), subject_(subject) {}

    void Teach() const {
        cout << GetInfo() << " teaches: "s << subject_ << endl;
    }

private:
	const string subject_;
};


class Policeman : public Man {
public:
	Policeman(const string& name) : Man(name, "Policeman"s) {}

	void Check(const Man& m) const {
		cout << GetInfo() << " checks "s << m.GetProfession() << ". "s << m.GetProfession() << "'s name is: "s << m.GetName() << endl;
	}

};

void VisitPlaces(Man& m, const vector<string>& places) {
	for(auto p : places) {
		m.Walk(p);
	}
}




int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
