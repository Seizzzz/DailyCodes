#pragma once

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() { cout << "Rectangle默认构造" << endl; };
	Rectangle(const double& a, const double& b) : lenA(a), lenB(b) { cout << "Rectangle有参构造" << endl;  };
	~Rectangle() { cout << "Rectangle析构" << endl; };
	virtual double getAreaSize() override;

	double lenA, lenB;

private:
	
};