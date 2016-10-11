#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,p;
long long jc[100010];
long long qpow(long long a,int b)
{
    a%=p;long long res=1;
    while(b>0)
    {
        if(b & 1)  res=(res*a)%p;
        b=b>>1;
        a=(a*a)%p;
    }
    return res;
}
long long Lucas(int a,int b)
{
    int nn,mm;long long res=1;
    while(a && b)
    {
        nn=a%p;mm=b%p;
        if(nn<mm) return 0;
        res=(res*jc[nn]*qpow(((jc[mm]*jc[nn-mm])%p),p-2))%p;
        a/=p;b/=p;
    }
    return res;
}
int main()
{
    int i,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&p);
        jc[0]=1;
        for(i=1;i<p;i++)  jc[i]=(jc[i-1]*i)%p;
        printf("%I64d\n",Lucas(n+m,m));
    }
    return 0;
}