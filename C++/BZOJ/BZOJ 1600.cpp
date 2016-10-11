#include<iostream> 
#include<cstdio> 
#include<cmath> 
using namespace std; 
int f[2510]; 
int n; 
int maxx; 
int main() 
{ 
    int i,j,k; 
    scanf("%d",&n); 
    f[0]=1; 
    maxx=n/2; 
    if(!(n & 1))  maxx--; 
    for(i=1;i<=4;i++) 
    for(j=n;j>=0;j--) 
    {f[j]=0; 
    for(k=1;k<=maxx;k++) 
    { 
    if(j>=k) 
    {f[j]+=f[j-k];} 
    }} 
    cout<<f[n]<<endl; 
    //system("pause"); 
    return 0; 
}