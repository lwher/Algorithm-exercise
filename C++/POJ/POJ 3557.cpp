#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,c[31][31];
double p,dp[30];
void calc()
{
     int i,j;
     c[0][0]=1;
     for(i=1;i<=21;i++)
     {
        c[i][0]=1; 
        for(j=1;j<=i;j++)  c[i][j]=c[i-1][j-1]+c[i-1][j];
     }
}
double qpow(double a,int b)
{
       double now=1;
       while(b>0)
       {
           if(b & 1)  now*=a;
           a*=a;
           b=b>>1;
       }
       return now;
}
int main()
{
    int i,j,k;
    calc();
    while(scanf("%d%lf",&n,&p)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        dp[1]=1;
        for(i=2;i<=n;i++)
        {
            double tmp=0;
            for(j=1;j<i;j++)   tmp+=c[i-1][j-1]*qpow(1-p,j*(i-j))*dp[j];
            dp[i]=1-tmp;
        }
        printf("%.5lf\n",dp[n]);
    }
    system("pause");
    return 0;
}
