#include "Backtrack.h"

void Backtrack::dfs(int at, int dis)
{
	if (dis > shortest) return;
	if(route.size() == num) //旅行即将完毕
	{
		if (distance[at][st] != INT_MAX) //可返回至起始
		{
			shortest = dis + distance[at][st];
			solution = route;
			fin = true;
		}
		return;
	}
	
	for (int i = 0; i < num; ++i)
	{
		if (once && fin) return;
		if (i == at) continue;
		
		if(distance[at][i] != INT_MAX && !visited[i])
		{
			route.push_back(i);
			visited[i] = true;
			dfs(i, dis + distance[at][i]);
			route.pop_back();
			visited[i] = false;
		}
	}
}

void Backtrack::output()
{
	cout << "shortest distance: " << shortest << endl;
	cout << "route: ";
	for (auto& i : solution) cout << i + 1 << " ";
	cout << st + 1;
	cout << endl;
}

Backtrack::Backtrack()
{
	cin >> num;
	int _st; cin >> _st;
	st = _st - 1;
	
	distance = new int* [num];
	for (int i = 0; i < num; ++i) distance[i] = new int[num];
	visited = new bool[num]();

	for (int i = 0; i < num; ++i)
	{
		for (int j = 0; j < num; ++j)
		{
			int tmp;
			cin >> tmp;
			if (tmp != -1) distance[i][j] = tmp;
			else distance[i][j] = INT_MAX;
		}
	}

	visited[st] = true;
	route.push_back(st);
	dfs(st, 0);

	output();
}

Backtrack::Backtrack(int _num, int _st, int** _distance) : num(_num), distance(_distance), st(_st)
{
	visited = new bool[num]();
	once = true;

	visited[st] = true;
	route.push_back(st);
	dfs(st, 0);
}
