#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	string s1,s2,s3,s4;
	cin >> s1 >> s2 >> s3 >> s4;
	char c1,c2; int c3;
	
	int lim1= min(s1.length(),s2.length());
	int i=0;
	for(;i<lim1;++i)
	{
		if(s1[i] == s2[i] && isupper(s1[i]))
		{
			c1=s1[i];
			break;
		}
	}
	for(++i;i<lim1;++i)
	{
		if(s1[i] == s2[i] && isupper(s1[i]))
		{
			c2=s1[i];
			break;
		}
	}
	i = 0;
	int lim2= min(s3.length(),s4.length());
	for(;i<lim2;++i)
	{
		if(s3[i] == s4[i] && isalpha(s3[i]))
		{
			c3 = i;
			break;
		}
	}
	
	switch(c1 - 'A').
	
	return 0;
}

