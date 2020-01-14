#include <bits/stdc++.h>
using namespace std;

#define ll long long

string n,ans;
ll k;

string rev(string n)
{
	string ans = n;
	reverse(ans.begin(),ans.end());
	for(int i = 0;i < ans.length();++i) ans[i] = ans[i] - '0' + n[i] - '0';
	if(ans[0] > '9') ans.insert(0,"0");
	for(int i=ans.length()-1;i>0;--i)
	{
		if(ans[i] > '9') ans[i-1] += (ans[i]/10);
		ans[i] %= 10;
	} 
	return ans;
}

bool judge(string s)
{
	int i = 0, j = s.length()-1;
	while(i<j)
	{
		if(s[i++] != s[j--]) return false;
	}
	return true;
}

int deal(string n,int step)
{
	cout << n << endl;
	if(step >= k)
	{
		ans = n;
		return -1;
	}
	if(judge(n))
	{
		ans = n;
		return step;
	}
	return deal(rev(n),step+1);
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	cin >> n >> k;

	int num = deal(n,0);

	cout << ans << endl;
	cout << ((num==-1)? k:num) << endl;
	
	return 0;
}

