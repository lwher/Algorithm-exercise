#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
struct sth
{
    int v,bh;
}p[100010];
int n,m;
int sz,to[200010],pre[200010],last[100010];
int fa[100010],sum[100010];
bool mark[100010];
double ans;
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline bool comp(sth a,sth b)
{
     return a.v>b.v;
}
int getfa(int x)
{
    if(fa[x]==0) return x;
    return fa[x]=getfa(fa[x]);
}
int main()
{
    int i,j,x,y,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i].v);
        p[i].bh=i;sum[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    sort(p+1,p+1+n,comp);
    for(i=1;i<=n;i++)
    {
       x=p[i].bh;
       for(j=last[x];j;j=pre[j])
       if(mark[to[j]])
       {
          y=getfa(to[j]);
          a=getfa(x);
          if(a!=y)
          {
             ans+=(long long)(sum[y])*sum[a]*p[i].v;
             sum[y]+=sum[a];
             fa[a]=y;
          }
       }
       mark[x]=1;
    }
    ans/=n*1.0;
    ans/=(n-1)*1.0;
    ans*=2.0;
    printf("%.12lf\n",ans);
    return 0;
}