#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
long long gcd(long long a,long long b)
{
     if(b==0)  return a;
     return gcd(b,a%b);
}
int main()
{
    long long a,b;
    int t=10;
    while(t--)
    {
          cin>>a>>b;
          cout<<a+b-gcd(a,b)<<endl;    
    }
    system("pause");
    return 0;
}
