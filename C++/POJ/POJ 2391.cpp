#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 510
#define M 500010
#define INF 0x7fffffff
#define inf 2000000000000LL
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
long long map[210][210];
int A[210],B[210],sum;
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
void build(long long x)
{
	int i,j;
	s=n*2+1;t=s+1;
	sz=1;memset(last,0,sizeof(last));
	for(i=1;i<=n;i++)  {Ins(s,i,A[i]);Ins(i+n,t,B[i]);}
	for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  if(map[i][j]<=x)  Ins(i,j+n,INF);
	
}
int main()
{
	int i,j,k,a,b;long long c;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  {scanf("%d%d",&A[i],&B[i]);sum+=A[i];}
	for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  if(i==j)  map[i][j]=0; else map[i][j]=inf;
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%I64d",&a,&b,&c); map[a][b]=min(map[a][b],c);map[b][a]=min(map[b][a],c);
	}
	for(k=1;k<=n;k++) for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
	if(map[i][j]>map[i][k]+map[k][j])  map[i][j]=map[i][k]+map[k][j];	
	
	long long l=0,r=2000000000000LL-1,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		build(mid);
		if(sap()==sum)  r=mid;
		else l=mid;
	}
	build(l); if(sap()==sum)  printf("%I64d\n",l); else if(r!=2000000000000LL-1)printf("%I64d\n",r);  else printf("-1\n");
	//system("pause");
	return 0;
}

