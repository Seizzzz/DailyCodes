#include "point.h"

Point::Point(const Point& otr)
{
	x = otr.x;
	y = otr.y;
}

Point& Point::operator++()
{
	++x; ++y;
	return *this;
}

Point Point::operator++(int)
{
	return Point(x++, y++);
}

Point& Point::operator--()
{
	--x; --y;
	return *this;
}

Point Point::operator--(int)
{
	return Point(x--, y--);
}

double Point::getDistance(const Point& otr)
{
	return sqrt(pow(x - otr.x, 2) + pow(y - otr.y, 2));
}

ostream& operator<<(ostream& out, const Point& obj)
{
	out << "µã×ø±êÎª£º(" << obj.x << "," << obj.y << ")";
	return out;
}
