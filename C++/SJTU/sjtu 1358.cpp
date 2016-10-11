#include<iostream>
#include<map>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1000001

using namespace std;

int n, f[N], size[N];
vector<int> to[N];

void dfs(int x,int from){
	size[x] = 1;
	for(int i = 0; i < to[x].size(); i++){
		if(to[x][i] == from) continue;
		dfs(to[x][i],x);
		f[x] = max(f[x], size[to[x][i]]);
		size[x] += size[to[x][i]];
	}
	f[x] = max(f[x], n - size[x]);
}
int main(){
	int a, b;
	scanf("%d", &n);
	for(int i = 1; i < n; i++){
		scanf("%d %d", &a, &b);
		to[a].push_back(b);
		to[b].push_back(a);
	}
	dfs(1,0);
	for(int i = 1; i <= n; i++) if(f[i] <= n / 2) printf("%d\n", i);
	return 0;
}

