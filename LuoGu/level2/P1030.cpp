#include <bits/stdc++.h>
using namespace std;

string in,post;

void dfs(int in_st,int in_ed,int post_st,int post_ed)
{
	if(in_st>in_ed) return;

	cout << post[post_ed];
	
	int pos;
	for(pos=in_st;in[pos]!=post[post_ed];pos++);
	
	dfs(in_st,pos-1,post_st,post_st+pos-in_st-1); //left-tree
	dfs(pos+1,in_ed,post_st+pos-in_st,post_ed-1); //right-tree
}

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> in >> post;
	
	dfs(0,in.length()-1,0,post.length()-1);
	cout << endl;

	return 0;
}

