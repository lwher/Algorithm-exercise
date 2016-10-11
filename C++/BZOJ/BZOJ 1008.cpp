#include<iostream> 
#include<stdio.h> 
#include<cmath> 
using namespace std; 
long long qpow(long long a,long long b) 
{ 
    long long ans=1; 
    a%=100003; 
    while(b>0) 
    { 
        if(b & 1) 
        {ans*=a;ans%=100003;} 
        a*=a; 
        a%=100003; 
        b/=2; 
    } 
    return ans; 
} 
long long n,m; 
int main() 
{ 
    cin>>m>>n; 
    long long a,b; 
    a=qpow(m,n); 
    b=qpow(m-1,n-1); 
    b*=(m%100003); 
    b%=100003; 
    long long ans=a-b; 
    while(ans<0) 
    ans+=100003; 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}