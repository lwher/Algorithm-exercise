#include<iostream>
#include<stdio.h>
#include<cmath>
#include<sstream>
#include<string>
using namespace std;
long long zr[13]={0,9,90,900,9000,90000,900000,9000000,90000000,900000000};
long long pf[20]={0,3,6,22,68,217,683,2163,6837,21623,68377,216228,683772,2162278,6837722,21622777,68377223,216227767,883772233};
long long sz[13]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

long long o;
int sstr(long long i,long long  j)
{
        int y=0;
        long long k=i;
        if(!j) return k%10;
        while(k>0)
        {
           k/=10;
           y++;
        }
        k=i;
        y=y-j;
        while(y>0)
        {
          k/=10;
          y--;
        }
        return k%10;
}
int qiu(long long kk)
{
    int u;
    int i;
    long long j;
    int a,b;
    long long k;
    long long l,now;
    long long p=1;
     k=kk;
       for(i=1;i<=13;i++)
       {
          if(k-(long long)zr[i]*i>0)
          k-=(long long)zr[i]*i;
          else
          {
             j=k/i;
             k-=i*j;
             now=sz[i-1]+j-1;
             if(k)
             now++;
             a=sstr(now,k);
             break;
          }
       }
       
       k=kk;
       for(i=1;i<=20;i++)
       {
          if(k-(long long)pf[i]*i>0)
          k-=(long long) pf[i]*i;
          else
          {
             for(u=1;u<=i-1;u++)
             p*=10;
             j=k/i;
             k-=i*j;
             now=(long long)(sqrt(p));
             if(now*now==p)
             now--;
             now=now+j;
             if(k)
             now++;
             b=sstr(now*now,k);
             break;
          }
       }
       return a+b;
}
int main()
{
    int a,b;
    while(cin>>o)
    {
    
      a=qiu(o);
      o++;
      b=qiu(o);
      while(b>=9)
      {
         if(b>9) {a++;break;}
         else
         {
         o++;
         b=qiu(o);
         }
      }
      printf("%d\n",a%10);
    }
    system("pause");
    return 0;
}
