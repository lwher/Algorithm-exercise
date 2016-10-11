#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m;
int a[5010],b[5010],t[5010],f[1010];
int last[1010],to[5010],sz,pre[5010];
double v[5010];
double d[1010];
bool o;
bool mark[1010];
void init()
{
     int i,j,k;
     int aa,bb,tt;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)
     scanf("%d",&f[i]);
     for(i=1;i<=m;i++)
     {
       scanf("%d%d%d",&aa,&bb,&tt);
       a[i]=aa;b[i]=bb;t[i]=tt;
     }
}
void rebuild(double now)
{
     int i;
     memset(last,0,sizeof(last));
     sz=0;
     for(i=1;i<=m;i++)
     {
        sz++;
        to[sz]=b[i];
        pre[sz]=last[a[i]];
        v[sz]=double(t[i]*now)-f[b[i]];
        last[a[i]]=sz;
     }
}
void spfa(int x)
{
     if(mark[x])
     {o=1;return;}
     int i=last[x];
     mark[x]=1;
     while(i>0)
     {
         if(d[x]+v[i]<d[to[i]])
         {
            d[to[i]]=d[x]+v[i];
            spfa(to[i]);
            if(o) return;
         }
         i=pre[i];
     }
     mark[x]=0;
}
void solve()
{
     double l=0,r=10000,mid;
     while(r-l>0.001)
     {
          mid=(l+r)/2.000;
          rebuild(mid);
          o=0;
          memset(d,127,sizeof(d));
          memset(mark,0,sizeof(mark));
          d[1]=0;
          spfa(1);
          if(o)
          l=mid;
          else
          r=mid;
     }
     printf("%.2lf\n",l);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
