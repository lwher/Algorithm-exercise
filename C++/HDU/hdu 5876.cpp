#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define N 200010
#define M 50010

using namespace std;

int n, m, dist[N], S, Q[N];
int sz, to[M], pre[M], last[N];

std::map<int, bool>rem[2];
std::map<int, bool>::iterator it;
void clear(){
	sz = 0;
	rem[0].clear(); 
	rem[1].clear();
	memset(last, 0, sizeof(last));
	memset(dist, -1, sizeof(dist));
}

void Ins(int a, int b){
	sz++; to[sz] = b; pre[sz] = last[a]; last[a] = sz;
}

void bfs(int s){
	dist[s] = 0;
	int t = 1, w = 1, now, p = 0, q = 1;
	Q[1] = s;
	for(int i = 1; i <= n; ++i){
		if(i != s) rem[p][i] = 1;
	}
	while(t <= w){
		now = Q[t]; ++t;
		for(int i = last[now]; i; i = pre[i]){
			if(rem[p].count(to[i])){
				rem[p].erase(to[i]);
				rem[q][to[i]] = 1;
			}
		}
		for(it = rem[p].begin(); it != rem[p].end(); ++it){
			dist[it -> first] = dist[now] + 1;
			Q[++w] = it -> first;
		}
		p ^= 1; q ^= 1;
		rem[q].clear();
	}
}

int main(){
	int T, a, b;
	cin >> T;
	while(T--){
		clear();
		scanf("%d %d", &n, &m);
		for(int i = 1; i <= m; ++i){
			scanf("%d %d", &a, &b);
			Ins(a, b);
			Ins(b, a);
		}
		scanf("%d", &S);
		bfs(S);
		if(S == n){
			for(int i = 1; i < n - 1; ++i)
				printf("%d ", dist[i]);
			printf("%d\n", dist[n - 1]);
		}
		else{
			for(int i = 1; i < n; ++i){
				if(S != i){
					printf("%d ", dist[i]);
				}
			}
			printf("%d\n", dist[n]);
		}
	}
	return 0;
}

