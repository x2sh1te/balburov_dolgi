#pragma once
#include <vector>
#include <string>
#include <iostream>
using namespace std;
struct Point {
	double x, y;
};
class Shape {
public:
	virtual double calc_area()=0;
	virtual double calc_perimeter()=0;
	virtual void name() = 0;
	virtual ~Shape() {}
};

class Circle : public Shape {
	Point center;
	double radius;
public:
	Circle(Point c, double r) : center(c), radius(r) {}
	double calc_area();
	double calc_perimeter();
	void name();
};

class Ellips : public Shape {
	Point center;
	double radius1,radius2;
public:
	Ellips(Point c, double r1,double r2) : center(c), radius1(r1),radius2(r2) {}
	double calc_area();
	double calc_perimeter();
	void name();
};

class Triangle : public Shape {
	vector<Point> vertices;
public:
	Triangle(Point a, Point b, Point c) : vertices({ a, b, c }) {}

	double calc_area();
	double calc_perimeter();
	void name();
};

class Rectangle : public Shape {
	vector<Point> vertices;
public:
	Rectangle(Point a, Point b, Point c, Point d) : vertices({ a, b, c, d }) {}

	double calc_area();
	double calc_perimeter();
	void name();
};

class Polygon : public Shape {
	vector<Point> vertices;
public:
	Polygon(std::string filename);

	double calc_area();
	double calc_perimeter();
	void name();
};



