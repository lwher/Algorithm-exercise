#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define N 5010
#define M 60010
#define INF 0x7fffffff

using namespace std;

int gs, n, K, S, T, dist[N];
int A[N], B[N], W[N], top, shu[N], num[N];
char s[13];

int sz = 1, to[M], v[M], cost[M], pre[M], last[N];
bool mark[N];

void Ins(int a, int b, int c, int d){
	sz++; to[sz] = b; v[sz] = c; cost[sz] =  d; pre[sz] = last[a]; last[a] = sz;
	sz++; to[sz] = a; v[sz] = 0; cost[sz] = -d; pre[sz] = last[b]; last[b] = sz;
}

inline int Getnum(char p[]){
	int res = 0;
	res += (p[0] - '0') * 1e5 + (p[1] - '0') * 1e4;
	res += (p[3] - '0') * 1e3 + (p[4] - '0') * 1e2;
	res += (p[6] - '0') * 10 + (p[7] - '0') * 1;
	return res;
}

int find(int x){
	int l = 1, r = n, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(num[mid] == x) return mid;
		if(num[mid] > x) r = mid;
		else l = mid;
	}
	if(num[l] == x) return l; 
	else return r;
}

void build(){
	for(int i = 1; i < n; i++) Ins(i, i + 1, K, 0);
	for(int i = 1; i <= gs; i++) Ins(A[i], B[i], 1, -W[i]);
	S = ++n; T = ++n;
	Ins(S, 1, K, 0); Ins(n - 2, T, K, 0);
}

std::queue<int> Q;
bool spfa(){
	memset(dist, 127, sizeof(dist));
	memset(mark, 0, sizeof(mark));
	dist[T] = 0; mark[T] = 1; Q.push(T);
	while(!Q.empty()){
		int now = Q.front(); Q.pop();
		mark[now] = 0;
		for(int i = last[now]; i; i = pre[i]){
			if(v[i ^ 1] && dist[to[i]] > dist[now] - cost[i]){
				dist[to[i]] = dist[now] - cost[i];
				if(!mark[to[i]]){
					mark[to[i]] = 1; Q.push(to[i]);
				}
			}
		}
	}
	return dist[S] != dist[0];
}

int dfs(int x, int F){
	mark[x] = 1;
	if(x == T) return F;
	int i, used = 0, w;
	for(i = last[x]; i; i = pre[i]){
		if(v[i] && !mark[to[i]] && dist[to[i]] == dist[x] - cost[i]){
			w = min(v[i], F - used);
			w = dfs(to[i], w);
			v[i] -= w; v[i ^ 1] += w;
			used += w;
			if(F == used) return F;
		}
	}
	return used;
}

int mincostflow(){
	int res = 0;
	while(spfa()){
		mark[T] = 1;
		while(mark[T]){
			memset(mark, 0, sizeof(mark));
			res += dfs(S, INF) * dist[S];
		}
	}
	return res;
}
int main(){
	scanf("%d%d", &gs, &K);
	for(int i = 1; i <= gs; i++){
		scanf("%s", s);
		A[i] = Getnum(s); shu[++top] = A[i];
		scanf("%s", s);
		B[i] = Getnum(s); shu[++top] = B[i];
		scanf("%d", &W[i]);
	}	
	sort(shu + 1, shu + 1 + top);
	num[++n] = shu[1];
	for(int i = 2; i <= top; i++) if(shu[i] != shu[i - 1]) num[++n] = shu[i];
	for(int i = 1; i <= gs; i++) A[i] = find(A[i]), B[i] = find(B[i]);
	build();
	printf("%d\n", -mincostflow());
	return 0;
}

