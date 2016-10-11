#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,top,fa[200010],size[200010],dui[200010];
int sz,to[200010],pre[200010],last[200010];
long long val[200010],lastval[200010],ans,num[200010];
bool OH,active[200010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void bfs(int x)
{
    while(fa[x]!=1) x=fa[x];
    int tou=1,wei=1,i,now;
    dui[1]=x;
    while(tou<=wei)
    {
       now=dui[tou];active[now]=1;tou++;
       for(i=last[now];i;i=pre[i]) if(size[to[i]]>0) dui[++wei]=to[i];
    }
}
void solveactive()
{
    for(int i=2;i<=n;i++) 
    if(fa[fa[i]] && !active[fa[i]] && val[fa[fa[i]]]+val[i]!=val[fa[i]]*2) 
    bfs(fa[i]);
}
bool checkinf()
{
    for(int i=2;i<=n;i++) if(size[i]>1)
    {
        for(int j=last[i];j;j=pre[j]) if(active[to[j]]) return 1;
    }
    return 0;
}
long long getsum(int x)
{
    int tou=1,wei=1,i,now;
    long long res=0;
    dui[1]=x;
    while(tou<=wei)
    {
       now=dui[tou];res+=val[now];tou++;
       for(i=last[now];i;i=pre[i]) dui[++wei]=to[i];
    } 
    return res;
}
long long calc(int x)
{
    int u=x,v=1;top=0;
    long long res=0,nowval=val[1];
    for(;u;v=u,u=to[last[u]]) num[++top]=val[u]-val[v];
    u=fa[v];
    res+=(size[u]-1)*val[v];
    sort(num+1,num+1+top);
    for(u=x;u;u=to[last[u]])
    {
       nowval+=num[top--];
       res+=nowval;
    }
    return res;
}
int main()
{
    int i,x;        
    while(scanf("%d",&n) && n)
    {
        OH=0;sz=0;
        for(i=1;i<=n;i++) lastval[i]=INF,fa[i]=0,size[i]=0,last[i]=0,active[i]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d%lld",&x,&val[i]);
            fa[i]=x;
            if(i==1) continue;
            size[x]++;
            if(x!=1 && lastval[x]!=INF && lastval[x]!=val[i]) OH=1;
            lastval[x]=val[i];
            Ins(x,i);
        }                        
        fa[1]=0;
        if(OH) {printf("+inf\n");continue;}
        solveactive();
        if(checkinf()) {printf("+inf\n");continue;}
        ans=val[1];
        for(i=last[1];i;i=pre[i]) if(!active[to[i]]) ans+=getsum(to[i]);
        else ans+=calc(to[i]);
        printf("%lld\n",ans);
    }
    return 0;
}