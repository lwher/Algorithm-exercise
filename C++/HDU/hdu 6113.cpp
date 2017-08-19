#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int map[110][110];
char s[110];

int Qx[1000010], Qy[1000010];
bool mark[110][110];

void bfs(int x, int y) {
	mark[x][y] = 1;
	int t = 1, w = 1, px, py, nx, ny;
	Qx[1] = x; Qy[1] = y;
	while(t <= w){
		px = Qx[t];
		py = Qy[t];
		++t;
		for (int k = 0; k < 4; ++k) {
			nx = px + dx[k];
			ny = py + dy[k];
			if (nx < 0 || ny < 0 || nx > n + 1 || ny > m + 1 || map[x][y] != map[nx][ny] || mark[nx][ny])
				continue;
			mark[nx][ny] = 1;
			Qx[++w] = nx;
			Qy[w] = ny;
		}
	}
}

int main() {
	while (cin >> n >> m) {
		memset(map, 0, sizeof(map));
		for (int i = 1; i <= n; ++i) {
			scanf("%s", s + 1);
			for (int j = 1; j <= m; ++j) {
				if (s[j] == '1') {
					map[i][j] = 1;
				}
				else {
					map[i][j] = 0;
				}
			}
		}
		int num1 = 0;
		memset(mark, 0, sizeof(mark));
		for(int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if(map[i][j] == 1 && !mark[i][j]) {
					bfs(i, j);
					num1 += 1;
				}
			}
		}
		if(num1 != 1) {
			cout << -1 << endl;
			continue;
		}
		bfs(0, 0);
		int num0 = 0;
		for(int i = 1; i <= n; ++i) {
			for (int j = 1; j <= m; ++j) {
				if(map[i][j] == 0 && !mark[i][j]){
					bfs(i, j);
					num0 += 1;
				}
			}
		}
		if(num0 == 0){
			cout << 1 << endl;
		}
		else if(num0 == 1){
			cout << 0 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}
