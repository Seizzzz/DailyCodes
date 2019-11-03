#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

int dfs(node* now, int depth, int max_depth, vector<node*>& now_path, vector<node*>& max_path)
{
	if(depth > max_depth) //寻找到更深的路径 
	{
		max_depth = depth;
		max_path = now_path;
	}
	if(now->lchild) //如果有左孩子 
	{
		now_path.push(now->lchild); //存入左孩子 
		dfs(now->lchild,depth+1,max_depth,now_path); //继续搜索左孩子的子树 
		now_path.pop(); //pop左孩子 转入右子树 
	}
	if(now->rchild) //同理 
	{
		now_path.push(now->rchild);
		dfs(now->rchild,depth+1,max_depth,now_path);
		now_path.pop();
	}
	return max_depth;
}

int main()
{
	vector<node*> now_path, max_path;
	now_path.push(root);
	int diam = dfs(root,0,-1,now_path,max_path); //从根节点开始 层数记为0 最大深度记为-1 
	//直径存储在diam中 路径存储在max_depth中 
	return 0;
}

