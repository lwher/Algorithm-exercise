#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
using namespace std;
 
int n,K,dp[100010][12],w[100010][12];
 
void solve(){
	if(!K){
		printf("%d\n",n);
		return;
	}
	for(int j=0;j<=K;j++){
		for(int i=1;i<=n;i++){ 
			dp[i][j]=i;w[i][j]=1;
			if(!j) continue;
			for(int k=w[i-1][j];k<=min(i,w[i-1][j]+50);k++) 
				if(dp[i][j]>max(dp[k-1][j],dp[i-k][j-1])+1)
					dp[i][j]=max(dp[k-1][j],dp[i-k][j-1])+1,w[i][j]=k;
		}
	}
	printf("%d\n",dp[n][K-1]);
}
 
int main()
{
	scanf("%d%d",&n,&K);
	solve();
	return 0;
}
