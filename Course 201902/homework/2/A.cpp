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

struct mylist* DeleteValue(struct mylist *head,int todelete) //按值删除 
{
	struct mylist *newhead=head,*previous=NULL,*current=head;
	
	while(current->number!=todelete)
	{
		previous=current;
		current=current->next;
	}
	
	if(previous==NULL) //删除表头 
	{
		newhead=head->next;
		return newhead;
	}
	
	previous->next=current->next;
	return newhead;
}

int CutList(struct mylist* head,int value)
{
	struct mylist *previous=NULL,*current=head;
	
	while(current->number!=value)
	{
		previous=current;
		current=current->next;
	}
	if(previous==NULL) //B中无元素 
	{
		list1=NULL;
		return -1;
	}
	else previous->next=NULL;
	
	return 0;
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

struct mylist* MergeList(struct mylist* headA,struct mylist* headB)
{
	struct mylist *currentA=headA,*previousA,*currentB=headB,*previousB,*newhead=headA;
	
	if(headA==NULL) 
	{
		if(headB==NULL)
		{
			cout << "There is no item in A list." << endl;
			cout << "There is no item in B list." << endl;
			exit(0);
		}
		else list1=NULL;
		return headB;
	}
	
	
	if(currentB->number<currentA->number) //B中第一个元素比A中小时，改变链表头 
	{
		newhead=headB;
		while(currentB->number<currentA->number)
		{
			if(currentB->next==NULL) //B中所有元素均比A中小 
			{
				currentB->next=currentA;
				return newhead;
			}
			else
			{
				previousB=currentB;
				currentB=currentB->next;
			}
		} //B中有元素大于等于A中头元素，开始常规归并
		previousB->next=headA;
		headB=currentB;
	}
	
	while(currentB!=NULL)
	{
		if(currentA->next==NULL)
		{
			currentA->next=currentB;
			if(CutList(headB,currentB->number)==0) list1=headB;
			QuickSort(list0);
			return newhead;
		}
		
		if(currentA->number==currentB->number)
		{
			currentB=currentB->next;
		}
		else if(currentA->number<currentB->number) //A中比B中小，判断下一个A 
		{
			previousA=currentA;
			currentA=currentA->next;
			continue;
		}
		else //currentA->number>currentB->number
		{
			int todelete=currentB->number;
			struct mylist* svcurrentB=currentB;
			
			currentB=currentB->next;
			headB=DeleteValue(headB,todelete);
			
			previousA->next=svcurrentB;
			svcurrentB->next=currentA;
		}
		
		
	}
	
	list1=headB; //若B头改变，则表头改变 
	
	return newhead;
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

/*
1 3 4 5 6 7 -1
2 3 6 8 9 10 11 -1

4 5 6 7 -1
1 2 3 23 -1
*/

int main()
{
	list0=MergeList(list0,list1);
	
	OutputList(list0,'A');
	OutputList(list1,'B');
	
	FreeList(list0);
	FreeList(list1);
	
	return 0;
}

