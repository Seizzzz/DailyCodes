#pragma once

#include <cmath>
#include <iostream>
using namespace std;

class Point
{
public:
	Point() : x(0), y(0) {};
	Point(double in_x, double in_y) : x(in_x), y(in_y) {};
	Point(const Point& otr);

	Point& operator++(); //«∞÷√
	Point operator++(int); //∫Û÷√
	Point& operator--();
	Point operator--(int);
	friend ostream& operator<<(ostream & out, const Point& obj);

	double x, y;
	double getDistance(const Point& otr);
};