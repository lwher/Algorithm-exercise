#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define abs(x) (((x)<0)?(-(x)):(x))
#define sqr(x) ((x)*(x))
int dp[105],f[105],g[105],h[100005],n,c;
const int inf=1061109567;
int main()
{
    scanf("%d%d",&n,&c);
    for(int i=1;i<=n;i++) scanf("%d",&h[i]);
    memset(dp,63,sizeof(dp));
    for(int i=h[1];i<=100;i++) dp[i]=sqr(i-h[1]);
    for(int i=2;i<=n;i++)
    {
        f[101]=inf; for(int j=100;j>=1;j--) f[j]=min(dp[j]+j*c,f[j+1]);
        g[0]=inf; for(int j=1;j<=100;j++) g[j]=min(dp[j]-j*c,g[j-1]);
        memset(dp,63,sizeof(dp));
        for(int j=h[i];j<=100;j++) dp[j]=sqr(j-h[i])+min(g[j]+j*c,f[j]-j*c);
    }
    int An=inf;
    for(int i=1;i<=100;i++) An=min(An,dp[i]);
    printf("%d\n",An);  
    return 0;
}