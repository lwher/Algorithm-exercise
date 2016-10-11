#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int f[2][210][210];
int map[210][210];
int p[1010];
int o;
int n,m;
int main()
{
    memset(f,127,sizeof(f));
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    scanf("%d",&map[i][j]);
    for(i=1;i<=m;i++)
    scanf("%d",&p[i]);
    f[o][2][3]=map[1][p[1]];
    f[o][1][2]=map[3][p[1]];
    f[o][1][3]=map[2][p[1]];
    o=1;
    for(i=2;i<=m;i++)
    {
       memset(f[o],127,sizeof(f[o]));
       for(j=1;j<=n;j++)
       for(k=1;k<=n;k++)
       {
            if(j!=p[i-1] && k!=p[i-1] && j!=k)
            {
               f[o][j][k]=min(f[o][j][k],f[1-o][j][k]+map[p[i-1]][p[i]]);
               f[o][j][p[i-1]]=min(f[o][j][p[i-1]],f[1-o][j][k]+map[k][p[i]]);
               f[o][k][p[i-1]]=min(f[o][k][p[i-1]],f[1-o][j][k]+map[j][p[i]]);
            }
       }
       o=1-o;
    }
    o=1-o;
    int ans=2147483647;
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
       ans=min(ans,f[o][i][j]);
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
