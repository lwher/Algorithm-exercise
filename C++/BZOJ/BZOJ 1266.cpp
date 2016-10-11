#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int to[550010],pre[550010],last[510];
int v[550010],t[550010];
int n,m;
int sz=1,sz1;
int d[510];
bool mark[510];
int from[550010],qu[550010],ss[550010],last1[510],zhi[550010];
int h[510],vh[510];
void cl(int a,int b,int cc,int vv)
{
     sz1++;
     from[sz1]=a;
     qu[sz1]=b;
     t[sz1]=cc;
     zhi[sz1]=vv;
     ss[sz1]=last1[a];
     last1[a]=sz1;
}
void Ins(int a,int b,int cc)
{
	sz++;
	to[sz]=b;
	pre[sz]=last[a];
	v[sz]=cc;
	last[a]=sz;
	sz++;
	to[sz]=a;
	pre[sz]=last[b];
	v[sz]=0;
	last[b]=sz;
}
void spfa()
{
	memset(d,127,sizeof(d));
	memset(mark,0,sizeof(mark));
	int dui[10010],now,i;
	int tou=1,wei=1;
	dui[1]=1;
	d[1]=0;
	while(tou<=wei)
	{
		now=dui[tou];
		i=last1[now];
		while(i>0)
		{
			if(d[now]+t[i]<d[qu[i]])
			{
				d[qu[i]]=d[now]+t[i];
				if(!mark[qu[i]])
				{wei++;dui[wei]=qu[i];}
			}
			i=ss[i];
		}
		mark[now]=0;
		tou++;
	}
}
void build()
{
     int i;
     for(i=1;i<=sz1;i++)
     {
        if(d[from[i]]+t[i]==d[qu[i]])
        Ins(from[i],qu[i],zhi[i]);
     }
}
void init()
{
	scanf("%d%d",&n,&m);
	int A,B,C,D;
	int i;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%d",&A,&B,&C,&D);
		{cl(A,B,C,D);cl(B,A,C,D);}
	}
	spfa();
	build();
}
int dfs(int x,int F)
{
	if(x==n) {return F;}
	int used=0,w;
	int i=last[x];
	while(i>0)
	{
		if(v[i]>0 && h[x]-1==h[to[i]])
		{
			w=F-used;
			w=dfs(to[i],min(v[i],w));
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)
			return F;
		}
		i=pre[i];
	}
	vh[h[x]]--;
	if(!vh[h[x]])
	h[1]=n;
	vh[++h[x]]++;
	return used;
}
void solve()
{
	printf("%d\n",d[n]);
    int ans=0;
    vh[0]=n;
    while(h[1]<n)
    ans+=dfs(1,INF);
	printf("%d\n",ans);
}
int main()
{
	init();
	solve();
	system("pause");
	return 0;
}
