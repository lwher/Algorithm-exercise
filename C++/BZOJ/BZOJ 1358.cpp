#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,N,x[301],f[301][301][2],ans;//0:l 1:r
bool vis[301][301];
void dp(int l,int r)
{
    if(vis[l][r]) return;
    vis[l][r]=1;
    if(l==r) 
    {
       f[l][r][0]=f[l][r][1]=m-abs(x[l])*N;
       return;
    } 
    dp(l+1,r);dp(l,r-1);
    f[l][r][0]=max(f[l+1][r][0]-(x[l+1]-x[l])*(N-r+l),f[l+1][r][1]-(x[r]-x[l])*(N-r+l))+m;
    f[l][r][1]=max(f[l][r-1][1]-(x[r]-x[r-1])*(N-r+l),f[l][r-1][0]-(x[r]-x[l])*(N-r+l))+m;
}
int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&x[i]);
    sort(x+1,x+1+n);
    for(N=1;N<=n;N++)
    {
       memset(vis,0,sizeof(vis));
       for(i=1;i<=n;i++)
       {
           j=i+N-1;
           if(j>n) break;
           dp(i,j);
           ans=max(ans,max(f[i][j][1],f[i][j][0]));
       }
    }
    cout<<ans<<endl;
    return 0;
}