#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,s,t,dist[1010],dui[1000010],p[1010][1010],du[1010];
int sz,to[2010],pre[2010],last[1010];
double f[1010][1010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
double dfs(int x,int y)
{
    if(f[x][y]) return f[x][y];
    if(x==y) return 0;
    if(p[x][y]==y || p[p[x][y]][y]==y) return f[x][y]=1;
    double tot=dfs(p[p[x][y]][y],y);
    for(int i=last[y];i;i=pre[i]) tot+=dfs(p[p[x][y]][y],to[i]);
    return f[x][y]=tot/(du[y]+1)+1;
}
void bfs(int x)
{
    memset(dist,-1,sizeof(dist));
    int tou=1,wei=1,now,i,tmp;
    dui[1]=x;dist[x]=0;
    while(tou<=wei)
    {
       now=dui[tou];tou++;
       tmp=p[x][now];
       for(i=last[now];i;i=pre[i])
       if(dist[to[i]]==-1 || (dist[now]+1==dist[to[i]] && tmp<p[x][to[i]]))
       {
          dist[to[i]]=dist[now]+1;
          p[x][to[i]]=tmp;
          if(!tmp) p[x][to[i]]=to[i];
          dui[++wei]=to[i];
       }
    }
}
int main()
{
    int i,a,b;
    scanf("%d%d",&n,&m);
    scanf("%d%d",&s,&t);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
        du[a]++;du[b]++;
    }
    for(i=1;i<=n;i++) bfs(i);    
    printf("%.3lf\n",dfs(s,t));
    system("pause");
    return 0;
}
