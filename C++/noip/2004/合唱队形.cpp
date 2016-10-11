#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,ans;
int h[110];
int zheng[110],fang[110];
int main()
{
	int i,j,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&h[i]);
	for(i=1;i<=n;i++)
	{
		zheng[i]=1;
		for(j=1;j<i;j++)
		{
			if(h[j]<h[i]) zheng[i]=max(zheng[i],zheng[j]+1);
		}
	}
	for(i=n;i>=1;i--)
	{
		fang[i]=1;
		for(j=n;j>i;j--)
		{
			if(h[j]<h[i]) fang[i]=max(fang[i],fang[j]+1);
		}
	}
	for(i=1;i<=n;i++)
	{
		if(zheng[i]+fang[i]-1>ans)  ans=zheng[i]+fang[i]-1;
	}
	cout<<n-ans<<endl;
	//system("pause");
	return 0;
}