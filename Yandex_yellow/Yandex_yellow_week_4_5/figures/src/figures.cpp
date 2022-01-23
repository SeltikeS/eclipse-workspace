//============================================================================
// Name        : figures.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <cmath>
using namespace std;

class Figure {
public:
	virtual string Name() = 0;
	virtual double Perimeter() = 0;
	virtual double Area() = 0;

	virtual ~Figure() {}
};







class Rect : public Figure {
public:
	Rect(int width, int height) : name_("RECT"s), width_(width), height_(height)  {}

	string Name() override { return name_; }
	double Perimeter() override{ return 2 * (width_ + height_); }
	double Area() override{ return width_ * height_; }

private:
	string name_;
	int width_;
	int height_;
};

class Triangle : public Figure {
public:
	Triangle(int a, int b, int c) : name_("TRIANGLE"s), a_(a), b_(b), c_(c)  {}
	string Name() override { return name_; }
	double Perimeter() override { return a_ + b_ + c_; }
	double Area() override {
		double p = Perimeter() / 2;
		return sqrt(p * (p - a_) * (p - b_) * (p - c_));
	}

private:
	string name_;
	int a_, b_, c_;
};

class Circle : public Figure {
public:
	Circle(int r) : name_("CIRCLE"s), r_(r) {}
	string Name() override { return name_; }
	double Perimeter() override { return 2 * 3.14 * r_; }
	double Area() override { return 3.14 * r_ * r_; }

private:
	string name_;
	int r_;
};


shared_ptr<Figure> CreateFigure(istream& is) {
	string figure;
	is >> figure;
	if(figure == "RECT"s) {
		int width, height;
		is >> width >> height;
		return make_shared<Rect>(width, height);
	}
	if(figure == "TRIANGLE") {
		int a, b, c;
		is >> a >> b >> c;
		return make_shared<Triangle>(a, b, c);
	}
	if(figure == "CIRCLE") {
		int r;
		is >> r;
		return make_shared<Circle>(r);
	}

	return shared_ptr<Figure>();
}





















int main() {
  vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      // Пропускаем "лишние" ведущие пробелы.
      // Подробнее об std::ws можно узнать здесь:
      // https://en.cppreference.com/w/cpp/io/manip/ws
      is >> ws;
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }
  return 0;
}
