#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int T,n;
double p,q;
double get_AA,get_AB,get_BA,get_BB;
double pop_AA,pop_AB,pop_BA,pop_BB;
double f[110],s[110];
int main()
{
    double k;scanf("%d",&T);
    while(T--)
    {
        f[0]=0;s[0]=1;
        scanf("%d%lf%lf",&n,&p,&q);
        if(n>100)  n=100;
        k=1-(1-p)*(1-q);
        get_AA=p/k;get_AB=(1-p)*q/k;
        get_BB=q/k;get_BA=(1-q)*p/k;
        k=1-p*q;
        pop_AA=(1-p)/k;pop_AB=(1-q)*p/k;
        pop_BA=q*(1-p)/k;pop_BB=(1-q)/k;
        for(int i=1;i<=n;i++)
        if(f[i-1]<s[i-1])
        {
             f[i]=get_AA*s[i-1]+get_AB*f[i-1];
             s[i]=get_BA*s[i-1]+get_BB*f[i-1];
        }
        else
        {
             f[i]=pop_AB*f[i-1]+pop_AA*s[i-1];
             s[i]=pop_BB*f[i-1]+pop_BA*s[i-1];
        }
        printf("%.6lf\n",f[n]);
    }
    return 0;
}