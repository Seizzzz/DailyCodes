#include <bits/stdc++.h>
using namespace std;

#define maxvtxnum 8
typedef int adjmatrix[maxvtxnum][maxvtxnum];
typedef struct
{
	adjmatrix arcs;
	int vtxnum,arcnum;
}graph;
bool visited[maxvtxnum];

graph g;

void output(int* path, int step, int st)
{
	bool flag = false;
	for(int i = 0; i <= step; ++i)
	{
		if(path[i] == st) flag = true;
		if(flag) cout << path[i] << " ";
	}
	cout << endl;
}

void dfs(graph g, int now, int* path, int step)
{
	path[step] = now;
	visited[now] = true;
	
	for(int i = 0;i < g.vtxnum; ++i)
	{
		if(g.arcs[now][i])
		{
			if(visited[i]) output(path,step,i);
			else
			{
				visited[i] = true;
				path[step+1] = i;
				dfs(g,i,path,step+1);
				visited[i] = false;
			}
		}
	}
} 

int main()
{
	std::ios::sync_with_stdio(false);
	
	int path[maxvtxnum+1];
	g.arcs[0][5] = g.arcs[5][4] = g.arcs[4][1] = g.arcs[1][0] = 1;
	g.arcs[1][2] = g.arcs[2][3] = g.arcs[3][4] = 1;
	g.vtxnum = 6;
	dfs(g,0,path,0);

	return 0;
}

