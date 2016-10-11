#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 10000001
using namespace std;
long long ans[N],Inv[N],jc[N];
int tot,prime[1000000],p;
bool mark[N];
void work()
{
    int i,j;
    for(i=2;i<N;i++)  
    {
        if(!mark[i])  prime[++tot]=i;
        for(j=1;j<=tot;j++)
        {
            if((long long)(i)*prime[j]>=N)  break;
            mark[i*prime[j]]=1;
            if(i%prime[j]==0) break;
        }
    }
    Inv[1]=1;jc[1]=1;ans[1]=1;
    for(i=2;i<N;i++) jc[i]=(jc[i-1]*i)%p;
    for(i=2;i<N;i++)  
    {
        if(i>=p)  break;
        Inv[i]=(Inv[p%i]*(p-p/i))%p;
    }
    for(i=2;i<N;i++)
    {
        if(!mark[i])
        {
            ans[i]=(ans[i-1]*(i-1))%p;
            ans[i]=(ans[i]*Inv[i%p])%p;
        }
        else ans[i]=ans[i-1];
    }
}
int main()
{
    int t,n,m;
    long long res;
    scanf("%d%d",&t,&p);
    work();
    while(t--)
    {
        scanf("%d%d",&n,&m);
        res=jc[n];
        res=(res*ans[m])%p;
        printf("%lld\n",res);
    }
    return 0;
}