#include <bits/stdc++.h>
using namespace std;

//concat len sub equal
#define ascii_max 128 //�ɼ��ַ� 
string solve(string s,string t)
{
	string r; //Ŀ���ַ��� 
	int in_s[ascii_max]; //���״γ�����s�� ���ڴ��ڼ�¼�±� 
	bool in_t[ascii_max]; //���ĳ�ַ��Ƿ���t�� 
	
	for(int i = 0; i < ascii_max; ++i) {in_t[i]=false; in_s[i] = -1;}
	//��ʼ���ַ���s�еı������ 
	for(int i = 0;i < t.Len(); ++i) in_t[t[i]] = true;
	//��������t������ 
	
	for(int i = 0; i < s.Len(); ++i)
	{
		if(!in_t[s[i]] && (in_s[s[i]] == -1))
		//�ַ�����t�� && ��ǰ��s��δ���� 
		{
			in_s[s[i]] = i; //��¼��һ�γ�����s�е��±� 
			r.Concat(s[i]); //concat��r�� 
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
