#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int n,m;
int main()
{
	long long a,b;
	int k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		k=abs(n-m);
		a=double(k)*(1.0+sqrt(5.0))/2.0;
		b=a+k;
		if((a==n && b==m) || (a==m && b==n))
		{
			printf("0\n");
		}
		else
		printf("1\n");
	}
	//system("pause");
	return 0;
}

