#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int f[1001][10001];
int n,m;
int qpow(long long a,int b)
{
	long long now=1;
	while(b>0)
	{
		if(b & 1)  now=(now*a)%1000000007;
		a=(a*a)%1000000007;
		b=b>>1;
	}
	return now;
}
int main()
{
	int i,j,k;
	scanf("%d%d",&n,&m);
	f[1][0]=1;
	for(i=2;i<=n;i++)
	{
		k=0;
		for(j=0;j<=i-1;j++)  {k=(k+f[i-1][j])%1000000007;f[i][j]=k;}
		for(j=i;j<=m;j++)
		{
			k=(k-f[i-1][j-i])%1000000007;
			if(k<0)  k+=1000000007;
			k=(k+f[i-1][j])%1000000007;
			f[i][j]=k;
		}
	}
	printf("%d\n",qpow(2,f[n][m]));
	//system("pause");
	return 0;
}
