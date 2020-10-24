#include <bits/stdc++.h>
using namespace std;

inline double cal(double x1,double y1,double x2,double y2)
{
	return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

int n;
double ans=-1,point[18][2]; 
double dis[18][18];
double dp[18][18];

int main()
{
	std::ios::sync_with_stdio(false);
	cin >> n;

	for(int i=1;i<=n;i++) cin >> point[i][0] >> point[i][1];
	
	for(int i=0;i<=n;i++)
	{
		dis[i][i]=0;
		for(int j=i+1;j<=n;j++)
		{
			dis[i][j]=cal(point[i][0],point[i][1],point[j][0],point[j][1]);
			dis[j][i]=dis[i][j];
		}
	}
	
	//dp
	int total=(1<<(n+1)); //2^n种状态 
	for(int s=1;s<total;s++) //总共的状态数 
	{
		for(int i=1;i<=n;i++) //选择下一个加入集合 
		{
			if(s&(1<<(i-1))) continue; //如果已在集合中
			if(s==(1<<(i-1)))
			{
				dp[i][s]=0;
				continue;
			}
			
			for(int j=0;j<n;j++)
			{
				if((s&(1<<(j-1)))==0||i==j) continue;
				dp[i][s]=min(dp[i][s],dp[j][s-(1<<(i-1))]+dis[i][j]);
			} 
		}
	}
	
	for(int i=1;i<=n;i++)
	{
        if(dp[total-1][i]+dis[i][0]<ans)
		{
            double s=dp[i][(1<<n)-1]+dis[i][0];
            if(ans==-1||ans>s) ans=s;
        }
    }
    
    cout << ans << endl;

	return 0;
}

