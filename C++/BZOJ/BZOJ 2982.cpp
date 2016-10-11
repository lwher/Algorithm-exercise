#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define mod 10007
using namespace std;
int n,m,jc[mod];
int qpow(int a,int b)
{
    int res=1;
    while(b>0)
    {
       if(b & 1) res=(res*a)%mod;
       a=(a*a)%mod;
       b>>=1;
    }
    return res;
}
int solve()
{
    int res=1,A,B,C;
    while(n>0 && m>0)
    {
        A=n%mod;B=m%mod;
        if(A<B) return 0;
        C=(jc[A-B]*jc[B])%mod;
        C=(jc[A]*qpow(C,mod-2))%mod;
        res=(res*C)%mod;
        n/=mod;m/=mod;
    }
    return res;
}
int main()
{
    int T;
    jc[0]=1;
    for(int i=1;i<=mod;i++) jc[i]=(jc[i-1]*i)%mod;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);   
        printf("%d\n",solve());
    }
    return 0;
}