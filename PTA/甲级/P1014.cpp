#include <bits/stdc++.h>
using namespace std;

struct node
{
	int no;
	int timetake;
	int timeleave;
}customer[1005];

int n,m,k,q,tim=0;
int bank[15][25];
queue<int> waiting;

string convert(int time)
{
	if(time > 540) return "Sorry";
	string ans;
	if(time < 120) ans.append("0");
	ans.append(to_string(8+time/60));
	ans.append(":");
	if(time%60 < 10) ans.append("0");
	ans.append(to_string(time%60));
	return ans;
}

void reload()
{
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(waiting.empty()) return;
			if(bank[i][j] == 0)
			{
				bank[i][j] = waiting.front();
				waiting.pop();
			}
		}
	}
	return;
}

void finish()
{
	for(int i=0;i<n;++i)
	{
		if(customer[bank[0][i]].timeleave <= tim)
		{
			for(int j=0;j<=m;++j)
			{
				bank[j][i] = bank[j+1][i];
				if(j==0) customer[bank[0][i]].timeleave = tim + customer[bank[0][i]].timetake;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n >> m >> k >> q;
	
	for(int i = 1;i<=k;++i) customer[i].no = i;
	for(int i = 1;i<=k;++i) cin >> customer[i].timetake; 
	
	
	for(int i = 1;i<=k;++i) waiting.push(customer[i].no);
	
	//init
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(waiting.empty()) break;
			if(bank[i][j] == 0)
			{
				bank[i][j] = waiting.front();
				waiting.pop();
			}
		}
	}
	for(int i=0;i<n;++i) customer[bank[0][i]].timeleave = tim + customer[bank[0][i]].timetake;
	
	//main
	for(tim=0;tim<=540;++tim)
	{
		finish();
		reload();
	}
	
	//remain
	for(int i=0;i<m;++i)
		for(int j=0;j<n;++j)
		{
			if(bank[i][j]) customer[bank[i][j]].timeleave = 541;
		}
	
	while(q--)
	{
		int tosearch;
		cin >> tosearch;
		cout << convert(customer[tosearch].timeleave) << endl;
	}

	return 0;
}

