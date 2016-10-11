#include <iostream>
#include <cstdio>
#include <cstdlib>
#define mod 1000000007
using namespace std;
int n, K, L, ans, f[21][1<<20];
void init(){
	scanf("%d%d%d", &n, &K, &L);
}
void dp(){
	int i, j, k, to, p = (1 << K);
	f[0][0] = 1;			
	for (i = 0;i < n;i ++)
		for (j = 0; j < p;j ++)
			if (f[i][j]){
				for (k = 0;k <= min(K, L);k ++) {
				        to = (j | (j << k) | (1 << (k-1))) & (p - 1);
			            f[i + 1][to] = (f[i + 1][to] + f[i][j]) % mod;
                    }
                if (L > K) f[i + 1][j] = (f[i + 1][j] + (long long)f[i][j] * (L - K) % mod) % mod;    
			}
	for (i = 0;i < p;i ++)
		if (i & (1 << (K - 1)))
			ans = (ans + f[n][i]) % mod;
	printf("%d\n", ans); 
}
int main(){
	init();
	dp();
	system("pause");
	return 0;
}
