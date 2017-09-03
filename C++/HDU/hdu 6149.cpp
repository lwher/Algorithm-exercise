#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAXN = 31;

int n, m, K, NumHigh, StackSize;
bool IsHigh[MAXN];
int IdHigh[MAXN], dp[MAXN][1 << 16], stack[MAXN];
vector<int> to[MAXN];

int main() {
	int T, u, v;
	cin >> T;
	while (T--) {
		scanf("%d%d%d", &n, &m, &K);
		for(int i = 1; i <= n; ++i) {
			to[i].clear();
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			to[u].push_back(v);
			to[v].push_back(u);
		}
		memset(IsHigh, 0, sizeof(IsHigh));
		memset(IdHigh, 0, sizeof(IdHigh));
		NumHigh = 0;
		for (int i = 1; i <= K; ++i) {
			scanf("%d", &u);
			IsHigh[u] = true;
			IdHigh[u] = ++NumHigh;
		}
		memset(dp, 0, sizeof(dp));
		int now = 0, totSize = (1 << NumHigh);
		for (int i = 1; i <= n; ++i) {
			if (IsHigh[i]) continue;
			++now;
			StackSize = 0;
			for (int j = 0; j < to[i].size(); ++j) {
				if (IsHigh[to[i][j]]) {
					stack[++StackSize] = to[i][j];
				}
			}
			for (int status = 0; status < totSize; ++status) {
				dp[now][status] = max(dp[now][status], dp[now - 1][status]);
				for (int j = 1; j <= StackSize; ++j) {
					if (status & (1 << (IdHigh[stack[j]] - 1))) continue;
					for (int k = j + 1; k <= StackSize; ++k) {
						if (stack[j] == stack[k] || (status & (1 << (IdHigh[stack[k]] - 1)))) continue;
						dp[now][status | (1 << (IdHigh[stack[j]] - 1)) | (1 << (IdHigh[stack[k]] - 1))] = 
							max(dp[now][status | (1 << (IdHigh[stack[j]] - 1)) | (1 << (IdHigh[stack[k]] - 1))], 
								dp[now - 1][status] + 1);
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < totSize; ++i) {
			ans = max(ans, dp[now][i]);
		}
		cout << ans << endl;
	}
	return 0;
}
