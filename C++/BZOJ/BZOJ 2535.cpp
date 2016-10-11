#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
    int k,id;
}p[2010];
int n,m,Ans[2010];
int sz,to[20010],pre[20010],last[2010];
bool vis[2010];
inline bool comp(sth a,sth b)
{
    return a.k<b.k;
}
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void init()
{
    int i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&p[i].k);
        p[i].id=i;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
}
inline void deal(int x)
{
    for(int i=last[x];i;i=pre[i]) if(i & 1) p[x].k=min(p[x].k,p[to[i]].k-1);
}
void solve1()
{
    int i,j;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) deal(j);
    sort(p+1,p+1+n,comp);
    for(i=1;i<n;i++) printf("%d ",p[i].id);
    printf("%d\n",p[n].id);
}
int Count(int x)
{
    int i,res=1;
    vis[x]=1;
    for(i=last[x];i;i=pre[i]) if(!(i & 1) && !vis[to[i]]) res+=Count(to[i]);
    return res;
}
void solve2()
{
    int i,j,ans,cnt;
    for(i=1;i<=n;i++)
    {
        memset(vis,0,sizeof(vis));
        ans=cnt=Count(i);
        for(j=1;j<=n;j++)
        if(!vis[p[j].id])
        {
           cnt++;
           if(p[j].k<=ans) ans++;
           else if(cnt>p[j].k) ans=p[j].k+1; 
        }
        Ans[i]=ans;
    }
    for(i=1;i<n;i++) printf("%d ",Ans[i]);
    printf("%d\n",Ans[n]);
}
int main()
{
    init();
    solve1();
    solve2();
    return 0;
}