#pragma once

#include "rectangle.h"

class Square : public Rectangle
{
public:
	~Square() { cout << "Square����" << endl; };

	Square(const double& a);
	virtual double getAreaSize() override;

};