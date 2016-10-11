#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,map[1010][1010];
int check[1010][1010];//0:unknow 1:yes 2:no
int dx[8]={0,1,-1,0,1,1,-1,-1};
int dy[8]={1,0,0,-1,1,-1,1,-1};
inline bool OK(){
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			if(check[i][j]==0)
				return 0;
	return 1;
}
void solve(){
	int Y,N,U,nx,ny;
	bool flag=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(check[i][j]!=0) continue;
			Y=0;N=0;U=0;
			for(int k=0;k<8;k++){
				nx=i+dx[k];ny=j+dy[k];
				if(nx<1 || nx>n || ny<1 || ny>m) continue;
				if(check[nx][ny]==0) U++;
				if(check[nx][ny]==1) Y++;
				if(check[nx][ny]==2) N++;
			}
			if(map[i][j]-Y<4){
				flag=1;
				check[i][j]=2;
				continue;
			}
			if(map[i][j]-(8-N)>0){
				flag=1;
				check[i][j]=1;
				continue;
			}
		}
	}
	if(!flag){
		int x,y,k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(check[i][j]==0 && map[i][j]>k){
					x=i;y=j;
				}
			}
		}
		check[x][y]=1;
	}
	
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(check[i][j]==1) printf("L");
			else printf("-");
			//cout<<check[i][j];
		}
		printf("\n");
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++){
			scanf("%d",&map[i][j]);
			if(map[i][j]<4) check[i][j]=2;
	}
	while(1){
		if(OK()) break;
		solve();
	}
	print();
	return 0;
}
