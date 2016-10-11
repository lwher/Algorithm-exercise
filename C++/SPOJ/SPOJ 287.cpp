#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 510
#define M 600010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
int A[M],B[M],yh[N],yhnum;
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
void build(int x)
{
	int i,j;
	sz=1;memset(last,0,sizeof(last));
	Ins(1,t,INF);
	for(i=1;i<=yhnum;i++)  Ins(s,yh[i],1);
	for(i=1;i<=m;i++) {Ins(A[i],B[i],x); Ins(B[i],A[i],x);}
} 
int main()
{
	int i,j,k,a,b;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&yhnum);
		for(i=1;i<=yhnum;i++)  scanf("%d",&yh[i]);
		for(i=1;i<=m;i++)  scanf("%d%d",&A[i],&B[i]);
		int l=0,r=yhnum,mid;
		s=n+1;t=s+1;
		while(l+1<r)
		{
			mid=(l+r)>>1;
			build(mid);
			if(sap()==yhnum)  r=mid;
			else l=mid;
		}
		build(l);if(sap()==yhnum)  printf("%d\n",l); else printf("%d\n",r);
    }
	system("pause");
	return 0;
}
