#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int sz,to[2010],pre[2010],last[1010];
int fa[1010],f[1010][1010],v[1010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dp(int x)
{
	int i=last[x],j;
	while(i>0)
	{
		for(j=1;j<=m;j++)  f[to[i]][j]=f[x][j];
		dp(to[i]);
		for(j=1;j<=m;j++)  f[x][j]=max(f[x][j],f[to[i]][j-1]+v[to[i]]);
		i=pre[i];
	}
}
int main()
{
	int i,j,s,a;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&v[i],&s);
		for(j=1;j<=s;j++)  
		{
			scanf("%d",&a); Ins(i,a);
		}
	}
	Ins(0,1);
	dp(0);
	int ans=0;
	for(i=0;i<=m;i++)  ans=max(ans,f[0][i]);
	printf("%d\n",ans);
	//system("pause");
	return 0;
}