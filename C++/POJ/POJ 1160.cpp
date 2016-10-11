#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define inf 1<<25
using namespace std;
int n,p,f[31][310],cost[310][310],x[310];
int getcost(int l,int r)
{
	int tmp=0;
	while(l<r)
    {
		tmp+=x[r]-x[l];
		l++;r--;
	}
	return tmp;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&p);
	for(i=1;i<=n;i++)  scanf("%d",&x[i]);
	for(i=1;i<=n;i++)  for(j=i+1;j<=n;j++)   cost[i][j]=getcost(i,j);
	for(i=0;i<=p;i++)  for(j=0;j<=n;j++)  f[i][j]=inf;
	f[0][0]=0;
	for(i=1;i<=p;i++)
	{
		for(j=1;j<=n;j++)
		{
			for(k=0;k<j;k++)  f[i][j]=min(f[i][j],f[i-1][k]+cost[k+1][j]);
		}
	}
	cout<<f[p][n]<<endl;
	//system("pause");
	return 0;
}