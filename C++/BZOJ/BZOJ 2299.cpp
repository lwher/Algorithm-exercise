#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
long long gcd(long long a,long long b)
{
     if(b==0)  return a;
     else return gcd(b,a%b);
}
bool check(long long a,long long b,long long x)
{
     if(a%x==0 && b%x==0)  return 1;
     else return 0;
}
int main()
{
    long long a,b,x,y,d;
    int t;
    scanf("%d",&t);    
    while(t--)
    {
       // scanf("%lld%lld%lld%lld",&a,&b,&x,&y);
        scanf("%I64d%I64d%I64d%I64d",&a,&b,&x,&y);        
        if(a==0 && b==0)
        {
                if(x==0 && y==0)   printf("Y\n"); 
                else  printf("N\n");
                continue;
        }
        d=gcd(a,b);
        d=d<<1;
        if(check(x,y,d) || check(x-a,y-b,d) || check(x-b,y-a,d) || check(x-a-b,y-a-b,d)) printf("Y\n");
        else printf("N\n");
    }
    system("pause");
    return 0;
}
