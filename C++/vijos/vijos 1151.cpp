#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
double  x1[70],x2[70],xd[70];
double a[70],d;
int n,m;
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    scanf("%lf%lf%lf",&d,&a[1],&a[n]);
    x1[1]=1;x2[1]=0;xd[1]=0;
    x2[2]=1;x1[2]=0;xd[2]=0;
    for(i=3;i<=n;i++)
    {
        x1[i]=x1[i-2]-2*x1[i-1];
        x2[i]=x2[i-2]-2*x2[i-1];
        xd[i]=xd[i-2]-2*xd[i-1]+2;
    }
    a[2]=(a[n]-xd[n]*d-x1[n]*a[1])/x2[n];
    a[m]=xd[m]*d+x1[m]*a[1]+x2[m]*a[2];
    printf("%.3lf\n",a[m]);
    system("pause");
    return 0;
}
