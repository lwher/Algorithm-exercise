#include<iostream> 
#include<cstdio> 
#include<algorithm> 
#include<cstring> 
using namespace std; 
int n,m,k,dp[2][151][21][21]; 
int mod=12345678; 
void work() 
{ 
    scanf("%d%d%d",&n,&m,&k); 
    int cs=1,ns=0; 
    dp[0][0][0][0]=1; 
    for(int i=0;i<n+m;i++) 
    { 
        swap(cs,ns); 
        memset(dp[ns],0,sizeof(dp[ns])); 
        for(int j=0;j<=min(i,n);j++) 
            for(int k1=0;k1<=min(j,k);k1++) 
                for(int k2=0;k2<=min(i-j,k);k2++) 
                { 
                   if(k1<k && j<n) (dp[ns][j+1][k1+1][max(k2-1,0)]%=mod)+=(dp[cs][j][k1][k2]%=mod); 
                   if(k2<k && i-j<m) (dp[ns][j][max(k1-1,0)][k2+1]%=mod)+=(dp[cs][j][k1][k2]%=mod); 
                } 
    } 
    int ans=0; 
    for(int k1=0;k1<=k;k1++) 
        for(int k2=0;k2<=k;k2++) 
        (ans+=(dp[ns][n][k1][k2]%=mod))%=mod;; 
    printf("%d\n",ans); 
} 
int main() 
{ 
    work(); 
   // system("pause"); 
    return 0; 
}