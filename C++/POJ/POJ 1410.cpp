#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define eps 1e-6
using namespace std;
struct sth
{
       double x,y;
}xd[2];
struct lwher
{
       double x,y;
}jxd[4];
int t;
double xmax,ymax,xmin,ymin;
inline double min(double a,double b)
{
       if(a<b) return a;return b;
}
inline double max(double a,double b)
{
       if(a>b) return a;return b;
}
bool in(sth w)
{
     if(w.x>xmax || w.x<xmin) return 0;if(w.y>ymax || w.y<ymin) return 0; return 1;
}
bool jxp(sth a,sth b,lwher c,lwher d)
{
     if(max(a.x,b.x)<min(c.x,d.x) || min(a.x,b.x)>max(c.x,d.x) || max(a.y,b.y)<min(c.y,d.y) || min(a.y,b.y)>max(c.y,d.y)) return 0;
     return 1;
}
double chaji(double ax,double ay,double bx,double by)
{
     return ax*by-ay*bx;
}
bool xiangjiao(sth a,sth b,lwher c,lwher d)
{
     if(!jxp(a,b,c,d))  return 0;
     if(chaji(d.x-c.x,d.y-c.y,b.x-c.x,b.y-c.y)*chaji(d.x-c.x,d.y-c.y,a.x-c.x,a.y-c.y)>eps)  return 0;
     if(chaji(a.x-b.x,a.y-b.y,d.x-b.x,d.y-b.y)*chaji(a.x-b.x,a.y-b.y,c.x-b.x,c.y-b.y)>eps)  return 0;
     return 1;
}
bool solve()
{
     if(in(xd[0]) && in(xd[1]))  return 1;
     if(xiangjiao(xd[0],xd[1],jxd[0],jxd[1]))  return 1;
     if(xiangjiao(xd[0],xd[1],jxd[1],jxd[2]))  return 1;
     if(xiangjiao(xd[0],xd[1],jxd[2],jxd[3]))  return 1;
     if(xiangjiao(xd[0],xd[1],jxd[0],jxd[3]))  return 1;
     return 0;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&xd[0].x,&xd[0].y,&xd[1].x,&xd[1].y);
        scanf("%lf%lf%lf%lf",&jxd[0].x,&jxd[0].y,&jxd[2].x,&jxd[2].y);
        jxd[1].x=jxd[0].x;jxd[1].y=jxd[2].y;jxd[3].x=jxd[2].x;jxd[3].y=jxd[0].y;
        xmax=max(jxd[0].x,jxd[2].x);xmin=min(jxd[0].x,jxd[2].x);
        ymax=max(jxd[0].y,jxd[2].y);ymin=min(jxd[0].y,jxd[2].y);
        if(solve())  printf("T\n"); else printf("F\n");
    }
    system("pause");
    return 0;
}
