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

int n, m , L, num[10010], sum[10010], f[10010][11];
int sz, gs[350010], tran[350010][2];

void Ins(int X, int p){
	int k, now = 0;
	for(int i = (1 << 30); i > 0; i >>= 1){
		if(X & i) k = 1; else k = 0;
		if(!tran[now][k]) tran[now][k] = ++sz;
		now = tran[now][k];
		gs[now] += p;
	}
}

int find(int X){
	int res = 0, k, now = 0;
	for(int i = (1 << 30); i > 0; i >>= 1){
		if(X & i) k = 1; else k = 0;
		if(gs[tran[now][k ^ 1]]){
			now = tran[now][k ^ 1]; 
			res += i;
		} else
		if(gs[tran[now][k]]){
			now = tran[now][k];
		}
		else return 0;
	}
	return res;
}

bool check(int mid){
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= L; i++){
		if(sum[i] >= mid) f[i][1] = 1;
	}
	for(int j = 2; j <= m; j++){
		for(int i = 1; i < j; i++){
			if(f[i][j - 1]){
				Ins(sum[i], 1);
			}
		}
		for(int i = j; i <= n; i++){
			if(find(sum[i]) >= mid) f[i][j] = 1;
			if(i - L > 0 && f[i - L][j - 1]) Ins(sum[i - L], -1);
			if(f[i][j - 1]) Ins(sum[i], 1); 
		}
		for(int i = n - L + 1; i <= n; i++){
			if(f[i][j - 1]) Ins(sum[i], -1);
		}
	}
	return f[n][m];
}

int main(){
	int T, t = 0;
	cin >> T;
	while(T--){
		scanf("%d %d %d", &n, &m, &L);
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
			sum[i] = (sum[i - 1] ^ num[i]);
		}		
		printf("Case #%d:\n", ++t);
		int l = 0, r = 2e9, mid;
		while(l + 1 < r){
			mid = (l + r) >> 1;
			if(check(mid)) l = mid;
			else r = mid;
		}
		if(check(r)) printf("%d\n", r);
		else printf("%d\n", l);
	}
	return 0;
}

