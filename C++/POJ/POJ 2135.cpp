#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define M 1010
#define N 40010
#define INF 0x7f7f7f7f
using namespace std;
int n,m;
int s,t;
int from[N],to[N],last[M],dis[M],pre[N],dui[N],cost[N],former[M];
bool mark[M];
int v[N];
int sz=1;
int tou=1,wei=1;
long long ans=0;
void Ins(int a,int b,int c,int vv)
{
     sz++;
     from[sz]=a;
     to[sz]=b;
     v[sz]=c;
     pre[sz]=last[a];
     last[a]=sz;
     cost[sz]=vv;
     sz++;
     from[sz]=b;
     to[sz]=a;
     v[sz]=0;
     pre[sz]=last[b];
     last[b]=sz;
     cost[sz]=-vv;
}
bool spfa()
{
    int i,now;
    dis[t]=INF;
    for(i=1;i<=n;i++)
    dis[i]=INF;
    tou=1;wei=1;
    dui[1]=s;
    dis[s]=0;
    mark[s]=1;
    while(tou<=wei)
    {
       now=dui[tou];
       i=last[now];
       while(i>0)
       {
         if(v[i]>0 && dis[now]+cost[i]<dis[to[i]])
         {
           dis[to[i]]=dis[now]+cost[i];
           former[to[i]]=i;
           if(!mark[to[i]])
           {wei++;dui[wei]=to[i];}
         }
         i=pre[i];
       }
       mark[now]=0;
       tou++;
    }
    if(dis[t]==INF)
    return 0;
    else 
    return 1;
}
void mincostflow()
{
    int i,sum=INF;
    i=former[t];
    while(i>0)
    {
       sum=min(sum,v[i]);
       i=former[from[i]];
    }
    i=former[t];
    while(i>0)
    {
       v[i]-=sum;
       v[i^1]+=sum;
       ans+=sum*cost[i];
       i=former[from[i]];
    }
}
int main()
{
    int i,j,a,b,c;
    s=0;t=1003;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
      scanf("%d%d%d",&a,&b,&c);
      Ins(a,b,1,c);
      Ins(b,a,1,c);
    }
    Ins(s,1,2,0);
    Ins(n,t,2,0);
    
    while(spfa())
    mincostflow();
    printf("%lld\n",ans);
    
    system("pause");
    return 0;
}
