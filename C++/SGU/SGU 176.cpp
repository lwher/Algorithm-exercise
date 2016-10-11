#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#define N 30010
#define INF 0x7fffffff
using namespace std;
int n,m,sz=1;
int s,t;
int to[N],pre[N],last[110],v[N],low[N];
int in[N],h[N],gap[N];
int dui[110];
int sum;
void Ins(int a,int b,int c,int d)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
	if(d) low[sz]=c;
	v[sz]=c-low[sz];
	in[a]-=low[sz];in[b]+=low[sz];
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
int SAP()
{
	int now=0;
	bfs();
	while(h[s]<=n+2)
	{
		now+=dfs(s,INF);
	}
	return now;
}
void solve()
{
	int i;
	int f1=0,f2=0;
	s=0;t=n+1;
	for(i=1;i<=n;i++)
	{
		if(in[i]>0) 
		{Ins(s,i,in[i],0);sum+=in[i];}
		else
		if(in[i]<0)
		{Ins(i,t,(-1)*in[i],0);}
	}
	
	f1=SAP();
	memset(h,0,sizeof(h));
	memset(gap,0,sizeof(gap));
	Ins(n,1,INF,0);
	
	f2=SAP();
	if(f1+f2!=sum)  {printf("Impossible\n");return;}
	printf("%d\n",v[sz]);
	for(i=2;i<=2*m+1;i+=2)
	printf("%d ",v[i^1]+low[i]);
	cout<<endl;
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
