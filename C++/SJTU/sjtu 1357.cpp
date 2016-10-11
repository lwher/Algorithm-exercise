#include<iostream>
#include<ctime>
#include<cmath>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int ans, duix[30], duiy[30];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool have[5][5];
char map[5][5];
bool mark[25];

bool bfs(int X, int Y){
	int sum = 1, p = 0, t = 1, w = 1, x, y, nx, ny;
	if(map[X][Y] == 'J') p++;
	duix[1] = X;duiy[1] = Y;have[X][Y] = 0;
	while(t <= w){
		x = duix[t];y = duiy[t];t++;
		for(int k = 0; k < 4; k++){
			nx = x + dx[k];ny = y + dy[k];
			if(nx < 0 || ny < 0 || nx >= 5 || ny >= 5 || !have[nx][ny]) continue;
			if(map[nx][ny] == 'J') p++;
			sum++;have[nx][ny] = 0;
			duix[++w] = nx;duiy[w] = ny;
		}
	}
	if(sum == 7 && p > 3) return 1;
	else return 0;
}

bool check(){
	for(int i = 0;i < 25; i++) if(mark[i]) have[i / 5][i %5 ] = 1; else have[i / 5][i % 5]=0;
	for(int i = 0;i < 25;i++){
		if(mark[i]){
			if(bfs(i / 5,i % 5)) return 1;
			else return 0;
		}
	}
}

int main(){
	for(int i = 0;i < 5;i++) scanf("%s", map[i]);	
	int i1,i2,i3,i4,i5,i6,i7;
	for(i1 = 0; i1 < 25; i1++)
		for(i2 = i1 + 1; i2 < 25; i2++)
			for(i3 = i2 + 1; i3 < 25 ; i3++)
				for(i4 = i3 + 1; i4 < 25; i4++)
					for(i5 = i4 + 1; i5 < 25; i5++)
						for(i6 = i5 + 1; i6 < 25; i6++)
							for(i7 = i6 + 1; i7 < 25; i7++){
								memset(mark, 0, sizeof(mark));
								mark[i1] = 1;mark[i2] = 1;mark[i3] = 1;mark[i4] = 1;
								mark[i5] = 1;mark[i6] = 1;mark[i7] = 1;
								if(check()) 
									ans++;
							}
	cout << ans << endl;
	return 0;
}

