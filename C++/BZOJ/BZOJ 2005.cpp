#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cstring> 
#include<cmath> 
using namespace std; 
long long f[100010]; 
int n,m; 
long long ans; 
int main() 
{ 
    scanf("%d%d",&n,&m); 
    int i,j,t; 
    t=min(n,m);  
    for(i=t;i>=1;i--) 
    { 
        f[i]=(long long)(n/i)*(m/i); 
        for(j=2;j<=t/i;j++) 
        f[i]-=f[i*j]; 
        ans+=f[i]*((i-1)*2+1); 
    } 
    cout<<ans<<endl; 
    //system("pause"); 
    return 0; 
}