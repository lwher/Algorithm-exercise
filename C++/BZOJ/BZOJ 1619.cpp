#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <queue>
#include <cmath>
using namespace std;
int map[800][800];
int used[800][800];
int d[8][2]={{1,0,},{1,-1},{1,1},{-1,0},{-1,1},{-1,-1},{0,1},{0,-1}};
bool ok;
int n,m,sum=0;

void DFS(int x,int y){
    int xx,yy;
    for(int i=0;i<8;i++){
        xx=d[i][0]+x;
        yy=d[i][1]+y;
        if(xx>=0 && xx<n && yy>=0 && yy<m){
            if(map[xx][yy]>map[x][y])
                ok=0;
            if(map[xx][yy]==map[x][y] && !used[xx][yy]){
                used[xx][yy]=1;
                DFS(xx,yy);
            }
        }
    }
}
int main(){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                scanf("%d",&map[i][j]);
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(!used[i][j] && map[i][j]){
                ok=1;
                DFS(i,j);
                if(ok)
                    sum++;
                }
        printf("%d\n",sum);
        system("pause");
}

