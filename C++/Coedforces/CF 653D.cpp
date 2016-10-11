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

const int N = 60;
const int M = 1010;
const int INF = 1e9;

int n, m, s, t, X;
int H[N], gap[N], cur[N];
int sz, to[M], v[M], pre[M], last[N];
int A[M], B[M], C[M];

void Ins(int a, int b, int c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
	sz++; to[sz] = a; v[sz] = 0; pre[sz] = last[b]; last[b] = sz;
}

std::queue<int> Q; 
void bfs(){
	memset(H, -1, sizeof(H));
	memset(gap, 0, sizeof(gap));
	H[t] = 0; gap[0] = 1;
	Q.push(t);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		for(int i = last[now]; i; i = pre[i]){
			if(H[to[i]] == -1){
				H[to[i]] = H[now] + 1;
				gap[H[to[i]]]++;
				Q.push(to[i]);
			}
		}
	}
}

int dfs(int x, int F){
	if(x == t) return F;
	int i, used = 0, w;
	for(int i = cur[x]; i; i = pre[i]){
		if(v[i] > 0 && H[to[i]] == H[x] - 1){
			w = min(v[i], F - used);
			w = dfs(to[i], w);
			v[i] -= w; v[i ^ 1] += w; used += w;
			if(v[i] > 0) cur[x] = i;
			if(F == used) return F;
		}
	}
	gap[H[x]]--;
	if(!gap[H[x]]) H[s] = n + 2;
	cur[x] = last[x];
	gap[++H[x]]++;
	return used;
}

int SAP(){
	int res = 0;
	bfs();
	for(int i = 1; i <= n; i++) cur[i] = last[i];
	while(H[s] < n + 2) res += dfs(s, INF);
	return res;
}

bool check(double x){
	sz = 1;
	memset(last, 0, sizeof(last));
	for(int i = 1; i <= m; i++){
		if(x * X <= C[i]) Ins(A[i], B[i], X);
		else Ins(A[i], B[i], C[i] * 1.000 / x);
	}
	Ins(s, 1, X);	
	if(SAP() == X) return 1;
	else return 0;
}

double solve(){
	t = n; s = ++n;
	double l = 0, r = 1e7, mid;		
	for(int i = 1; i <= 66; i++){ 
		mid = (l + r) * 0.5;
		if(check(mid)) l = mid;
		else r = mid;
	}
	return l * X;
}

int main(){
	scanf("%d%d%d", &n, &m, &X);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
	}
	printf("%.10lf\n", solve());
	return 0;
}

