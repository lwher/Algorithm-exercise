#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define N 300010

using namespace std;

int n, A[N], top, tot, num[N], shu[N], size[N];
long long K, ans;
bool vis[N];
int sz, to[N], pre[N], last[N];

int tt, ft[N], sd[N], dfsxu[N];

int root[N], rot;
int tsz, sum[N * 10], ls[N * 10], rs[N * 10];

int Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

void dfs(int x){
	ft[x] = ++tt;
	dfsxu[tt] = x;
	size[x] = 1;
	for(int i = last[x]; i; i = pre[i]){
		dfs(to[i]);
		size[x] += size[to[i]];
	}
	sd[x] = tt;
}

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

void Insert(int x, int &y, int l, int r, int p){
	y = ++tsz;
	sum[y] = sum[x] + 1;
	if(l == r) return;
	ls[y] = ls[x]; rs[y] = rs[x];
	int mid = (l + r) >> 1;
	if(p <= mid) Insert(ls[x], ls[y], l, mid, p);
	else Insert(rs[x], rs[y], mid + 1, r, p);
}

int query(int L, int R, long long k){
	if(L > R) return 0;
	int res = 0;
	L = root[L - 1]; R = root[R];
	int l = 1, r = tot, mid;
	while(l != r){
		mid = (l + r) >> 1;
		if(num[mid] <= k){
			res += sum[ls[R]] - sum[ls[L]];
			L = rs[L]; R = rs[R];
			l = mid + 1;
		}
		else{
			L = ls[L]; R = ls[R];
			r = mid;
		}
	}
	if(num[l] <= k) res += sum[R] - sum[L];
	return res;
}

int main(){
	int T, u, v;
	cin >> T;
	while(T--){
		sz = 0; tt = 0; ans = 0;
		memset(last, 0, sizeof(last));
		memset(size, 0, sizeof(size));
		memset(vis, 0, sizeof(vis));
		
		tot = 0; top = 0;
		
		tsz = 0;
		memset(sum, 0, sizeof(sum));
		memset(ls, 0, sizeof(ls));
		memset(rs, 0, sizeof(rs));
		
		scanf("%d %I64d", &n, &K);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
			shu[++top] = A[i];
		}
		for(int i = 1; i < n; i++){
			scanf("%d %d", &u, &v);
			Ins(u, v); vis[v] = 1;
		}
		for(int i = 1; i <= n; i++)
			if(!vis[i]){
				rot = i;
				break;
			}
		dfs(rot);
		
		sort(shu + 1, shu + 1 + top);
		num[++tot] = shu[1];
		for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++tot] = shu[i];
		for(int i = 1; i <= n; i++) A[i] = find(A[i]);
		
		for(int i = 1; i <= n; i++){
			Insert(root[i - 1], root[i], 1, tot, A[dfsxu[i]]);
		}
		
		for(int i = 1; i <= n; i++) {
			if(num[A[i]] != 0) ans += query(ft[i] + 1, sd[i], K / num[A[i]]);
			else ans += size[i] - 1;
		}
		
		cout << ans << endl;
	}
}
