#include<iostream> 
#include<cstdio> 
#include<cstdlib> 
#include<cmath> 
#include<cstring> 
using namespace std; 
int n,A,B; 
int map[1010][1010],duix[1000010],duiy[1000010]; 
bool mark[1010][1010],fA[1010][1010],fB[1010][1010];//A É½·å B É½¹È  
int dx[8]={0,1,1,1,0,-1,-1,-1}; 
int dy[8]={1,0,1,-1,-1,-1,0,1}; 
void bfs(int a,int b) 
{ 
    int k,nx,ny,x,y,tou=1,wei=1; 
    bool flagA=0,flagB=0; 
    duix[1]=a;duiy[1]=b; 
    mark[a][b]=1; 
    if(fA[a][b])  flagA=1; 
    if(fB[a][b])  flagB=1; 
    while(tou<=wei) 
    { 
        x=duix[tou];y=duiy[tou];tou++; 
        for(k=0;k<8;k++) 
        { 
            nx=x+dx[k];ny=y+dy[k]; 
            if(nx<1 || nx>n || ny<1 || ny>n || mark[nx][ny] || map[nx][ny]!=map[a][b]) continue; 
            if(fA[nx][ny])  flagA=1; 
            if(fB[nx][ny])  flagB=1; 
            mark[nx][ny]=1; 
            wei++;duix[wei]=nx;duiy[wei]=ny; 
        } 
    } 
    if(!flagA)  A++; 
    if(!flagB)  B++; 
} 
int main() 
{ 
    int i,j,k,nx,ny; 
    scanf("%d",&n); 
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)  scanf("%d",&map[i][j]); 
    for(i=1;i<=n;i++) for(j=1;j<=n;j++) 
    { 
        for(k=0;k<8;k++) 
        { 
            nx=i+dx[k];ny=j+dy[k]; 
            if(nx<1 || nx>n || ny<1 || ny>n)  continue; 
            if(map[nx][ny]>map[i][j])  fA[i][j]=1; 
            if(map[nx][ny]<map[i][j])  fB[i][j]=1; 
        } 
    } 
    for(i=1;i<=n;i++) for(j=1;j<=n;j++)  if(!mark[i][j])  bfs(i,j); 
    cout<<A<<" "<<B<<endl; 
    //system("pause"); 
    return 0; 
}