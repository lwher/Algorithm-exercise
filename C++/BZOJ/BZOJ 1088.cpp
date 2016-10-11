#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
using namespace std; 
int f[10010][2][2]; 
int sum[10010]; 
int n,ans; 
int main() 
{ 
    int i,j; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) 
    scanf("%d",&sum[i]); 
    if(sum[1]==0) 
    f[2][0][0]=1; 
    if(sum[1]==1) 
    f[2][0][1]=f[2][1][0]=1; 
    if(sum[1]==2) 
    f[2][1][1]=1; 
    for(i=3;i<=n;i++) 
    { 
        if(sum[i-1]==0) 
        f[i][0][0]+=f[i-1][0][0]; 
        if(sum[i-1]==1) 
        { 
            f[i][0][0]+=f[i-1][0][1]; 
            f[i][0][1]+=f[i-1][1][0]; 
            f[i][1][0]+=f[i-1][0][0]; 
        } 
        if(sum[i-1]==2) 
        { 
            f[i][0][1]+=f[i-1][1][1]; 
            f[i][1][0]+=f[i-1][0][1]; 
            f[i][1][1]+=f[i-1][1][0]; 
        } 
        if(sum[i-1]==3) 
        { 
            f[i][1][1]+=f[i-1][1][1]; 
        }    
    } 
    if(sum[n]==0) 
    ans=f[n][0][0]; 
    if(sum[n]==1) 
    ans=f[n][0][1]+f[n][1][0]; 
    if(sum[n]==2) 
    ans=f[n][1][1]; 
    cout<<ans<<endl; 
//  system("pause"); 
    return 0; 
}