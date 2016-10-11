#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
using namespace std;
double r,pi=3.1415926,ans;
double x[110],y[110];
int n;
double juli(int a,int b)
{
       return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
int main()
{
    scanf("%d%lf",&n,&r);
    int i;
    for(i=1;i<=n;i++) scanf("%lf%lf",&x[i],&y[i]);
    for(i=2;i<=n;i++)  ans+=juli(i-1,i);
    ans+=juli(n,1);ans+=r*2*pi;
    printf("%.2lf\n",ans);
    system("pause");
    return 0;
}
