#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

#define INF (1LL << 50)

using namespace std;

struct node{
	int u;
	long long d;
	node(int U, long long D) : u(U), d(D) {}
	bool operator < (const node &B) const {
		return d > B.d;
	}
};

int n, m, A[5010];
long long dist[50010];
bool mark[50010];
std::priority_queue<node> Q;

void Dij(){
	for(int i = 0; i <= A[1]; i++) dist[i] = INF;
	dist[0] = 0;
	Q.push(node(0, 0));
	while(!Q.empty()){
		node p = Q.top(); Q.pop();
		int now = p.u;
		if(mark[now]) continue;
		mark[now] = 1;
		for(int i = 1; i <= n; i++){
			int to = (now + A[i]) % A[1];
			if(dist[to] > dist[now] + A[i]){
				dist[to] = dist[now] + A[i];
				Q.push(node(to, dist[to]));
			}
		}
	}
}

int main(){
	long long B;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &A[i]);
	sort(A + 1, A + 1 + n);
	Dij();
	scanf("%d", &m);
	for(int i = 1; i <= m; i++){
		scanf("%lld", &B);
		int b = B % A[1];
		if(B >= dist[b]) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

