#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 800010
 
using namespace std;
 
int n, root, dep[N], du[N];
int sz, to[N << 1], pre[N << 1], last[N];
unsigned long long v[N << 1];
 
unsigned long long DP[N];
 
struct node{
	int p, deep;
	bool operator < (const node &b) const{
		return deep < b.deep;
	}
}P[N];
 
void Ins(int a, int b, unsigned long long c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz; du[a]++;
}
 
int Q[N];
void bfs(){
	int t = 1, w = 1, now;
	Q[1] = root; dep[root] = 1;
	while(t <= w){
		now = Q[t]; t++;
		for(int i = last[now]; i; i = pre[i]){
			if(dep[to[i]]) continue;
			dep[to[i]] = dep[now] + 1;
			Q[++w] = to[i];
		}
	}
}
 
node B[800010];
void Q_sort(node A[], int l, int r)
{
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
 
int main(){
	int a, b, c;
	scanf("%d %d", &n, &root);
	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ins(a, b, c); Ins(b, a, c);
	}
	bfs();
	for(int i = 1; i <= n; i++) P[i].p = i, P[i].deep = dep[i];
	Q_sort(P, 1, n);
	for(int i = n; i >= 1; i--){
		int x = P[i].p;
		DP[x] = 0;
		for(int j = last[x]; j; j = pre[j]){
			if(dep[to[j]] > dep[x]){
				if(du[to[j]] == 1) DP[x] = DP[x] + v[j];
				else DP[x] = min(DP[x] + v[j], DP[x] + DP[to[j]]);
			}
		}
	}
	cout << DP[root] << endl;
	return 0;
}
