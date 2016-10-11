#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
long long n;
long long ans=0;
int main()
{
    int i,lmt;
    cin>>n;
    n=2*n+1;
    lmt=sqrt(n);
    for(i=1;i<=lmt;i++)
    if(n%i==0)
    {
       if(n/i!=i)  {ans+=i;ans+=n/i;}
       else ans+=i;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
