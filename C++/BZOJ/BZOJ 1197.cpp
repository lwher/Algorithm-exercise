#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
unsigned long long f[16][101];
int main()
{
    int i,j;
    scanf("%d%d",&m,&n);
    for(i=1;i<=m;i++)  f[1][i]=i*2;
    for(i=1;i<=n;i++)  f[i][1]=2;
    for(i=2;i<=n;i++)  for(j=2;j<=m;j++)  f[i][j]=f[i][j-1]+f[i-1][j-1];
    cout<<f[n][m]<<endl;
    system("pause");
    return 0;
}
