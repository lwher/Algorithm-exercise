#include<cstdio>
#include<iostream>
#include<cstring>
#define T 1001
#define inf 0x7fffffff
#define ll long long
using namespace std;
int n,m,cnt=1;ll ans;
int c[251],a[251][251],s[251],t[251][11],w[251][11];
int head[1005],d[1005],q[1005],from[1005];
bool inq[1005];
struct edge{int from,to,next,c,v;}e[500001];
void ins(int u,int v,int w,int c)
{
    cnt++;
    e[cnt].from=u;e[cnt].to=v;
    e[cnt].next=head[u];head[u]=cnt;
    e[cnt].c=c;e[cnt].v=w;
}
void insert(int u,int v,int w,int c)
{ins(u,v,w,c);ins(v,u,0,-c);}
bool spfa()
{
    for(int i=0;i<=T;i++)d[i]=inf;
    int t=0,w=1;
    d[0]=0;inq[0]=1;q[0]=0;
    while(t!=w)
    {
        int now=q[t];t++;if(t==T)t=0;
        for(int i=head[now];i;i=e[i].next)
            if(e[i].v&&d[e[i].to]>d[now]+e[i].c)
            {
                d[e[i].to]=d[now]+e[i].c;
                from[e[i].to]=i;
                if(!inq[e[i].to])
                {inq[e[i].to]=1;q[w++]=e[i].to;if(w==T)w=0;} 
            }
        inq[now]=0; 
    }
    if(d[T]==inf)return 0;
    return 1;
}
void mcf()
{
    int x=inf;
    for(int i=from[T];i;i=from[e[i].from])
        x=min(x,e[i].v);
    for(int i=from[T];i;i=from[e[i].from])
    {
        e[i].v-=x;
        e[i^1].v+=x;
        ans+=e[i].c*x;
    }
}
void build()
{
    for(int i=1;i<=n;i++)
        insert(0,i,c[i],0);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(a[i][j])insert(j,n+i,inf,0);
    for(int i=1;i<=m;i++)
       for(int j=1;j<=s[i]+1;j++)
          insert(n+i,T,t[i][j]-t[i][j-1],w[i][j]);
} 
int main()
{
    scanf("%d%d",&m,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d",&s[i]);
        for(int j=1;j<=s[i];j++)
            scanf("%d",&t[i][j]);
        t[i][s[i]+1]=inf;
        for(int j=1;j<=s[i]+1;j++)
            scanf("%d",&w[i][j]);
    }
    build();
    while(spfa())mcf();
    printf("%lld",ans);
    return 0; 
}