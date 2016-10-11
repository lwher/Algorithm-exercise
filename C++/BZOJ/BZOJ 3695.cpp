#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
double X,x[110],h[110],v[110];
double calc(double a,double b)
{
    if(b/a<0) return 1e9;
    return sqrt(b/a);
}
int main()
{
    int i,j;
    scanf("%d%lf",&n,&X);
    for(i=1;i<=n;i++) scanf("%lf",&h[i]);
    for(i=1;i<=n;i++) scanf("%lf",&v[i]);
    double l=-100,r=0,mid,sum;        
    for(i=1;i<=100;i++)
    {
        mid=(l+r)*0.5;
        sum=0;
        for(j=1;j<=n;j++)
        {
           x[j]=calc(1-v[j]*v[j]*mid*mid,v[j]*v[j]*mid*mid*h[j]*h[j]);
           sum+=x[j];
        }
        if(sum<X) r=mid;
        else l=mid;
    }
    mid=(l+r)*0.5;
    for(j=1;j<=n;j++) x[j]=calc(1-v[j]*v[j]*mid*mid,v[j]*v[j]*mid*mid*h[j]*h[j]);
    double ans=0;
    for(i=1;i<=n;i++) ans+=sqrt(x[i]*x[i]+h[i]*h[i])/v[i];
    printf("%.3lf\n",ans);
   // system("pause");
    return 0;
}
