#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 30010

using namespace std;

struct sth{
	int a, b, v;
	bool operator < (const sth &B) const {
		return v < B.v;
	}
}R[N];

int n, fa[N], size[N];

int getfa(int x){
	if(fa[x] == 0) return x;
	else return fa[x] = getfa(fa[x]);
}

int main(){
	int T;
	cin >> T;
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i < n; i++){
			scanf("%d %d %d", &R[i].a, &R[i].b, &R[i].v);
		}
		sort(R + 1, R + n);
		for(int i = 1; i <= n; i++) fa[i] = 0, size[i] = 1;
		long long ans = 0;
		for(int i = 1; i < n; i++){
			int x = getfa(R[i].a), y = getfa(R[i].b);
			ans += ((long long)(size[x]) * size[y] - 1) * (R[i].v + 1);
			ans += R[i].v;
			fa[x] = y; size[y] += size[x];
		}
		cout << ans << endl;
	}
	return 0;
}

