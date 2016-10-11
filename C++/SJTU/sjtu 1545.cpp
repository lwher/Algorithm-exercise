#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define N 10010

using namespace std;

int n, m, K;
int x[N], y[N], r[N], fa[1010][1010];
char ch[1010][1010], col[N][3];

int getfa(int p, int x){
	if(fa[p][x] == 0) return x;
	return fa[p][x] = getfa(p, fa[p][x]);
}

int main(){
	scanf("%d %d %d", &n, &m, &K);
	for(int i = 1; i <= K; i++){
		scanf("%d %d %d %s", &x[i], &y[i], &r[i], col[i]);
	}
	for(int i = K; i >= 1; i--){
		int up = max(1, x[i] - r[i]), down = min(n, x[i] + r[i]);
		for(int j = up; j <= down; j++){
			int D = sqrt(r[i] * r[i] - (j - x[i]) * (j - x[i]));
			int l = max(1, y[i] - D), r = min(m, y[i] + D);
			for(int k = getfa(j, l); k <= r; k = getfa(j, k + 1)){
				if(!fa[j][k]){
					ch[j][k] = col[i][0];
					fa[j][k] = k + 1;
				}
			}
		}	
	}
	int R = 0, B = 0, G = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(ch[i][j] == 'R') R++; else
			if(ch[i][j] == 'B') B++; else
			if(ch[i][j] == 'G') G++;
		}
	cout << "Red:" << R << endl;
	cout << "Green:" << G << endl;
	cout << "Blue:" << B << endl; 
	return 0;
}

