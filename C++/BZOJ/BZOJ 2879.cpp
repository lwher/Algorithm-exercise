#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t,p[50],P,ans,T[50][110];
int id,vp[110][810],top[110];
int sz=1,to[3000000],pre[3000000],v[3000000],cost[3000000],last[100010],fa[100010];
int dui[5000000],d[100010];
bool mark[100010];
void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;cost[sz]=d;last[a]=sz;
    sz++;to[sz]=a;pre[sz]=last[b];v[sz]=0;cost[sz]=-d;last[b]=sz;
}
void spfa()
{
    int tou=1,wei=1,now,i;
    for(i=1;i<=id;i++)  {d[i]=INF;mark[i]=0;fa[i]=0;}
    dui[1]=t;d[t]=0;mark[t]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        if(v[i^1]>0 && d[now]-cost[i]<d[to[i]])
        {
            d[to[i]]=d[now]-cost[i];fa[to[i]]=(i^1);
            if(!mark[to[i]])
            {
                mark[to[i]]=1;dui[++wei]=to[i];
            }
        }
        mark[now]=0;
    }
}
int mincostflow()
{
    spfa();
    int now=s,i;
    while(now!=t)
    {
        i=fa[now];
        ans+=cost[i];
        v[i]-=1;v[i^1]+=1;
        now=to[i];
    }
    return to[fa[s]];
}
void addline(int now)
{
    int i,j;
    for(i=1;i<=m;i++)  
    if(vp[i][top[i]]==now)
    {
        vp[i][++top[i]]=++id;
        Ins(s,id,1,0);
        for(j=1;j<=n;j++)  Ins(id,j,1,T[j][i]*top[i]);
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  {scanf("%d",&p[i]);P+=p[i];}
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&T[i][j]);
    id=n;s=++id;t=++id;
    for(i=1;i<=m;i++)
    {
        vp[i][++top[i]]=++id;
        Ins(s,id,1,0);
        for(j=1;j<=n;j++)  Ins(id,j,1,T[j][i]);
    }
    for(i=1;i<=n;i++)  Ins(i,t,p[i],0);  
    for(i=1;i<=P;i++)  
    addline(mincostflow());
    printf("%d\n",ans);
    return 0;
}