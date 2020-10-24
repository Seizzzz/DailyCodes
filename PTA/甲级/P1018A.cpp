#include <bits/stdc++.h>
using namespace std;

int cmax,n,sp,m; //capacity station problem road 
int mymap[502][502];
int station[502];

int sv_path[502];
int path[502];
int leastbike=0x7fffffff;
int sv_takeback = 0;
int leastlen=0x7fffffff;
bool visited[502];

void find_road(int nowat,int step,int bike,int len,int take)
{
	if(len <= leastlen);
	else return;
	
	if(nowat == sp)
	{
		if(bike <= leastbike)
		{
			sv_takeback = take;
			leastlen = len;
			leastbike = bike;
			for(int i=0;i<step;++i) sv_path[i] = path[i];
			sv_path[step] = nowat;
		}
		return;
	}
	
	for(int j=0;j<=n;++j)
	{
		if(!visited[j] && mymap[nowat][j])
		{
			visited[j] = true;
			path[step] = nowat;
			find_road(j,
						step+1,
						station[j]<(cmax>>1) ? bike+((cmax>>1)-station[j]):bike,
						len+mymap[nowat][j],
						station[j]>(cmax>>1) ? take+(station[j]-(cmax >> 1)):take);
			visited[j] = false;
		}
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> cmax >> n >> sp >> m;
	for(int i = 1;i <= n; ++i) cin >> station[i];
	for(int i = 0;i < m; ++i)
	{
		int x,y,len;
		cin >> x >> y >> len;
		mymap[x][y] = len;
	}
	
	visited[0] = true;
	find_road(0,0,0,0,0);
	
	cout << ((leastbike-sv_takeback>0)? leastbike-sv_takeback:0) << " ";
	for(int i=0;sv_path[i]!=sp;++i)
	{
		cout << sv_path[i] << "->";
	}
	cout << sp << " " << (sv_takeback-leastbike>0)? sv_takeback-leastbike:0;
	cout << endl;
	
	return 0;
}

