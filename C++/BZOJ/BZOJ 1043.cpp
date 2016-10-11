#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-10
#define pi 3.14159265358
using namespace std;
struct point
{
       double x,y,r;
}p[1010];
struct line
{
     double w;int f;
}dd[5010];
int n,top;
double ans,now;
double dist(point a,point b)
{
       return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void getpoint(point a,point b,point &A,point &B)
{
      double d,k;point t;
      d=dist(a,b);
      k=(a.r*a.r+d*d-b.r*b.r)/(2.000*d*a.r);// k cos
      k=acos(k);// k-> hudu
      t.x=(b.x-a.x)/d;t.y=(b.y-a.y)/d;
      A.x=a.x+a.r*(t.x*cos(k)-t.y*(sin(k)));A.y=a.y+a.r*(t.y*cos(k)+t.x*sin(k));
      t.x=(b.x-a.x)/d;t.y=(b.y-a.y)/d;
      B.x=a.x+a.r*(t.x*cos(k)+t.y*(sin(k)));B.y=a.y+a.r*(t.y*cos(k)-t.x*sin(k));
}
inline bool comp(line a,line b)
{
       return a.w<b.w;
}
int main()
{
    int i,j,tmp;bool o;
    double d,minr,R,f1,f2,last;
    point a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  scanf("%lf%lf%lf",&p[i].r,&p[i].x,&p[i].y);    
    for(i=1;i<=n;i++)  
    {
        o=0;top=0;
        for(j=i+1;j<=n;j++)
        {
            d=dist(p[i],p[j]);
            minr=min(p[i].r,p[j].r);R=max(p[i].r,p[j].r);
            if(p[j].r>p[i].r && (d+minr<R || fabs(R-minr-d)<eps))  {o=1;break;}  
            if(d>p[i].r+p[j].r || fabs(d-p[i].r-p[j].r)<eps)  continue;
            if(fabs(R-minr-d)<eps || d+minr<R)  continue;
            getpoint(p[i],p[j],a,b);
            f1=atan2(b.y-p[i].y,b.x-p[i].x);f2=atan2(a.y-p[i].y,a.x-p[i].x);
            if(f1>f2)
            {
                dd[++top].w=f1;dd[top].f=1;
                dd[++top].w=pi;dd[top].f=-1;
                dd[++top].w=-pi;dd[top].f=1;
                dd[++top].w=f2;dd[top].f=-1;
            }
            else
            {
                dd[++top].w=f1;dd[top].f=1;
                dd[++top].w=f2;dd[top].f=-1;
            }
        }
        if(o)  continue;
        sort(dd+1,dd+1+top,comp);
        tmp=0;now=0;
        for(j=1;j<=top;j++)
        {
            if(tmp==0 && dd[j].f==1)  last=dd[j].w;
            tmp+=dd[j].f;
            if(tmp==0 && dd[j].f==-1)  now+=(dd[j].w-last)*p[i].r;
        }
        ans+=2*p[i].r*pi-now;
    }
    printf("%.3lf\n",ans);
    system("pause");
    return 0;
}
