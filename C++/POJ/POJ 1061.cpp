#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int  n,m,l,x,y;
long long xx,yy;
int gcd(int a,int b)
{
    if(b==0)
    {
      xx=1;
      yy=0;
      return a;
    }
    int d=gcd(b,a%b);
    int temp=xx;
    xx=yy;
    yy=temp-(a/b)*yy;
    return d;
}
int main()
{
       long long  a;
       long long  b;
       long long  c;
       long long  d;
    cin>>x>>y>>m>>n>>l;
    long long r;
       a=n-m;
       b=l;
       c=x-y;
    if (a<0)
    {
        a=-a;
        c=-c;
    }
    r=gcd(a,l);
    if((x+y)%r!=0)
    cout<<"Impossible";
    else
    {
        a=a/r;
        b=b/r;
        c=c/r;
       d=gcd(a,b);
       xx=((xx*c)%b+b)%b;
       if(!xx)
       xx+=b;
       cout<<xx<<endl;
    }
  //  system("pause");
    return 0;
}

