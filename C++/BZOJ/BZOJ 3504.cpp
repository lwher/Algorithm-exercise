#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
#define inf 100000000
using namespace std;
int n,s,t,a1,a2,an,b1,b2,bn;
int sz,to[10010],v[10010],pre[10010],last[60];
int dui[60],h[60],gap[60];
char map[60][60];
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
    if(x==t)  return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        used+=w;
        v[i]-=w;
        v[i^1]+=w;
        if(F==used)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=t+2;
    gap[++h[x]]++;
    return used;
}
void build1()
{
     int i,j;sz=1;
     memset(last,0,sizeof(last));
     s=n+1;t=s+1;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
     {
         if(map[i][j]=='O')  Ins(i,j,2);
         if(map[i][j]=='N')  Ins(i,j,inf);
     }
     Ins(s,a1,2*an);Ins(s,b1,2*bn);
     Ins(a2,t,2*an);Ins(b2,t,2*bn);
}
void build2()
{
     int i,j;sz=1;
     memset(last,0,sizeof(last));
     s=n+1;t=s+1;
     for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
     {
         if(map[i][j]=='O')  Ins(i,j,2);
         if(map[i][j]=='N')  Ins(i,j,inf);
     }
     Ins(s,a1,2*an);Ins(s,b2,2*bn);
     Ins(a2,t,2*an);Ins(b1,t,2*bn);
}
int sap()
{
    int now=0;
    bfs();
    while(h[s]<t+2)  now+=dfs(s,INF);
    return now;
}
bool solve()
{
     build1();
     if(sap()!=an*2+bn*2)  return 0;
     build2();
     if(sap()!=an*2+bn*2)  return 0;
     return 1; 
}
int main()
{
    int i,j;
    while(scanf("%d%d%d%d%d%d%d",&n,&a1,&a2,&an,&b1,&b2,&bn)!=EOF)
    {
        a1++;a2++;b1++;b2++;
        for(i=1;i<=n;i++)  scanf("%s",map[i]+1);
        if(solve())  printf("Yes\n");  else  printf("No\n");
    }
    system("pause");
    return 0;
}
