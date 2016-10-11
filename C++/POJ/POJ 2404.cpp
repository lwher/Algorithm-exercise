#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define inf 1e8
using namespace std;
int n,m,ans;
int map[30][30],dp[33000],du[30];
int dfs(int x)
{
    if(x==0) return 0;
    if(dp[x]!=-1)  return dp[x];
    int i,j,tmp=inf;
    for(i=1;i<=n;i++) 
    if(x & (1<<(i-1)))
    {
         for(j=1;j<=n;j++)
         if(i!=j && (x & (1<<(j-1))))
         {
             tmp=min(tmp,dfs(x^(1<<(i-1))^(1<<(j-1)))+map[i][j]);
         }
    }
    return dp[x]=tmp;
}
int main()
{
    int i,j,k,a,b,c;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(i=1;i<=n;i++)  
        { 
           for(j=1;j<=n;j++)  map[i][j]=inf;
           map[i][i]=0;
        }
        memset(du,0,sizeof(du));
        ans=0;
        for(i=1;i<=m;i++)  
        {
           scanf("%d%d%d",&a,&b,&c);
           if(map[a][b]>c)  map[a][b]=map[b][a]=c;
           du[a]++;du[b]++;
           ans+=c;
        }
        for(k=1;k<=n;k++)  for(i=1;i<=n;i++)  for(j=1;j<=n;j++)
        if(map[i][j]>map[i][k]+map[k][j])  map[i][j]=map[i][k]+map[k][j];
        int st=0;
        for(i=1;i<=n;i++)  if(du[i] & 1)  st|=(1<<(i-1));
        memset(dp,-1,sizeof(dp));
        printf("%d\n",ans+dfs(st));  
    }
    system("pause");
    return 0;
}
