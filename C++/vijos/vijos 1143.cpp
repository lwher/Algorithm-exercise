#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int map[25][25];
int f[50][25][25][25];
int main()
{
    int i,j,k,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  for(j=1;j<=n;j++)  scanf("%d",&map[i][j]);
    f[1][1][1][1]=map[1][1];
    for(x=2;x<=n+n-1;x++)
    for(i=1;i<=min(x,n);i++)
    for(j=1;j<=min(x,n);j++)
    for(k=1;k<=min(x,n);k++)
    {
        f[x][i][j][k]=max(f[x-1][i][j][k],max(f[x-1][i-1][j][k],max(f[x-1][i][j-1][k],f[x-1][i][j][k-1])));
        f[x][i][j][k]=max(f[x][i][j][k],max(f[x-1][i-1][j-1][k],max(f[x-1][i-1][j][k-1],max(f[x-1][i][j-1][k-1],f[x-1][i-1][j-1][k-1]))));
        if(i==j && i==k)    f[x][i][j][k]+=map[x+1-i][i];
        else
        if(i==j)  f[x][i][j][k]+=map[x+1-i][i]+map[x+1-k][k];
        else
        if(i==k)  f[x][i][j][k]+=map[x+1-i][i]+map[x+1-j][j];
        else
        if(k==j)  f[x][i][j][k]+=map[x+1-i][i]+map[x+1-k][k];
        else
        f[x][i][j][k]+=map[x+1-i][i]+map[x+1-k][k]+map[x+1-j][j];
    }
    cout<<f[n+n-1][n][n][n]<<endl;
    system("pause");
    return 0;
}
