#include<iostream>
#include<cmath>
#include<stdio.h>
#define eps 1e-8
using namespace std;
long long r;
long long d,u,v;
double v1;
long long vv;
long long ans;
long long  gcd(long long  a,long long  b)
{
    if(b==0)
    return a;
    return gcd(b,a%b);
}
int main()
{
    cin>>r;
    r*=2;
    long long k;
    for(d=1;d<=sqrt(r);d++)
    {
       if(r%d==0)
       {
          k=r/d;
          for(u=1;u<=sqrt(r/d);u++)
          {
              vv=k-u*u;
              v1=sqrt(vv);
              v=(int) sqrt(vv);
              if(v1-v<eps)
              {
                  if(u<v && gcd(u,v)==1)
                  {
                       ans++;
                  }
              }
          }
           if(d*d==r)  continue;
           k=d;
           for(u=1;u<=sqrt(d);u++)
          {
              vv=k-u*u;
              v1=sqrt(vv);
              v=(int) sqrt(vv);
              if(v1-v<eps)
              {
                  if(u<v && gcd(u,v)==1)
                  {
                       ans++;
                  }
              }
          }
       }
      
       
    }
    ans*=4;
    ans+=4;
    cout<<ans<<endl;
    system("pause");
    return 0;
}
