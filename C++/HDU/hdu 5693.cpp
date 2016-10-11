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

int n, m, num[310], f[310];
bool dp[310][310];
std::map<int, bool> Q;

int main(){
	int D, T;
	cin >> T;
	for(int tt = 1; tt <= T; tt++){
		Q.clear();
		memset(f, 0, sizeof(f));
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n ,&m);
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
			dp[i + 1][i] = 1;
		}
		for(int i = 1; i <= m; i++){
			scanf("%d", &D);
			Q[D] = 1;
		}
		for(int len = 2; len <= n; len++){
			for(int i = 1; i <= n; i++){
				int j = i + len - 1;
				if(j > n) break;
				if(Q.count(num[j] - num[i])){
					if(dp[i + 1][j - 1]) dp[i][j] = 1;
				}
				for(int k = i; k < j; k++){
					if(dp[i][k] && dp[k + 1][j])
						dp[i][j] = 1;
				}
				for(int k = i + 1; k < j; k++){
					if(num[j] - num[k] == num[k] - num[i]){
						if(Q.count(num[k] - num[i])){
							if(dp[i + 1][k - 1] && dp[k + 1][j - 1])
								dp[i][j] = 1;
						}
					}
				}
			}
		}
		f[0] = 0;
		for(int i = 1; i <= n; i++){
			f[i] = f[i - 1];
			for(int j = 0; j < i; j++){
				if(dp[j + 1][i]){
					f[i] = max(f[i], f[j] + i - j);
				} 
			}
		}
		printf("%d\n", f[n]);
	}
	return 0;
}

