#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,s,t,S,T,in[310];
int sz=1,to[30010],pre[30010],v[30010],cost[30010],last[210],cur[210];
int dui[210],h[210],gap[210];
inline void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;v[sz]=d-c;pre[sz]=last[a];last[a]=sz; 
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz; 
    in[b]+=c;in[a]-=c;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,now,i;
     dui[1]=T;h[T]=1;gap[1]=1;
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
int dfs(int x,int F)
{
    if(x==T) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(v[i]>0) cur[x]=i;
        if(F==used) return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]]) h[S]=T+2;
    gap[++h[x]]++;
    cur[x]=last[x];
    return used;
}
void SAP()
{
     bfs();
     for(int i=1;i<=T;i++) cur[i]=last[i];
     while(h[S]<T+2) dfs(S,0x7fffffff); 
}
int main()
{
    int i,j,k,x;
    scanf("%d",&n);
    s=n+1;t=s+1;
    S=t+1;T=S+1;
    for(i=1;i<=n;i++)
    {
       scanf("%d",&k);
       for(j=1;j<=k;j++) 
       {
          scanf("%d",&x);
          Ins(i,x,1,INF);
       }
       Ins(s,i,0,INF);
       Ins(i,t,0,INF);    
    }    
    for(i=1;i<=t;i++) 
    {
       if(in[i]>0) Ins(S,i,0,in[i]);
       else Ins(i,T,0,-in[i]);
    }    
    SAP();
    Ins(t,s,0,INF);
    SAP();
    printf("%d\n",v[sz]);
    return 0;
} 