#include <bits/stdc++.h>
using namespace std;

int quick(int a,int b,int c)
{
	int ans=1;   //��¼���
	a=a%c;   //Ԥ����ʹ��a����c�����ݷ�Χ֮��
	while(b!=0)
	{
		if(b&1) ans=(ans*a)%c;   //���b�Ķ�����λ����0����ô���ǵĽ����Ҫ���������
		b>>=1;    //�����Ƶ���λ�������൱��ÿ�γ���2���ö����ƿ����������ǲ��ϵı���b�Ķ�����λ
		a=(a*a)%c;   //���ϵļӱ�
	}
	return ans;
}

int main()
{
	cin >> a >> b >> c;
	cout << quick(a,b,c) << endl;

	return 0;
}

