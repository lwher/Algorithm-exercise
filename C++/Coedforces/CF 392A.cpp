#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long long ans=0,n;
    long long i,j,pre;
    cin>>n; 
    pre=n;
    if(n==0)  printf("1\n");
    else
    {
        for(i=1;i<=n;i++)
        {
            j=(long long)(sqrt(n*n-i*i));
            if(pre-j>0)  ans+=pre-j;
            else   ans++;
            pre=j;
        }
        ans*=4;
        cout<<ans<<endl;
    }
//  system("pause");
    return 0;
}