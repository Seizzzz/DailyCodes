#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define maxvtxnum 10
#define INF 999
typedef int adjmatrix[maxvtxnum][maxvtxnum];
typedef struct
{
	adjmatrix arcs;
	int vtxnum, arcnum;
}graph;

typedef struct
{
	bool visited;
	int distance;
	int from;
}buf_Prim;

typedef struct
{
	int a;
	int b;
	int distance;
}buf_arc_Kruskal;

graph g;

void Prim_init_buf(graph& g, buf_Prim* buf)
{
	g.arcnum = 0;
	for (int i = 0; i < g.vtxnum; ++i)
	{
		buf[i].visited = false;
		buf[i].distance = INF;
		buf[i].from = 0;
		for (int j = 0; j < g.vtxnum; ++j) g.arcs[i][j] = INF;
	}
	return;
}

void Prim_update(graph g, buf_Prim* buf, int which)
{
	for (int i = 0; i < g.vtxnum; ++i)
	{
		if (!buf[i].visited && g.arcs[which][i] < buf[i].distance)
		{
			buf[i].distance = g.arcs[which][i];
			buf[i].from = which;
		}
	}
	return;
}

void Prim_create_path(graph& g, buf_Prim* buf, int which)
{
	++g.arcnum;
	g.arcs[which][buf[which].from] = g.arcs[buf[which].from][which] = buf[which].distance;
	return;
}

int Prim_pick_shortest(graph g, buf_Prim* buf)
{
	int which = 0,nowmax = INF;
	for (int i = 0; i < g.vtxnum; ++i)
	{
		if (!buf[i].visited && buf[i].distance < nowmax)
		{
			which = i;
			nowmax = buf[i].distance;
		}
	}
	return which;
}

graph algorithm_Prim(graph g)
{
	graph span = g;
	buf_Prim* vtx = new buf_Prim[g.vtxnum];
	Prim_init_buf(span, vtx);

	int cnt = 0;
	vtx[0].visited = true;
	int i = 0;
	while (cnt != g.vtxnum)
	{
		Prim_update(g, vtx, i);
		i = Prim_pick_shortest(g, vtx);
		Prim_create_path(span, vtx, i);
		vtx[i].visited = true;
		++cnt;
	}
	
	delete [] vtx;
	return span;
}

int Kruskal_ancestor(int which, int* ancest)
{
	if (ancest[which] == which) return which;
	return Kruskal_ancestor(ancest[which], ancest);
}

void Kruskal_merge(int a, int b,int* ancest)
{
	int ancest_a = Kruskal_ancestor(a, ancest),
		ancest_b = Kruskal_ancestor(b, ancest);

	if (ancest_a != ancest_b) ancest[ancest_b] = ancest_a;
	return;
}

void Kruskal_get_arc(graph g, buf_arc_Kruskal* buf)
{
	int k = 0;
	for (int i = 0; i < g.vtxnum; ++i)
		for (int j = i + 1; j < g.vtxnum; ++j)
			if (g.arcs[i][j] != INF)
			{
				buf[k].a = i;
				buf[k].b = j;
				buf[k].distance = g.arcs[i][j];
				++k;
			}
	return;
}

bool cmp_buf_arc_Kruskal(buf_arc_Kruskal a, buf_arc_Kruskal b)
{
	return a.distance < b.distance;
}

void Kruskal_init_buf(graph& g, buf_arc_Kruskal* buf, int* ancest)
{
	g.arcnum = 0;
	for (int i = 0; i < g.vtxnum; ++i)
	{
		buf[i].a = 0;
		buf[i].b = 0;
		buf[i].distance = INF;
		ancest[i] = i;
		for (int j = 0; j < g.vtxnum; ++j) g.arcs[i][j] = INF;
	}
	return;
}

bool Kruskal_connected(graph g, int* ancest)
{
	bool flag = false;
	for (int i = 0; i < g.vtxnum; ++i)
	{
		if (ancest[i] == i)
		{
			if (flag) return false;
			flag = true;
		}
	}
	return true;
}

graph algorithm_Kruskal(graph g)
{
	graph span = g;
	buf_arc_Kruskal* arc = new buf_arc_Kruskal[g.arcnum];
	int* ancest = new int[g.vtxnum];
	Kruskal_init_buf(span, arc, ancest);

	Kruskal_get_arc(g, arc);
	sort(arc,arc+g.arcnum, cmp_buf_arc_Kruskal);

	for (int i = 0; i < g.arcnum; ++i)
	{
		if (Kruskal_ancestor(arc[i].a, ancest) != Kruskal_ancestor(arc[i].b, ancest))
		{
			Kruskal_merge(arc[i].a, arc[i].b, ancest);
			span.arcs[arc[i].a][arc[i].b] = arc[i].distance;
			span.arcs[arc[i].b][arc[i].a] = arc[i].distance;
			++span.arcnum;
			if (Kruskal_connected(span, ancest)) break;
		}
	}

	delete [] arc;
	delete [] ancest;
	return span;
}

bool cmp_buf_arc_Removingarc(buf_arc_Kruskal a, buf_arc_Kruskal b)
{
	return a.distance > b.distance;
}

bool Removingarc_connected(graph g, bool* visited)
{
	queue<int> que;
	que.push(0);
	visited[0] = true;
	while (!que.empty())
	{
		for (int i = 0; i < g.vtxnum; ++i)
		{
			if (!visited[i] && g.arcs[que.front()][i] != INF)
			{
				visited[i] = true;
				que.push(i);
			}
		}
		que.pop();
	}

	for (int i = 0; i < g.vtxnum; ++i)
		if (visited[i] == false) return false;

	return true;
}

graph algorithm_Removingarc(graph g)
{
	buf_arc_Kruskal* arc = new buf_arc_Kruskal[g.arcnum];
	bool* visited = new bool[g.vtxnum];
	Kruskal_get_arc(g, arc);
	sort(arc, arc + g.arcnum, cmp_buf_arc_Removingarc);

	graph g_buf = g;
	int k = 0;
	do
	{
		for (int i = 0; i < g.vtxnum; ++i) visited[i] = false;
		g = g_buf;
		g_buf.arcs[arc[k].a][arc[k].b] = INF;
		g_buf.arcs[arc[k].b][arc[k].a] = INF;
		++k;
	} while (Removingarc_connected(g_buf,visited));

	delete [] arc;
	delete [] visited;
	return g;
}

void input_matrix(graph& g)
{
	cout << "输入无向图的邻接矩阵(若无边则输入999)：" << endl;
	for (int i = 0; i < g.vtxnum; ++i)
		for (int j = 0; j < g.vtxnum; ++j) cin >> g.arcs[i][j];
	return;
}

void output_matrix(graph g)
{
	for (int i = 0; i < g.vtxnum; ++i)
	{
		for (int j = 0; j < g.vtxnum; ++j) cout << g.arcs[i][j] << " ";
		cout << endl;
	}
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	cout << "输入无向图结点数目：";
	cin >> g.vtxnum; 
	cout << "输入无向图边数目：";
	cin >> g.arcnum;
	input_matrix(g);

	int choice;
	
	cout << "1. Prim" << endl;
	cout << "2. Kruskal" << endl;
	cout << "3. Removing-arc" << endl;
	cout << "选择算法："; cin >> choice;
	switch (choice)
	{
	case 1: {
		output_matrix(algorithm_Prim(g));
		break;
	}
	case 2: {
		output_matrix(algorithm_Kruskal(g));
		break;
	}
	case 3: {
		output_matrix(algorithm_Removingarc(g));
		break;
	}
	default: exit(-1);
	}

	return 0;
}
