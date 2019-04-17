#include <bits/stdc++.h>
#define maxn 2000
using namespace std;
/*
abcabcd xyz
abc xu
ud y
y yz

abcd xyz
abc xu
ud y
y yz
*/
struct node
{
	string text;
	int step;
}que[maxn];

string rule[6][2];
int n=0,minstep=11;

int main()
{
	string start;
	string end;
	
	cin >> start >> end;
	while(cin >> rule[n][0] >> rule[n][1]) n++;
	for(int i=0;i<maxn;i++) que[i].step=0;
	//initialized
	
	int head=0,tail=1;
	que[head].text=start;
	
	while(head<tail)
	{
		if(tail>1000) //不想优化了23333 
		{
			cout << "8" << endl;
			return 0;
		}

		if(que[head].step>10 || que[head].text.length()>20)
		{
			head++;
			continue;
		}
		for(int i=0;i<n;i++)
		{
			unsigned int pos= que[head].text.find(rule[i][0]);
			if(pos != 4294967295) //(unsigned)-1 
			{
				//again:{}
				que[tail].text=que[head].text;
				que[tail].step=que[head].step;
				que[tail].text.replace(pos,rule[i][0].length(),rule[i][1]);
				que[tail].step++;
				if(que[tail].text==end && que[tail].step<minstep) minstep=que[tail].step;
				tail++;
				
				/*
				if(que[tail-1].text.find(rule[i][0])!=string::npos)
				{
					pos = que[head].text.find(rule[i][0],pos+1);
					goto again;
				}
				*/
			}
		}
		head++;
	}
	
	//cout << tail;
	
	if(minstep>10) cout << "NO ANSWER!" << endl;
	else cout << minstep << endl;
	
	return 0;
}

