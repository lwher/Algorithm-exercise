#include<iostream>
#include<cstdio>
#include<cstdlib>
 
using namespace std;
 
int n, num[200010], B[200010];
 
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
;
 
int main(){
	int T;
	cin >> T;
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= n; i++){
			scanf("%d", &num[i]);
		}
		Q_sort(num, 1, n);
		for(int i = 1; i < n; i++) printf("%d ", num[i]);
		printf("%d\n", num[n]);
	}
	return 0;
}
