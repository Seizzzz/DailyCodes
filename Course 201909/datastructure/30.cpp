#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node* next;
};

void insert_list(node* head, node* x)
{
	bool inserted = false; //标记是否已经插入在中间 
	node* t = head;
	while(t->next)
	{
		if(t->next->val > x->val) //从小到大排序 当遇到更大的才插入 有稳定性 
		{
			x->next = t->next;
			t->next = x;
			inserted = true;
			break;
		} 
		t = t->next;
	}
	if(!inserted) t->next = x; //若遍历至尾仍未插入 则将其插入在尾部 
	return;
}

void insert_sort(node*& head)
{
	node* sorted = new node; //创建一个存储已排序链表的头结点 
	sorted->next = NULL;
	node* t = head;
	
	while(t) //遍历待排序链表 
	{
		node* next_t = NULL;
		if(t->next) next_t = t->next;
		t->next = NULL;
		insert_list(sorted,t); //向已排序链表中插入当前节点 
		if(next_t) t = next_t;
	}
	
	head = sorted->next; //更新新的首元素 
	delete sorted; //删除临时申请的头结点 
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	int n;
	cin >> n;
	
	node* head = new node;
	node* t = head;
	for(int i=0;i<n;++i)
	{
		cin >> t->val;
		t->next = new node;
		t = t->next;
	}
	t->next = NULL;
	
	insert_sort(head);
	
	t = head;
	while(t)
	{
		cout << t->val << " ";
		t = t->next;
	}

	return 0;
}

