#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct point
{
    double zb[2],key;
    int id;
}p[100010],tp[100010];
int n,m,K,root,ls[100010],rs[100010],ansid[23];
double pmax[100010][2],pmin[100010][2],ansd[23];
inline bool comp(point a,point b)
{
    return a.key<b.key;
}
inline void updata(int x)
{
    for(int i=0;i<2;i++)
    {
        if(pmax[ls[x]][i]>pmax[x][i]) pmax[x][i]=pmax[ls[x]][i];
        if(pmax[rs[x]][i]>pmax[x][i]) pmax[x][i]=pmax[rs[x]][i];
        if(pmin[ls[x]][i]<pmin[x][i]) pmin[x][i]=pmin[ls[x]][i];
        if(pmin[rs[x]][i]<pmin[x][i]) pmin[x][i]=pmin[rs[x]][i];
    }
}
inline double sqr(double x) {return x*x;}
inline double dist(point a,point b)
{
     double d=0;
     for(int i=0;i<2;i++) d+=sqr(a.zb[i]-b.zb[i]);
     return d;
}
int build(int l,int r,int w)
{
    if(l>r) return 0;
    int i,x,mid=(l+r)>>1;
    for(i=l;i<=r;i++) p[i].key=p[i].zb[w];
    sort(p+l,p+r+1,comp);
    x=mid;tp[x]=p[x];
    for(i=0;i<2;i++) pmax[x][i]=p[x].zb[i],pmin[x][i]=p[x].zb[i];
    ls[x]=build(l,mid-1,w^1);rs[x]=build(mid+1,r,w^1);
    updata(x);
    return x;
}
void query(int x,int w)
{
     if(x==0) return;
     int i,j;double d=0;
     for(i=0;i<2;i++) d+=max(sqr(pmax[x][i]-p[0].zb[i]),sqr(pmin[x][i]-p[0].zb[i]));
     if(d<ansd[K]-eps) return;
     d=dist(tp[x],p[0]);
     for(i=1;i<=K;i++) if(d>ansd[i] || (fabs(ansd[i]-d)<eps && tp[x].id<ansid[i])) break;
     for(j=K;j>=i+1;j--) ansid[j]=ansid[j-1],ansd[j]=ansd[j-1];
     ansid[i]=tp[x].id;ansd[i]=d;
     if(p[0].zb[w]<=tp[x].zb[w])
     {
         query(rs[x],w^1);
         query(ls[x],w^1);
     }
     else
     {
         query(ls[x],w^1);
         query(rs[x],w^1);
     }
}
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=0;i<2;i++) pmax[0][i]=-1e20,pmin[0][i]=1e20;
    for(i=1;i<=n;i++) 
    {
       scanf("%lf%lf",&p[i].zb[0],&p[i].zb[1]);
       p[i].id=i;
    }
    root=build(1,n,0);
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
       scanf("%lf%lf%d",&p[0].zb[0],&p[0].zb[1],&K);
       for(j=1;j<=K;j++) ansd[j]=-1;
       query(root,0);
       printf("%d\n",ansid[K]);
    }
    system("pause");
    return 0;
}
