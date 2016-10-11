#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<memory.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(a) ((a)>0?(a):(-(a)))
#define sqr(a) (a)*(a)
#define Dist(a,b,c,d) sqrt(sqr((a)-(c))+sqr((b)-(d)))
#define Dis(a,b,c,d) abs((a)-(c))+abs((b)-(d))
#define eps 1e-8
#define S 10000
#define MAX 2139062143
#define N 1004
#define M 100004
using namespace std;
int n,m,ans;
bool f[M];
int c[N],s[N];
int main()
{
	int i,j,k;
	while(scanf("%d%d",&n,&m) && n && m)
	{
		ans=0;
		memset(f,0,m+1);f[0]=1;
		for(i=1;i<=n;i++)
			scanf("%d",&c[i]);
		for(i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(i=1;i<=n;i++)
		{
			if(c[i]>m)continue;
			if(c[i]*s[i]>=m)
				for(j=c[i];j<=m;j++)
					f[j]|=f[j-c[i]];
			else
			{
				k=0;
				while((1<<k)<=s[i])
				{
					for(j=m;j>=c[i]*(1<<k);j--)
						f[j]|=f[j-c[i]*(1<<k)];
					s[i]-=1<<k;
					k++;
				}
				if(s[i]>0)
					for(j=m;j>=c[i]*s[i];j--)
						f[j]|=f[j-c[i]*s[i]];
			}
		}
		for(i=1;i<=m;i++)
			if(f[i])
				ans++;
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}

