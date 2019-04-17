#include <bits/stdc++.h>
using namespace std;

struct mylist
{
	char number;
	struct mylist* next;
};

struct mylist* CreateList()
{
	struct mylist *head=NULL,*last=NULL,*current=NULL;
	
	string line;
	getline(cin,line);
	line=line.substr(0,line.length()-3); 
	stringstream ss(line);
	
	if(line=="-1") return head;
	
	char temp;
	while(ss >> temp)
	{
		current=(struct mylist*)malloc(sizeof(struct mylist));
		if(current!=NULL)
		{
			current->number=temp;
			if(head==NULL) head=current;
			else last->next=current;
			last=current;
		}
	}

	last->next=NULL;
	
	return head;
}

struct mylist* listL=CreateList();
struct mylist* listA=NULL;
struct mylist* listB=NULL;
struct mylist* listC=NULL;

void OutputList(struct mylist* head,char ListName)
{
	struct mylist* current=head;
	
	if(head==NULL)
	{
		cout << "There is no item in " << ListName << " list." << endl;
		return;
	}
	
	cout << "The list " << ListName << " is: ";
	while(current!=NULL)
	{
		cout << current->number << " ";
		current=current->next;
	}
	cout << endl;
	
	return;
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

bool cmp(struct mylist* a,struct mylist* b)
{
	return a->number < b->number;
}

struct mylist* QuickSort(struct mylist* head)
{
	if(head==NULL) return head;
	
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

void Method(struct mylist* head)
{
	struct mylist *current=head,*currentA=listA,*currentB=listB,*currentC=listC,\
					*previous=current,*previousA=NULL,*previousB=NULL,*previousC=NULL;
	
	while(current!=NULL)
	{
		previous=current;
		current=current->next;
		
		if(isalpha(previous->number)) //add to A
		{
			if(currentA==listA)
			{
				listA=previous;
				currentA=listA;
			}
			else currentA=previous;
			if(previousA!=NULL) previousA->next=currentA;
			else previousA=currentA;
			previousA=currentA;
			currentA->next=NULL;
			currentA=currentA->next;
		}
		else if(isdigit(previous->number)) //add to B
		{
			if(currentB==listB)
			{
				listB=previous;
				currentB=listB;
			}
			else currentB=previous;
			if(previousB!=NULL) previousB->next=currentB;
			else previousB=currentB;
			previousB=currentB;
			currentB->next=NULL;
			currentB=currentB->next;
		}
		else //add to C
		{
			if(currentC==listC)
			{
				listC=previous;
				currentC=listC;
			}
			else currentC=previous;
			if(previousC!=NULL) previousC->next=currentC;
			else previousC=currentC;
			previousC=currentC;
			currentC->next=NULL;
			currentC=currentC->next;
		}
	}
	
	listA=QuickSort(listA);
	listB=QuickSort(listB);
	listC=QuickSort(listC);
	
	return;
}

int main()
{
	Method(listL);
	
	OutputList(listA,'A');
	OutputList(listB,'B');
	OutputList(listC,'C');

	FreeList(listA);
	FreeList(listB);
	FreeList(listC);

	return 0;
}

