#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node *lc,*rc;
}root;

#define INF 0x7fffffff
int now = -INF;
bool judge_binsortree(node* x)
{ //判断中序遍历是否递增 
	bool ret = true;
	if(x->lc) ret = ret && judge_binsortree(x->lc);
	if(x->val > now) now = x->val;
	else return false;
	if(x->rc) ret = ret && judge_binsortree(x->rc);
	return ret;
}

int main()
{
	std::ios::sync_with_stdio(false);
	judge_binsortree(&root);
	
	return 0;
}

