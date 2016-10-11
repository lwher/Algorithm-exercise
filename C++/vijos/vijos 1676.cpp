#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
int c[4010],v[4010][4010],fl[4010][510],fr[4010][510],sum[4010];
void dfsl(int x)
{
	int i,j,p;
	for(i=1;i<=v[x][0];i++)
	{
		p=v[x][i];
		for(j=1;j<=k;j++)   fl[p][j]=fl[x][j];
		sum[p]=sum[x]+c[p];
		dfsl(p);
		for(j=1;j<=k;j++)   fl[x][j]=max(fl[x][j],fl[p][j-1]+c[p]);
	}
}
void dfsr(int x)
{
	int i,j,p;
	for(i=v[x][0];i>=1;i--)
	{
		p=v[x][i];
		for(j=1;j<=k;j++)   fr[p][j]=fr[x][j];
		dfsr(p);
		for(j=1;j<=k;j++)   fr[x][j]=max(fr[x][j],fr[p][j-1]+c[p]);
	}
}
int main()
{
	int i,j,fa;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&fa,&c[i]);
		if(fa)  v[fa][++v[fa][0]]=i;
	}
	sum[1]=c[1];
	dfsl(1);
	dfsr(1);
	int ans=0;
	for(i=1;i<=n;i++)
	if(v[i][0]==0)
	{
		for(j=0;j<=k;j++)  ans=max(ans,fl[i][j]+fr[i][k-j]+sum[i]);
	}
	printf("%d\n",ans);
	//system("pause");
	return 0;
}