#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define eps 1e-5
using namespace std;
int n,K;
double A[1010],B[1010],p[1010];
int main()
{
    int i;double tmp,l,r,mid;
    while(scanf("%d%d",&n,&K))
    {
        if(n==0 && K==0) break;
        for(i=1;i<=n;i++) scanf("%lf",&A[i]);
        for(i=1;i<=n;i++) scanf("%lf",&B[i]);
        l=0;r=1e15;
        while(r-l>eps)
        {
            mid=(l+r)*0.5;tmp=0;
            for(i=1;i<=n;i++)  p[i]=A[i]-B[i]*mid;
            sort(p+1,p+1+n);
            for(i=K+1;i<=n;i++) tmp+=p[i];
            if(tmp>0) l=mid;
            else r=mid;
        }
        printf("%.0lf\n",l*100.0);
    }
    return 0;
}