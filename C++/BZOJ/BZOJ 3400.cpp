#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
const int mod = 100000000;
int dp[2][1010];
int main()
{
    int n,f;
    scanf("%d%d",&n,&f);
    int pre,cur;
    for(int i=1;i<=n;i++)
    {
        cur=i&1;
        pre=cur^1;
        int p;
        scanf("%d",&p);
        memset(dp[cur],0,(f+5)<<2);
        dp[cur][p%f]++;
        for(int j=0;j<f;j++)
        {
            dp[cur][j]=(dp[cur][j]+dp[pre][j])%mod;
            dp[cur][(j+p)%f]=(dp[cur][(j+p)%f]+dp[pre][j])%mod;
        }    
    }
    printf("%d\n", dp[cur][0]);
    system("pause");
    return 0;
}
