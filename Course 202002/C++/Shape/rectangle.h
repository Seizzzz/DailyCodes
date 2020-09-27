#pragma once

#include "shape.h"

class Rectangle : public Shape
{
public:
	Rectangle() { cout << "RectangleĬ�Ϲ���" << endl; };
	Rectangle(const double& a, const double& b) : lenA(a), lenB(b) { cout << "Rectangle�вι���" << endl;  };
	~Rectangle() { cout << "Rectangle����" << endl; };
	virtual double getAreaSize() override;

	double lenA, lenB;

private:
	
};