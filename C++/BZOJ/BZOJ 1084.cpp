#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
using namespace std;
int dp[101][11],f[101][101][11];
int n,m,K;
int sum[101];
int s1[101],s2[101];
int main()
{
    int i,j,k,l;
    int s,ss;
    scanf("%d%d%d",&n,&m,&K);
    if(m==1)
    {
        for(i=1;i<=n;i++)
        {scanf("%d",&k);sum[i]=sum[i-1]+k;}
        for(i=1;i<=n;i++)
        for(k=1;k<=K;k++)
        {
           dp[i][k]=dp[i-1][k];
           for(j=0;j<i;j++)
           dp[i][k]=max(dp[i][k],dp[j][k-1]+sum[i]-sum[j]);
        }
        cout<<dp[n][K]<<endl;
    }
    else
    {
        for(i=1;i<=n;i++)
        {scanf("%d%d",&s,&ss);s1[i]=s1[i-1]+s;s2[i]=s2[i-1]+ss;}
        for(k=1;k<=K;k++)
        for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
        {
            f[i][j][k]=max(f[i-1][j][k],f[i][j-1][k]);
            for(l=0;l<i;l++)  f[i][j][k]=max(f[i][j][k],f[l][j][k-1]+s1[i]-s1[l]);
            for(l=0;l<j;l++)  f[i][j][k]=max(f[i][j][k],f[i][l][k-1]+s2[j]-s2[l]);
            if(i==j)  
            for(l=0;l<i;l++)  
            f[i][j][k]=max(f[i][j][k],f[l][l][k-1]+s1[i]-s1[l]+s2[j]-s2[l]);
        }
        cout<<f[n][n][K]<<endl;
    }
    system("pause");
    return 0;
}
