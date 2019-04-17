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
	
	if(temp==-1) return head;
	
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
struct mylist* list1=CreateList();

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

void OutputList(struct mylist* head,char ListName)
{
	struct mylist* current=head;
	
	if(head==NULL)
	{
		cout << "There is no item in " << ListName << " list." << endl;
		return;
	}
	
	cout << "The new list " << ListName << ":";
	while(current!=NULL)
	{
		cout << current->number << " ";
		current=current->next;
	}
	cout << endl;
	
	return;
}

struct mylist* MergeList(struct mylist* headA,struct mylist* headB)
{
	struct mylist *currentA=headA,*previousA,*currentB=headB,*previousB=list1,*nextB; 
	
	if(headA==NULL)
	{
		list1=NULL;
		return headB;
	}
	if(headB==NULL) return headA;
	
	while(currentB!=NULL)
	{
		/*
		OutputList(currentA,'A');
		OutputList(currentB,'B');
		OutputList(list0,'0');
		OutputList(list1,'1');
		cout << "\n";
		*/
		
		nextB=currentB->next;
		
		if(currentA==NULL)
		{
			while(currentB->number<=previousA->number)
			{
				previousB=currentB;
				currentB=currentB->next;
			}
			currentA=currentB;
			previousA->next=currentA;
			if(previousB!=list1 || previousB->number==previousA->number) previousB->next=NULL;
			if(currentB==list1) list1=NULL;
			break;
		}
		
		if(currentA->number > currentB->number)
		{
			if(currentA==list0)
			{
				currentB->next=currentA;
				list0=currentB;
				headA=list0;
				currentA=list0;
				currentB=nextB;
				previousB=currentB;
				list1=currentB;
			}
			else
			{
				previousA->next=currentB;
				currentB->next=currentA;
				currentA=currentB;
				
				currentB=nextB;
				if(previousB==list1)
				{
					list1=nextB;
					previousB=list1;
				}
				else previousB->next=nextB;
			}
		}
		else if(currentA->number < currentB->number)
		{
			previousA=currentA;
			currentA=currentA->next;
		}
		else //currentA->number == currentB->number
		{
			previousB=currentB;
			currentB=nextB;
		}
	}
	
	return list0;
}

int main()
{
	list0=MergeList(list0,list1);
	
	OutputList(list0,'A');
	OutputList(list1,'B');
	
	FreeList(list0);
	FreeList(list1);

	return 0;
}

