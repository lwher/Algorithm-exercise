#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n;bool flag;
long long x,y;
long long exgcd(long long a,long long b)
{
     if(!b) 
     {
         x=1;y=0;
         return a;
     }
     long long d=exgcd(b,a%b);
     long long t=x;
     x=y;
     y=t-a/b*y;
     return d;
}
int main()
{
    long long a,b,A,B,a1,b1,c1,d;
    while(scanf("%d",&n)!=EOF)
    {        
        flag=0;n--;
        scanf("%I64d%I64d",&A,&B);                
        while(n--)
        {
            scanf("%I64d%I64d",&a,&b);
            if(flag) continue;
            a1=A;b1=a;c1=b-B;
            d=exgcd(a1,b1);
            if(c1%d!=0) {flag=1;continue;}
            a1/=d;b1/=d;c1/=d;
            exgcd(a1,b1);
            x=(x%b1+b1)%b1;
            x=((x*c1)%b1+b1)%b1;
            if(!x) x+=b1;
            B=x*A+B;A=a1*b1*d;
            B%=A;
        }
        if(flag) cout<<-1<<endl; 
        else {if(!B) B+=A;cout<<B<<endl;}
    }
    return 0;
}
