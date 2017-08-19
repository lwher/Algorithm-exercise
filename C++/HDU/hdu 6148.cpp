#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1000000007;

int n, m, ans;

long long dp[110][10][3]; // 0: up, 1: down, 2: don't know
char s[110];

int main() {
	int T, n;
	cin >> T;
	for (int i = 0; i < 10; ++i) {
		dp[1][i][2] += 1;
	}
	for (int i = 2; i <= 100; ++i) {
		for (int j = 0; j < 10; ++j) {
			for (int k = 0; k < 10; ++k) {
				if (j == k) {
					dp[i][j][2] = (dp[i][j][2] + dp[i - 1][k][2]) % mod;
					dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][1]) % mod;
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][0]) % mod;
				}
				else if (j < k) {
					dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][1]) % mod;
					dp[i][j][1] = (dp[i][j][1] + dp[i - 1][k][2]) % mod;
				}
				else {					
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][0]) % mod;
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][1]) % mod;
					dp[i][j][0] = (dp[i][j][0] + dp[i - 1][k][2]) % mod;
				}
			}
		}
	}
	for (int tt = 1; tt <= T; ++tt) {
		scanf("%s", s + 1);
		n = strlen(s + 1);
		ans = 0;
		if (n == 1) {
			ans = s[1] - '0';
		}		
		else {
			for (int i = 1; i < n; ++i) {
				for (int j = 1; j < 10; ++j) {
					ans = (ans + dp[i][j][0]) % mod;
					ans = (ans + dp[i][j][1]) % mod;
					ans = (ans + dp[i][j][2]) % mod;
				}
			}
			int flag = 2;
			for (int i = 1; i <= n; ++i) {
				int now = s[i] - '0';
				for (int j = 0; j < now; ++j) {
					if (j == 0 && i == 1) continue;
					if (i > 1 && j > s[i - 1] - '0') {
						flag = 0;
					}
					else if(i > 1 && j < s[i - 1] - '0') {
						if (flag == 0) 
							continue;
						flag = 1;
					}
					if (i == n){
						ans = (ans + 1) % mod;
						continue;
					}
					for (int k = 0; k < 10; ++k) {
						if (j == k) {
							ans = (ans + dp[n - i][k][2]) % mod;
							ans = (ans + dp[n - i][k][1]) % mod;
							if(flag) ans = (ans + dp[n - i][k][0]) % mod;
						}
						else if (j < k) {
							ans = (ans + dp[n - i][k][2]) % mod;
							ans = (ans + dp[n - i][k][1]) % mod;
						}
						else {
							if(flag){
								ans = (ans + dp[n - i][k][2]) % mod;
								ans = (ans + dp[n - i][k][1]) % mod;
								ans = (ans + dp[n - i][k][0]) % mod;
							}
						}
					}
				}
				if (i > 1 && s[i] - '0' > s[i - 1] - '0') {
					flag = 0;
				}
				else if(i > 1 && s[i] - '0' < s[i - 1] - '0') {
					if (flag == 0) 
						break;
					flag = 1;
				}
				if(i == n)
					ans = (ans + 1) % mod;
			}	
		}
		cout << ans << endl;
	}
		
	return 0;
}
