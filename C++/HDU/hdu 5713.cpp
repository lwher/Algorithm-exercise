#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define mod 1000000009

using namespace std;

int n, m, K, SZ;
int map[16][16];
long long cnt[33000], f[33000], dp[33000][16], mi[231];

inline int lowbit(int &x){
	return (x & (-x));
}

void DP(){
	memset(dp, 0, sizeof(dp));
	memset(f, 0, sizeof(f));
	for(int k = 1; k < SZ; k++){
		f[k] = mi[cnt[k]];
		for(int j = (k - 1) & k; j; j = (j - 1) & k) if(j & lowbit(k)){
			f[k] = ((f[k] - (mi[cnt[k - j]] * f[j])) % mod + mod) % mod;
		}
	}
	dp[0][0] = 1;
	for(int k = 1; k <= K; k++){
		for(int s = 1; s < SZ; s++){
			for(int j = s; j; j = (j - 1) & s) if(j & lowbit(s)){
				dp[s][k] = (dp[s][k] + (dp[s - j][k - 1] * f[j]) % mod) % mod;
			}
		}
	}
	cout << dp[SZ - 1][K] << endl;
}

int main(){
	int T, a, b;
	mi[0] = 1;
	for(int i = 1; i <= 230; i++) mi[i] = (mi[i - 1] << 1) % mod;
	cin >> T;
	for(int tt = 1; tt <= T; tt++){
		memset(map, 0, sizeof(map));
		scanf("%d %d %d", &n, &m, &K);
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &a, &b);
			++map[a][b]; 
			if(a != b) ++map[b][a];
		}
		SZ = (1 << n);
		memset(cnt, 0, sizeof(cnt));
		for(int k = 1; k < SZ; k++){
			for(int i = 1; i <= n; i++) if(k & (1 << (i - 1))){
				for(int j = i; j <= n; j++) if(k & (1 << (j - 1))){
					cnt[k] += map[i][j];
				}
			}
		}		
		cout << "Case #" << tt << ":" << endl;		
		DP();
	}
	return 0;
}

