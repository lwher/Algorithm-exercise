#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 100010
#define mod 1000000007

using namespace std;

int n, top, tot, num[N], A[N], shu[N], t[N<<1];
int f[N][11];
long long ans;

int find(int x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] > x) r = mid;
		else l = mid;
	}
	if(num[l] == x) return l;
	else return r;
}

void add(int x, int k){
	for(int i = x; i > 0; i -= (i & (-i)))
		t[i] = (t[i] + k) % mod;
}

int ask(int x){
	int res = 0;
	for(int i = x; i <= tot; i += (i & (-i)))
		res = (res + t[i]) % mod;
	return res;	
}

int main(){
	int K;
	scanf("%d%d", &n, &K);
	for(int i = 1; i <= n; i++){ 
		scanf("%d", &A[i]);
		shu[++top] = A[i];
	}
	sort(shu + 1, shu + 1 + top);
	num[++tot] = shu[1];
	for(int i = 2; i <= n; i++) if(shu[i] != shu[i - 1]) num[++tot] = shu[i];
	
	for(int i = 1; i <= n; i++) A[i] = find(A[i]);
	
	for(int i = 1; i <= n; i ++) f[i][1] = 1;
	
	for(int j = 2; j <= K; j++){
		memset(t, 0, sizeof(t));
		
		for(int i = 1; i <= n; i++){
			f[i][j] = (f[i][j] + ask(A[i] + 1)) % mod;
			add(A[i], f[i][j - 1]);
		}
	}
	for(int i = 1; i <= n; i++)
		ans = (ans + f[i][K]) % mod;
	cout << ans << endl;
	return 0;
}

