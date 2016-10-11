#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int MAXM=200100;
const int MAXN=5100;
const int INF=0x7fffffff;

struct edge
{
    int y,d,next;
}e[MAXM];
struct node
{
    int p,d;
};
int n,m,tot,ans,K,last;
int first[MAXN],No[MAXN],h[MAXN];
bool vis[MAXN];
queue<int> q1;
priority_queue<node,vector<node> > q2;
bool operator < (node a,node b)
    {return a.d>b.d;}

void Add(int x,int y,int z)
{
    e[++tot].y=y;
    e[tot].d=z;
    e[tot].next=first[x];
    first[x]=tot;
}

void Init()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;++i)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        Add(x,y,z);
        Add(y,x,z);
    }
}

void Prepare()
{
    for (int i=1;i<=n;++i)
        h[i]=INF,vis[i]=0;
    h[1]=0,vis[1]=1;
    q1.push(1);
    while (!q1.empty())
    {
        int u=q1.front();q1.pop();vis[u]=0;
        for (int i=first[u];i;i=e[i].next)
        {
            int v=e[i].y;
            if (h[v]>h[u]+e[i].d)
            {
                h[v]=h[u]+e[i].d;
                if (!vis[v]) q1.push(v),vis[v]=1;
            }
        }
    }
}

void Solve()
{
    memset(No,0,sizeof(No));
    node u,v;
    u.p=1,u.d=0;
    q2.push(u);
    while (!q2.empty())
    {
        u=q2.top(),q2.pop();
        //if (No[u.p]>=2) continue;
        ++No[u.p];
        if (u.p==n)
        {
            if (u.d!=last)
                if (++K==2){ans=u.d;break;}
            last=u.d;
        }
        //if (u.p==n && No[u.p]==2) {ans=u.d;break;}
        for (int i=first[u.p];i;i=e[i].next)
        {
            v.p=e[i].y,v.d=u.d+e[i].d;
            q2.push(v);
        }
    }
    printf("%d\n",ans);
}

int main()
{
    Init();
    Prepare();
    Solve();
    return 0;
}
