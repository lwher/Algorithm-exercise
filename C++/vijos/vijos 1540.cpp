#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,p;
bool o,mark[510];
int fa[510],sz,to[3010],v[3010],pre[3010],last[510],h[510];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
int getfa(int x)
{
    if(fa[x]==0)  return x;
    else return fa[x]=getfa(fa[x]);
}
void link(int a,int b)
{
     int x=getfa(a),y=getfa(b);
     if(x!=y)  fa[x]=y;  
}
void dfs(int x,int H)
{
     if(mark[x])
     {
         if(H!=h[x])  o=1;
         return;
     }
     h[x]=H;mark[x]=1;
     int i=last[x];
     while(i>0)
     {
         dfs(to[i],h[x]+v[i]);
         i=pre[i];
     }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d",&n,&p);
    for(i=1;i<=p;i++)
    {
         scanf("%d%d%d",&a,&b,&c);
         Ins(a,b,c);Ins(b,a,-c);
         link(a,b);
    }
    if(p<n-1)  o=1;
    int now=0;
    for(i=1;i<=n;i++)  if(!fa[i])  now++;
    if(now>1)  o=1;
    if(!o)  dfs(1,0);
    if(!o)
    {
       int minn=1e9;
       for(i=1;i<=n;i++)  minn=min(minn,h[i]);
       for(i=1;i<=n;i++)  h[i]-=minn;
    }
    if(o)  printf("-1\n");
    else   for(i=1;i<=n;i++)  printf("%d\n",h[i]);
    system("pause");
    return 0;
}
