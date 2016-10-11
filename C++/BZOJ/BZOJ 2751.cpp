#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1000000007;
struct sth
{
    int w,num;
}xz[100010];
int m,k;
long long n;
inline bool comp(sth a,sth b)
{
    if(a.w==b.w)  return a.num<b.num;
    return a.w<b.w;
}
long long qpow(long long a,int b)
{
    long long tmp=1;a%=mod;
    while(b>0)
    {
        if(b & 1) tmp=(tmp*a)%mod;
        a=(a*a)%mod;
        b=b>>1;
    }
    return tmp;
}
int main()
{
    cin>>n>>m>>k;
    int i,x,y;long long ans=1,sum,now;
    sum=(n+1)*n/2;
    for(i=1;i<=k;i++)
    {
        scanf("%d%d",&x,&y);
        xz[i].w=x;xz[i].num=y;
    }
    sort(xz+1,xz+1+k,comp); now=sum;
    for(i=1;i<=k+1;i++)
    {
        if(i!=1 && xz[i].w!=xz[i-1].w){m--;ans=(ans*(now%mod))%mod; now=sum-xz[i].num;}
        else  if(xz[i].num!=xz[i-1].num)  now-=xz[i].num;
         
    }
    ans=(ans*qpow(sum,m))%mod;
    cout<<ans<<endl;
    //system("pause");
    return 0;
}