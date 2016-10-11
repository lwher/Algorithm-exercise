#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int m,t,n;
double p[1010][31];
double f[1010][31][31];
int main()
{
    int i,j,k;
    while(scanf("%d%d%d",&m,&t,&n))
    {
         if(m==0 && t==0 && n==0)  break;
         for(i=1;i<=t;i++)  for(j=1;j<=m;j++)  scanf("%lf",&p[i][j]);
         memset(f,0,sizeof(f));
         for(i=1;i<=t;i++)  f[i][0][0]=1;
         for(i=1;i<=t;i++)
         for(j=1;j<=m;j++)
         for(k=0;k<=j;k++)
         {
            if(k)  f[i][j][k]+=f[i][j-1][k-1]*p[i][j];
            f[i][j][k]+=f[i][j-1][k]*(1-p[i][j]);
         }
         double ans=1,temp=1,sum;
         for(i=1;i<=t;i++)  ans*=(1-f[i][m][0]);
         for(i=1;i<=t;i++)
         {
             sum=0;
             for(j=1;j<n;j++)  sum+=f[i][m][j];
             temp*=sum;
         }
         printf("%.3lf\n",ans-temp);    
    }
    system("pause");
    return 0;
}
