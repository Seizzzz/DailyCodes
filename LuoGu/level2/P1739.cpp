#include <bits/stdc++.h>
using namespace std;

int cnt=0; 

int main()
{
	std::ios::sync_with_stdio(false);
	
	char tmp;
	while(cin.get(tmp))
	{
		if(tmp=='@') break;
		else if(tmp=='(') cnt++;
		else if(tmp==')') cnt--;
		if(cnt<0)
		{
			cout << "NO" << endl;
			exit(0);
		}
	}
	
	if(cnt==0) cout << "YES" << endl;
	else cout << "NO" << endl;
	
	return 0;
}

