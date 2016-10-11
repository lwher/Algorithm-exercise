#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,ans;
int sz,to[2000010],pre[2000010],last[1010];
bool map[1010][1010],mark[1010],in[2000010];
int tt,dfn[1010],low[1010],color[1010];
int u[2000010],v[2000010],top;
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init()
{
	sz=0;memset(last,0,sizeof(last));
	memset(map,0,sizeof(map));
	int i,j,a,b;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		map[a][b]=1;map[b][a]=1;
	}
	for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  if(!map[i][j] && i!=j)  Ins(i,j);
}
bool dfs(int x)
{
	int i=last[x];
	while(i>0)
	{
		if(in[to[i]])
		{
			if(color[to[i]]==-1)
			{
				color[to[i]]=color[x]^1;
				if(!dfs(to[i]))  return 0;
			}
			else  if(color[to[i]]==color[x])  return 0;
	    }
		i=pre[i];
	}
	return 1;
}
void pd(int x,int y)
{
	memset(in,0,sizeof(in));
	int i,k=x;
	while(u[top]!=x || v[top]!=y)
	{
		in[u[top]]=1;in[v[top]]=1;
		top--;
	}
	in[x]=1;in[y]=1;top--;
	memset(color,-1,sizeof(color));
	color[k]=0;
	if(!dfs(k))
	{
		for(i=1;i<=n;i++)  if(in[i])  mark[i]=1;
	}
}
void Tarjan(int x,int fa)
{
	tt++;dfn[x]=tt;low[x]=tt;
	int i=last[x];
	while(i>0)
	{
		if(to[i]!=fa)
		{
			if(!dfn[to[i]])
			{
				u[++top]=x;v[top]=to[i];
				Tarjan(to[i],x);
				low[x]=min(low[x],low[to[i]]);
				if(low[to[i]]>=dfn[x])  pd(x,to[i]);
			}
			else  low[x]=min(low[x],dfn[to[i]]);
	    }
		i=pre[i];
	}
}
void solve()
{
	int i;
	top=0;tt=0;ans=0;
	memset(mark,0,sizeof(mark));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));			
	for(i=1;i<=n;i++)  if(!dfn[i])  Tarjan(i,0);
	for(i=1;i<=n;i++)  if(mark[i])  ans++;
	printf("%d\n",n-ans);
}
int main()
{
	while(scanf("%d%d",&n,&m))
	{
	   if(n==0 && m==0)  break;
	   init();
	   solve();
    }
	//system("pause");
	return 0;
}