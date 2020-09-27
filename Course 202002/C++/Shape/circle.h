#pragma once

#include "shape.h"
#include "point.h"
#include <cmath>

class Circle : public Shape
{
public:
	Circle(const Point& p, const double& r) : centre(p), radius(r) { cout << "Circle����" << endl; };
	~Circle() { cout << "Circle����" << endl; }
	bool judgeIntersect(const Circle& otr);
	virtual double getAreaSize() override;

private:
	Point centre;
	double radius;
};