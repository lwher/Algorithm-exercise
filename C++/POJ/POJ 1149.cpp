#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 110
#define M 300010
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
int map[1010][1010],sum[1010],have[110];
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
	int i,k,a,j;
	scanf("%d%d",&m,&n);
	for(i=1;i<=m;i++)  scanf("%d",&sum[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		while(k--)
		{
			scanf("%d",&a);
			map[a][++map[a][0]]=i;
		}
		scanf("%d",&have[i]);
	}
	s=n+1;t=s+1;
	for(i=1;i<=m;i++)
	{
		if(map[i][0]==0)  continue;
		Ins(s,map[i][1],sum[i]);
		for(j=1;j<map[i][0];j++)  Ins(map[i][j],map[i][j+1],INF);
	}
	for(i=1;i<=n;i++)  Ins(i,t,have[i]);
	printf("%d\n",sap());
	//system("pause");
	return 0;
}

