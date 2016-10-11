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

int n,x,y,dir,X,Y;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
bool mark[1001][1001];

int main(){
	scanf("%d%d%d",&n,&X,&Y);
	int nx=1,ny=1,x,y;
	dir=0;
	mark[1][1]=1;
	for(int i = 0; i <= n * n; i++){
		if(nx ==X && ny == Y){
			printf("%d\n",i);
			break;
		}
		x = nx + dx[dir];
		y = ny + dy[dir];
		if(x < 1 || y < 1 || x > n || y > n || mark[x][y])
			dir = (dir+1) % 4;
		nx += dx[dir];
		ny += dy[dir];
		mark[nx][ny] = 1;
	}	
	return 0;
}

