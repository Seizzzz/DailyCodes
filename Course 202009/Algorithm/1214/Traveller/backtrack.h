#pragma once
#include <iostream>
#include <vector>
using namespace std;

class Backtrack
{
public:
	int** distance;
	
	void dfs(int at, int dis);
	bool once = false;
	bool fin = false;
	
	int num;
	int st;
	int shortest = INT_MAX;
	bool* visited;
	vector<int> route;
	vector<int> solution;
	
	void output();

	Backtrack();
	Backtrack(int, int, int**);
};