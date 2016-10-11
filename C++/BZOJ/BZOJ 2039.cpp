#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define INF 1LL<<50
using namespace std;
int n,s,t,cost[1010];
long long e[1010][1010],v[3000010],ans,sum[1010];
int sz=1,to[3000010],pre[3000010],last[1010],lost[1010];
int dui[1010],h[1010],gap[1010];
void Ins(int a,int b,long long c)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;last[b]=sz;
}
long long min(long long a,long long b)
{
    if(a<b) return a; return b;
}
void bfs()
{
    memset(h,-1,sizeof(h));
    int tou=1,wei=1,now,i;
    dui[1]=t;h[t]=1;gap[1]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        if(h[to[i]]==-1)
        {
            h[to[i]]=h[now]+1;
            gap[h[to[i]]]++;
            dui[++wei]=to[i];
        }
    }
}
long long dfs(int x,long long F)
{
    if(x==t) return F;
    long long used=0,w;int i;
    for(i=lost[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(F-used,v[i]);
        w=dfs(to[i],w);
        used+=w;
        v[i]-=w; 
        if(v[i]>0)  lost[x]=i;
        v[i^1]+=w;
        if(F==used)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++; lost[x]=last[x];
    return used;
}
long long SAP()
{
    int i;long long tmp=0;
    bfs();
    for(i=1;i<=t;i++)  lost[i]=last[i];
    while(h[s]<t+2)  tmp+=dfs(s,INF);
    return tmp; 
}
void init()
{
    int i,j;
    scanf("%d",&n);
    s=n+1;t=s+1;
    for(i=1;i<=n;i++)  {scanf("%d",&cost[i]);Ins(i,t,cost[i]);}
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  
    {
        scanf("%lld",&e[i][j]); 
        if(e[i][j]>0) Ins(i,j,e[i][j]*2);
        sum[i]+=e[i][j];ans+=e[i][j];
    }
    for(i=1;i<=n;i++)  Ins(s,i,sum[i]);
}
int main()
{
    init();
    printf("%lld\n",ans-SAP());
    return 0;
}