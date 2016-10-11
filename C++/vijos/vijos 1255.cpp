#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,map[301][301];
long long sum[301][301],num[301],dp[301],tmp,ans;
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  
	{
		scanf("%d",&map[i][j]);
		if(map[i][j]==0)  map[i][j]=-1e9;
	}
	for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  sum[i][j]=sum[i-1][j]+map[i][j];
	for(i=1;i<=n;i++)   for(j=i;j<=n;j++)
	{
		for(k=1;k<=m;k++)  num[k]=sum[j][k]-sum[i-1][k];
		dp[0]=0;tmp=0;
		for(k=1;k<=m;k++)    {dp[k]=max(num[k],dp[k-1]+num[k]);tmp=max(tmp,dp[k]);}
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}