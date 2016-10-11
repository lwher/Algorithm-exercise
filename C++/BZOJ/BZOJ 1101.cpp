#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int tot,prime[50010],u[50010];
int n,m,d;
bool mark[50010];
void getu()
{
     int i,j;
     u[1]=1;
     for(i=2;i<=50000;i++)
     {
         if(!mark[i])  {prime[++tot]=i;u[i]=-1;}
         for(j=1;j<=tot;j++)
         {
             if(i*prime[j]>50000)  break;
             mark[i*prime[j]]=1;
             if(i%prime[j]==0)  {u[i*prime[j]]=0;break;}
             else  u[i*prime[j]]=-u[i];
         }
     }
     for(i=1;i<=50000;i++)  u[i]+=u[i-1];
}
int main()
{
    int i,j,k,T;
    long long ans;
    getu();
    scanf("%d",&T);
    while(T--)
    {
       scanf("%d%d%d",&n,&m,&d);
       n/=d;m/=d;
       k=min(n,m);ans=0;
       for(i=1;i<=k;i=j+1)
       {
           j=min(n/(n/i),m/(m/i));
           ans+=(long long)(n/i)*(m/i)*(u[j]-u[i-1]);
       }
       printf("%lld\n",ans);
    }
    return 0;
}