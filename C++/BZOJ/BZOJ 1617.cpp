#include<cstdio>
#include<iostream>
using namespace std;
int dp[2509];
int a[2509];
int min(int a,int b)
{
    return a>b?b:a;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,add=0;
        for(i=1;i<=n;i++)
        {
            int temp;
            scanf("%d",&temp);
            add+=temp;
            a[i]=add+m;
            dp[i]=a[i];
        }
        int j;
        for(i=2;i<=n;i++)
        {
            for(j=1;j<i;j++)
            {
                dp[i]=min(dp[i],dp[i-j]+dp[j]+m);
            }
        }

        printf("%d\n",dp[n]);
    }
}
