#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
public:
    explicit Person(const string& name, const string& type) : Name(name), Type(type) {}
    string GetName() const{
        return Name;
    }

    string GetType() const{
        return Type;
    }

    string GetTypeName() const{
        return Type+": "+Name;
    }

    virtual void Walk(const string& destination) const {
        cout << GetTypeName() << " walks to: " << destination << endl;
    }

private:
    const string Name;
    const string Type;
};


class Student : public Person {
public:

    Student(const string& name, const string& favouriteSong) : Person(name, "Student"), FavouriteSong(favouriteSong) {}

    void Learn() const {
        cout << GetTypeName() << " learns" << endl;
    }

    void Walk(const string& destination) const override  {
        Person::Walk(destination);
        cout << GetTypeName() << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() const{
        cout << GetTypeName() << " sings a song: " << FavouriteSong << endl;
    }

private:
    const string FavouriteSong;
};


class Teacher : public Person{
public:

    Teacher(string name, string subject) : Person(name, "Teacher"), Subject(subject) {}

    void Teach() {
        cout << GetTypeName() << " teaches: " << Subject << endl;
    }

private:
    string Subject;
};


class Policeman : public Person {
public:
    Policeman(string name) : Person(name, "Policeman") {}

    void Check(const Person& t) const {
        cout << GetTypeName() << " checks " << t.GetType() << ". " << t.GetType() << "'s name is: " << t.GetName() << endl;
    }

};


void VisitPlaces(Person& person, vector<string> places) {
    for (auto p : places) {
        person.Walk(p);
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
