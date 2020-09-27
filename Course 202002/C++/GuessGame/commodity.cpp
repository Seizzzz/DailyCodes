#include "commodity.h"

Commodity::Commodity()
{
	price = 1 + rand() % 1000;
}

retState Commodity::guessPrice(int guess)
{
	if (guess > price) return higher;
	else if (guess < price) return lower;
	else return hit;
}
