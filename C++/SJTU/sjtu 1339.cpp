#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 1010
using namespace std;
int n, m, dist[N][N], qx[N*N], qy[N*N];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char map[N][N];
bool in[N][N];
void init(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) scanf("%s",map[i]+1);
}
inline void inc(int &x){
	x++;if(x > n*m) x = 0;
}
void Spfa(){
	memset(in,0,sizeof(in));
	memset(dist,127,sizeof(dist));
	int x, y, nx, ny, t = 0, w = 1;
	qx[1] = 1;
	qy[1] = 1;
	in[1][1] = 1;
	dist[1][1] = 0;
	while(t != w){
		inc(t);
		x = qx[t];y = qy[t];
		in[x][y] = 0;
		for(int k = 0; k < 4; k++){
			nx = x + dx[k];
			ny = y + dy[k];
			if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if(dist[nx][ny] > dist[x][y] + (map[x][y] != map[nx][ny])){
				dist[nx][ny] = dist[x][y] + (map[x][y] != map[nx][ny]);
				if(!in[nx][ny]){
					inc(w);
					qx[w] = nx;qy[w] = ny;
					in[nx][ny] = 1;
				}
			}
		}
	}
	printf("%d\n", dist[n][m]);
}
int main(){
	int T;
	cin >> T;
	while(T--){
		init();
		Spfa();
	}
	return 0;
}

