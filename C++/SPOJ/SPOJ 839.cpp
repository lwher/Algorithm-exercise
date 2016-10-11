#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,p,s,t;
int sz,to[30010],pre[30010],v[30010],last[510];
int qi[3010],zhong[3010],ans[510];
int h[510],gap[510],dui[510];
bool mark[510],have[510];
void init()
{
     int i,a,b;
     memset(ans,0,sizeof(ans));
     memset(have,0,sizeof(have));
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)  scanf("%d%d",&qi[i],&zhong[i]);
     scanf("%d",&p);
     for(i=1;i<=p;i++)  {scanf("%d%d",&a,&b);ans[a]=b;have[a]=1;}
     s=n+1;t=s+1;
}
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,now,i;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
          now=dui[tou];tou++;
          i=last[now];
          while(i>0)
          {
              if(h[to[i]]==-1)
              {
                  h[to[i]]=h[now]+1;
                  gap[h[now]+1]++;
                  dui[++wei]=to[i];
              }
              i=pre[i];
          }
     }
}
int dfs(int x,int F)
{
    if(x==t)  return F;
    int used=0,w,i;
    i=last[x];
    while(i>0)
    {
        if(v[i]>0 && h[x]-1==h[to[i]])
        {
           w=min(v[i],F-used);
           w=dfs(to[i],w);
           v[i]-=w;
           v[i^1]+=w;
           used+=w;
           if(F==used)  return F;
        }
        i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)  h[s]=t+2;
    gap[++h[x]]++;
    return used;
}
void SAP()
{
     bfs();  while(h[s]<t+2)  dfs(s,INF);
}
void dfs1(int x,int num)
{
     mark[x]=1;
     if(!have[x])  ans[x]|=num;
     int i=last[x];
     while(i>0)
     {
         if(!mark[to[i]] && v[i]>0)  dfs1(to[i],num);
         i=pre[i];
     }
}
void solve()
{
     int i,j,k;
     for(k=0;k<32;k++)
     {
          sz=1;memset(last,0,sizeof(last));
          for(i=1;i<=n;i++)  if(have[i])
          {
              if((ans[i]>>k) & 1)  Ins(s,i,INF);
              else Ins(i,t,INF);
          }
          for(i=1;i<=m;i++)  {Ins(qi[i],zhong[i],1);Ins(zhong[i],qi[i],1);}
          SAP();
          memset(mark,0,sizeof(mark));
          dfs1(s,1<<k);
     }
     for(i=1;i<=n;i++)  printf("%d\n",ans[i]);
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
    system("pause");
    return 0;
}
