#include "square.h"

Square::Square(const double& a)
{
	Rectangle::lenA = Rectangle::lenB = a;
	cout << "Square¹¹Ôì" << endl;
}

double Square::getAreaSize()
{
	return Rectangle::getAreaSize();
}
