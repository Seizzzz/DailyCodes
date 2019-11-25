#include <bits/stdc++.h>
using namespace std;

/*
A(B(D(#,#),E(#,#)),C(#,#))
*/

#define elemtype char
struct node{
    elemtype data;
    struct node *lchild, *rchild;
};

int find_comma(string s)
{
	int cnt = 0;
	for(int i = 0; i < s.length(); ++i)
	{
		switch(s[i])
		{
			case ',':{
				if(cnt == 1) return i;
				break;
			}
			case '(':{
				++cnt;
				break;
			}
			case ')':{
				--cnt;
				break;
			}
		}
	}
}

node* gen(string s)
{
	if(s == "#") return NULL;
	
	node* x = new node;
	x->data = s[0];
	int comma = find_comma(s);
	x->lchild = gen(s.substr(2,comma-2));
	x->rchild = gen(s.substr(comma+1,s.length()-comma-2));
	return x;
}

void trav(node* x)
{
	if(x->lchild) trav(x->lchild);
	cout << x->data;
	if(x->rchild) trav(x->rchild);
}

void delete_tree(node* x)
{
	if(x->lchild)
	{
		delete_tree(x->lchild);
		delete x->lchild;
	}
	if(x->rchild)
	{
		delete_tree(x->rchild);
		delete x->rchild;
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	string s;
	cin >> s;
	
	node* root = gen(s);
	
	trav(root);
	
	delete_tree(root);
	
	return 0;
}

