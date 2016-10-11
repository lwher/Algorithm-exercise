#pragma comment(linker, "/STACK:1024000000,1024000000")
#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define ls k << 1
#define rs k << 1 | 1

#define N 100010

using namespace std;

long long Max(long long a, long long b){
	if(a > b) return a;
	else return b;
}

int n, m, V[N];
int sz, to[N << 1], pre[N << 1], last[N];
void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

int tt, ft[N], sd[N];
void dfs(int x, int fa){
	ft[x] = ++tt;
	for(int i = last[x]; i; i = pre[i]){
		if(to[i] == fa) continue;
		dfs(to[i], x);
	} 
	sd[x] = tt;
}

long long tag[N << 2], tmax[N << 2];

void downpush(int k, int l, int r){
	int mid = (l + r) >> 1;
	if(tag[k]){
		tag[ls] += tag[k]; tag[rs] += tag[k];
		tmax[ls] += tag[k]; tmax[rs] += tag[k];
		tag[k] = 0;
	}
}

void update(int k, int l, int r, int a, int b, long long x){
	if(l >= a && r <= b){
		tag[k] += x; tmax[k] += x;
		return;
	}
	downpush(k, l, r);
	int mid = (l + r) >> 1;
	if(a <= mid) update(ls, l, mid, a, b, x);
	if(b > mid) update(rs, mid + 1, r, a, b, x);
	tmax[k] = Max(tmax[ls], tmax[rs]);
}

long long ansmax(int k, int l, int r, int a, int b){
	if(l > b || r < a) return -1e20;
	if(l >= a && r <= b) return tmax[k];
	downpush(k, l, r);
	int mid = (l + r) >> 1;
	return Max(ansmax(ls, l, mid, a, b), ansmax(rs, mid + 1, r, a, b));
}

int main(){
	int T, a, b, ty;
	cin >> T;
	for(int t = 1; t <= T; t++){
		sz = 0;
		memset(last, 0, sizeof(last));
		memset(tmax, 0, sizeof(tmax));
		memset(tag, 0, sizeof(tag));
		scanf("%d %d", &n, &m);
		printf("Case #%d:\n", t);
		for(int i = 1; i < n; i++){
			scanf("%d %d", &a, &b);
			a++; b++;
			Ins(a, b); Ins(b, a);
		}
		tt = 0;
		dfs(1, 0);
		for(int i = 1; i <= n; i++){
			scanf("%d", &a); V[i] = a; update(1, 1, n, ft[i], sd[i], a);
		}
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &ty, &a);
			a++;
			if(ty == 0){
				scanf("%d", &b);
				update(1, 1, n, ft[a], sd[a], b - V[a]);
				V[a] = b;
			}
			else{
				printf("%I64d\n", ansmax(1, 1, n, ft[a], sd[a]));
			}
		}
	}
	return 0;
}

