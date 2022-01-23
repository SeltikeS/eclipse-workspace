//============================================================================
// Name        : inheritance.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Animal {
public:

	Animal(string n_name) : Name(n_name) {}

    const string Name;
};


class Dog : public Animal{
public:

	Dog(string n_name) : Animal(n_name) {}

    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

int main() {
	Dog d("WOOOOF");
	d.Bark();
}
