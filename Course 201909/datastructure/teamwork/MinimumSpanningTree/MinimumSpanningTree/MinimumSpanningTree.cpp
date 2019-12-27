#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define maxvtxnum 10 //最大结点数
#define INF 999 //定义无边的结点权重 即无穷远
typedef int adjmatrix[maxvtxnum][maxvtxnum];
typedef struct
{
	adjmatrix arcs;
	int vtxnum, arcnum;
}graph; //邻接矩阵

typedef struct
{
	bool visited;
	int distance;
	int from;
}buf_Prim; //用于使用Prim算法时保存信息

typedef struct
{
	int a;
	int b;
	int distance;
}buf_arc_Kruskal; //用于使用Kruskal算法时保存信息

graph g;

void Prim_init_buf(graph& g, buf_Prim* buf) //使用Prim算法时初始化所需变量
{
	g.arcnum = 0; //初始时将最小生成树的图边数设为0
	for (int i = 0; i < g.vtxnum; ++i) //初始化临时存储信息的数组 并将图中边全部去除
	{
		buf[i].visited = false;
		buf[i].distance = INF;
		buf[i].from = 0;
		for (int j = 0; j < g.vtxnum; ++j) g.arcs[i][j] = INF;
	}
	return;
}

void Prim_update(graph g, buf_Prim* buf, int which) //更新数组信息
{
	for (int i = 0; i < g.vtxnum; ++i)
	{
		if (!buf[i].visited && g.arcs[which][i] < buf[i].distance) //当有更短的边可跨接
		{
			buf[i].distance = g.arcs[which][i]; //记录新的最短跨接长度
			buf[i].from = which; //记录来源
		}
	}
	return;
}

void Prim_create_path(graph& g, buf_Prim* buf, int which) //操作跨接两个图分量
{
	++g.arcnum; //新增一条边
	g.arcs[which][buf[which].from] = g.arcs[buf[which].from][which] = buf[which].distance; //无向图双向设置边的权值
	return;
}

int Prim_pick_shortest(graph g, buf_Prim* buf) //从定义的临时存储信息的数组中找出当前跨接分量的最短边
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

graph algorithm_Prim(graph g) //Prim算法主体
{
	graph span = g; //用于保存最小生成树
	buf_Prim* vtx = new buf_Prim[g.vtxnum]; //动态存储临时信息
	Prim_init_buf(span, vtx); //初始化

	vtx[0].visited = true;
	int i = 0;
	for (int cnt = 0; cnt < g.vtxnum; ++cnt) //循环到所有结点加入图
	{
		Prim_update(g, vtx, i); //更新数组信息
		i = Prim_pick_shortest(g, vtx); //找出最短边
		Prim_create_path(span, vtx, i); //创建最短边
		vtx[i].visited = true; //标记已访问
	}
	
	delete [] vtx;
	return span;
}

int Kruskal_ancestor(int which, int* ancest) //并查集找出祖先
{
	if (ancest[which] == which) return which;
	return ancest[which] = Kruskal_ancestor(ancest[which], ancest); //返回祖先并路径压缩
}

void Kruskal_merge(int a, int b,int* ancest) //并查集合并
{
	int ancest_a = Kruskal_ancestor(a, ancest),
		ancest_b = Kruskal_ancestor(b, ancest);

	if (ancest_a != ancest_b) ancest[ancest_b] = ancest_a;
	return;
}

void Kruskal_get_arc(graph g, buf_arc_Kruskal* buf) //从图中获取所有边信息
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

bool cmp_buf_arc_Kruskal(buf_arc_Kruskal a, buf_arc_Kruskal b) //用于sort排序
{
	return a.distance < b.distance;
}

void Kruskal_init_buf(graph& g, buf_arc_Kruskal* buf, int* ancest) //初始化存储信息的数组
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

bool Kruskal_connected(graph g, int* ancest) //判断图是否连通
{
	bool flag = false;
	for (int i = 0; i < g.vtxnum; ++i)
	{
		if (ancest[i] == i) //通过并查集判断 若连通则只存在一个共同祖先
		{
			if (flag) return false;
			flag = true;
		}
	}
	return true;
}

graph algorithm_Kruskal(graph g) //Kruskal算法主体
{
	graph span = g; //保存最小生成树
	buf_arc_Kruskal* arc = new buf_arc_Kruskal[g.arcnum]; //动态创建存储临时信息的数组
	int* ancest = new int[g.vtxnum]; //动态创建保存并查集信息的数组
	Kruskal_init_buf(span, arc, ancest); //初始化创建的数组

	Kruskal_get_arc(g, arc); //从输入中获取所有边信息
	sort(arc,arc+g.arcnum, cmp_buf_arc_Kruskal); //按边权重从小到大进行排序

	for (int i = 0; i < g.arcnum; ++i) //从小到大依次尝试加入边
	{
		if (Kruskal_ancestor(arc[i].a, ancest) != Kruskal_ancestor(arc[i].b, ancest)) //如果边对应的两点没有共同祖先 则两点所在的分量不连通
		{
			Kruskal_merge(arc[i].a, arc[i].b, ancest); //并查集合并两点
			span.arcs[arc[i].a][arc[i].b] = arc[i].distance;
			span.arcs[arc[i].b][arc[i].a] = arc[i].distance;
			++span.arcnum; //在最小生成树中创建无向图的两边
			if (Kruskal_connected(span, ancest)) break; //如果图连通 则可提前结束
		}
	}

	delete [] arc;
	delete [] ancest;
	return span;
}

bool cmp_buf_arc_Removingarc(buf_arc_Kruskal a, buf_arc_Kruskal b) //用于sort排序
{
	return a.distance > b.distance;
}

bool Removingarc_connected(graph g, bool* visited) //判断图是否连通
{
	queue<int> que; //借助队列广度优先遍历图
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

	for (int i = 0; i < g.vtxnum; ++i) //判断是否所有点都可遍历到
		if (visited[i] == false) return false;

	return true;
}

graph algorithm_Removingarc(graph g) //去边法主体
{
	buf_arc_Kruskal* arc = new buf_arc_Kruskal[g.arcnum]; //动态创建临时存储信息的数组 复用Kruskal算法中的结构
	bool* visited = new bool[g.vtxnum]; //动态创建访问标记数组
	Kruskal_get_arc(g, arc); //从输入中获取所有边信息
	sort(arc, arc + g.arcnum, cmp_buf_arc_Removingarc); //对边从大到小排序

	graph g_buf = g; //g_buf用于保存去除下一条边后的图
	for (int k = 0; k < g.arcnum; ++k) //从大到小依次尝试去除所有边
	{
		for (int i = 0; i < g.vtxnum; ++i) visited[i] = false; //初始化标记数组
		g_buf.arcs[arc[k].a][arc[k].b] = INF;
		g_buf.arcs[arc[k].b][arc[k].a] = INF;
		--g_buf.arcnum; //去除边
		if (Removingarc_connected(g_buf, visited)) g = g_buf; //如果去除后图仍然连通 更新g
		else g_buf = g; //若去除后不连通 则恢复至上一个状态
		++k;
	}

	delete [] arc;
	delete [] visited;
	return g;
}

void input_matrix(graph& g) //获取输入的邻接矩阵
{
	cout << "输入无向图的邻接矩阵(若无边则输入999)：" << endl;
	for (int i = 0; i < g.vtxnum; ++i)
		for (int j = 0; j < g.vtxnum; ++j) cin >> g.arcs[i][j];
	return;
}

void output_matrix(graph g) //输出图的邻接矩阵
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
