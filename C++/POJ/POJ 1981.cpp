#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-8
using namespace std;
struct point 
{
    double x,y;
}p[310];
int n,ans;
inline double sqr(double x) {return x*x;}
inline double dist(point a,point b)
{
     return sqr(a.x-b.x)+sqr(a.y-b.y);
}
void getpoint(point p1,point p2,point &a,point &b)
{
     double l=sqrt(dist(p1,p2)),d=l*0.5,ap=acos(d);
     double sinap=sin(ap),cosap=cos(ap);
     point xl;
     xl.x=(p2.x-p1.x)/l;xl.y=(p2.y-p1.y)/l;
     a.x=p1.x+xl.x*cosap-xl.y*sinap;a.y=p1.y+xl.y*cosap+xl.x*sinap;
     b.x=p1.x+xl.x*cosap+xl.y*sinap;b.y=p1.y+xl.y*cosap-xl.x*sinap;
}
inline void check(point a)
{
     int i,tmp=0;
     for(i=1;i<=n;i++) if(dist(a,p[i])<1.00+eps) tmp++;
     if(tmp>ans) ans=tmp;
}
int main()
{
    int i,j;
    point a,b;
    while(scanf("%d",&n) && n)
    {
        ans=1;
        for(i=1;i<=n;i++) scanf("%lf%lf",&p[i].x,&p[i].y);
        for(i=1;i<=n;i++) for(j=i+1;j<=n;j++)
        {
            if(dist(p[i],p[j])<4.00+eps) 
            {
                getpoint(p[i],p[j],a,b);
                check(a);check(b);
            }
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
