#include<iostream>
#include<map>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int n,m,A[1010][1010],dp[1010][1010];
void init(){
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&A[n-i+1][j]);
}
void solve(){
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++){
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        dp[i][j]=max(dp[i][j],dp[i-1][j-1]+A[i][j]);
    }
    cout<<dp[n][m]<<endl;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        init();
        solve();
    }
    return 0;
}
