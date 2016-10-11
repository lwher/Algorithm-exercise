#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int qpow(int a,int b)
{
    int s=1;
    a%=10007;
    while(b>0)
    {
        if(b & 1)  s=(s*a)%10007;
        a=(a*a)%10007;
        b=b>>1;
    }
    return s;
}
int c(int n,int k)
{
    int i;
    long long s1=1,s2=1;
    if(k<n/2) k=n-k;
    for(i=k+1;i<=n;i++)  s1=(s1*i)%10007;
    for(i=2;i<=n-k;i++)  s2=(s2*i)%10007;
    return (s1*qpow(s2,10005))%10007;
}
int main()
{
    int n,m,k,a,b;
    cin>>a>>b>>k>>n>>m;
    long int j;
    j=(((c(k,n)*qpow(a,n))%10007)*qpow(b,m))%10007;
    cout<<j<<endl;
    system("pause");
    return 0;
}
