#include <bits/stdc++.h>
using namespace std;

#define maxvtxnum 8
typedef int edgetype;
typedef int vextype;
typedef struct arcnode {
	int adjvex;
	edgetype info;
	struct arcnode * nextarc;
} arcnode;
typedef struct {
	vextype vexdata;
	struct arcnode * firstarc;
} vexnode;
typedef vexnode adjlist[maxvtxnum];

int main()
{
	std::ios::sync_with_stdio(false);
	
	adjlist info;
	
	int vexnum = 0;
	while(cin >> info[vexnum].vexdata)
	{
		int arc;
		while(cin ) 
		++vexnum;
	}

	return 0;
}

