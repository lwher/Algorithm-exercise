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

using namespace std;

int n, tot, top, A[N], num[N], shu[N], t[N];
long long ans;

void add(int x){
	for(int i = x; i <= tot; i += (i & -i))
		t[i]++;
}

int ask(int x){
	int res = 0;
	for(int i = x; i > 0; i -= (i & -i))
		res += t[i];
	return res;
}

int find(int x){
	int l = 1, r = tot, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] > x) r = mid;
		else l = mid;
	}
	if(num[r] == x) return r;
	else return l;
}

void init(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){ 
		scanf("%d", &A[i]);
		shu[++top] = A[i];
		shu[++top] = A[i] * 2;
	}
	sort(shu + 1, shu + 1 + top);
	num[++tot] = shu[1];
	for(int i = 2; i <= top; i++) 
		if(shu[i] != shu[i-1]) 
			num[++tot] = shu[i];
}

void solve(){
	int p;
	for(int i = n; i > 0; i--){
		p = find(A[i]) - 1;
		ans += ask(p);
		add(find(A[i] * 2));
	}
	cout << ans << endl;
}
int main(){
	init();
	solve();
	return 0;
}

