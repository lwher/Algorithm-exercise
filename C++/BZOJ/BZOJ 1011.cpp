#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long int64;
const int MAXN=1000000,T=100;
const double eps=1e-8;
int  M[MAXN],n;
double a,f[MAXN];
int main()
{
   scanf("%d %lf",&n,&a);
   int l,r,i,j;
   for (i=1;i<=n;i++) scanf("%d",&M[i]);
   for (i=1;i<=T;i++)
   {
       f[i]=0;
       r=(int)(eps+floor(a*i));
       for (j=1;j<=r;j++) f[i]+=1.0*M[i]*M[j]/(i-j);
   }
   for (i=T+1;i<=n;i++)
   {
       f[i]=0;
       r=(int)(eps+floor(a*i));
       l=(int)(eps+floor(a*(i-T)));
       for (j=l+1;j<=r;j++) f[i]+=1.0*M[i]*M[j]/(i-j);
       f[i]+=1.0*M[i]*(f[i-T]/M[i-T])*(i-T-1.0*l/2)/(i-1.0*l/2) ;
   }
   for (i=1;i<=n;i++) printf("%.6lf\n",f[i]);
   system("pause");
   return 0;

}

