#include <bits/stdc++.h>
using namespace std;

struct mylist
{
	int number;
	struct mylist* next;
};

struct mylist* createlist()
{
	int num;
	cin >> num;
	
	struct mylist *head=NULL,*last=NULL,*current=NULL;
	
	while(num!=-1) //end by -1
	{
		current=(struct mylist*)malloc(sizeof(struct mylist)); //temp
		if(current!=NULL) //succeed malloc
		{
			current->number=num;
			if(head==NULL) head=current; //first
			else last->next=current; //not first
			last=current;
		}
		cin >> num; //loop
	}
	last->next=NULL; //end list
	return head;
}

struct mylist* list1=createlist();

void outputlist(struct mylist* head)
{
	struct mylist* current=head;
	
	while(current!=NULL) //not null pointer 
	{
		cout << current->number << endl;
		current=current->next;
	}
	
	cout << endl;
	return;
}

void outputreverse(struct mylist* head)
{
	if(head!=NULL) outputreverse(head->next);
	else return;
	
	cout << head->number << endl;

	return;
}

int searchlist(struct mylist* head,int tofind)
{
	struct mylist* current=head;
	int at=0;
	
	while(current!=NULL) //search end
	{
		if(current->number==tofind) return at;
		at++;
		current=current->next;
	}
	return -1; //-1 not exist
}

int searchmaxnode(struct mylist* head)
{
	struct mylist* current=head;
	int max=head->number,maxat=0,at=0;
	
	while(current!=NULL)
	{
		if(current->number>max)
		{
			max=current->number;
			maxat=at;
		}
		at++;
		current=current->next;
	}
	return maxat;
}

void deleteelement(struct mylist* head,int todelete)
{
	struct mylist *current=head,*previous=head;
	
	while(current!=NULL)
	{
		if(current->number==todelete)
		{
			if(previous==head) list1=list1->next; //transfer head !!!
			else if(current->next==NULL) //delete end element
			{
				previous->next=NULL;
				free(current);
			}
			else //delete middle element BUT here current is not freed!!!
			{
				previous->next=current->next;
				free(current);
			}
			
			return;
		}
		else //not found
		{
			previous=current;
			current=current->next;
		}
	}
}

void deletevalue(struct mylist* head,int todelete)
{
	struct mylist* current=head;
	//if(current==NULL) return;
	
	while(current!=NULL)
	{
		if(current->number==todelete)
		{
			deletevalue(current->next,todelete);
			//deleteelement(current,todelete); //todo
			return;
		}
		else current=current->next;
	}
	return;
}

void reviseelement1(struct mylist* head,int at,int torevise) //revise by positon
{
	int cnt=0;
	struct mylist *current=head;
	
	while(current!=NULL)
	{
		if(cnt==at)
		{
			current->number=torevise;
			return;
		}
		else
		{
			current=current->next;
			cnt++;
		}
	}
	return;
}

void reviseelement2(struct mylist* head,int value,int torevise) //revise by value
{
	struct mylist *current=head;
	
	while(current!=NULL)
	{
		if(current->number==value)
		{
			current->number=torevise;
			return;
		}
		else current=current->next;
	}
	return;
}

void insertelement(struct mylist* head,struct mylist* extra,int toinsert,int position)
{
	struct mylist *current=head,*previous=head;
	
	if(position==0) //insert befor head BUT here for convenience, insert at 1 and swap the value
	{
		current=head->next;
		head->next=extra;
		extra->next=current;
		extra->number=head->number;
		head->number=toinsert;
	}
	else
	{
		int cnt=0;
		while(cnt!=position)
		{
			previous=current;
			current=current->next;
			cnt++;
		}
		previous->next=extra;
		extra->next=current;
		extra->number=toinsert;
	}
	return;
}

bool judgeincrease(struct mylist* head)
{
	struct mylist *current=head;
	
	int currentnum=head->number;
	while(current!=NULL)
	{
		if(current->number>=currentnum)
		{
			currentnum=current->number;
			current=current->next;
		}
		else return false;
	}
	return true;
}

int main()
{
/*
	//output
	outputlist(list1);
	
	//output-reverse
	outputreverse(list1);
	
	//search
	int tofind;
	cin >> tofind;
	cout << searchlist(list1,tofind) << endl;
	
	//delete
	int todelete;
	cin >> todelete;
	deleteelement(list1,todelete);
	outputlist(list1);

	//insert
	int toinsert,position;
	cin >> toinsert >> position;
	struct mylist* extra;
	extra=(struct mylist*)malloc(sizeof(struct mylist));
	if(extra!=NULL) insertelement(list1,extra,toinsert,position);
	outputlist(list1);
	
	//revise by positon
	int torevise; //here omit positon
	cin >> torevise >> position;
	reviseelement1(list1,position,torevise);
	outputlist(list1);
	
	//revise by value
	int value; //here omit torevise
	cin >> value >> torevise;
	reviseelement2(list1,value,torevise);
	outputlist(list1);
	
	//judge increase
	cout << judgeincrease(list1);
*/
	//delete all value in list
	int todelete;
	cin >> todelete;
	deletevalue(list1,todelete);
	outputlist(list1);
	
	
	
	return 0;
}

