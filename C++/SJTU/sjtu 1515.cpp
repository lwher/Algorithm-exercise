#include<iostream>
#include<queue>
#include<cmath>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m,map[1001][1001];
int qx,qy,zx,zy;
int dist[1001][1001][2],Qx[3000010],Qy[3000010],Qk[3000010];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void init(){
	cin>>m>>n;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]==2){
				qx=i;qy=j;
			}
			if(map[i][j]==3){
				zx=i;zy=j;
			}
		}
}

void BFS(){
	memset(dist,127,sizeof(dist));
	dist[qx][qy][0]=0;
	int tou=1,wei=1,x,y,k,nx,ny,nk;
	Qx[1]=qx;Qy[1]=qy;Qk[1]=0;
	while(tou<=wei){
		x=Qx[tou];y=Qy[tou];k=Qk[tou];
		tou++;
		for(int p=0;p<4;p++){
			nx=x+dx[p];
			ny=y+dy[p];
			if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]==1) continue;
			if(map[nx][ny]==4) nk=1; else nk=k;
			if(dist[nx][ny][nk]>dist[x][y][k]+1){
				dist[nx][ny][nk]=dist[x][y][k]+1;
				Qx[++wei]=nx;Qy[wei]=ny;Qk[wei]=nk;
			}
		}
	}
	cout<<dist[zx][zy][1]<<endl;
}
int main(){
	init();
	BFS();
	return 0;
}

