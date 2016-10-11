#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 10000000
using namespace std;
int n,k,cc,m;
int to[320000],last[320],h[320],pre[320000],dui[320];
int  dis[320][320];
int v[320000];
int sz=1;
int tou=1,wei=1;
int ans=0;
void Ins(int a,int b,int c)
{
     sz++;
     to[sz]=b;
     v[sz]=c;
     pre[sz]=last[a];
     last[a]=sz;
     sz++;
     to[sz]=a;
     v[sz]=0;
     pre[sz]=last[b];
     last[b]=sz;
}
bool bfs()
{
    int i,now;
    memset(h,-1,sizeof(h));
    tou=1;wei=1;
    dui[1]=308;
    h[308]=1;
    while(tou<=wei)
    {
       now=dui[tou];
       i=last[now];
       while(i>0)
       {
         if(v[i]>0 && h[to[i]]<0)
         {
           wei++;
           dui[wei]=to[i];
           h[to[i]]=h[now]+1;
         }
         i=pre[i];
       }
       tou++;
    }
    if(h[309]==-1)
    return 0;
    else 
    return 1;
}
int dfs(int x,int F)
{
    if(x==309)  return F;
    int i;
    i=last[x];
    int w,used=0;
    while(i>0)
    {
       if(v[i]>0 && h[to[i]]==h[x]+1)
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
    if(used==0)  h[x]=-1;
    return used;
}
void build(int x)
{
    int i,j;
    sz=1;
    ans=0;
    memset(last,0,sizeof(last));
    for(i=1;i<=k;i++)   Ins(i,309,m);
    for(i=k+1;i<=n;i++)   Ins(308,i,1);
    
	
    for(j=k+1;j<=n;j++)
    for(i=1;i<=k;i++)
    {
		if(dis[j][i]<=x)
		Ins(j,i,1);
	}
}
bool dinic()
{
    while(bfs())
    {ans+=dfs(308,INF);}
    if(ans==cc)
    return 1;
    else
    return 0;
}
int main()
{
    int i,j,a,b;
    while(scanf("%d%d%d",&k,&cc,&m)!=EOF)
    {
	n=k+cc;	
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		scanf("%d",&dis[i][j]);
		if(dis[i][j]==0)  dis[i][j]=INF;
	}
	for(a=1;a<=n;a++)
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	{
		if(dis[i][a]+dis[a][j]<dis[i][j])
		dis[i][j]=dis[i][a]+dis[a][j];
	}
    int l=0,r=100000,mid;
    
    while(l<r)
    {
		if(l+1==r)  break;
		mid=(l+r)/2;
		build(mid);
		if(dinic())
		r=mid;
		else
		l=mid;
	}
	build(l);
	if(dinic())
	printf("%d\n",l);
	else
	printf("%d\n",r);
    }
  //  system("pause");
    return 0;
}

