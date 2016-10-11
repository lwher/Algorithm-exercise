#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 70010
#define M 300010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
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
	if(gap[h[x]]==0)  h[s]=t+2;
	gap[++h[x]]++;
	return used;
}
int sap()
{
	int tmp=0;
	bfs();
	while(h[s]<t+2)  tmp+=dfs(s,INF);
	return tmp;
}
int main()
{
	int T,i,j,k,a,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(n<3)  {printf("NO\n");continue;}
		sz=1;memset(last,0,sizeof(last));
		s=n+n+1;t=s+1;
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);  if(a>n || b>n)  continue;
			Ins(a+n,b,INF);Ins(b+n,a,INF);
		}
		for(i=1;i<=n;i++)  Ins(i,i+n,1);
		Ins(s,2+n,2);Ins(1+n,t,1);Ins(3+n,t,1);
		if(sap()==2)  printf("YES\n"); else printf("NO\n");
	}
	system("pause");
	return 0;
}
