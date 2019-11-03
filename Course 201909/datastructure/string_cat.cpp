#include <bits/stdc++.h>
using namespace std;

void string_cat(list<char> s,list<char>& t,char tosearch)
{
	list<char>::iterator ptr_t;
	for(ptr_t = t.begin();ptr_t != t.end(); ++ptr_t)
	{
		if(*ptr_t == tosearch) //如果找到目标字符 
		{
			++ptr_t; //移动至下一位开始插入 
			for(list<char>::iterator ptr_s = s.begin();ptr_s != s.end(); ++ptr_s)
				t.insert(ptr_t,*ptr_s); //按序插入s字符
			return;
		} 
	}
	if(ptr_t == t.end()) //至t字符串结尾 未找到目标字符 
		for(list<char>::iterator ptr_s = s.begin();ptr_s != s.end();++ptr_s)
			t.insert(ptr_t,*ptr_s); //按序插入s字符
	return;
}

int main()
{
	std::ios::sync_with_stdio(false);
	
	list<char> s,t;
	string s_s,t_s;
	cin >> s_s >> t_s;
	for(int i=0;i<s_s.length();++i) s.push_back(s_s[i]);
	for(int i=0;i<t_s.length();++i) t.push_back(t_s[i]);
	
	string_cat(s,t,'a');

	for(list<char>::iterator ptr_t = t.begin();ptr_t != t.end();++ptr_t) cout << *ptr_t;
	
	return 0;
}

