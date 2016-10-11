#include<iostream>
#include<cstdio>
#include<cstdlib>
 
#define N 10010
 
using namespace std;
 
int t[N], n, K[N];
 
int add(int x, int p){
	for(int i = x; i <= n; i += (i & -i)) t[i] += p;
}
 
int ask(int x){
	int res = 0;
	for(int i = x; i > 0; i -= (i & -i)) res += t[i];
	return res;
}
 
void Delete(int x){
	int l = 1, r = n, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(ask(mid) >= x) r = mid;
		else l = mid;
	}
	if(ask(l) == x)	add(l, -1);
	else add(r, -1);
}
 
int main(){
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d", &K[i]);
		K[i]--;
	}
	for(int i = 1; i <= n; i++) add(i, 1);
	int p = 1, now = n;
	for(int i = 1; i < n; i++){
		p = (p + K[i] % now) % now;
		if(!p) p = now;
		Delete(p); now--;
		//cout << p << endl;
		//for(int j = 1; j <= n; j++) cout << ask(j) << " ";
		//cout << endl;
	}
	for(int i = 1; i <= n; i++){
		if(ask(i) > 0){
			cout << i << endl;
			break;
		}
	}
	return 0;
}
