#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,K;
double A[1010],B[1010],res[1010];
inline int next(int x,int y)
{
    x-=y;if(x<=0)x+=n;
    return x;
}
void mul(double a[1010],double b[1010],double c[1010])
{
     int i,j;double ans[1010];
     for(i=1;i<=n;i++) 
     {
         ans[i]=0;
         for(j=1;j<=n;j++) ans[i]+=a[j]*b[next(i,j-1)];
     }
     for(i=1;i<=n;i++) c[i]=ans[i];
}
void qpow(double a[1010],int K,double ans[1010])
{
     res[1]=1;
     while(K>0)
     {
         if(K & 1) mul(res,a,res);
         mul(a,a,a);
         K=K>>1;
     }
     for(int i=1;i<=n;i++) ans[i]=res[i];
}
int main()
{
    int i,j;
    scanf("%d%d%d",&n,&m,&K);
    for(i=1;i<=n;i++) scanf("%lf",&A[i]);
    B[1]=(double)(m-1)/m;B[2]=1.00/m;
    qpow(B,K,B);
    mul(A,B,A);
    for(i=1;i<=n;i++) printf("%.3lf\n",A[i]);
    system("pause");
    return 0;
}
