#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define eps 1e-8
using namespace std;
int n;
double a,b;
double calc(double ba,double fl,double fr,double fmid)
{
    return  (fl+fr+4*fmid)*ba/6.00;
}
double f(double x)
{
    return 2*sqrt(b*b-x*x*b*b/(a*a));
}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double s)
{
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
    double fm1=f(m1),fm2=f(m2);
    double s1=calc(mid-l,fl,fmid,fm1),s2=calc(r-mid,fmid,fr,fm2);
    if(fabs(s-s1-s2)<eps)  return s1+s2;
    return simpson(l,m1,mid,fl,fm1,fmid,s1)+simpson(mid,m2,r,fmid,fm2,fr,s2);
}
int main()
{
    double l,r,mid;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&l,&r);
        mid=(l+r)*0.5;
        printf("%.3lf\n",simpson(l,mid,r,f(l),f(mid),f(r),calc(r-l,f(l),f(r),f(mid))));
    }
    //system("pause");
    return 0;
}