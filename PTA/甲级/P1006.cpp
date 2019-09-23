#include <bits/stdc++.h>
using namespace std;

int main()
{	
	string firstin,lastout;
	int fin=0x7fffffff,lot=0;
	
	int t;
	cin >> t;
	while(t--)
	{
		string id;
		cin >> id;
		int hour,min,sec;
		scanf("%d:%d:%d",&hour,&min,&sec);
		int intime = hour*10000+min*100+sec;
		scanf("%d:%d:%d",&hour,&min,&sec);
		int outtime = hour*10000+min*100+sec;
		
		if(intime<fin)
		{
			firstin=id;
			fin=intime;
		}
		if(outtime>lot)
		{
			lastout=id;
			lot=outtime;
		}
	}
	
	cout << firstin << " " << lastout << endl;

	return 0;
}

