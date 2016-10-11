#include<iostream> 
using namespace std; 
int main (void) 
{ 
    long long n,d,k,s; 
    cin>>n; 
    d=1;s=1;k=1; 
    while (k<n) 
    { 
      d=d+d; 
      k+=d; 
      s++; 
    } 
    cout<<s; 
}