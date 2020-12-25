#include "branch.h"

void Branch::bfs()
{
	priority_queue<state> q;
	state start;
	start.len = 0;
	start.route.push_back(st);
	q.push(start);

	while(!q.empty())
	{
		state now = q.top();
		q.pop();
		
		if(now.route.size() == num)
		{
			int round = now.len + distance[now.route.back()][st];
			if(round <= upperbound)
			{
				upperbound = round;
				solution = now.route;
			}
			continue;
		}
		
		for (int i = 0; i < num; ++i)
		{
			if (now.route.front() == i) continue;
			if (find(now.route.begin(), now.route.end(), i) != now.route.end()) continue;
			int nextdis = distance[now.route.back()][i];
			if(nextdis != INT_MAX && now.len + nextdis <= upperbound)
			{
				state next;
				next.len = now.len + nextdis;
				next.route = now.route;
				next.route.push_back(i);
				q.push(next);
			}
		}
	}
	
}

void Branch::output()
{
	cout << "shortest distance: " << upperbound << endl;
	cout << "route: ";
	for (auto& i : solution) cout << i + 1 << " ";
	cout << st + 1;
	cout << endl;
}

Branch::Branch()
{
	cin >> num;
	int _st; cin >> _st;
	st = _st - 1;

	distance = new int* [num];
	for (int i = 0; i < num; ++i) distance[i] = new int[num];

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

	Backtrack tmp(num, st, distance);
	upperbound = tmp.shortest;
	bfs();

	output();
}
