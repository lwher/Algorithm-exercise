#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define MOD 20100713

using namespace std;

int n, K;
long long jc[1000010];

int qpow(long long a, int b){
	long long res = 1;
	while(b > 0){
		if(b & 1) res = (res * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res % MOD;
}

int main(){
	jc[0] = 1;
	for(int i = 1; i <= 1000000; i++) jc[i] = (jc[i - 1] * i) % MOD;
	int T;
	cin >> T;
	while(T--){
		scanf("%d%d", &n, &K);
		long long ans = qpow(K + 1, n - K) - qpow(K, n - K);
		if(ans < 0) ans += MOD;
		ans = ans * jc[K] % MOD;
		cout << ans << endl;
	}
	return 0;
}

