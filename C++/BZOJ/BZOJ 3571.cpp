#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct point
{
    int x,y;
};
int n,s,t,A[71][71],B[71][71],ans,pipei[71];
int sz,to[13000],pre[13000],v[13000],last[150];
int dui[30010];
long long cost[13000],d[150];
bool mark[150];
void Ins(int a,int b,int c,long long d)
{
     sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
     int i,now,tou=1,wei=1;
     for(i=0;i<=t;i++) d[i]=1e20;
     memset(mark,0,sizeof(mark));
     dui[1]=t;d[t]=0;mark[t]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(v[i^1]>0 && d[to[i]]>d[now]-cost[i])
         {
            d[to[i]]=d[now]-cost[i];
            if(!mark[to[i]])
            {
               mark[to[i]]=1;
               dui[++wei]=to[i];
            }
         }
         mark[now]=0;
     }
     if(d[s]==d[0]) return 0; return 1;
}
int dfs(int x,int F)
{
   mark[x]=1;
   if(x==t) return F;
   int used=0,w,i;
   for(i=last[x];i;i=pre[i])
   if(!mark[to[i]] && v[i]>0 && d[x]-cost[i]==d[to[i]])
   {
      w=min(v[i],F-used);
      w=dfs(to[i],w);
      used+=w;v[i]-=w;v[i^1]+=w;
      if(F==used) return F;
   }
   return used;
}
point mincostflow()
{
    int x=0,y=0,i,j;
    while(spfa())
    {
       mark[t]=1;
       while(mark[t])
       {
          memset(mark,0,sizeof(mark));
          dfs(s,INF);
       }
    }
    for(i=1;i<=n;i++)
    {
       for(j=last[i];j;j=pre[j])
       if(!v[j] && to[j]>=n+1 && to[j]<=n+n)
       {
          pipei[i]=to[j]-n;
          break;
       }
    }
    for(i=1;i<=n;i++) 
    {
       x+=A[i][pipei[i]];
       y+=B[i][pipei[i]];
    }
    if(x*y<ans) ans=x*y;
    point k;
    k.x=x;k.y=y;
    return k;
}
void build(long long a,long long b,long long c)
{
     int i,j;sz=1;
     memset(last,0,sizeof(last));
     for(i=1;i<=n;i++)
     {
        Ins(s,i,1,0);
        Ins(i+n,t,1,0);
     }
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) Ins(i,j+n,1,c*(a*A[i][j]+b*B[i][j]));
}
void init()
{
     int i,j;
     scanf("%d",&n);
     s=n+n+1;t=s+1;
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&A[i][j]);
     for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&B[i][j]);
}
void work(point l,point r)
{
    long long a=r.y-l.y,b=l.x-r.x,c=-(a*l.x+b*l.y);
    build(a,b,-1);
    point mid=mincostflow();
    if(a*mid.x+b*mid.y+c<=0) return;
    work(l,mid);work(mid,r);
}
void solve()
{
     point l,r;ans=1<<30;     
     build(1,0,1);
     l=mincostflow();
     build(0,1,1);r=mincostflow();
     work(l,r);
     printf("%d\n",ans);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        init();
        solve();
    }
    return 0;
}