#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[30010],pre[30010],v[30010],cost[30010],last[601];
int d[601],dui[300010];
bool mark[601];char map[20][20];
void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
    memset(d,127,sizeof(d));
    memset(mark,0,sizeof(mark));
    int tou=1,wei=1,inf=d[0],now,i;
    d[t]=0;mark[t]=1;dui[1]=t;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i>0;i=pre[i])
        {
            if(v[i^1]>0 && d[to[i]]>d[now]-cost[i])
            {
                d[to[i]]=d[now]-cost[i];
                if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
            }
        }
        mark[now]=0;
    }
    if(d[s]==inf)  return 0; return 1;
}
int dfs(int x,int F)
{
    mark[x]=1;
    if(x==t)  return F;
    int i,used=0,w;
    for(i=last[x];i>0;i=pre[i])
    {
        if(!mark[to[i]] && v[i]>0 && d[to[i]]==d[x]-cost[i])
        {
            w=min(v[i],F-used);
            w=dfs(to[i],w);
            used+=w;
            v[i]-=w;
            v[i^1]+=w;
            if(used==F)  return F;
        }
    }
    return used;
}
int mincostflow()
{
    int tmp=0;
    while(spfa())
    {
        mark[t]=1;
        while(mark[t])
        {
            memset(mark,0,sizeof(mark));
            tmp+=dfs(s,INF)*d[s];
        }
    }
    return tmp;
}
int P(int x,int y)
{
    return (x-1)*m+y;
}
int up(int x,int y)
{
    x--; if(x==0)  x=n;
    return P(x,y);
}
int down(int x,int y)
{
    x++; if(x>n)   x=1;
    return P(x,y);
}
int left(int x,int y)
{
    y--; if(y==0) y=m;
    return P(x,y);
}
int right(int x,int y)
{
    y++; if(y>m) y=1;
    return P(x,y);
}
void init()
{
    int i,j,nm,p1,p2;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%s",map[i]+1);
    nm=n*m;
    s=2*nm+1;t=s+1;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        p1=P(i,j);
        Ins(s,p1,1,0);Ins(p1+nm,t,1,0);
        if(map[i][j]=='U')
        {
            p2=up(i,j); Ins(p1,p2+nm,1,0);
            p2=down(i,j); Ins(p1,p2+nm,1,1);
            p2=left(i,j); Ins(p1,p2+nm,1,1);
            p2=right(i,j); Ins(p1,p2+nm,1,1);
        }else
        if(map[i][j]=='D')
        {
            p2=up(i,j); Ins(p1,p2+nm,1,1);
            p2=down(i,j); Ins(p1,p2+nm,1,0);
            p2=left(i,j); Ins(p1,p2+nm,1,1);
            p2=right(i,j); Ins(p1,p2+nm,1,1);
        }else
        if(map[i][j]=='L')
        {
            p2=up(i,j); Ins(p1,p2+nm,1,1);
            p2=down(i,j); Ins(p1,p2+nm,1,1);
            p2=left(i,j); Ins(p1,p2+nm,1,0);
            p2=right(i,j); Ins(p1,p2+nm,1,1);
        }
        else
        {
            p2=up(i,j); Ins(p1,p2+nm,1,1);
            p2=down(i,j); Ins(p1,p2+nm,1,1);
            p2=left(i,j); Ins(p1,p2+nm,1,1);
            p2=right(i,j); Ins(p1,p2+nm,1,0);
        }
    }
}
int main()
{
    init();
    printf("%d\n",mincostflow());
    //system("pause");
    return 0;
}