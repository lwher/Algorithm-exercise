#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int n, K, m, a[100010], dirl[500100], f[100010];
long long sum[100010], ans = 0;

void update(int k, int l, int r, int p, int x) {
    dirl[k] += x;
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) update(k << 1, l, mid, p, x);
    else update(k << 1 | 1, mid + 1, r, p, x);
}

int query(int k, int l, int r, int K) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(dirl[k << 1] >= K) return query(k << 1, l, mid, K);
    else return query(k << 1 | 1, mid + 1, r, K - dirl[k << 1]);
}

struct Vect {
    int l, r, v;
    Vect() {}
    Vect(int l, int r, int v):l(l), r(r), v(v) {}
};vector<Vect> g[100010];

int main() {	
    while(scanf("%d%d%d", &n, &K, &m) != EOF) {
        memset(f, 0, sizeof(f));
        ans = 0;
        for(int i = 1; i <= n; ++i) scanf("%d", &a[i]);
        memset(dirl, 0, sizeof(dirl));
        for(int i = 1; i <= n; ++i) g[i].clear();
        for(int i = 1; i <= m; ++i) {
            int l, r;
            scanf("%d%d", &l, &r);
            ++f[l];
            --f[r + 1];
            g[l].push_back(Vect(l, r, 1));
            g[r + 1].push_back(Vect(l, r, -1));
        }
        for(int i = 1; i <= n; ++i) f[i] += f[i - 1], sum[i] = sum[i - 1] +a[i]; 
		       
        for(int i = 1; i <= n; ++i) {
            for(int j = 0; j < g[i].size(); ++j) {
                int l = g[i][j].l;
                int v = g[i][j].v;
                update(1, 1, n, l, v);
            }
            if(f[i] < K) continue;
            int t = query(1, 1, n, K);
            ans = max(ans, sum[i] - sum[t - 1]);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}

