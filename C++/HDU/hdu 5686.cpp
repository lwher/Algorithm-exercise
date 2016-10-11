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

int n;

struct HPC{
	int num[101];
}dp[210][2];

void print(const HPC &A){
	printf("%d",A.num[A.num[0]]);
	for(int i=A.num[0]-1;i>0;i--) printf("%.4d",A.num[i]);
	printf("\n");
}

HPC operator +(const HPC &a,const HPC &b){
	HPC ans;int &len=ans.num[0],L=max(a.num[0],b.num[0]);
	memset(ans.num,0,sizeof(ans.num));
	for(int i=1;i<L;i++){
		ans.num[i]+=a.num[i]+b.num[i];ans.num[i+1]+=ans.num[i]/10000;ans.num[i]%=10000;
	}
	len=L;ans.num[len]+=a.num[len]+b.num[len];
	for(;ans.num[len]>=10000;len++){
		ans.num[len+1]+=ans.num[len]/10000;ans.num[len]%=10000;
	}
	return ans;
}

int main(){
	dp[1][1].num[0] = 1; dp[1][1].num[1] = 1;
	dp[1][0].num[0] = 1;
	for(int i = 2; i <= 200; i++){
		dp[i][0] = dp[i - 1][1];
		dp[i][1] = dp[i - 1][1] + dp[i - 1][0];
	}
	while(scanf("%d", &n) != EOF){
		print(dp[n][0] + dp[n][1]);
	}	
	return 0;
}

