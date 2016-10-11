#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth{
    int x,y;
}Q[30001];
int n,ans,map[101][101],T[101][101];
bool mark[101][101];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
void bfs(){
    int t=1,w=0,i,j,k,tx,ty,nx,ny;
    for(i=1;i<=n;i++) for(j=1;j<=n;j++){
        if(map[i][j]==1){
            mark[i][j]=1;
            Q[++w].x=i;
            Q[w].y=j;
        }
    }    
    while(t<=w){
        nx=Q[t].x;ny=Q[t].y;t++;
        for(k=0;k<4;k++){
            tx=nx+dx[k];
            ty=ny+dy[k];
            if(tx<1 || tx>n || ty<1 || ty>n) continue;
            if(!mark[tx][ty] && map[tx][ty]!=2){
                mark[tx][ty]=1;
                T[tx][ty]=T[nx][ny]+1;
                Q[++w].x=tx;Q[w].y=ty;
            }
        }
    }
}
int main(){
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) scanf("%d",&map[i][j]);    
    bfs();
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) 
        if(T[i][j]>ans) ans=T[i][j];
    cout<<ans<<endl;
    system("pause");
    return 0;
}
