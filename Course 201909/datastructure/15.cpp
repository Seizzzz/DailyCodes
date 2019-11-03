#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

bool find_path(node* now, node* tofind,queue<node*>& path)
{
	if(now == tofind) return true;
	if((now->lchild && find_path(now->lchild,tofind,path)) ||
	   (now->rchild && find_path(now->rchild,tofind,path)))
	{
		path.push(now);
		return true;
	}
	return false;
}

node* find_ancestor(node *a, node *b)
{
	queue<node*> a_path, b_path;
	find_path(root,a,a_path);
	find_path(root,b,b_path);
	
	while(a_path.size() > b_path.size()) a_path.pop();
	while(b_path.size() > a_path.size()) b_path.pop();
	while(a_path.back() != b_path.back())
	{
		a_path.pop();
		b_path.pop();
	}
	return a_path.back();
}


int main()
{
	std::ios::sync_with_stdio(false);
	
	

	return 0;
}

