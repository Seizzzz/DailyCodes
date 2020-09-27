#include "circle.h"

bool Circle::judgeIntersect(const Circle& otr)
{
	double dis = centre.getDistance(otr.centre);

	if (dis < radius + otr.radius) return true;
	return false;
}

double Circle::getAreaSize()
{
	return radius * radius * acos(-1);
}
