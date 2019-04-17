#include <bits/stdc++.h>
using namespace std;

struct mylist
{
	int number;
	struct mylist* next;
};

struct mylist* CreateList()
{
	struct mylist *head=NULL,*last=NULL,*current=NULL;
	
	int temp;
	cin >> temp;
	while(temp!=-1)
	{
		current=(struct mylist*)malloc(sizeof(struct mylist));
		if(current!=NULL)
		{
			current->number=temp;
			if(head==NULL) head=current;
			else last->next=current;
			last=current;
		}
		cin >> temp;
	}
	last->next=NULL;
	
	return head;
}

struct mylist* list0=CreateList();

int ListLength(struct mylist* head)
{
	struct mylist *current=head;
	int len=0;
	while(current!=NULL)
	{
		len++;
		current=current->next;
	}
	return len;
}

bool cmp(struct mylist* a,struct mylist* b)
{
	return a->number<b->number;
}

struct mylist* QuickSort(struct mylist* head)
{
	int len=ListLength(head);

	struct mylist *mylistPTR[len],*current=head;
	for(int i=0;i<len;i++)
	{
		mylistPTR[i]=current;
		current=current->next;
	}
	sort(mylistPTR,mylistPTR+len,cmp);
	
	head=mylistPTR[0];
	current=head;
	for(int i=1;i<len;i++)
	{
		current->next=mylistPTR[i];
		current=current->next;
	}
	current->next=NULL;
	
	return head;
}

void OutputList(struct mylist* head)
{
	struct mylist* current=head;
	
	while(current!=NULL)
	{
		cout << current->number << " ";
		current=current->next;
	}
	cout << endl;
	
	return;
}

void FreeList(struct mylist* head)
{
	int len=ListLength(head);

	struct mylist *mylistPTR[len],*current=head;
	for(int i=0;i<len;i++)
	{
		mylistPTR[i]=current;
		current=current->next;
	}
	for(int i=0;i<len;i++) free(mylistPTR[i]);
	
	return;
}


int main()
{
	list0=QuickSort(list0);
	
	cout << "The new list is:";
	OutputList(list0);
	
	FreeList(list0);
	
	return 0;
}

