#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
struct sth
{
       int a,b,v,cost;
}lu[5010];
int n,m,k,s,t;
int sz=1,to[30010],v[30010],cost[30010],pre[30010],last[1010];
int dui[100010],h[1010],gap[1010],d[1010];
bool mark[1010];
void Ins(int a,int b,int c,int d)
{
     sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     int i,now,tou=1,wei=1;
     memset(h,-1,sizeof(h));
     dui[1]=t;h[t]=0;gap[0]=1;
     while(tou<=wei)
     {
          now=dui[tou];tou++;
          i=last[now];
          while(i>0)
          {
               if(h[to[i]]!=-1)
               {
                   h[to[i]]=h[now]+1;
                   gap[h[to[i]]]++;
                   dui[++wei]=to[i];
               }
               i=pre[i];
          }
     }
}
int sap_dfs(int x,int F)
{
    if(x==t)  return F;
    int i=last[x],used=0,w;
    while(i>0)
    {
        if(v[i]>0 && h[to[i]]==h[x]-1)
        {
             w=F-used;
             w=sap_dfs(to[i],min(v[i],w));
             v[i]-=w;
             v[i^1]+=w;
             used+=w;
             if(used==F)  return F;
        }
        i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)  h[1]=n+1;
    gap[++h[x]]++;
    return used;
}
int SAP()
{
    int ans=0;
    bfs();
    while(h[1]<n+1)  ans+=sap_dfs(1,INF);
    return ans;
}
bool spfa()
{
     int tou=1,wei=1,p,i,now;
     memset(mark,0,sizeof(mark));
     memset(d,127,sizeof(d));
     dui[1]=t;d[t]=0;p=d[0];mark[t]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         i=last[now];
         while(i>0)
         {
             if(v[i^1] && d[to[i]]>d[now]-cost[i])
             {
                  d[to[i]]=d[now]-cost[i];
                  if(!mark[to[i]])   mark[to[i]]=1,dui[++wei]=to[i];
             }
             i=pre[i];
         }
         mark[now]=0;
     }
     if(d[s]!=p)  return 1; return 0;
}
int mincost_dfs(int x,int F)
{
    if(x==t)  {mark[t]=1;return F;}
    int i=last[x],used=0,w;
    mark[x]=1;
    while(i>0)
    {
        if(v[i]>0 && !mark[to[i]] && d[to[i]]==d[x]-cost[i])
        {
             w=F-used;
             w=mincost_dfs(to[i],min(v[i],w));
             v[i]-=w;
             v[i^1]+=w;
             used+=w;
             if(used==F)  return F;
        }
        i=pre[i];
    }
    return used;
}
int mincostflow()
{
    int ans=0;
    while(spfa())
    {
        mark[t]=1;
        while(mark[t])
        {
            memset(mark,0,sizeof(mark));
            ans+=mincost_dfs(s,INF)*d[s];
        }
    }
    return ans;
}
void solve()
{
     int i,a,b,c,d;
     scanf("%d%d%d",&n,&m,&k);
     s=n+1;t=n;
     for(i=1;i<=m;i++)  
     {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        lu[i].a=a;lu[i].b=b;lu[i].v=c;lu[i].cost=d;
        Ins(a,b,c,0);
     }
     printf("%d ",SAP());
     for(i=1;i<=m;i++)  Ins(lu[i].a,lu[i].b,10000000,lu[i].cost);
     Ins(s,1,k,0);
     printf("%d\n",mincostflow());
}
int main()
{
    solve();
    system("pause");
    return 0;
}
