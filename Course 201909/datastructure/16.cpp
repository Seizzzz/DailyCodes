#include <bits/stdc++.h>
using namespace std;

typedef struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

int dfs(node* now, int depth, int max_depth, vector<node*>& now_path, vector<node*>& max_path)
{
	if(depth > max_depth) //Ѱ�ҵ������·�� 
	{
		max_depth = depth;
		max_path = now_path;
	}
	if(now->lchild) //��������� 
	{
		now_path.push(now->lchild); //�������� 
		dfs(now->lchild,depth+1,max_depth,now_path); //�����������ӵ����� 
		now_path.pop(); //pop���� ת�������� 
	}
	if(now->rchild) //ͬ�� 
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
	int diam = dfs(root,0,-1,now_path,max_path); //�Ӹ��ڵ㿪ʼ ������Ϊ0 �����ȼ�Ϊ-1 
	//ֱ���洢��diam�� ·���洢��max_depth�� 
	return 0;
}

