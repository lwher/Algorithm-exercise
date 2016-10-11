#include<iostream>
#include<map>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

int n, num[50][50];

int main(){
	scanf("%d", &n);
	int x = 1, y = n + 1 >> 1;
	for(int i = 1; i <= n * n; i++){
		num[x][y] = i;
		if(x == 1 && y != n){
			x = n; y++;
		} else
		if(y == n && x != 1){
			x--; y = 1;
		} else
		if(x == 1 && y == n){
			x++;
		} 
		else{
			int nx = x - 1, ny = y + 1;
			if(!num[nx][ny]){
				x = nx; y = ny;
			}
			else{
				x++;
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j < n; j++)
			printf("%d ", num[i][j]);
		printf("%d\n", num[i][n]);
	}
	return 0;
}

