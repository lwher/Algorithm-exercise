#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, ty, maxx, maxy, minx, miny;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
double S, maxdist, mindist;
char map[1010][1010];

inline bool On_side(int x, int y){
	int nx, ny;
	for(int k = 0; k < 4; k++){
		nx = x + dx[k]; ny = y + dy[k];
		if(map[nx][ny] == '0') return 1;
	}
	return 0;
}

void solve(){
	double res1 = S / ((maxx - minx) * (maxy - miny));
	double res2 = mindist / maxdist;
	if(res1 >= 0.76 && res1 <= 0.82 && res2 >= 0.9 && res2 <= 1.1){
		printf("circle\n");
		return;
	}
	if(res1 >= 0.45 && res2 >= 0.45 && res2 <= 0.55){
		printf("square\n");
		return;
	}
	printf("triangle\n");
}

int main(){
	scanf("%d %d", &m, &n);
	S = 0; maxx = -1e8; maxy = -1e8; minx = 1e8; miny = 1e8;
	for(int i = 1; i <= n; i++){
		scanf("%s", map[i] + 1);
		for(int j = 1; j <= m; j++)
			if(map[i][j] == '1'){
				S++;
				maxx = max(maxx, i);
				minx = min(minx, i);
				maxy = max(maxy, j);
				miny = min(miny, j);
			}
	}
	double X = double(maxx + minx) * 0.5;
	double Y = double(maxy + miny) * 0.5;
	maxdist = -1e9; mindist = 1e9;
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(map[i][j] == '1' && On_side(i, j)){
				double dist = (X - i) * (X - i) + (Y - j) * (Y- j);
				if(dist > maxdist) maxdist = dist;
				if(dist < mindist) mindist = dist;
			}
		}
	solve();
	while(1);
	return 0;
}

