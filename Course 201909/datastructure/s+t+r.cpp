#include <bits/stdc++.h>
using namespace std;

//concat len sub equal
#define ascii_max 128 //可见字符 
string solve(string s,string t)
{
	string r; //目标字符串 
	int in_s[ascii_max]; //若首次出现在s中 则在此内记录下标 
	bool in_t[ascii_max]; //标记某字符是否在t中 
	
	for(int i = 0; i < ascii_max; ++i) {in_t[i]=false; in_s[i] = -1;}
	//初始化字符在s中的标记数组 
	for(int i = 0;i < t.Len(); ++i) in_t[t[i]] = true;
	//若出现在t中则标记 
	
	for(int i = 0; i < s.Len(); ++i)
	{
		if(!in_t[s[i]] && (in_s[s[i]] == -1))
		//字符不在t中 && 当前在s中未出现 
		{
			in_s[s[i]] = i; //记录第一次出现在s中的下标 
			r.Concat(s[i]); //concat至r后 
		}
	}
	return r;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	string s,t,r;
	cin >> s >> t;
	
	r = solve(s,t);
	for(int i=0;i<r.length();++i)
	{
		cout << r[i] << ":" << in_s[r[i]] << endl;
	}
	return 0;
}
