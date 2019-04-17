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

void OutputList(struct mylist* head)
{
	struct mylist* current=head;
	
	while(current!=NULL && current->next!=NULL)
	{
		cout << current->number << " ";
		current=current->next;
	}
	cout << current->number << endl;
	
	return;
}

struct mylist* Exchange(struct mylist* head,int s1,int t1,int s2,int t2)
{
	int len=ListLength(head);
	
	struct mylist *mylistPTR[len],*current=head;
	for(int i=1;i<=len;i++)
	{
		mylistPTR[i]=current;
		current=current->next;
	}
	
	if(s1!=1) mylistPTR[s1-1]->next=mylistPTR[s2];
	mylistPTR[t2]->next=(t1+1==s2)? mylistPTR[s1]:mylistPTR[t1+1];
	mylistPTR[s2-1]->next=mylistPTR[s1];
	mylistPTR[t1]->next=mylistPTR[t2+1];
	
	if(t2==len) mylistPTR[t1]->next=NULL;
	
	return (s1==1)? mylistPTR[s2]:head;
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
	int s1,t1,s2,t2;
	cin >> s1 >> t1 >> s2 >> t2;
	
	cout << "The new list is:";
	OutputList(Exchange(list0,s1,t1,s2,t2));
	
	FreeList(list0);

	return 0;
}

