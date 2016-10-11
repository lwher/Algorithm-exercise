#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[111][111];//dp[i][j]表示前i个公司分配j台机械的最大价值
//dp[i][j]=max(dp[i-1][k]+a[i][j-k]);
int a[111][111];//a[i][j]表示第I个公司分配J台机器的盈利
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j-k]);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

