#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node *lc,*rc;
};

int postorder[32],inorder[32];

node* build(int* post,int* in,int n)
{
	if(n<=0) return NULL;
	node* x = new node;
	x->val = post[n-1];
	
	int pos;
	for(int i=0;i<n;++i)
	{
		if(in[i] == post[n-1])
		{
			pos = i;
			break;
		}
	}
	
	x->lc = build(post,in,pos);
	x->rc = build(post+pos,in+pos+1,n-pos-1);
	return x;
}

void leveltrav(node* x)
{
	queue<node*> que;
	que.push(x);
	
	bool outed = false;
	while(!que.empty())
	{
		if(outed) cout << " " << que.front()->val;
		else
		{
			cout << que.front()->val;
			outed = true;
		}
		if(que.front()->lc) que.push(que.front()->lc);
		if(que.front()->rc) que.push(que.front()->rc);
		que.pop();
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	for(int i=0;i<n;++i) cin >> postorder[i]; 
	for(int i=0;i<n;++i) cin >> inorder[i]; 
	
	node* x = build(postorder,inorder,n);
	
	leveltrav(x);

	return 0;
}

