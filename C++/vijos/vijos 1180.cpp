#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,m,f[310][310],fa[310],v[310];
void dp(int x,int c)
{
	if(c==0)  return;
	for(int i=1;i<=n;i++)
	if(fa[i]==x)
	{
		int j;
		for(j=0;j<=c;j++)  f[i][j]=f[x][j];
		dp(i,c-1);
		for(j=1;j<=c;j++)  f[x][j]=max(f[x][j],f[i][j-1]+v[i]);
	}
}
int main()
{
	int i;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  scanf("%d%d",&fa[i],&v[i]);
	dp(0,m);
	cout<<f[0][m]<<endl;
	//system("pause");
	return 0;
}
