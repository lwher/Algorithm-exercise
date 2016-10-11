#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int n,m[21],s;
int dp[21][(1<<13)+1];
int dfs(int now,int left)
{
	if(dp[now][left]!=-1)  return dp[now][left];
	if(left==0)
	{dp[now][0]=1;return 1;}
	int i,ans=0;
	for(i=1;i<=m[now];i++)
	{
		if(left<i)  break;
		if(dfs(now%n+1,left-i)==0)
		ans=1;
	}
	dp[now][left]=ans;
	return ans;
}
int main()
{
	int i;
	while(scanf("%d",&n) && n)
	{
		n*=2;
		scanf("%d",&s);
		for(i=1;i<=n;i++)
		scanf("%d",&m[i]);
		memset(dp,-1,sizeof(dp));
		if(dfs(1,s)==1)
		printf("1\n");
		else
		printf("0\n");
	}
	//system("pause");
	return 0;
}

