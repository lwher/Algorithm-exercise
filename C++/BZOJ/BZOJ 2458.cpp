#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;
struct point
{
    double x,y;
}p[200010],np[200010];
inline double sqr(double x) {return x*x;}
inline double dist(point a,point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
inline bool comp(point a,point b)
{
    if(fabs(a.x-b.x)<eps) return a.y<b.y;
    return a.x<b.x;
}
inline bool cmp(point a,point b)
{
    return a.y<b.y;
}
int n;
double work(int l,int r)
{
     int i,j,k,R;double minc=1e20;
     if(r-l+1<5)
     {
         for(i=l;i<=r;i++)  for(j=i+1;j<=r;j++) for(k=j+1;k<=r;k++) 
         minc=min(minc,dist(p[i],p[j])+dist(p[i],p[k])+dist(p[k],p[j]));
         return minc;
     }
     int mid=(l+r)>>1,top=0;
     minc=min(work(l,mid),work(mid,r));
     for(i=l;i<=r;i++) if(fabs(p[mid].x-p[i].x)<=minc/2) np[++top]=p[i];
     sort(np+1,np+1+top,cmp);
     for(i=1;i<top;i++)
     {
         R=i+1;
         while(R<top && np[R+1].y-np[i].y<=minc/2) R++;
         for(j=i+1;j<=R;j++) for(k=j+1;k<=R;k++) 
         minc=min(minc,dist(np[i],np[j])+dist(np[i],np[k])+dist(np[k],np[j]));
     }
     return minc;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
    sort(p+1,p+1+n,comp);
    printf("%.6lf\n",work(1,n));
    return 0;
}