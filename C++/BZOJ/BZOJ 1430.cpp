#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define mod 9999991
using namespace std;
int n;
long long qpow(long long a,int b)
{
    a%=mod;long long res=1;
    while(b>0)
    {
        if(b & 1)  res=(res*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return res;
}
int main()
{
    long long ans=1;
    scanf("%d",&n);
    for(int i=2;i<n;i++)  ans=(ans*i)%mod;
    ans=(ans*qpow(n,n-2))%mod;
    cout<<ans<<endl;
    return 0;
}