#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t,sum;
bool mark[810];
int sz,to[60010],pre[60010],v[60010],last[810];
int h[810],gap[810],dui[810];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void init()
{
     int i,a,c,b;sz=1;
     memset(last,0,sizeof(last));
     memset(mark,0,sizeof(mark));
     memset(gap,0,sizeof(gap));
     memset(h,-1,sizeof(h));
     for(i=1;i<=m;i++)
     {
        scanf("%d%d%d",&a,&b,&c);Ins(a,b,c);Ins(b,a,c);
     }
}
void bfs()
{
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
                   gap[h[to[i]]]++;
                   wei++;dui[wei]=to[i];
               }
               i=pre[i];
          }
     }
}
int dfs(int x,int F)
{
     if(x==t)  return F;
     int i=last[x],used=0,w;
     while(i>0)
     {
         if(v[i] && h[x]-1==h[to[i]])
         {
             w=F-used;
             w=dfs(to[i],min(v[i],w));
             v[i]-=w;
             v[i^1]+=w;
             used+=w;
             if(used==F)  return F;
         }
         i=pre[i];
     }
     gap[h[x]]--;
     if(gap[h[x]]==0)  h[s]=n+1;
     gap[++h[x]]++;
     return used;
}
void SAP()
{
     bfs();
     while(h[s]<=n)  dfs(s,INF);
}
void dfs1(int x)
{
     if(mark[x]) return;
     int i=last[x];
     sum++;mark[x]=1;
     while(i>0)
     {
         if(!(i & 1) && v[i])  dfs1(to[i]);
         i=pre[i];
     }
}
void dfs2(int x)
{
     if(mark[x]) return;
     int i=last[x];
     sum++;mark[x]=1;
     while(i>0)
     {
         if((i & 1) && v[i^1])  dfs2(to[i]);
         i=pre[i];
     }
}
void solve()
{
     SAP();
     sum=0;
     dfs1(s);dfs2(t);
     if(sum<n)  printf("AMBIGUOUS\n");
     else       printf("UNIQUE\n");
}
int main()
{
    while(scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        if(n==0 && m==0 && s==0 && t==0)  break;
        init();
        solve();
    }
    system("pause");
    return 0;
}
