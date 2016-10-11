#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-5
using namespace std;
double num[100010],total;
int n;
bool check(double mid)
{
    int i;
    double tmp,best;
    tmp=num[2]-mid;best=tmp;
    for(i=3;i<n;i++)
    {
        if(tmp<0)  tmp=0;
        tmp+=num[i]-mid;
        if(best<tmp)  best=tmp;  
    }
    if(total-n*mid-best<eps)  return 1;return 0;
}
int main()
{
    int i;double l,mid,r;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  
    {
        scanf("%lf",&num[i]);total+=num[i];
    }
    l=0;r=1e9;      
    while(r-l>eps)
    {
        mid=(l+r)*0.5;
        if(check(mid))  r=mid;
        else l=mid;
    }
    printf("%.3lf\n",l);
    //system("pause");
    return 0;
}