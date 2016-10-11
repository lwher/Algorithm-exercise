#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,map[50][50];
bool flag;
int xorsum(int x,int y)
{
    return (map[x][y]^map[x-1][y]^map[x][y-1]^map[x][y+1]);
}
void check()
{
    int i,j;
    for(i=2;i<=n;i++)  for(j=1;j<=m;j++)
    {
       if(xorsum(i-1,j)==1)  map[i][j]=1; else map[i][j]=0; 
    }
    for(j=1;j<=m;j++)  if(xorsum(n,j)==1)  return;
    flag=1;
}
void dfs(int top)
{
    if(top>(m/2+1))
    {
        int i,mid=m/2+1;
        for(i=m;i>=mid;i--)  map[1][i]=map[1][m-i+1];
        check();
        return;
    }
    map[1][top]=1; dfs(top+1);
    if(flag)  return;
    map[1][top]=0; dfs(top+1);
}
int main()
{
    scanf("%d%d",&n,&m);
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<m;j++)  printf("%d ",map[i][j]);
        printf("%d\n",map[i][m]);
    }
    return 0;
}