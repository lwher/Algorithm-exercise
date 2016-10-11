#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<cstring>
using namespace std;
int n,m,ans=50,tot;
int map[40][40],Ans[40];
void init()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  map[i][i]=1,map[i][n+1]=1;
	for(i=1;i<=m;i++)
    {
		scanf("%d%d",&a,&b);
		map[a][b]=1;map[b][a]=1;
	}
}
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void gauss()
{
	int i,j,k;
	for(i=1;i<=n;i++)
	{
		j=i;
		while(j<=n && map[j][i]==0)  j++;
		if(j>n)  continue;
		if(i!=j)  for(k=1;k<=n+1;k++)  swap(map[i][k],map[j][k]);
		for(j=1;j<=n;j++)
		if(i!=j && map[j][i]==1) 
		{
			for(k=1;k<=n+1;k++)  map[j][k]^=map[i][k];
		} 
	}
}
void dfs(int now)
{
	int i,kk;
	if(tot>=ans)  return;
	if(now==0)
	{
		if(ans>tot) ans=tot; return;
	}
	if(map[now][now])
	{
		kk=map[now][n+1];
		for(i=now+1;i<=n;i++)  if(map[now][i])  kk^=Ans[i];
		Ans[now]=kk;
		if(kk==1)  tot++;
		dfs(now-1);  
		if(kk==1)  tot--;
	}
	else
	{
		Ans[now]=0;  dfs(now-1);
		Ans[now]=1; tot++;  dfs(now-1); tot--;
		//Ans[now]=0;
	}
}
int main()
{
	init();
	gauss();
	dfs(n);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}

