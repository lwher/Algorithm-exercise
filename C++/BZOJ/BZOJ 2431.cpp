#include <algorithm>
#include <cstdio>
using namespace std;
const int MAXN = 1002, MOD = 10000;
int f[2][MAXN], s[2][MAXN];
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++ i)
    {
        int p = i & 1, q = p ^ 1;
        s[p][1] = f[p][1] = 1;
        for (int j = 2; j <= k + 1; ++ j)
        {
            f[p][j] = (s[q][j] - s[q][j - min(j, i)] + MOD) % MOD;
            s[p][j] = (s[p][j - 1] + f[p][j]) % MOD;
        }
    }
    printf("%d\n", f[n & 1][k + 1]);
    return 0;
}

