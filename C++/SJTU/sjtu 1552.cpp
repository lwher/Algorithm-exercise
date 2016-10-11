#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
 
#define N 200010
 
using namespace std;
 
int n, m, num[N], B[N];
int sz, to[N], pre[N], last[N];
 
int hsz,heap[N];
 
void uppush(int x){
	while(x > 1 && heap[x] < heap[x >> 1]){
		swap(heap[x], heap[x >> 1]);
		x >>= 1;
	}
}
 
void heap_Ins(int p){
	heap[++hsz] = p;
	uppush(hsz);
}
 
void downpush(int x){
	while(1){
		if(x * 2 > hsz) break;
		int To = x * 2;
		if(To < hsz && heap[To] > heap[To + 1]) To++;
		if(heap[x] > heap[To]){
			swap(heap[x], heap[To]);
			x = To;
		}
		else break;
	}
}
 
void heap_Delete(){
	swap(heap[1], heap[hsz]);
	hsz--;
	downpush(1);
}
 
void Q_sort(int A[], int l, int r){
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
 
struct sth{
	int a, b;
	bool operator <(const sth &rhs) const{
		return b > rhs.b;
	}
}path[N], BB[N], PP[N];
 
 
int find(int x){
	int l = 1, r = n, mid;
	while(l + 1 < r){
		int mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] > x) r = mid;
		else l = mid;
	}
	if(num[l] == x) return l; 
	else return r;
}
 
void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}
 
int Q[N], du[N];
void Build(int x){
	sz = 0;
	memset(du, 0, sizeof(du));
	memset(last, 0, sizeof(last));
	for(int i = 1; i <= x; i++){
		Ins(path[i].a, path[i].b);
		du[path[i].b]++;
	}
}
 
bool topsort(){
	int w = 0, now;
	hsz = 0;
	for(int i = 1; i <= n; i++){
		if(!du[i]){
			heap_Ins(i);
		}
	}
	while(hsz > 0){
		now = heap[1]; Q[++w] = now;
		heap_Delete();
		for(int i = last[now]; i; i = pre[i]){
			du[to[i]]--;
			if(!du[to[i]]) heap_Ins(to[i]);
		}
	}
	if(w < n) return 0;
	else return 1;
}
 
void solve(){
	Build(m);	
	if(topsort()){
		Build(m);
		topsort();
		for(int i  = 1; i < n; i++) printf("%d ", num[Q[i]]);
		printf("%d\n", num[Q[n]]);
		return;
	}
	int l = 1, r = m, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		Build(mid);
		if(!topsort()) r = mid;
		else l = mid;
	}
	Build(l); 
	if(!topsort()) printf("%d\n", l);
	else printf("%d\n", r);
}
 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &num[i]);
	}
	Q_sort(num, 1, n);
	for(int i = 1; i <= m; i++){
		scanf("%d%d", &path[i].a, &path[i].b);
		path[i].a = find(path[i].a); path[i].b = find(path[i].b);
	}
	solve();
	return 0;
}
