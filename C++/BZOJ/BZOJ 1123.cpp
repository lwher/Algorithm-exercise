#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m;
int sz,to[1000010],pre[1000010],last[100010];
long long ans[100010];
int tt,dfn[100010],low[100010],size[100010];
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x,int fa)
{
     long long now=0;
     tt++;dfn[x]=tt;low[x]=tt;size[x]=1;
     int i=last[x];
     while(i>0)
     {
          if(to[i]!=fa)
          {
              if(dfn[to[i]])  low[x]=min(dfn[to[i]],low[x]);
              else
              {
                  Tarjan(to[i],x); low[x]=min(low[x],low[to[i]]);size[x]+=size[to[i]];
                  if(low[to[i]]>=dfn[x])
                  {
                       ans[x]+=now*size[to[i]];
                       now+=size[to[i]];
                  }
              }
          }
          i=pre[i];
     }
     ans[x]+=now*(n-now-1)+n-1;
}
int main()
{
    int i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)  
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    Tarjan(1,0);
    for(i=1;i<=n;i++)  printf("%lld\n",ans[i]<<1);
    system("pause");
    return 0;
}
