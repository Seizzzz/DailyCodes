#include <iostream>
#include <vector>
using namespace std;

struct node
{
	int val;
	node* left, * right;
};

vector<int> pre, trav_pre, trav_mpre, post;

void insert(node* root, int x)
{
	if (x < root->val)
	{
		if (root->left) insert(root->left, x);
		else
		{
			root->left = new node;
			root->left->val = x;
			root->left->left = root->left->right = nullptr;
		}
	}
	else // x > root->val
	{
		if (root->right) insert(root->right, x);
		else
		{
			root->right = new node;
			root->right->val = x;
			root->right->left = root->right->right = nullptr;
		}
	}
	return;
}

void pretrav(node* x)
{
	trav_pre.push_back(x->val);
	if (x->left) pretrav(x->left);
	if (x->right) pretrav(x->right);
}

void mpretrav(node* x)
{
	trav_mpre.push_back(x->val);
	if (x->right) mpretrav(x->right);
	if (x->left) mpretrav(x->left);
}

void postrav(node* x)
{
	if (x->left) postrav(x->left);
	if (x->right) postrav(x->right);
	post.push_back(x->val);
}

void mpostrav(node* x)
{
	if (x->right) mpostrav(x->right);
	if (x->left) mpostrav(x->left);
	post.push_back(x->val);
}

void out_post()
{
	for (int i = 0; i < post.size() - 1; ++i) cout << post[i] << " ";
	cout << post[post.size() - 1] << endl;
}

int main()
{
	ios::sync_with_stdio(false);

	int n; cin >> n;
	node* root = new node;

	for (int i = 0; i < n; ++i)
	{
		int x; cin >> x;
		pre.push_back(x);
		if (i == 0)
		{
			root->val = x;
			root->left = root->right = nullptr;
		}
		else insert(root, x);
	}

	pretrav(root);
	if (pre == trav_pre)
	{
		cout << "YES" << endl;
		postrav(root);
		out_post();
		return 0;
	}
	mpretrav(root);
	if (pre == trav_mpre)
	{
		cout << "YES" << endl;
		mpostrav(root);
		out_post();
		return 0;
	}
	cout << "NO" << endl;

	return 0;
}