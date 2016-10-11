#include<iostream>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,K,num[300001],sumlen,len;//len,len+1
std::vector<long long> dp[300001];
int main(){
	int now;
	scanf("%d%d",&n,&K);
	for(int i=1;i<=n;i++) scanf("%d",&num[i]);
	sort(num+1,num+1+n);
	len=n/K;sumlen=K-n%K;
	dp[0].push_back(0LL);			
	for(int i=1;i<=K;i++){
		int k=min(sumlen,i);
		for(int j=0;j<=k;j++){
			now=j*len+(i-j)*(len+1);
			long long tmp=(1LL<<60);
			if(j>0) tmp=min(tmp,dp[i-1][j-1]+num[now]-num[now-len+1]);
			if(i>j) tmp=min(tmp,dp[i-1][j]+num[now]-num[now-len]);
			dp[i].push_back(tmp);
		}
	}
	cout<<dp[K][sumlen]<<endl;
	return 0;
}

