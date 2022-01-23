//============================================================================
// Name        : refact.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================



#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Pedestrian {
public:
    Pedestrian(const string& new_occupation, const string& new_name)
        : occupation( new_occupation ), name( new_name ) {}

    virtual ~Pedestrian() = default;

    const string& Occupation() const { return occupation; }
    const string& Name() const { return name; }

    virtual void Walk(const string& destination) const {
        Ze() << " walks to: " << destination << endl;
    }

protected:
    // He/She/They
    ostream& Ze(ostream& output = cout) const {
        return output << Occupation() << ": " << Name();
    }

private:
    const string occupation, name;
};


class Student : public Pedestrian {
public:
    Student(const string& new_name, const string& new_favourite_song)
        : Pedestrian( "Student", new_name ), favourite_song( new_favourite_song ) {}

    void Learn() const {
        Ze() << " learns" << endl;
    }

    void SingSong() const {
        Ze() << " sings a song: " << favourite_song << endl;
    }

    virtual void Walk(const string& destination) const override {
        Pedestrian::Walk(destination);
        SingSong();
    }

private:
    const string favourite_song;
};


class Teacher : public Pedestrian {
public:
    Teacher(const string& new_name, const string& new_subject)
        : Pedestrian( "Teacher", new_name ), subject( new_subject ) {}

    void Teach() const {
        Ze() << " teaches: " << subject << endl;
    }

private:
    const string subject;
};


class Policeman : public Pedestrian {
public:
    Policeman(const string& new_name)
        : Pedestrian( "Policeman", new_name ) {}

    void Check(const Pedestrian& pd) const {
        Ze() << " checks " << pd.Occupation() << ". " << pd.Occupation() << "'s name is " << pd.Name() << endl;
    }
};


void VisitPlaces(const Pedestrian& pd, const vector<string>& places) {
    for (const auto& pl : places) {
        pd.Walk(pl);
    }
}


int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, { "Moscow", "London" });
    p.Check(s);
    VisitPlaces(s, { "Moscow", "London" });
    return 0;
}

