#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 50010

using namespace std;

int L, n, m, X[N]; 

bool check(int mid){
	if(mid > L) return 0;
	int l = 1, r = n, used = 0, last = 0;
	while(l <= r && X[l] < mid) l++, used++;
	while(l <= r && L - X[r] < mid) r--, used++;
	for(int i = l; i <= r; i++){
		if(X[i] - last < mid) used++;
		else last = X[i];	
	}
	return (used <= m);
}

int main(){
	scanf("%d %d %d", &L, &n, &m);
	for(int i = 1; i <= n; i++) 
		scanf("%d", &X[i]);
	int l = 0, r = 1e9 + 5, mid;	
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)) l = mid;
		else r = mid;
	}
	if(check(r)) cout << r << endl;
	else cout << l << endl;
	return 0;
}

