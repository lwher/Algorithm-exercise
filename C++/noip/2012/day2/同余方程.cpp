#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int x,y;
int exgcd(int a,int b)
{
    if(b==0)
    {
         x=1;y=0;
         return a;
    }
    int d=exgcd(b,a%b);
    int t=x;
    x=y;
    y=t-(a/b)*y;
    return d;
}
int main()
{
    int a,b;
    cin>>a>>b;
    exgcd(a,b);
    x=(x%b+b)%b;
    if(x==0) x+=b;
    cout<<x<<endl;
    system("pause");
    return 0;
}
