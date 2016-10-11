#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1 << 30

int n, a[20], p[20], num[20], dp[1 << 17][20];

void getmax(int &x, int y) {
    if (x < y) x = y;
}
void Dp(){
	int tot = 1 << n;
	for (int i = 0; i < tot; i++)  for (int j = 1; j <= n; j++) dp[i][j] = -INF;
        if (num[1] != -1) {
            dp[1 << num[1] - 1][num[1]] = 0;
        } 
		else {
            for (int i = 1; i <= n; i++) if (p[i] == 1 || p[i] == -1)  dp[1 << i - 1][i] = 0;   
        }
        for (int i = 1; i + 1 < (1 << n); i++) {
            int cnt = __builtin_popcount(i);
            for (int j = 1; j <= n; j++) {
                if ((i & (1 << j - 1)) == 0) continue;
                if (num[cnt + 1] != -1) {
                    if (i & (1 << num[cnt + 1] - 1)) continue;
                    getmax(dp[i | (1 << num[cnt + 1] - 1)][num[cnt + 1]], dp[i][j] + a[j] * a[num[cnt + 1]]);
                } else {
                    for (int k = 1; k <= n; k++) {
                        if (i & (1 << k - 1)) continue;
                        getmax(dp[i | (1 << k - 1)][k], dp[i][j] + a[j] * a[k]);
                    }
                }
            }
        }
        int ans = -INF;
        for (int i = 1; i <= n; i++) {
			if(ans < dp[tot - 1][i]) ans = dp[tot - 1][i];
        }
        printf("%d\n", ans);
}

int main() {
	int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        printf("Case #%d:\n", t);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", a + i, p + i);
            if (p[i] != -1) p[i]++;
            num[i] = -1;
        }
        for (int i = 1; i <= n; i++) {
            if (p[i] != -1) num[p[i]] = i;
        }
        Dp();
    }
    return 0;
}

