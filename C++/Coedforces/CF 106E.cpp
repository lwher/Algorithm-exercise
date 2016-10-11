#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int n;
double x[101],y[101],z[101];
double xx,yy,zz;
double sqr(double a)
{
    return a*a;
}
int main()
{
    int i,j,u;
    cin>>n;
    for(i=1;i<=n;i++)
    cin>>x[i]>>y[i]>>z[i];
    xx=0;yy=0;zz=0;
    double d=1;
    double maxx;
    for(i=1;i<=100000;i++)
    {
        maxx=-1;
        for(j=1;j<=n;j++)
        {
            if(sqr(xx-x[j])+sqr(yy-y[j])+sqr(zz-z[j])>maxx)
            {maxx=sqr(xx-x[j])+sqr(yy-y[j])+sqr(zz-z[j]);u=j;}  
        }
            xx+=d*(x[u]-xx);
            yy+=d*(y[u]-yy);
            zz+=d*(z[u]-zz);
            d*=0.999;
    }
    printf("%.7lf %.7lf %.7lf",xx,yy,zz);
   // system("pause");
    return 0;
}
