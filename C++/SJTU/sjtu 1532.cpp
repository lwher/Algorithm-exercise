#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, m, map[35][35];
int ans, ansx, ansy;

inline bool Is_zero(){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(map[i][j]) 
				return 0;
	return 1;
}

inline void find(int &x, int &y){
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++){
			if(map[i][j]){
				x = i; y = j; return;
			}
		}
}

inline bool L_OK(int x, int y, int L){
	if(!map[x][y]) return 0;
	for(int i = 1; i <= L; i++)
		if(!map[x - i][y] || !map[x + i][y] || !map[x][y - i] || !map[x][y + i])
			return 0;
	return 1;
}

void work(int x, int y, int L, int p){
	map[x][y] += p;
	for(int i = 1; i <= L; i++){
		map[x - i][y] += p;
		map[x + i][y] += p;
		map[x][y - i] += p;
		map[x][y + i] += p;
	}
}
void dfs(int top, int tx, int ty){
	if(Is_zero()){
		ans = top; ansx = tx; ansy = ty;
		return;
	}
	if(top > 9) return;
	int x, y, ntx, nty;
	find(x, y);
	for(int L = 3; L <= 11; L += 2){
		if(L_OK(x + L / 2, y, L / 2)){
			work(x + L / 2, y, L / 2, -1);
			ntx = tx; nty = ty;
			if(x + L / 2 > ntx || (x + L / 2 == ntx && y > nty)){
				ntx = x + L / 2; nty = y;
			}
			dfs(top + 1, ntx , nty);
			work(x + L / 2, y, L / 2, 1);
		}
	}	
}

int main(){
	cin >> n >> m;
	ansx = n; ansy = m;
	for(int i = 1; i <= n ;i++)
		for(int j = 1; j <= m; j++){
			cin >> map[i][j];
		}
	dfs(0, 0, 0);
	cout << ans << endl;
	cout << ansx << " " << ansy << endl;
	return 0;
}

