#include <bits/stdc++.h>
using namespace std;

string table[11];

int main()
{
	std::ios::sync_with_stdio(false);
	
	table[0]="zero";
	table[1]="one";
	table[2]="two";
	table[3]="three";
	table[4]="four";
	table[5]="five";
	table[6]="six";
	table[7]="seven";
	table[8]="eight";
	table[9]="nine";
	
	int tmp,ans=0;
	while(scanf("%1d",&tmp) == 1) ans+=tmp;
	
	string s_ans = to_string(ans);
	
	cout << table[s_ans[0]-'0'];
	for(int i=1;i<s_ans.length();i++) cout << " " << table[s_ans[i]-'0'];
	cout << endl;
	
	return 0;
}

