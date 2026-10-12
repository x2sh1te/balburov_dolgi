#include"shape.h"
#include <cmath>
#include <fstream>
using namespace std;
const double PI = 3.14159;

double Circle::calc_area() {
	return PI * (radius * radius);
}
double Circle::calc_perimeter() {
	return 2 * PI * radius;
}
void Circle::name() {
	cout << "Circle";
}

double Ellips::calc_area() {
	return PI * radius1 * radius2;
}
double Ellips::calc_perimeter() {
	return PI * (3 * (radius1 + radius2) - std::sqrt((3 * radius1 + radius2) * (radius1 + 3 * radius2)));
}
void Ellips::name() {
	cout << "Ellips";
}

double calculate_area_points(const vector<Point>& v) {
    double area = 0.0;
    int n = v.size();
    if (n < 3) return 0.0;
    for (int i = 0; i < n; i++) {
        area += (v[i].x * v[(i + 1) % n].y) - (v[(i + 1) % n].x * v[i].y);
    }
    return abs(area) / 2.0;
}
double Triangle::calc_area() {
    return calculate_area_points(vertices);

}
double Triangle::calc_perimeter() {
    double p = 0;
    for (int i = 0; i < 3; i++) {
        p += sqrt(pow(vertices[i].x - vertices[(i + 1) % 3].x, 2) +
            pow(vertices[i].y - vertices[(i + 1) % 3].y, 2));
    }
    return p;
}
void Triangle::name() {
    cout << "Triangle";
}

double Rectangle::calc_area() {
    return calculate_area_points(vertices);
}
double Rectangle::calc_perimeter() {
    double p = 0;
    for (int i = 0; i < 4; i++) {
        p += sqrt(pow(vertices[i].x - vertices[(i + 1) % 4].x, 2) +
            pow(vertices[i].y - vertices[(i + 1) % 4].y, 2));
    }
    return p;
}
void Rectangle::name() {
    cout << "Rectangle";
}

Polygon::Polygon(string filename) {
    ifstream file(filename);
    int count;
    if (file >> count) {
        double x, y;
        while (file >> x >> y) {
            vertices.push_back({ x, y });
        }
    }
}
double Polygon::calc_area() {
    return calculate_area_points(vertices);
}
double Polygon::calc_perimeter() {
    double p = 0;
    for (size_t i = 0; i < vertices.size(); i++) {
        p += sqrt(pow(vertices[i].x - vertices[(i + 1) % vertices.size()].x, 2) +
            pow(vertices[i].y - vertices[(i + 1) % vertices.size()].y, 2));
    }
    return p;
}
void Polygon::name() {
    cout << "Polygon";
}

