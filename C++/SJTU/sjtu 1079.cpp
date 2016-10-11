#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 310 
using namespace std;

int n, m, K;
int sz, to[N<<1], v[N<<1], pre[N<<1], last[N];

void Ins(int a, int b, int c){
	sz++; to[sz] = b; v[sz] = c; pre[sz] = last[a]; last[a] = sz;
}

int f[N][N][2];//0:³Ô 1:²»³Ô 

void DP1(int x,int father){
	f[x][0][1] = 0;
	f[x][1][0] = 0;
	for(int i = last[x]; i > 0; i = pre[i]){
		if(to[i] == father) continue;
		DP1(to[i], x);
		for(int j = K; j >= 0; j--){
			for(int k = 1; j + k <= K; k++){
				f[x][j + k][1] = min(f[x][j + k][1], f[to[i]][k][0] + f[x][j][1]);
				f[x][j + k][1] = min(f[x][j + k][1], f[to[i]][k][1] + f[x][j][1] + v[i]);
				f[x][j + k][0] = min(f[x][j + k][0], f[to[i]][k][1] + f[x][j][0]);
				f[x][j + k][0] = min(f[x][j + k][0], f[to[i]][k][0] + f[x][j][0] + v[i]);
			}
			if(f[to[i]][0][1] != 1e8){
				f[x][j][1] += f[to[i]][0][1] + v[i];
				f[x][j][0] += f[to[i]][0][1];
			}
			else{
				f[x][j][1] = 1e8;
				f[x][j][0] = 1e8;
			}
		}
	}
}

void DP2(int x,int father){
	f[x][0][1] = 0;
	f[x][1][0] = 0;
	for(int i = last[x]; i > 0; i = pre[i]){
		if(to[i] == father) continue;
		DP2(to[i], x);
		for(int j = K; j >= 0; j--){
			for(int k = 0; j + k <= K; k++){
				f[x][j + k][1] = min(f[x][j + k][1], f[to[i]][k][0] + f[x][j][1]);
				f[x][j + k][1] = min(f[x][j + k][1], f[to[i]][k][1] + f[x][j][1]);
				f[x][j + k][0] = min(f[x][j + k][0], f[to[i]][k][1] + f[x][j][0]);
				f[x][j + k][0] = min(f[x][j + k][0], f[to[i]][k][0] + f[x][j][0] + v[i]);
			}
		}
	}
}

void solve(){
	if(n - K < m - 1){
		printf("-1\n");
		return;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 0; j <= n; j++){
			f[i][j][0] = f[i][j][1] = 1e8;
		}
	if(m == 2){
		DP1(1,0);
	}
	else{
		DP2(1,0);
	}
	printf("%d\n", f[1][K][0]);
}

int main(){
	int a, b, c;
	scanf("%d %d %d", &n ,&m, &K);
	for(int i = 1; i < n; i++){
		scanf("%d %d %d", &a, &b, &c);
		Ins(a, b, c);
		Ins(b, a, c);
	}
	solve();
	return 0;
}

