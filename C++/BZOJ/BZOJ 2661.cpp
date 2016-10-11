#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,A,B,s,t,maxflow,mincost;
int sz=1,to[3000010],pre[3000010],v[3000010],cost[3000010],last[2010];
int dui[5000010],dist[2010];
bool mark[2010];
inline void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
     memset(mark,0,sizeof(mark));
     memset(dist,127,sizeof(dist));
     int tou=1,wei=1,inf=dist[0],i,now;
     dui[1]=t;dist[t]=0;mark[t]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(v[i^1]>0 && dist[now]-cost[i]<dist[to[i]])
         {
             dist[to[i]]=dist[now]-cost[i];
             if(!mark[to[i]]) {mark[to[i]]=1;dui[++wei]=to[i];}
         }
         mark[now]=0;
     }
     if(dist[s]==inf) return 0; return 1;
}
int dfs(int x,int F)
{
    mark[x]=1;
    if(x==t) return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    if(v[i]>0 && !mark[to[i]] && dist[x]-cost[i]==dist[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(used==F) return F;
    }
    return used;
} 
void mincostflow()
{
     while(spfa())
     {
         mark[t]=1;
         while(mark[t])
         {
             memset(mark,0,sizeof(mark));
             int tmp=dfs(s,INF);
             maxflow+=tmp;
             mincost+=dist[s]*tmp;
         }
     }
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int gcd(int a,int b)
{
    if(b==0) return a; return gcd(b,a%b);
}
bool check(int a,int b)
{
     if(a<b) swap(a,b);
     int c=floor(sqrt(a*a-b*b));
     if(c*c!=a*a-b*b) return 0;
     if(gcd(c,b)!=1) return 0;
     return 1;
}
int main()
{
    int i,j,p,q;
    scanf("%d%d",&A,&B);
    n=B-A+1;s=2*n+1;t=s+1;
    for(i=A;i<=B;i++) for(j=A;j<=B;j++) if(i!=j && check(i,j)) Ins(i-A+1,j-A+1+n,1,-i-j);
    for(i=1;i<=n;i++) 
    {
        Ins(s,i,1,0);
        Ins(i+n,t,1,0);
    }
    mincostflow();
    printf("%d %d\n",maxflow>>1,-1*(mincost>>1));
    system("pause");
    return 0;
} 
