#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 10000037

using namespace std;

int n, A, B;

int sz, num[1000010], t[1000010], pre[1000010], last[N];

int find(int p){
	int k = p % N;
	for(int i = last[k]; i; i = pre[i]){
		if(num[i] == p) return i;
	}
	sz++; num[sz] = p; t[sz] = 0; pre[sz] = last[k]; last[k] = sz;
	return sz;
}

int main(){
	int p, x, ans;
	while(scanf("%d", &n)){
		if(!n) break;
		scanf("%d %d", &A, &B);
		A %= n; B %= n;
		p = 0;
		while(1){
			x = find(p);
			t[x]++;
			if(t[x] == 3) break;
			p = ((((long long)(A) * p) % n) * p % n + B) % n;
		}
		ans = n;
		for(int i = 1; i <= sz; i++){
			if(t[i] >= 2) ans--;
			last[num[i] % N] = 0;
		}
		sz = 0;
		printf("%d\n", ans);
	}
	return 0;
}

