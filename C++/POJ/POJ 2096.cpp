#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,s;
double ns;
double dp[1010][1010];
int main()
{
	int i,j;
	scanf("%d%d",&n,&s);
	ns=n*s;
	dp[n][s]=0;
	for(i=n;i>=0;i--)
	for(j=s;j>=0;j--)
	{
		if(i!=n || j!=s)
		{
			dp[i][j]=((n-i)*(s-j)*dp[i+1][j+1]+ns+(n-i)*j*dp[i+1][j]+i*(s-j)*dp[i][j+1])/(ns-(i*j)); 
		}
	}
	printf("%.4lf\n",dp[0][0]);
	//system("pause");
	return 0;
}

