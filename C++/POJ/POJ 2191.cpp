#include<ctime>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
long long factor[100],fac_top = -1;
long long ran[1000000],ID;
long long  Rand()
{
    srand(ran[ID++%1000000]);
    return rand();
}
long long gcd(long long a,long long b)
{
    if(a==0)
        return b;
    long long c;
    while(b!=0)
    {
        c=b;
        b=a%b;
        a=c;
    }
    return a;
}
//ret = (a*b)%n (n<2^62)
long long muti_mod(long long a,long long b,long long n)
{
    long long  exp = a%n, res = 0;
    while(b)
    {
        if(b&1)
        {
            res += exp;
            if(res>n) res -= n;
        }
        exp <<= 1;
        if(exp>n)
            exp -= n;

        b>>=1;
    }
    return res;
}
// ret = (a^b)%n
long long mod_exp(long long a,long long p,long long m)
{
    long long exp=a%m, res=1; //
    while(p>1)
    {
        if(p&1)//
            res=muti_mod(res,exp,m);
        exp = muti_mod(exp,exp,m);
        p>>=1;
    }
    return muti_mod(res,exp,m);
}
bool miller_rabin(long long n, long long times)
{
    if(n==2)return 1;
    if(n<2||!(n&1))return 0;

    long long a, u=n-1, x, y;
    int t=0;
    while(u%2==0)
    {
        t++;
        u/=2;
    }
    for(int i=0; i<times; i++)
    {
        a = Rand() % (n-1) + 1;
        x = mod_exp(a, u, n);
        for(int j=0; j<t; j++)
        {
            y = muti_mod(x, x, n);
            if ( y == 1 && x != 1 && x != n-1 )
                return false;
            x = y;
        }
        if( y!=1) return false;
    }
    return true;
}
long long pollard_rho(long long n,int c)
{
    long long x,y,d,i = 1,k = 2;
    x = Rand()%(n-1)+1;
    y = x;
    while(true)
    {
        i++;
        x = (muti_mod(x,x,n) + c) % n;
        d = gcd(y-x, n);
        if(1 < d && d < n)
            return d;
        if( y == x)
            return n;
        if(i == k)
        {
            y = x;
            k <<= 1;
        }
    }
}
void findFactor(long long n,int k)
{
    if(n==1)return;
    if(miller_rabin(n, 6))
    {
        factor[++fac_top] = n;
        return;
    }
    long long p = n;
    while(p >= n)
        p = pollard_rho(p,k--);
    findFactor(p,k);
    findFactor(n/p,k);
}
int main()
{
    for(int tt=0; tt<1000000; tt++)
        ran[tt]=tt;
    random_shuffle(ran,ran+1000000);
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        for(int i=11; i<=k; i++)
        {
            ID=0;
            if(!miller_rabin((long long)i,30))
                continue;
            long long n=(1ll<<i)-1;
            ID=0;
            fac_top=-1;
            if(!miller_rabin(n,30))
            {
                findFactor(n,107);
                sort(factor,factor+fac_top+1);
                for(int j=0; j<fac_top; j++)
                    printf("%lld * ",factor[j]);
                printf("%lld = %lld = ( 2 ^ %d ) - 1\n",factor[fac_top],n,i);
            }
        }
    }
    return 0;
}
