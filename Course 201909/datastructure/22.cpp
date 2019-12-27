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
	string s;
	stringstream ss;
	
	while(cin >> s)
	{
		ss << s;
		ss >> info[vexnum].vexdata;
		info[vexnum].firstarc = new arcnode;
		arcnode* buf = info[vexnum].firstarc;
		while(ss >> arc)
		{
			buf->adjvex = arc;
			buf->nextarc = new arcnode;
			buf = buf.nextarc;
		}
		delete buf;
		buf = NULL;
		++vexnum;
	}

	return 0;
}

