#include <bits/stdc++.h>
using namespace std;

#define elemtype char 

struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

void trav(node* x, int depth)
{
	if(x->rchild) trav(x->rchild,depth+1);
	for(int i=0;i<depth;++i) cout << " "; cout << x->data << endl;
	if(x->lchild) trav(x->lchild,depth+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	node* array[12];
	for(int i = 0;i<12;++i) array[i] = new node;
	array[0]->data='-';
	array[0]->lchild=array[1];
	array[0]->rchild=array[2];
	
	array[1]->data='+';
	array[1]->lchild=array[3];
	array[1]->rchild=array[4];
	
	array[2]->data='/';
	array[2]->lchild=array[5];
	array[2]->rchild=array[6];
	
	array[3]->data='a';
	array[3]->lchild=NULL;
	array[3]->rchild=NULL;
	
	array[4]->data='*';
	array[4]->lchild=array[7];
	array[4]->rchild=array[8];
	
	array[5]->data='e';
	array[5]->lchild=NULL;
	array[5]->rchild=NULL;
	
	array[6]->data='f';
	array[6]->lchild=NULL;
	array[6]->rchild=NULL;
	
	array[7]->data='b';
	array[7]->lchild=NULL;
	array[7]->rchild=NULL;
	
	array[8]->data='-';
	array[8]->lchild=array[9];
	array[8]->rchild=array[10];
	
	array[9]->data='c';
	array[9]->lchild=NULL;
	array[9]->rchild=NULL;
	
	array[10]->data='d';
	array[10]->lchild=NULL;
	array[10]->rchild=NULL;
	
	trav(array[0],0);

	return 0;
}

