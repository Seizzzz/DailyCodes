#include <bits/stdc++.h>
using namespace std;

struct node
{
	int val;
	node* next;
};

void insert_list(node* head, node* x)
{
	bool inserted = false; //����Ƿ��Ѿ��������м� 
	node* t = head;
	while(t->next)
	{
		if(t->next->val > x->val) //��С�������� ����������ĲŲ��� ���ȶ��� 
		{
			x->next = t->next;
			t->next = x;
			inserted = true;
			break;
		} 
		t = t->next;
	}
	if(!inserted) t->next = x; //��������β��δ���� ���������β�� 
	return;
}

void insert_sort(node*& head)
{
	node* sorted = new node; //����һ���洢�����������ͷ��� 
	sorted->next = NULL;
	node* t = head;
	
	while(t) //�������������� 
	{
		node* next_t = NULL;
		if(t->next) next_t = t->next;
		t->next = NULL;
		insert_list(sorted,t); //�������������в��뵱ǰ�ڵ� 
		if(next_t) t = next_t;
	}
	
	head = sorted->next; //�����µ���Ԫ�� 
	delete sorted; //ɾ����ʱ�����ͷ��� 
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

