#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 1010
#define M 30010
#define INF 0x7fffffff
using namespace std;
int n,s,t;
int sz=1,to[M],pre[M],v[M],cost[M],last[N];
int dui[3000010],d[N];
bool mark[N];
int num[N];
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
	memset(mark,0,sizeof(mark));
	memset(d,127,sizeof(d));
	int inf=d[0],tou=1,wei=1,now,i; 
	dui[1]=t;d[t]=0;mark[t]=1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=last[now];
		while(i>0)
		{
			if(v[i^1] && d[to[i]]>d[now]-cost[i])
			{
				d[to[i]]=d[now]-cost[i];
				if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
			}
			i=pre[i];
		}
		mark[now]=0;
	}
	if(d[s]==inf)  return 0; return 1;
}
int dfs(int x,int F)
{
	mark[x]=1;
	if(x==t) return F;
	int used=0,w,i=last[x];
	while(i>0)
	{
		if(v[i]>0 && !mark[to[i]] && d[x]-cost[i]==d[to[i]])
		{
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(F==used)  return F;
		}
	    i=pre[i];
	}
	return used;
}
int mincostflow()
{
	int tmp=0;
	while(spfa())
	{
		mark[t]=1;
		while(mark[t])
		{
			memset(mark,0,sizeof(mark));
			tmp+=dfs(s,INF)*d[s];
		}
	}
	return tmp;
}
int main()
{
	int T,i;
	scanf("%d",&T);
	while(T--)
	{
		sz=1;memset(last,0,sizeof(last));
		scanf("%d",&n);
		for(i=1;i<=n;i++) scanf("%d",&num[i]);
		s=n+1;t=s+1;
		for(i=1;i<=n;i++)  
		{
			if(num[i]<1)  Ins(i,t,1,0);
			if(num[i]>1)  Ins(s,i,num[i]-1,0);
			if(i-1>0)  Ins(i,i-1,INF,1); else Ins(i,n,INF,1);
			if(i+1<=n)  Ins(i,i+1,INF,1); else Ins(i,1,INF,1);
		}	
		printf("%d\n",mincostflow());
	}
	system("pause");
	return 0;
}
