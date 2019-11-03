#include <bits/stdc++.h>
using namespace std;

#define elemtype char
struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

const char list_priority[4][4] = { //算符优先级顺序 
	//        +      -      *      /
	/*+*/    '=',   '=',   '<',   '<',
	/*-*/    '=',   '=',   '<',   '<',
	/***/    '>',   '>',   '=',   '=',
	/*/*/    '>',   '>',   '=',   '='};

int num_symbol(char a)
{
	switch(a)
	{
		case '+': return 0;
		case '-': return 1;
		case '*': return 2;
		case '/': return 3;
		default: return 2; //字母也相当于乘除运算符 优先级高 无需括号 
	}
}

void trav_inorder(node* x)
{
	if(x)
	{
		if(x->lchild)
		{
			//当前运算符优先级高于左孩子运算符时左孩子才需要括号 
			if(list_priority[num_symbol(x->data)][num_symbol(x->lchild->data)] == '>')
			{
				cout << "(";
				trav_inorder(x->lchild);
				cout << ")";
			}
			else trav_inorder(x->lchild);
		}
		cout << x->data;
		if(x->rchild)
		{
			//当前运算符优先级高于右孩子运算符时右孩子才需要括号 
			if(list_priority[num_symbol(x->data)][num_symbol(x->rchild->data)] == '>')
			{
				cout << "(";
				trav_inorder(x->rchild);
				cout << ")";
			}
			else trav_inorder(x->rchild);
		}
	}
	return;
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

	trav_inorder(array[0]);

	return 0;
}

