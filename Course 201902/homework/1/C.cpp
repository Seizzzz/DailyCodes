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

bool JudgeSub(struct mylist* listA,struct mylist* listB)
{
	struct mylist *currentA=listA,*currentB=listB;
	int LengthToCompare=ListLength(listB);
	
	while(currentA!=NULL)
	{
		struct mylist *svA=currentA,*svB=currentB;
		for(int i=0;i<LengthToCompare;i++)
		{
			if(svA!=NULL && svA->number==svB->number)
			{
				svA=svA->next;
				svB=svB->next;
				if(i==LengthToCompare-1) return true;
			}
			else break;
		}

		currentA=currentA->next;
		currentB=listB;
	}
	
	return false;
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
	if(JudgeSub(list0,list1)) cout << "ListB is the sub sequence of ListA." << endl;
	else cout << "ListB is not the sub sequence of ListA." << endl;
	
	FreeList(list0);
	FreeList(list1);

	return 0;
}

