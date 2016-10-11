#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n,K;
long long A[2],B[2][2],ans[2],C[2][2];
void mul(long long a[2][2],long long b[2][2],long long c[2][2])
{
     int i,j,k,d[2][2]={0};
     for(i=0;i<2;i++) for(j=0;j<2;j++) for(k=0;k<2;k++)
     d[i][j]=(d[i][j]+(a[i][k]*b[k][j])%mod)%mod;
     for(i=0;i<2;i++) for(j=0;j<2;j++) c[i][j]=d[i][j];
}
void qpow(long long p[2][2],int b,long long c[2][2])
{
     long long now[2][2]={0},a[2][2];
     int i,j;
     for(i=0;i<2;i++) now[i][i]=1;
     for(i=0;i<2;i++) for(j=0;j<2;j++) a[i][j]=p[i][j];
     while(b>0)
     {
         if(b & 1)  mul(now,a,now);
         mul(a,a,a);
         b>>=1;
     }
     for(i=0;i<2;i++) for(j=0;j<2;j++) c[i][j]=now[i][j];
}  
int main()
{
    freopen("fib.in","r",stdin);
    freopen("fib.out","w",stdout);
    int T,i,j;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&K);
        A[0]=0;A[1]=1;
        B[0][0]=0;
        B[0][1]=B[1][0]=B[1][1]=1;        
        qpow(B,n+1,C);
        for(i=0;i<2;i++) for(j=0;j<2;j++) C[i][j]=(C[i][j]+mod-B[i][j])%mod;
        qpow(C,K,C);
        ans[0]=0;ans[1]=0;
        for(i=0;i<2;i++) for(j=0;j<2;j++)  ans[i]=(ans[i]+(C[j][i]*A[j])%mod)%mod;
        printf("%lld\n",ans[1]);
    }
   // system("pause");
    return 0;
}
