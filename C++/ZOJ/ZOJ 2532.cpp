#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 110
#define M 10010
#define INF 0x7fffffff
using namespace std;
int n,m,l,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N],mark[N],ans[M],A[M],B[M];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
	memset(h,-1,sizeof(h));
	memset(gap,0,sizeof(gap));
	int tou=1,wei=1,now,i;
	dui[1]=t;h[t]=1;gap[1]=1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=last[now];
		while(i>0)
		{
			if(h[to[i]]==-1)
			{
				h[to[i]]=h[now]+1;
				gap[h[now]+1]++;
				dui[++wei]=to[i];
			}
			i=pre[i];
		}
	}
}
int dfs(int x,int F)
{
	if(x==t)  return F;
	int i,used=0,w;
	i=last[x];
	while(i>0)
	{
		if(v[i] && h[x]-1==h[to[i]])
		{
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)  return F;
		}
		i=pre[i];
	}
	gap[h[x]]--;
	if(gap[h[x]]==0)  h[s]=n+2;
	gap[++h[x]]++;
	return used;
}
int sap()
{
	int tmp=0;
	bfs();
	while(h[s]<n+2)  tmp+=dfs(s,INF);
	return tmp;
}
void dfs1(int x)
{
	int i=last[x];
	mark[x]=1;
	while(i>0)
	{
		if(mark[to[i]]==0 && v[i]>0)  dfs1(to[i]);
		i=pre[i];
	}
}
void dfs2(int x)
{
	int i=last[x];
	mark[x]=2;
	while(i>0)
	{
		if(mark[to[i]]==0 && v[i^1]>0)  dfs2(to[i]);
		i=pre[i];
	}
}
int main()
{
	int T,i,j,k,a,b,c;
	while(scanf("%d%d%d",&n,&m,&l))
	{
		if(n==0 && m==0 && l==0)  break;
		s=n+m+1;t=0;
		sz=1;memset(last,0,sizeof(last));
		for(i=1;i<=l;i++)
		{
			scanf("%d%d%d",&a,&b,&c); Ins(a,b,c);
			A[i]=a;B[i]=b;
		}
		for(i=1;i<=n;i++)  Ins(s,i,INF);
		n=n+m+2;
		sap();
		memset(mark,0,sizeof(mark));
		dfs1(s);
		dfs2(t);
		ans[0]=0;
		for(i=1;i<=l;i++)
		{
			if(mark[A[i]]==1 && mark[B[i]]==2)   ans[++ans[0]]=i; 
		}
		if(ans[0]==0)  printf("\n"); else
		{
			for(i=1;i<ans[0];i++)  printf("%d ",ans[i]); printf("%d\n",ans[ans[0]]);
		}
	}
	system("pause");
	return 0;
}
