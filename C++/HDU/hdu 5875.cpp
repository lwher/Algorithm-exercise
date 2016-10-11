#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define N 100010

using namespace std;

int n, m, f[N][17], Log[N];

void init(){
	int now = 0, next = 2;
	Log[1] = 0;
	for(int i = 1; i <= 100000; ++i){
		if(i == next){
			++now;
			next <<= 1;
		}
		Log[i] = now;
	}
}

void RMQ_prework(){
	for(int i = 1; i <= Log[n]; ++i){
		for(int j = 1; j <= n; ++j){
			if(j + (1 << i) - 1 > n) break;
			f[j][i] = min(f[j][i - 1], f[j + (1 << (i - 1))][i - 1]);
		}
	}
}

inline int get_min(int l, int r){
	int len = r - l + 1;
	int k = Log[len];
	return min(f[l][k], f[r - (1 << k) + 1][k]);
}

int find_next(int p, int num){
	if(p == n || get_min(p + 1, n) > num) return -1;
	int l = p + 1, r = n, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(get_min(p + 1, mid) <= num) r = mid;
		else l = mid;
	}
	if(get_min(p + 1, l) <= num) return l;
	else return r;
}

int main(){
	init();
	int T, l, r;
	cin >> T;
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", &f[i][0]);
		RMQ_prework();
		scanf("%d", &m);
		for(int i = 1; i <= m; ++i){
			scanf("%d %d", &l, &r);
			int now = f[l][0], p = l;
			for(;;){
				p = find_next(p, now);
				if(p == -1 || p > r || now == 0) break;
				now %= f[p][0];
			}
			printf("%d\n", now);
		}
	}
	return 0;
}

