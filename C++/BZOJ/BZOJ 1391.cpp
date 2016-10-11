#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t,ans;
int sz=1,to[3000010],pre[3000010],v[3000010],last[2510],cur[2510];
int h[2510],gap[2510],dui[2510];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
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
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;if(v[i]>0)  cur[x]=i;
        v[i^1]+=w;
        used+=w;
        if(used==F)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    cur[x]=last[x];
    return used;
}
void init()
{
     int i,j,k,a,b;
     n=read();m=read();
     s=n+m+1;t=s+1;
     for(i=1;i<=n;i++)
     {
         k=read();
         Ins(s,i,k);ans+=k;
         k=read();
         for(j=1;j<=k;j++)
         {
             a=read();b=read();
             Ins(i,a+n,b);
         }
     }
     for(i=1;i<=m;i++)
     {
         k=read();
         Ins(n+i,t,k);
     }
}
void SAP()
{
     int tmp=0;
     bfs();
     for(int i=1;i<=t;i++)  cur[i]=last[i];
     while(h[s]<t+2)  tmp+=dfs(s,INF);
     ans-=tmp;
     printf("%d\n",ans);
}
int main()
{
    init();
    SAP();
    system("pause");
    return 0;
}
