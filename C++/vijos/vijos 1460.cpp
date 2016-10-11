#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,sum;
long long ans;
int sz,to[10010],pre[10010],v[10010],last[10010];
int fa[10010][16],deep[10010];
long long dist[10010];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void dfs(int x)
{
	int i=last[x];
	while(i>0)
	{
		dist[to[i]]=dist[x]+v[i];
		fa[to[i]][0]=x;
		deep[to[i]]=deep[x]+1;
		dfs(to[i]);
		i=pre[i];
	}
}
int LCA(int u,int v)
{
	int i,x;
	if(deep[u]>deep[v])
	{
		x=deep[u]-deep[v];
	    for(i=15;i>=0;i--)
		{
			if(x>=(1<<i))  {x-=(1<<i);u=fa[u][i];}
		}	
	}
	if(deep[u]<deep[v])
	{
		x=deep[v]-deep[u];
	    for(i=15;i>=0;i--)
		{
			if(x>=(1<<i))  {x-=(1<<i);v=fa[v][i];}
		}	
	}
	for(i=15;i>=0;i--)
	{
		if(deep[u]>(1<<i) && fa[u][i]!=fa[v][i])  {u=fa[u][i];v=fa[v][i];}
	}
	if(u==v)  return u;
	return fa[u][0];
}
int main()
{
	int i,j,a,b,c;
	scanf("%d%d",&n,&m);
	for(i=1;i<n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);
	}
	deep[1]=1;
	dfs(1);
	for(i=1;i<=15;i++)  for(j=1;j<=n;j++)  fa[j][i]=fa[fa[j][i-1]][i-1];
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		c=LCA(a,b);
		if(c==a)
		{
			sum++;ans+=dist[b]-dist[a];
		}
	}
	cout<<sum<<endl;
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
