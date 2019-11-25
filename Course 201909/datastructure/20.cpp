#include <bits/stdc++.h>
using namespace std;

#define maxvtxnum 8
typedef int adjmatrix[maxvtxnum][maxvtxnum];
typedef struct
{
	adjmatrix arcs;
	int vtxnum,arcnum;
}graph;

graph g;

bool visited[maxvtxnum];

bool find_k_path(graph g, int k, int a, int b)
{
	visited[a] = true;
	
	if(k == 0)
	{
		if(a == b) return true;
		return false;
	}
	
	for(int v = 0; v < g.vtxnum; ++v)
	{
		if(g.arcs[a][v] && !visited[v])
		{
			visited[v] = true;
			if(find_k_path(g,k-1,v,b)) return true;
			visited[v] = false;
		}
	}
	return false;
} 

int main()
{
	std::ios::sync_with_stdio(false);
	
	g.arcs[0][1] = g.arcs[1][0] = 1;
	g.arcs[0][2] = g.arcs[2][0] = 1;
	g.arcs[2][3] = g.arcs[3][2] = 1;
	g.arcs[3][6] = g.arcs[6][3] = 1;
	g.arcs[2][6] = g.arcs[6][2] = 1;
	g.arcs[1][5] = g.arcs[5][1] = 1;
	g.arcs[1][7] = g.arcs[7][1] = 1;
	g.arcs[5][4] = g.arcs[4][5] = 1;
	g.arcs[4][7] = g.arcs[7][4] = 1;
	g.vtxnum = 8;
	g.arcnum = 16;
	
	cout << find_k_path(g,3,1,5);

	return 0;
}

