#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
	int x,y;
}pe[110],ho[110];// pe:people  ho: house
int n,m,psz,hsz,s,t;
int sz,to[100010],pre[100010],v[100010],cost[100010],last[210];
char map[110][110];
int dui[300010],d[210]; bool mark[210];
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
	sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
int juli(sth a,sth b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}
void init()
{
	int i,j;hsz=0;psz=0;
	for(i=1;i<=n;i++)
	{
		scanf("%s",map[i]+1);
		for(j=1;j<=m;j++)  
		{
			if(map[i][j]=='H')  {ho[++hsz].x=i;ho[hsz].y=j;}
			if(map[i][j]=='m')  {pe[++psz].x=i;pe[psz].y=j;}
		}
	}
}
void build()
{
	sz=1;memset(last,0,sizeof(last));
	int i,j;s=hsz+psz+1;t=s+1;
	for(i=1;i<=psz;i++)  Ins(s,i,1,0);
	for(i=1;i<=hsz;i++)  Ins(i+psz,t,1,0);
	for(i=1;i<=psz;i++)  for(j=1;j<=hsz;j++)
	{
		Ins(i,j+psz,1,juli(pe[i],ho[j]));
	}
}
bool spfa()
{
	memset(d,127,sizeof(d));
	memset(mark,0,sizeof(mark));
	int tou=1,wei=1,now,i,inf=d[0];
	dui[1]=t;d[t]=0;mark[t]=1;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		for(i=last[now];i>0;i=pre[i])
		{
			if(v[i^1]>0 && d[now]-cost[i]<d[to[i]])
			{
				d[to[i]]=d[now]-cost[i];
				if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
			}
		}
		mark[now]=0;
	}
	if(d[s]==inf)  return 0;  return 1;
}
int dfs(int x,int F)
{
	mark[x]=1;
	if(x==t)  return F;
	int i,used=0,w;
	for(i=last[x];i>0;i=pre[i])
	{
		if(!mark[to[i]] && v[i]>0 && d[x]-cost[i]==d[to[i]])
		{
			w=min(v[i],F-used);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)  return F;
		}
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
	while(scanf("%d%d",&n,&m) && n && m)
	{
		init();
		build();				
		printf("%d\n",mincostflow());
	}
	//system("pause");
	return 0;
}