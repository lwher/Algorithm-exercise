#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

using namespace std;

long long prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};

long long bestSum;
long long bestRes;
long long N;
void work(long long res,long long sum,int k,long long limit)
{
    if(res>N)
    return;
    if(sum>bestSum)
    {
        bestSum=sum;
        bestRes=res;
    }
    else if(sum==bestSum && res<bestRes)
    {
        bestRes=res;
    }
    if(k>=16)
    return;

    long long p=prime[k];
    for(long long i=1;i<=limit;i++,p*=prime[k])
    {
        if(res*p>N)
        break;
        work(res*p,sum*(i+1),k+1,i);
    }
}
int main()
{
    //freopen("input.txt","r",stdin);
    while(scanf("%lld",&N)!=EOF)
    {
        bestSum=1LL;
        bestRes=1LL;
        work(1LL,1LL,0,50LL);
        printf("%lld\n",bestRes);
    }
    return 0;
}
