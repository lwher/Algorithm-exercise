#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, qx, qy, sum, ans, map[101][101], pt[101][101], dist[101][101][35];
int Qx[3000010], Qy[3000010], Qp[3000010];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
void bfs(){
	memset(dist, 127, sizeof(dist));
	dist[qx][qy][0] = 0; ans = dist[0][0][0];
	int t = 1, w = 1, nx, ny, np, x, y, p;
	Qx[1] = qx; Qy[1] = qy; Qp[1] = 0;
	while(t <= w){
		x = Qx[t]; y = Qy[t]; p = Qp[t]; t++;
		for(int k = 0; k < 4; k++){
			nx = x + dx[k];
			ny = y + dy[k];
			np = p;
			if(nx < 1 || nx > n || ny < 1 || ny > m || map[nx][ny] == -1) continue;
			if(map[nx][ny] == 1) np |= (1 << pt[nx][ny]);
			if(dist[x][y][p] + 1 < dist[nx][ny][np]){
				dist[nx][ny][np] = dist[x][y][p] + 1;
				Qx[++w] = nx; Qy[w] = ny; Qp[w] = np;
			}
		}
	}
}

int main(){
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] == 2) qx = i, qy = j;
			if(map[i][j] == 1) pt[i][j] = sum++;
		}
	bfs();
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= m; j++){
			if(ans > dist[i][j][(1 << sum) - 1]) 
				ans = dist[i][j][(1 << sum) - 1];
		}
	if(ans == dist[0][0][0]) printf("-1\n");
	else printf("%d\n", ans);
	return 0;
}

