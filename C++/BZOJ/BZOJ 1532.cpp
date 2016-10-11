#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,s,t,A[10010],B[10010];
int sz,to[300010],pre[300010],v[300010],last[30010],cur[30010];
int h[30010],dui[30010];
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void build(int x)
{
     s=n+m+1;t=s+1;sz=1;
     memset(last,0,sizeof(last));
     for(int i=1;i<=n;i++) Ins(i,t,x);
     for(int i=1;i<=m;i++)
     {
        Ins(s,i+n,1);
        Ins(i+n,A[i],1);
        Ins(i+n,B[i],1); 
     }
}
bool bfs()
{
     int tou=1,wei=1,now,i;
     for(i=1;i<=t;i++) h[i]=-1;
     dui[1]=t;h[t]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         if(v[i^1]>0 && h[to[i]]==-1)
         {
             h[to[i]]=h[now]+1;
             dui[++wei]=to[i];            
         }
     }
     if(h[s]!=-1)return 1;return 0;
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,i,w;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(v[i]>0) cur[x]=i;
        if(F==used) return F;
    }
    if(!used) h[x]=-1;
    return used;
}
int DINIC()
{
    int i,tmp=0;
    while(bfs())
    {
        for(i=1;i<=t;i++) cur[i]=last[i];
        tmp+=dfs(s,0x7fffffff);
    }    
    return tmp;
}
int main()
{
    int i,l,r,mid;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++) scanf("%d%d",&A[i],&B[i]);
    l=0;r=5000;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        build(mid);
        if(DINIC()==m) r=mid;
        else l=mid;
    }
    build(l);
    if(DINIC()==m) printf("%d\n",l); else printf("%d\n",r);
    return 0;
}