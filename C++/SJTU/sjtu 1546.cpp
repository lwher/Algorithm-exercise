#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
#define N 400010
#define ls k<<1
#define rs k<<1|1
 
using namespace std;
 
int n, m;
long long sum[N], mul[N], add[N], P;
 
inline void Add(long long &x, long long y){
	x = (x + y) % P;
}
 
inline void update(int k){
	sum[k] = (sum[ls] + sum[rs]) % P;
}
 
inline void pushdown(int k, int l, int r){
	if(mul[k] != 1){
		mul[ls] = mul[ls] * mul[k] % P;
		mul[rs] = mul[rs] * mul[k] % P;
		add[ls] = add[ls] * mul[k] % P;
		add[rs] = add[rs] * mul[k] % P;
		sum[ls] = sum[ls] * mul[k] % P;
		sum[rs] = sum[rs] * mul[k] % P;
		mul[k] = 1;
	}
	if(add[k] != 0){
		int mid = (l + r) >> 1;
		Add(add[ls], add[k]);
		Add(add[rs], add[k]);
		Add(sum[ls], add[k] * (mid - l + 1) % P);
		Add(sum[rs], add[k] * (r - mid) % P);
		add[k] = 0;
	}
}
 
void tree_add(int k, int l, int r, int a, int b, long long x){
	if(l >= a && r <= b){
		Add(add[k], x);
		Add(sum[k], x * (r - l + 1) % P);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(k, l, r);
	if(a <= mid) tree_add(ls, l, mid, a, b, x);
	if(b > mid) tree_add(rs, mid + 1, r, a, b, x);
	update(k);
}
 
void tree_mul(int k, int l, int r, int a, int b, long long x){
	if(l >= a && r <= b){
		add[k] = (add[k] * x) % P;
		mul[k] = (mul[k] * x) % P;
		sum[k] = (sum[k] * x) % P;
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(k, l, r);
	if(a <= mid) tree_mul(ls, l, mid, a, b, x);
	if(b > mid) tree_mul(rs, mid + 1, r, a, b, x);
	update(k);
}
 
long long tree_ask(int k, int l, int r, int a, int b){
	if(l > b || r < a) return 0;
	if(l >= a && r <= b) return sum[k];
	int mid = (l + r) >> 1;
	pushdown(k, l, r);
	return (tree_ask(ls, l, mid, a, b) + tree_ask(rs, mid + 1, r, a, b)) % P;
}
 
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int l, r, x, op;
	cin >> n >> P;
	for(int i = 1; i <= 4 * n; i++) mul[i] = 1;
	for(int i = 1; i <= n; i++){
		cin >> x;//scanf("%d", &x);
		tree_add(1, 1, n, i, i, x);
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		cin >> op >> l >> r;//scanf("%d %d %d", &op, &l, &r);
		if(op == 1){
			cin >> x; //scanf("%d", &x);
			tree_mul(1, 1, n, l, r, x);
		} else
		if(op == 2){
			cin >> x; //scanf("%d", &x);
			tree_add(1, 1, n, l, r, x);
		}
		else {
			cout << tree_ask(1, 1, n, l, r) << '\n'; //printf("%d\n", tree_ask(1, 1, n, l, r));
		}
	}
	return 0;
}
