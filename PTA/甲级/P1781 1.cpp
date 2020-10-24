#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,xv=1;
    int i;
    string score,max;
    int lenscore,maxlen;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        cin >> score;
        lenscore=score.length();
        maxlen=max.length();
        
        if(lenscore>maxlen || (lenscore>=maxlen && score>max) )//比较字符串长度
        {
            max=score;
            xv=i+1;
        }
    }
    
    cout << xv << endl;
    cout << max <<endl;
    
    return 0;
}

