#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 100010
#define INF 0x7fffffff
using namespace std;
int n,m,sz=1;
int s,t;
int to[N],pre[N],last[210],v[N],low[N];
int in[N],h[N],gap[N];
int dui[210];
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;low[sz]=c;v[sz]=d-c;
	in[a]+=low[sz];in[b]-=low[sz];
	sz++;to[sz]=a;pre[sz]=last[b];last[b]=sz;v[sz]=0;
}
void bfs()
{
	int i,now,tou=1,wei=1;
	h[t]=1;
	gap[1]++;
	dui[1]=t;
	while(tou<=wei)
	{
		now=dui[tou];
		i=last[now];
		while(i>0)
		{
			if(!h[to[i]])
			{
				h[to[i]]=h[now]+1;gap[h[to[i]]]++;wei++;dui[wei]=to[i];
			}
			i=pre[i];
		}
		tou++;
	}
}
int dfs(int x,int F)
{
	int i,used=0,w;
	if(x==t)  return F;
	i=last[x];
	while(i>0)
	{
		if(v[i]>0 && h[x]-1==h[to[i]])
		{
			w=F-used;
			w=dfs(to[i],min(w,v[i]));
			v[i]-=w;
			v[i^1]+=w;
			used+=w;
			if(used==F)
			return F;
		}
		i=pre[i];
	}
	gap[h[x]]--;
	if(gap[h[x]]==0)  
	h[s]=n+3;
	gap[++h[x]]++;
	return used;
}
void SAP()
{
	bfs();
	while(h[s]<=n+2)
	{
		dfs(s,INF);
	}
}
void solve()
{
	int i;
	
	s=0;t=n+1;
	for(i=1;i<=n;i++)
	{
		if(in[i]<0) 
		Ins(s,i,0,in[i]*(-1));
		else
		if(in[i]>0)
		Ins(i,t,0,in[i]);
	}
	SAP();
	i=last[s];
	while(i>0)
	{
		if(v[i])
		{printf("NO\n");return;}
		i=pre[i];
	}
	printf("YES\n");
	for(i=2;i<=2*m+1;i+=2)
	printf("%d\n",low[i]+v[i^1]);
}
void init()
{
	int i;
	int a,b,c,d;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		Ins(a,b,c,d);
	}
}
int main()
{
	init();
	solve();
	system("pause");
	return 0;
}
