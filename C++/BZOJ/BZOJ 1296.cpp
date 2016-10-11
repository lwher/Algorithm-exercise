#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,T,f[51][51],dp[51][2510],sum[51],ans;
char s[60];
int main()
{
    int i,j,k,p,tmp;
    scanf("%d%d%d",&n,&m,&T);
    for(i=1;i<=n;i++)  
    {
       scanf("%s",s+1);
       for(j=1;j<=m;j++) if(s[j]=='1') sum[j]=sum[j-1]+1; else sum[j]=sum[j-1];
       memset(f,0,sizeof(f));
       for(p=1;p<=m;p++)  for(j=1;j<=m;j++)
       {
          for(k=0;k<j;k++)  
          {
              tmp=sum[j]-sum[k];
              f[j][p]=max(f[j][p],f[k][p-1]+max(tmp,j-k-tmp));
          }
       }
       for(j=1;j<=T;j++)
       {
          tmp=min(m,j);
          for(k=1;k<=tmp;k++)  dp[i][j]=max(dp[i][j],dp[i-1][j-k]+f[m][k]);
       }
    }
    for(i=1;i<=T;i++)  ans=max(dp[n][i],ans);
    printf("%d\n",ans);
    return 0;
}