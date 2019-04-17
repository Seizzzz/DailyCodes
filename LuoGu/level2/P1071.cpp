#include <bits/stdc++.h>
using namespace std;

char wordlist[2][30];

int main()
{
	for(int i=0;i<2;i++)
		for(int j=0;j<26;j++) wordlist[i][j]='\0';
	
	char info[105];
	char oinfo[105];
	
	cin >> info;
	cin >> oinfo;
	
	int infolen=strlen(info);
	int oinfolen=strlen(oinfo);
	
	if(infolen!=oinfolen)
	{
		cout << "Failed" << endl;
		return 0;
	}
	
	for(int i=0;i<infolen;i++)
	{
		if(wordlist[1][info[i]-'A']=='\0')
		{
			wordlist[1][info[i]-'A']=info[i];
			wordlist[0][info[i]-'A']=oinfo[i];
		}
		else
		{
			if(wordlist[0][info[i]-'A']!=oinfo[i])
			{
				cout << "Failed" << endl;
				return 0;
			}
		}
	}
	
	int judge[30];
	for(int i=0;i<26;i++) judge[i]=0;
	for(int i=0;i<26;i++) judge[wordlist[0][i]-'A']++;
	
	for(int i=0;i<26;i++)
	{
		if(judge[i]!=1)
		{
			cout << "Failed" << endl;
			return 0;
		}
	}
	
	char todo[105];
	cin >> todo;
	int todolen=strlen(todo);
	for(int i=0;i<todolen;i++) cout << wordlist[0][todo[i]-'A'];
	cout << endl;

	return 0;
}

