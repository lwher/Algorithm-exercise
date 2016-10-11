#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define N 50001
using namespace std;
int prime[50010],tot,mu[50010],sum[50010];
bool mark[50010];
void getmu()
{
    int i,j;
    mu[1]=1;
    for(i=2;i<=N;i++)
    {
        if(!mark[i])  {prime[++tot]=i;mu[i]=-1;}
        for(j=1;j<=tot;j++)
        {
            if(prime[j]*i>N)  break;
            mark[prime[j]*i]=1;
            if(i%prime[j]==0)
            {
                mu[i*prime[j]]=0;break;
            }
            else mu[i*prime[j]]=-mu[i];
        }
    }
    for(i=1;i<=N;i++)  sum[i]=sum[i-1]+mu[i];
}
int getsum(int n,int m)
{
    int i,j,tmp=0,limt=min(n,m);
    for(i=1;i<=limt;i=j+1)
    {
        j=min(n/(n/i),m/(m/i));
        tmp+=(sum[j]-sum[i-1])*(n/i)*(m/i);
    }
    return tmp;
}
int main()
{
    int T,a,b,c,d,k,ans;
    getmu();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d%d",&a,&b,&c,&d,&k);
        ans=getsum(b/k,d/k)-getsum((a-1)/k,d/k)-getsum(b/k,(c-1)/k)+getsum((a-1)/k,(c-1)/k);
        printf("%d\n",ans);
    }
    return 0;
}