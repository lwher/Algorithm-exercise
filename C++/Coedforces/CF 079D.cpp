#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,k,sz;
long long f[1050000];
int P[10010],bh[31],size[110];
int dui[10010],dist[10010],d[31][31];
bool mark[1050000];
void bfs(int x)
{
     int tou=1,wei=1,now,i;
     memset(dist,-1,sizeof(dist));
     dui[1]=bh[x];dist[bh[x]]=0;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=1;i<=m;i++)
         {
             if(now-size[i]>0 && dist[now-size[i]]==-1)
             {
                 dist[now-size[i]]=dist[now]+1;
                 dui[++wei]=now-size[i];
             } 
             if(now+size[i]<=n+1 && dist[now+size[i]]==-1)
             {
                 dist[now+size[i]]=dist[now]+1;
                 dui[++wei]=now+size[i];
             }
         }
     }
     for(i=1;i<=sz;i++)  d[x][i]=dist[bh[i]];
}
long long dp(int x)
{
    if(!x) return 0;
    if(mark[x])  return f[x];
    mark[x]=1;
    int i,st=0;
    f[x]=INF;
    for(i=1;i<=sz;i++) 
    {
       if(x & (1<<(i-1)))
       {
            if(!st)  st=i;
            else
            {
                if(d[st][i]!=-1)  f[x]=min(f[x],dp(x^(1<<(st-1))^(1<<(i-1)))+d[st][i]);
            }
       }
    }
    return f[x];
}
int main()
{
    int i,x;
    scanf("%d%d%d",&n,&k,&m);
    for(i=1;i<=k;i++)  
    {
        scanf("%d",&x);
        P[x]^=1;P[x+1]^=1;
    }
    for(i=1;i<=n+1;i++) if(P[i]) bh[++sz]=i;
    for(i=1;i<=m;i++)  scanf("%d",&size[i]);
    for(i=1;i<=sz;i++)  bfs(i);
    dp((1<<sz)-1);
    if(f[(1<<sz)-1]==INF)  printf("-1\n");
    else  printf("%d\n",f[(1<<sz)-1]);
    return 0;
}