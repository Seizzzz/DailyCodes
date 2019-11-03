#include <bits/stdc++.h>
using namespace std;

int level[102],max_depth=-1;

struct node
{
	int id;
	vector<node*> child;
}nodes[102];

void trav(node* x,int depth)
{
	if((x->child).empty())
	{
		++level[depth];
		max_depth = max(max_depth,depth);
		return;
	}
	for(int i=0;i<(x->child).size();++i) trav((x->child)[i],depth+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int m,n;
	cin >> n >> m;
	
	for(int i=0;i<m;++i)
	{
		int tmp_id,tmp_child;
		cin >> tmp_id >> tmp_child;
		for(int j=0;j<tmp_child;++j)
		{
			int tmp_who;
			cin >> tmp_who;
			nodes[tmp_id].child.push_back(&nodes[tmp_who]);
		}
	}
	
	trav(&nodes[1],1);
	
	cout << level[1];
	for(int i=2;i<=max_depth;++i) cout << " " << level[i];

	return 0;
}

