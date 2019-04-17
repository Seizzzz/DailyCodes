#include<bits/stdc++.h>
#define maxn 20
using namespace std;

/*
631758924
*/

void mypop(string& a,string& ans)
{
	if(a.length()==2)
	{
		ans.append(a);
		a.clear();
		return;
	}
	ans.append(a,0,1);
	a.append(a,1,1);
	a=a.substr(2);
	return;
}

int main()
{
	string a;
	cin >> a;
	
	string ans;
		
	while(a.length()>=2) mypop(a,ans);
	
	cout << ans <<endl;
	
	return 0;
}

