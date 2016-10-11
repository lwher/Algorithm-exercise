#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
char ch[15];
int map[110];
int sum[110][110];
int f[110][110][110];
int ggs[1024];
int getsum(int x)
{
	int gs=0,i;
	for(i=0;i<=m-1;i++)
	{
		if((x>>i) & 1)
		gs++;
	} 
	return gs;
}
int main()
{
	int i,j,k,l,o,p;
	scanf("%d%d",&n,&m);
	for(i=1;i<(1<<m);i++)
	ggs[i]=getsum(i);
	for(i=1;i<=n;i++)
	{
		scanf("\n%s",ch+1);
		for(j=1;j<=m;j++)
		if(ch[j]=='H')
		{map[i]+=(1<<m-j);}
	}
	for(i=1;i<=n;i++)
	{
	 for(j=0;j<=(1<<m)-1;j++)
	 if(!(j & (j>>1)) && !(j & (j>>2)) && !(j & map[i]))
	 {
			sum[i][0]++;
			sum[i][sum[i][0]]=j;
	 }
	}
	
	sum[0][0]=1;sum[0][1]=0;
	for(i=1;i<=sum[1][0];i++)
	f[1][i][1]=ggs[sum[1][i]];
	
	for(i=2;i<=n;i++)
	{
		for(k=1;k<=sum[i][0];k++)
		for(j=1;j<=sum[i-1][0];j++)
		if(!(sum[i][k] & sum[i-1][j]))
		{
			for(l=1;l<=sum[i-2][0];l++)
			if(!(sum[i-2][l] & sum[i][k]))
			{
				f[i][k][j]=max(f[i][k][j],f[i-1][j][l]+ggs[sum[i][k]]);
			}
		}
	}
	int ans=0;
	for(i=1;i<=sum[n][0];i++)
	for(j=1;j<=sum[n-1][0];j++)
	if(f[n][i][j]>ans)
	ans=f[n][i][j];
	cout<<ans<<endl;
	//system("pause");
	return 0;
}

