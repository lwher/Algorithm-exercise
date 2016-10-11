#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int gcd(int a,int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int i,n,x,q=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x==0)  continue;
        if(x<0)  x=-x;
        q=gcd(q,x);
    }
    cout<<q<<endl;
    system("pause");
    return 0;
}
