#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 50010
#define M 3000010
#define INF 0x7fffffff
using namespace std;
int n,m,ss,s,t;
int sz=1,to[M],pre[M],v[M],last[N];
int h[N],gap[N],dui[N];
int C[51],x[51],y[51],D,W;
bool map[51][51],mark[51];
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
void dfs(int x)
{
     int i;
     mark[x]=1;
     for(i=1;i<=n;i++)  if(map[x][i] && !mark[i])  dfs(i);
}
void build(int tt)
{
     ss=(n+n)*tt+1;s=ss+1;t=s+1;
     int i,j,k;
     sz=1;memset(last,0,sizeof(last));
     Ins(s,ss,m);
     for(i=1;i<=n;i++)  if(y[i]<=D)
     {
         for(j=1;j<tt;j++)  Ins(ss,(j-1)*(n+n)+i,INF);
     }
     for(i=1;i<=n;i++)  if(W-y[i]<=D)
     {
         for(j=1;j<tt;j++)  Ins((j-1)*(n+n)+i+n,t,INF);
     }
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
     if(map[i][j])
     {
        for(k=1;k<tt;k++)   Ins((k-1)*(n+n)+i+n,k*(n+n)+j,INF);
     }
     for(k=1;k<=tt;k++) for(i=1;i<=n;i++)  Ins((k-1)*(n+n)+i,(k-1)*(n+n)+i+n,C[i]);
}
int main()
{
	int i,j,k,a,b;
	scanf("%d%d%d%d",&n,&m,&D,&W);
	for(i=1;i<=n;i++)  
	{
        scanf("%d%d%d",&x[i],&y[i],&C[i]);
        if(C[i]<=0)  {n--;i--;}  
    }
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
    {
       if((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])<=D*D)  map[i][j]=1;
    }
    for(i=1;i<=n;i++)  if(y[i]<=D)  dfs(i);
    bool o=0;
    for(i=1;i<=n;i++)  if(W-y[i]<=D && mark[i])  o=1; 
    if(W<=D)  printf("1\n");
    else
    if(!o)  printf("IMPOSSIBLE\n");
    else
    {
        for(i=1;i<=50000;i++) 
        {
            build(i);
            if(sap()==m)  {printf("%d\n",i);break;}
        } 
    } 
	system("pause");
	return 0;
}
