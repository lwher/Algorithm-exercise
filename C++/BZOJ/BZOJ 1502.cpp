#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define eps 1e-6
using namespace std;
int n;
double alp,x[510],h,R[510],fx1[510],fy1[510],fx2[510],fy2[510];
double sqr(double t) {return t*t;}
double calc(double ba,double fl,double fmid,double fr)
{
    return (fl+fr+4*fmid)*ba/6;
}
double f(double w)
{
    double sum=0;
    for(int i=1;i<=n;i++)
    {
        if(fabs(x[i]-w)<R[i]) sum=max(sum,sqrt(sqr(R[i])-sqr(x[i]-w)));
        if(x[i+1]-x[i]>fabs(R[i+1]-R[i]) && fx1[i]<w && w<fx2[i])
        sum=max(sum,(fy2[i]-fy1[i])/(fx2[i]-fx1[i])*(w-fx1[i])+fy1[i]);
    }
    return sum;
}
double simpson(double l,double mid,double r,double fl,double fmid,double fr,double s)
{
    double m1=(l+mid)*0.5,m2=(mid+r)*0.5;
    double fm1=f(m1),fm2=f(m2);
    double s1=calc(mid-l,fl,fm1,fmid),s2=calc(r-mid,fmid,fm2,fr);
    if(fabs(s-s1-s2)<eps)  return s1+s2;
    return simpson(l,m1,mid,fl,fm1,fmid,s1)+simpson(mid,m2,r,fmid,fm2,fr,s2);
}
int main()
{
    int i;
    scanf("%d%lf",&n,&alp); alp=1/tan(alp);
    for(i=1;i<=n+1;i++)  {scanf("%lf",&x[i]);h+=x[i];x[i]=h*alp;}
    double l=x[n+1],r=l;
    for(i=1;i<=n;i++)  
    {
        scanf("%lf",&R[i]);
        l=min(l,x[i]-R[i]);
        r=max(r,x[i]+R[i]);
    }  
    for(i=1;i<=n;i++)
    {
        fx1[i]=x[i]+R[i]*(R[i]-R[i+1])/(x[i+1]-x[i]),fy1[i]=sqrt(sqr(R[i])-sqr(fx1[i]-x[i])),
        fx2[i]=x[i+1]+R[i+1]*(R[i]-R[i+1])/(x[i+1]-x[i]),fy2[i]=sqrt(sqr(R[i+1])-sqr(fx2[i]-x[i+1]));
    }
    double mid=(l+r)*0.5;
    double fl=f(l),fr=f(r),fmid=f(mid);
    printf("%.2lf\n",2*simpson(l,mid,r,fl,fmid,fr,calc(r-l,fl,fmid,fr)));
    //system("pause");
    return 0;
}