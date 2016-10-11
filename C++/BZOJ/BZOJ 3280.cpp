#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
#define inf 100000000
using namespace std;
int n,m,k,s,ss,t,flow,sum,ans;
int sz,to[10010],v[10010],cost[10010],pre[10010],last[105];
int d[105],dui[30010];
bool mark[105];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void Ins(int a,int b,int c,int d)
{
    sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
    memset(d,127,sizeof(d));
    memset(mark,0,sizeof(mark));
    int tou=1,wei=1,now,i,mx=d[3];
    dui[1]=t;d[t]=0;mark[t]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        if(v[i^1]>0 && d[now]-cost[i]<d[to[i]])
        {
            d[to[i]]=d[now]-cost[i];
            if(!mark[to[i]])  {dui[++wei]=to[i];mark[to[i]]=1;}
        }
        mark[now]=0;
    }
    if(d[s]==mx)  return 0; return 1;
}
int dfs(int x,int F)
{
    mark[x]=1;
    if(x==t)  return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    if(v[i]>0 && !mark[to[i]] && d[x]-cost[i]==d[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        used+=w;
        v[i]-=w;
        v[i^1]+=w;
        if(F==used)  return F;
    }
    return used;
}
void mincostflow()
{
    while(spfa())
    {
        mark[t]=1;
        while(mark[t])
        {
            memset(mark,0,sizeof(mark));
            int tmp=dfs(s,INF);
            flow+=tmp;ans+=tmp*d[s];
        }
    }
}
void init_build()
{
    int i,j,a,b;
    memset(last,0,sizeof(last));
    flow=0;ans=0;sz=1;sum=0;
    n=read();m=read();k=read();//scanf("%d%d%d",&n,&m,&k);
    s=n+n+1;ss=s+1;t=ss+1;
    for(i=1;i<=n;i++) 
    {
        a=read();//scanf("%d",&a);
        sum+=a;Ins(i+n,t,a,0);Ins(s,i,a,0);
    }
    for(i=1;i<n;i++) Ins(i,i+1,inf,0);
    for(i=1;i<=m;i++) 
    {
        a=read();b=read();//scanf("%d%d",&a,&b);
        Ins(s,ss,a,b);
    }
    for(i=1;i<=k;i++)
    {
        a=read();b=read();//scanf("%d%d",&a,&b);
        for(j=1;j<=n-a-1;j++)   Ins(j,j+a+1+n,inf,b);
    }
    for(i=1;i<=n;i++)  Ins(ss,i+n,inf,0);
}
int main()
{
    int T,nn=0;T=read();//scanf("%d",&T);   
    while(T--)
    {
        init_build();
        mincostflow();
        printf("Case %d: ",++nn);
        if(flow!=sum) printf("impossible\n"); else printf("%d\n",ans);  
    }
    return 0;
}