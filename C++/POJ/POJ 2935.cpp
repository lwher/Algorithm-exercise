#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

bool mark[10][10];

int X[6], Y[6];

int qx, qy, zx, zy;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int Qx[30010], Qy[30010], pre[30010];
char op[30010];

void print(int x){
	if(x == 1) return;
	print(pre[x]);
	putchar(op[x]);
}

void bfs(){
	bool flag;
	memset(mark, 0, sizeof(mark));
	int t = 1, w = 1, x, y;
	Qx[1] = qx; Qy[1] = qy;
	mark[qx][qy] = 1;
	char K;
	while(t <= w){
		x = Qx[t]; y = Qy[t]; t++;
		for(int k = 0; k < 4; k++){
			int nx = x + dx[k], ny = y + dy[k];
			if(nx < 1 || nx > 6 || ny < 1 || ny > 6 || mark[nx][ny]) continue;
			if(nx > x){ //E
				K = 'E';
				flag = 0;
				for(int i = 0; i < 3; i++) if(X[i] == X[i + 3] && X[i] == x){
					if(y > Y[i] && y <= Y[i + 3]) {
						flag = 1; break;
					}
				}
				if(flag) continue;
			}
			if(nx < x){ //W
				K = 'W';
				flag = 0;
				for(int i = 0; i < 3; i++) if(X[i] == X[i + 3] && X[i] == nx){
					if(y > Y[i] && y <= Y[i + 3]) {
						flag = 1; break;
					}
				}
				if(flag) continue;
			}
			if(ny > y){ //S
				K = 'S';
				flag = 0;
				for(int i = 0; i < 3; i++) if(Y[i] == Y[i + 3] && Y[i] == y){
					if(x > X[i] && x <= X[i + 3]) {
						flag = 1; break;
					}
				}
				if(flag) continue;
			}
			if(ny < y){ //N
				K = 'N';
				flag = 0;
				for(int i = 0; i < 3; i++) if(Y[i] == Y[i + 3] && Y[i] == ny){
					if(x > X[i] && x <= X[i + 3]) {
						flag = 1; break;
					}
				}
				if(flag) continue;
			}
			mark[nx][ny] = 1;
			Qx[++w] = nx; Qy[w] = ny; pre[w] = t - 1; op[w] = K;
			if(nx == zx && ny == zy){
				print(w);printf("\n");
				return;
			}
		}
	}
}

int main(){
	while(scanf("%d %d", &qx, &qy)){
		if(qx == 0 && qy == 0) break;
		scanf("%d %d", &zx, &zy);
		for(int i = 0 ; i < 3; i++){
			scanf("%d %d", &X[i], &Y[i]);
			scanf("%d %d", &X[i + 3], &Y[i + 3]);
			if(X[i] > X[i + 3]) swap(X[i], X[i + 3]);
			if(Y[i] > Y[i + 3]) swap(Y[i], Y[i + 3]);
		}
		bfs();
	}
	return 0;
}
