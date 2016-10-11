#include<iostream>
#include<stdio.h>
#include<string.h>
#include<cmath>
using namespace std;
int mu[70];
int gg[60];
bool mark[70];
bool kk[4000];
int n;
int sum,maxx;
bool o;
bool ok(int l,int gs,int now)
{
     int i;
     if(gs==0)  return 1;
     for(i=1;i<=n;i++)
     {
        if(!mark[i] && now+mu[i]<l)
        {
          mark[i]=1;;
          if(ok(l,gs,now+mu[i])) return 1;
          mark[i]=0;
        }
        if(!mark[i] && now+mu[i]==l)
        {
          mark[i]=1;;
          if(ok(l,gs-1,0)) return 1;
          mark[i]=0;
        }
     }
     return 0;
}
int main()
{
    int i,j;
    
    while(scanf("%d",&n))
    {
      if(n==0)  break;
      sum=0;maxx=0;o=0;
      memset(mark,0,sizeof(mark));
      memset(kk,0,sizeof(kk));
      kk[0]=1;
      for(i=1;i<=n;i++)
      {
       scanf("%d",&mu[i]);
       if(mu[i]>maxx)
       maxx=mu[i];
       sum+=mu[i];
      } 
      for(i=1;i<=n;i++)
      for(j=sum;j>=0;j--)
      {
       if(kk[j] && mu[i]+j<=sum)
       kk[mu[i]+j]=1; 
      }
     for(i=maxx;i<=sum-1;i++)
      {
        if(sum%i==0 && kk[i])
        if(ok(i,sum/i,0))
        {printf("%d\n",i);o=1;break;}
      }
      if(!o)  printf("%d\n",sum);
    }
    system("pause");
    return 0;
}
