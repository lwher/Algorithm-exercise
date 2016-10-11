#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 1e9
using namespace std;
int n,p,root,ans;
int sum[151],son[151][151],fa[151];
int f[151][151];
void dp(int x)
{
     int i,j,k;
     f[x][1]=sum[x];
     for(i=1;i<=sum[x];i++)
     {
         dp(son[x][i]);
         for(j=p;j>=2;j--)  for(k=1;k<=j-1;k++)
         f[x][j]=min(f[x][j],f[x][j-k]+f[son[x][i]][k]-1);
     }
}
int main()
{
    int i,j,a,b;
    scanf("%d%d",&n,&p);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        sum[a]++;son[a][sum[a]]=b;fa[b]=a;
    }
    for(i=1;i<=n;i++)  for(j=1;j<=p;j++)  f[i][j]=INF;
    root=1;
    while(fa[root])  root=fa[root];
    dp(root);
    ans=f[root][p];
    for(i=1;i<=n;i++)  if(i!=root)  ans=min(ans,f[i][p]+1);
    cout<<ans<<endl;
    system("pause");
    return 0;
}
