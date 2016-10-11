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
    double zb[5],key;
}p[50010];
int n,m,k,K,root,id[13],ls[50010],rs[50010];
double dmin[13];
inline bool comp(point a,point b)
{
    return a.key<b.key;
}
double sqr(double x) {return x*x;}
double dist(point a,point b)
{
    double d=0;
    for(int i=0;i<k;i++) d+=sqr(a.zb[i]-b.zb[i]);
    return d;
}
int build(int l,int r,int w)
{
    if(l>r) return 0;
    int i,x=(l+r)>>1;
    for(i=l;i<=r;i++) p[i].key=p[i].zb[w];
    sort(p+l,p+r+1,comp);
    ls[x]=build(l,x-1,(w+1)%k);rs[x]=build(x+1,r,(w+1)%k);
    return x;
}
void query(int x,int w)
{
    if(x==0) return;
    int i,j;
    double d=dist(p[x],p[0]);
    for(i=1;i<=K;i++) if(d<dmin[i]-eps) break;
    for(j=K;j>i;j--) dmin[j]=dmin[j-1],id[j]=id[j-1];
    dmin[i]=d;id[i]=x;
    if(p[0].zb[w]<p[x].zb[w]+eps)
    {
        query(ls[x],(w+1)%k);
        if(sqr(p[x].zb[w]-p[0].zb[w])<dmin[K]-eps) query(rs[x],(w+1)%k);
    }
    else
    {
        query(rs[x],(w+1)%k);
        if(sqr(p[x].zb[w]-p[0].zb[w])<dmin[K]-eps) query(ls[x],(w+1)%k);
    }
}
inline void print(int x)
{
    for(int i=0;i<k-1;i++) printf("%.0lf ",p[x].zb[i]);
    printf("%.0lf\n",p[x].zb[k-1]);
}
int main()
{
    int i,j;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        for(i=1;i<=n;i++) for(j=0;j<k;j++) scanf("%lf",&p[i].zb[j]);
        root=build(1,n,0);
        scanf("%d",&m);
        for(i=1;i<=m;i++)
        {
            for(j=0;j<k;j++) scanf("%lf",&p[0].zb[j]);
            scanf("%d",&K);
            for(j=1;j<=K;j++) dmin[j]=1e20;
            query(root,0);
            printf("the closest %d points are:\n",K);
            for(j=1;j<=K;j++) print(id[j]);
        }
    }
    system("pause");
    return 0;
}
