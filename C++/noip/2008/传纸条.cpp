#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int map[51][51];
int n,m;
int f[101][51][51];
int main()
{
    int i,j,k,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)   for(j=1;j<=m;j++)  scanf("%d",&map[i][j]);
    f[1][1][1]=map[1][1];
    f[2][1][1]=map[1][1]+map[2][1];
    f[2][2][2]=map[1][1]+map[1][2];
    f[2][1][2]=map[1][1]+map[1][2]+map[2][1];
    f[2][2][1]=map[1][1]+map[1][2]+map[2][1];
    for(k=3;k<=n+m-1;k++)
    {
    if(k>n-1)  a=k-n+1; else a=1;
    for(i=a;i<=min(k,m);i++)
    for(j=a;j<=min(k,m);j++)
    {
         f[k][i][j]=max(f[k-1][i][j],max(f[k-1][i-1][j],max(f[k-1][i][j-1],f[k-1][i-1][j-1])));
         if(i==j)  f[k][i][j]+=map[k+1-i][i];
         else
         {
             f[k][i][j]+=map[k+1-i][i]+map[k+1-j][j];
         }
    }
    }
    cout<<f[n+m-1][m][m]<<endl;
    system("pause");
    return 0;
}
