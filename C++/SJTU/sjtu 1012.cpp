#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define eps 1e-9
using namespace std;
int S, T, ans, dp[200001];
long long Sum, sum[200001];
int main(){
	cin >> S >> T;
	for(int i = S;i <= T;i++){
		dp[i] = sum[i] = 1;
	}
	for(int i = S;i < T;i++){
		for(int j = 1;j <= 200;j++) if(j * i % 100 == 0){
			int k = i * j / 100;
			if(i + k > T) break;
			if(dp[i + k] < dp[i] + 1){
				dp[i + k] = dp[i] + 1;
				sum[i + k] = sum[i];
			} else
			if(dp[i + k] == dp[i] + 1){
				sum[i + k] += sum[i];
			}
		}
	}
	for(int i = S;i <= T;i++){
		if(dp[i] > ans){
			ans = dp[i];
			Sum = sum[i];
		} else
		if(dp[i] == ans) Sum += sum[i];
	}
	cout << ans << endl << Sum << endl;
	return 0;
}

