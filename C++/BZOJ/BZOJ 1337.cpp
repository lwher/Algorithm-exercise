#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#define eps 1e-8
using namespace std;
struct point
{
    double x,y;
}p[200010],o;
int n;double r;
double sqr(double x)
{
    return x*x;
}
double dist(point a,point b)
{
    return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}
void swap(point &a,point &b)
{
     point t=a;a=b;b=t;
}
point geto(point a,point b,point c)
{
      point ans;
      double a1,b1,c1,a2,b2,c2;
      a1=2*(a.x-b.x); b1=2*(a.y-b.y); c1=a.x*a.x+a.y*a.y-b.x*b.x-b.y*b.y;
      a2=2*(a.x-c.x); b2=2*(a.y-c.y); c2=a.x*a.x+a.y*a.y-c.x*c.x-c.y*c.y;
      if(fabs(a1)<eps)
      {
           ans.y=c1/b1;
           ans.x=(c2-ans.y*b2)/a2;
      }
      else
      if(fabs(b1)<eps)
      {
           ans.x=c1/a1;
           ans.y=(c2-ans.x*a2)/b2;
      }
      else
      {
          ans.x=(c2*b1-c1*b2)/(a2*b1-a1*b2);
          ans.y=(c2*a1-c1*a2)/(b2*a1-b1*a2);
      }
      return ans;
}
int main()
{
    freopen("minc.in","r",stdin);
    freopen("minc.out","w",stdout);
    srand(time(0));
    int i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
    for(i=1;i<=n;i++)  swap(p[rand()%i+1],p[rand()%i+1]);
    o=p[1];r=0;
    for(i=2;i<=n;i++)
    {
        if(dist(o,p[i])<r || fabs(dist(o,p[i])-r)<eps)  continue;
        o.x=(p[i].x+p[1].x)/2.00;o.y=(p[i].y+p[1].y)/2.00;r=dist(p[1],p[i])/2.00;
        for(j=2;j<=i-1;j++)
        {
             if(dist(o,p[j])<r || fabs(dist(o,p[j])-r)<eps)  continue;
             o.x=(p[i].x+p[j].x)/2.00;o.y=(p[i].y+p[j].y)/2.00;r=dist(p[j],p[i])/2.00;
             for(k=1;k<=j-1;k++)
             {
                  if(dist(o,p[k])<r || fabs(dist(o,p[k])-r)<eps)  continue;
                  o=geto(p[k],p[i],p[j]);
                  r=dist(o,p[i]);
             }
        }
    }
    printf("%.2lf\n",r);
    //system("pause");
    return 0;
}
