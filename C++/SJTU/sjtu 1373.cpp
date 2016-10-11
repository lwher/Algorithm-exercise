#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 3000000
using namespace std;

int n, m, H[501][501], have[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int qx[N], qy[N], QX, QY;
bool mark[501][501];

bool check(int mid){
	int t = 1, w = 1, x, y, nx, ny;
	memset(mark, 0, sizeof(mark));	
	mark[QX][QY] = 1;
	qx[1] = QX;
	qy[1] = QY;
	while(t <= w){
		x = qx[t]; y = qy[t]; t++;
		for(int k = 0; k < 4; k++){
			nx = x + dx[k];
			ny = y + dy[k];
			if(nx < 1 || nx > n || ny < 1 || ny > m || mark[nx][ny] || abs(H[nx][ny] - H[x][y]) > mid) continue;
			qx[++w] = nx; qy[w] = ny; 
			mark[nx][ny] = 1;
		}
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(have[i][j] == 1 && !mark[i][j])
				return 0;
	return 1;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &H[i][j]);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			scanf("%d", &have[i][j]);
			if(have[i][j] == 1)
				QX = i, QY = j;
		}	
	int l = 0, r = 2e9, mid;
	while(l + 1 < r){
		mid = (l + r) >> 1;
		if(check(mid)) r = mid;
		else l = mid;
	}
	if(check(l)) printf("%d\n", l);
	else printf("%d\n", r);
	return 0;
}

