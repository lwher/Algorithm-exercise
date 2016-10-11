#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 3000010

using namespace std;

int S, T, n, P, A[N], B[N];
bool mark[N];

int Q[N], dist[N];

int Bfs(){
	memset(dist, 0, sizeof(dist));
	memset(mark, 0, sizeof(mark));
	int t = 1, w = 1;
	if(S == T) return 0;
	S %= P;
	Q[1] = S;
	mark[S] = 1;
	while(t <= w){
		int now = Q[t]; t++;
		for(int i = 1; i <= n; i++){
			int To = (((long long)A[i] * now) + B[i]) % P;
			if(To == T){
				return dist[now] + 1;
			}
			if(!mark[To]){
				dist[To] = dist[now] + 1;
				Q[++w] = To;
				mark[To] = 1;
			}
		}
	}
	return -1;
}

int main(){
	
	while(scanf("%d %d %d %d", &S, &T, &n, &P) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d %d", &A[i], &B[i]);
			A[i] %= P; B[i] %= P;
		}
		printf("%d\n", Bfs());
	}
	return 0;
}

