#include <bits/stdc++.h>
using namespace std;

int* nodes;
bool mymap[10002][10002]; 
int n;

int parent(int a)
{
	if(nodes[a] == a) return a;
	return nodes[a] = parent(nodes[a]);
}

int merge(int a,int b)
{
	int pa = parent(a),
		pb = parent(b); 
	if(pa!=pb) nodes[pb] = pa;
}

int nowmax = 0;
vector<int> deepest;
bool visited[10002];
void dfs(int now,int len)
{
	if(len >= nowmax)
	{
		if(len > nowmax) deepest.clear();
		nowmax = len;
		deepest.push_back(now);
	}
	
	for(int i=1;i<=n;++i)
	{
		if(!visited[i] && mymap[now][i])
		{
			visited[i] = true;
			dfs(i,len+1);
			visited[i] = false;
		}
	}
}

int nowmax2=0;
vector<int> deepest2; 
void dfs2(int now,int len)
{
	if(len >= nowmax2)
	{
		if(len > nowmax2) deepest2.clear();
		nowmax2 = len;
		deepest2.push_back(now);
	}
	
	for(int i=1;i<=n;++i)
	{
		if(!visited[i] && mymap[now][i])
		{
			visited[i] = true;
			dfs2(i,len+1);
			visited[i] = false;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n;
	nodes = new int[n+2];
	
	for(int i=1;i<=n;++i) nodes[i] = i;
	for(int i=0;i<n-1;++i)
	{
		int a,b;
		cin >> a >> b;
		mymap[a][b] = mymap[b][a] = true;
		merge(a,b);
	}
	
	int cnt = 0;
	for(int i=1;i<=n;++i)
	{
		if(nodes[i] == i) ++cnt;
	}
	if(cnt > 1)
	{
		cout << "Error: " << cnt << " components" << endl;
		return 0;
	}
	
	visited[1] = true;
	dfs(1,0); 
	visited[1] = false;
	
	visited[deepest[0]] = true;
	dfs2(deepest[0],0);
	
	deepest.insert(deepest.end(),deepest2.begin(),deepest2.end());
	sort(deepest.begin(),deepest.end());
	
	auto ptr = unique(deepest.begin(),deepest.end());
	deepest.erase(ptr,deepest.end());
	
	for(int i=0;i<deepest.size();++i) cout << deepest[i] << endl;

	return 0;
}

