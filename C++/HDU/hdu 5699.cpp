#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 1000010
#define INF 1e8

using namespace std;

int n, m, X[N], Y[N];

bool check(int x){
	int minx = -INF, miny = -INF, maxx = INF, maxy = INF;
	for(int i = 1; i <= m; i++){
		if(Y[i] - X[i] > x){
			minx = max(minx, X[i] + Y[i] - x);
			maxx = min(maxx, X[i] + Y[i] + x);
			miny = max(miny, Y[i] - X[i] - x);
			maxy = min(maxy, Y[i] - X[i] + x);
			if(minx > maxx) return 0;
			if(miny > maxy) return 0;	
		}
	}	
	return 1;
}

int main(){
	while(scanf("%d %d", &n, &m) != EOF){
		for(int i = 1; i <= m; i++){
			scanf("%d %d", &X[i], &Y[i]);
			if(X[i] > Y[i]) swap(X[i], Y[i]);
		}
		int l = 0, r = n, mid;
		while(l + 1 < r){
			mid = (l + r) >> 1;
			if(check(mid)) r = mid;
			else l = mid;
		}	
		if(check(l)) printf("%d\n", l);
		else printf("%d\n", r);
	}
	return 0;
}

