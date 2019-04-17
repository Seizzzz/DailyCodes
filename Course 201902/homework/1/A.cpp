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

int SearchMaximum(struct mylist* head)
{
	struct mylist* current=head;
	int max=head->number;
	
	while(current!=NULL)
	{
		if(current->number>max) max=current->number;
		current=current->next;
	}
	
	return max;
}

int SearchMinimum(struct mylist* head)
{
	struct mylist* current=head;
	int min=head->number;
	
	while(current!=NULL)
	{
		if(current->number<min) min=current->number;
		current=current->next;
	}
	
	return min;
}

int CalculateTotal(struct mylist* head)
{
	struct mylist* current=head;
	int sum=0;
	
	while(current!=NULL)
	{
		sum+=current->number;
		current=current->next;
	}
	
	return sum;
}

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

struct mylist* list0=CreateList();

int main()
{
	cout << "The maximum,minmum and the total are:";
	cout << SearchMaximum(list0) << " ";
	cout << SearchMinimum(list0) << " ";
	cout << CalculateTotal(list0) << endl;
	
	FreeList(list0);
	
	return 0;
}

