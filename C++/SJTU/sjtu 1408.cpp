#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth{
	int u, v, ai;
}R[300001];
inline bool comp(const sth &a, const sth &b){
	return a.ai < b.ai;
}
int n, m, top, px[300001], fx[300001], f[300001];
void init(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &R[i].u, &R[i].v, &R[i].ai);
	}
}
void solve(){
	sort(R + 1, R + 1 + m, comp);
	for(int i = 1; i <= m; i++){
		int j = i;
		while(R[j].ai == R[i].ai){
			px[++top]=R[j].v;
			fx[top]=f[R[j].u]+1;
			j++;
		}
		while(top > 0){
			f[px[top]] = max(f[px[top]], fx[top]);
			top--;
		}
		i = j - 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(f[i] > ans) ans = f[i];
	}
	cout << ans << endl;
}
int main(){
	init();
	solve();
	return 0;
}

