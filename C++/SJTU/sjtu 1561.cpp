#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
 
#define N 200010
#define M 500010
#define eps 1e-6
 
using namespace std;
 
struct node{
	long long fz, fm;
	bool operator <(const node &b) const{
		if(fz != b.fz) return fz < b.fz;
		else return fm < b.fm;
	}
	bool operator ==(const node &b) const{
		return (fz == b.fz && fm == b.fm);
	}
	bool operator !=(const node &b) const{
		return !(*this == b);
	}
}yy[M], nshu[M], nnum[M];
long double X[M], Y[M], shu[M], num[M];
int n, m, K, top, tot;
 
 
long double B[M];
void Q_sort(long double A[], int l, int r){
	if(l == r || l > r) return;
	int mid = (l + r) >> 1;
	Q_sort(A, l, mid); Q_sort(A, mid + 1, r);
	int w = l - 1, L = l, R = mid + 1;
	while(L <= mid && R <= r){
		if(A[L] < A[R]) B[++w] = A[L++];
		else B[++w] = A[R++];
	}
	while(L <= mid) B[++w] = A[L++];
	while(R <= r) B[++w] = A[R++];
	for(int i = l; i <= r; i++) A[i] = B[i];
}
 
node nB[M];
void Q_sort_n(node nA[], int l, int r){
	if(l == r || l > r) return;
	int mid = (l + r) >> 1;
	Q_sort_n(nA, l, mid); Q_sort_n(nA, mid + 1, r);
	int w = l - 1, L = l, R = mid + 1;
	while(L <= mid && R <= r){
		if(nA[L] < nA[R]) nB[++w] = nA[L++];
		else nB[++w] = nA[R++];
	}
	while(L <= mid) nB[++w] = nA[L++];
	while(R <= r) nB[++w] = nA[R++];
	for(int i = l; i <= r; i++) nA[i] = nB[i];
}
 
int find(long double x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(fabs(num[mid] - x) < eps) return mid;
		if(num[mid] < x - eps) l = mid;
		else r = mid;
	}
	if(fabs(num[l] - x) < eps) return l;
	else return r;
}
 
int find_n(node x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(nnum[mid] == x) return mid;
		if(nnum[mid] < x) l = mid;
		else r = mid;
	}
	if(nnum[l] == x) return l;
	else return r;
}
 
long long gcd(long long a, long long b){
	if(!b) return a;
	else return gcd(b, a % b);
}
 
int sz, to[M], pre[M], last[N];
void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

int markstack[N], marktop;
int pipei[N];
bool mark[N];
bool match(int x){
	for(int i = last[x]; i; i = pre[i]){
		if(mark[to[i]]) continue;
		mark[to[i]] = 1;
		markstack[++marktop] = to[i];
		if(pipei[to[i]] == -1 || match(pipei[to[i]])){
			pipei[to[i]] = x;
			return 1;
		}
	}
	return 0;
}
 
 
int main(){
	long long x, y;
	scanf("%d", &K);
	for(int i = 1; i <= K; i++){
		scanf("%lld", &x);
		scanf("%lld", &y);
		X[i] = (long double)(x) * x + (long double)(y) * y;
		long long d = gcd(abs(x), abs(y));
		if(!x){
			yy[i].fz = 0; yy[i].fm = 1;
		}
		else if(!y){
			yy[i].fz = 1; yy[i].fm = 0;
		}
		else{
			x /= d; y /= d;
			if(x < 0){x = -x; y = -y;}
			yy[i].fz = x; yy[i].fm = y;
		}
	}
	
	for(int i = 1; i <= K; i++){
		shu[++top] = X[i];
	}
	Q_sort(shu, 1, top);
	num[++tot] = shu[1]; 
	for(int i = 2; i <= top; i++) if(fabs(shu[i] - shu[i - 1]) > eps) num[++tot] = shu[i];
	n = tot;
	for(int i = 1; i <= K; i++) X[i] = find(X[i]);
	
	top = 0; tot = 0;
	for(int i = 1; i <= K; i++){
		nshu[++top] = yy[i];
	}
	Q_sort_n(nshu, 1, top);
	nnum[++tot] = nshu[1]; 
	for(int i = 2; i <= top; i++) if(nshu[i] != nshu[i - 1]) nnum[++tot] = nshu[i];
	m = tot;
	for(int i = 1; i <= K; i++) Y[i] = find_n(yy[i]);
	
	for(int i = 1; i <= K; i++) Ins(X[i], Y[i]);
	
	for(int i = 1; i <= m; i++) pipei[i] = -1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		while(marktop > 0) mark[markstack[marktop--]] = 0;
		if(match(i)) ans++;
	}
	cout << ans << endl;
	
	return 0;
}
