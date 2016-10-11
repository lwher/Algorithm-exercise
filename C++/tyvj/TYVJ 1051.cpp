#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m;
int f[310][310];
int fa[310],v[310];
void dfs(int x,int c)
{
     int i,j;
     if(c>0)
     for(i=1;i<=n;i++)
     if(fa[i]==x)
     {
         for(j=0;j<=c;j++)  f[i][j]=f[x][j];
         dfs(i,c-1);
         for(j=1;j<=c;j++)  f[x][j]=max(f[x][j],f[i][j-1]+v[i]);
     }
}
int main()
{
    int i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  scanf("%d%d",&fa[i],&v[i]);
    dfs(0,m);
    cout<<f[0][m]<<endl;
    system("pause");
    return 0;
}
