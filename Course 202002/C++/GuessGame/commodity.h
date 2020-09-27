#pragma once
#include <cstdlib>

enum retState { higher = 0, lower = 1, hit = 2 };

class Commodity
{
public:
	Commodity();
	retState guessPrice(int guess);

private:
	int price;
};