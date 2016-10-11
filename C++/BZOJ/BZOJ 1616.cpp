#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char map[101][101];
int n,m,t;
int ans;
int qx,qy,zx,zy;
void dfs(int x,int y,int top)
{
     if(top==0)
     {
               if(x==zx && y==zy)
               ans++;
               return;
     }
     if(abs(zx-x)+abs(zy-y)>top)  return;
     if(x>1 && map[x-1][y]!='*')    dfs(x-1,y,top-1);
     if(x<n && map[x+1][y]!='*')    dfs(x+1,y,top-1);
     if(y>1 && map[x][y-1]!='*')    dfs(x,y-1,top-1);
     if(y<m && map[x][y+1]!='*')    dfs(x,y+1,top-1);
}
int main()
{
    int i,j;
    cin>>n>>m>>t;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    cin>>map[i][j];
    cin>>qx>>qy;
    cin>>zx>>zy;
    dfs(qx,qy,t);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
