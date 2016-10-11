#include<iostream>
#include<cstdio>
#include<cstdlib>
#define P 1000000009
using namespace std;
int main()
{
    long long ans=1;
    int i,n;
    cin>>n;n*=2;
    for(i=1;i<=n;i+=2)  ans=(ans*i)%P;
    cout<<ans<<endl;  
    system("pause");
    return 0;
}
