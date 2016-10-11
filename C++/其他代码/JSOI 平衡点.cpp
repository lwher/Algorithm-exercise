#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-9
using namespace std;
struct point
{
    double x,y,w;
}ans,p[1001];
int n;
double dist(point a,point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
int main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
       scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].w);
       ans.x+=p[i].w*p[i].x;ans.y+=p[i].w*p[i].y;
    }    
    ans.x/=n;ans.y/=n;
    double t=10000,x,y;
    while(t>eps)
    {
        x=0;y=0;
        for(i=1;i<=n;i++)
        {
            x+=(p[i].x-ans.x)/dist(p[i],ans)*p[i].w;
            y+=(p[i].y-ans.y)/dist(p[i],ans)*p[i].w;
        }
        ans.x+=t*x;
        ans.y+=t*y;
        t*=0.99;
    }
    printf("%.3lf %.3lf\n",ans.x,ans.y);
    return 0;
}
