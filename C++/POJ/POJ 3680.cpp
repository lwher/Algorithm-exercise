#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,k,s,t,ans;
int sz=1,to[10010],pre[10010],v[10010],cost[10010],last[510];
int dui[100010],d[510];
bool mark[510];
int shu[510],num[510],top,tot,L[210],R[210],quan[210];
void Ins(int a,int b,int c,int e)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;cost[sz]=e;last[a]=sz;
	sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;cost[sz]=-e;last[b]=sz;
}
bool spfa()
{
	memset(d,-1,sizeof(d));
	memset(mark,0,sizeof(mark));
	int tou=1,wei=1,i,now;
	dui[1]=t;mark[t]=1;d[t]=0;
	while(tou<=wei)
	{
		now=dui[tou];tou++;
		i=last[now];
		while(i>0)
		{
			if(v[i^1]>0 && d[now]-cost[i]>d[to[i]])
			{
				d[to[i]]=d[now]-cost[i];
				if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
			}
			i=pre[i];
		}
		mark[now]=0;
	}
	if(d[s]==-1)  return 0;  return 1;
}
int dfs(int x,int F)
{
	if(x==t)  {mark[t]=1;return F;}
	mark[x]=1;
	int i=last[x],used=0,w;
	while(i>0)
	{
		if(v[i]>0 && !mark[to[i]] && d[x]-cost[i]==d[to[i]])
		{
			w=min(F-used,v[i]);
			w=dfs(to[i],w);
			used+=w;
			v[i]-=w;
			v[i^1]+=w;
			if(used==F)  return F;
		}
		i=pre[i];
	}
	return used;
}
void ZKW()
{
	while(spfa())
	{
		mark[t]=1;
		while(mark[t])
		{
			memset(mark,0,sizeof(mark));
			ans+=dfs(s,INF)*d[s];
		}
    }
    printf("%d\n",ans);
}
int find(int x)
{
	int l=1,r=tot,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(num[mid]==x)  return mid;
		if(num[mid]>x)  r=mid;
		else l=mid;
	}
	if(num[r]==x) return r; return l;
}
int main()
{
	int T,i,a,b,c;
	scanf("%d",&T);
	while(T--)
	{
		top=0;sz=1;tot=0;ans=0;
		memset(last,0,sizeof(last));
		scanf("%d%d",&n,&k);
		for(i=1;i<=n;i++)
		{
			scanf("%d%d%d",&L[i],&R[i],&quan[i]);
			shu[++top]=L[i];shu[++top]=R[i];
		}
		sort(shu+1,shu+1+top);
		num[++tot]=shu[1];
		for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
		s=tot+1;t=s+1;
		for(i=1;i<tot;i++)  Ins(i,i+1,k,0);
		Ins(s,1,k,0);Ins(tot,t,k,0);
		for(i=1;i<=n;i++)  Ins(find(L[i]),find(R[i]),1,quan[i]);
		ZKW();
	}
	//system("pause");
	return 0;
}

