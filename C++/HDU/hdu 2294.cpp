#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define mod 1234567891
using namespace std;
int n,K;
void mul(long long a[][31],long long b[][31],long long c[][31])
{
    int i,j,k;
    long long d[31][31]={0};
    for(i=0;i<=K;i++)
    for(j=0;j<=K;j++)
    {
        for(k=0;k<=K;k++)  
        {
            d[i][j]+=(a[i][k]*b[k][j])%mod;
            d[i][j]%=mod;
        }
    }
    for(i=0;i<=K;i++)  for(j=0;j<=K;j++)  c[i][j]=d[i][j];
}
int main()
{
    int i,j,T;
    long long a[31],b[31][31],c[31][31],ans[31];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&K);
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(ans,0,sizeof(ans));
        a[1]=K;
        for(i=0;i<=K;i++) c[i][i]=1;
        for(i=1;i<=K;i++)
        {
            b[i][i]=i;
            if(i>1) b[i-1][i]=K-i+1;
        }
        b[0][0]=1;b[K][0]=1;                
        while(n>0)
        {
            if(n & 1)  mul(c,b,c);
            n=n>>1;
            mul(b,b,b);
        }        
        for(i=0;i<=K;i++)  
        {
            for(j=0;j<=K;j++)
            {
                ans[i]+=(a[j]*c[j][i])%mod;
                ans[i]%=mod;
            }
        }
        printf("%I64d\n",ans[0]);
    }
    return 0;
}