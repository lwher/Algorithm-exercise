#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
double g[10010],f[10010],n;
int main()
{
    int i;scanf("%lf",&n);
    for(i=n-1;i>=0;i--)  g[i]=g[i+1]+n/(n-i);
    for(i=n-1;i>=0;i--)  f[i]=f[i+1]+g[i+1]+(n*i)/((n-i)*n)*g[i]+n/(n-i);
    printf("%.2lf\n",f[0]);
    return 0;
}