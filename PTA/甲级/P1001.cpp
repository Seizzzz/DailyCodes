#include <bits/stdc++.h>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);
	
	int a,b;
	cin >> a >> b;
	string s=to_string(a+b);
	
	for(int i=0;i<s.length();i++)
	{
		cout << s[i];
		if(s[i]=='-') continue;
		if((s.length()-i-1)%3==0 && i!=s.length()-1) cout << ",";
	}
	cout << endl;

	return 0;
}

