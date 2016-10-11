#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
const int N=5010;
struct edge
{
    int fm,to,next;
}e[N*10],fe[N*10];
int n,m,f[N],g[N],p[N],fp[N],q[N],en;
bool vis[N];
void dfs(int u)
{
    vis[u]=true;
    bool find=false;
    for(int x=p[u];x!=-1;x=e[x].next)
    {
        int v=e[x].to;
        if(!vis[v])
            dfs(v);
        f[u]+=f[v];
        find=true;
    }
    if(!find)
        f[u]++;
}
void dfs2(int u)
{
    vis[u]=true;
    for(int x=fp[u];x!=-1;x=fe[x].next)
    {
        int v=fe[x].to;
        if(!vis[v])
            dfs2(v);
        g[u]+=g[v];
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int i,j=0;
    memset(p,-1,sizeof(p));
    memset(fp,-1,sizeof(fp));
    for(i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y)
            swap(x,y);
        e[j].fm=y;e[j].to=x;e[j].next=p[y];p[y]=j;
        fe[j].to=y;fe[j].next=fp[x];fp[x]=j++;

    }
    en=j-1;
    dfs(n);
    memset(vis,0,sizeof(vis));
    g[n]=1;
    for(i=1;i<n;i++)
        if(!vis[i])
            dfs2(i);
    int ans=0;
    for(i=0;i<=en;i++)
    {
        int u=e[i].fm,v=e[i].to;
        int tmp=g[u]*f[v];
        if(ans<tmp)
            ans=tmp;
    }
    printf("%d\n",ans);
    system("pause");
    return 0;
}
