#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n;
int num[1000010];
long long sum[1000010],dp[1000010];
int main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
       scanf("%d",&num[i]);
    }
    sort(num+1,num+1+n);
    for(i=1;i<=n;i++)
    dp[i]=max(num[i]-dp[i-1],dp[i-1]);
    cout<<dp[n]<<endl;
    system("pause");
    return 0;
}
