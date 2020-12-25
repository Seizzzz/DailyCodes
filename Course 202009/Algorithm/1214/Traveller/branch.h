#pragma once
#include <iostream>
#include <vector>
#include "backtrack.h"
#include <queue>
#include <algorithm>
using namespace std;

struct state
{
	int len;
	vector<int> route;

	bool operator < (const state& otr) const { return otr.len < len; }
};

class Branch
{
public:
	void bfs();

	int num;
	int st;

	int** distance;

	int upperbound = INT_MAX;

	vector<int> solution;

	void output();

	Branch();
};