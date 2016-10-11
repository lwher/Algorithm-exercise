#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 10010
#define M 30010

using namespace std;

int n, m, K, X[M], Y[M], shu[M], num[M], top, tot;

int B[M];
 
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

int find(int x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] < x) l = mid;
		else r = mid;
	}
	if(num[l] == x) return l;
	else return r;
}

int sz, to[M], pre[M], last[N];
void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

int pipei[N];
bool mark[N];
bool match(int x){
	for(int i = last[x]; i; i = pre[i]){
		if(mark[to[i]]) continue;
		mark[to[i]] = 1;
		if(pipei[to[i]] == -1 || match(pipei[to[i]])){
			pipei[to[i]] = x;
			return 1;
		}
	}
	return 0;
}

int main(){
	int x, y;
	scanf("%d", &n);
	scanf("%d", &K);
	for(int i = 1; i <= K; i++){
		scanf("%d %d", &X[i], &Y[i]);
	}
	for(int i = 1; i <= K; i++){
		shu[++top] = X[i];
	}
	Q_sort(shu, 1, top);
	num[++tot] = shu[1]; 
	for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++tot] = shu[i];
	n = tot;
	for(int i = 1; i <= K; i++) X[i] = find(X[i]);
	top = 0; tot = 0;
	for(int i = 1; i <= K; i++){
		shu[++top] = Y[i];
	}
	Q_sort(shu, 1, top);
	num[++tot] = shu[1]; 
	for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++tot] = shu[i];
	m = tot;
	for(int i = 1; i <= K; i++) Y[i] = find(Y[i]);
	
	for(int i = 1; i <= K; i++) Ins(X[i], Y[i]);
	
	for(int i = 1; i <= m; i++) pipei[i] = -1;
	int ans = 0;
	for(int i = 1; i <= n; i++){
		memset(mark, 0, sizeof(mark));
		if(match(i)) ans++;
	}
	cout << ans << endl;
	return 0;
}

