#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
long long a,b;
long long cf[15];
long long calc(long long x)
{
	if(x<0)  return 0;
	long long sum=1;
	int i;
	long long quo,rem,now;
	for(i=1;i<15;i++)
	{
		if(x<cf[i])  break;
		quo=x/cf[i];
		rem=x%cf[i-1];
		now=(x%cf[i]-x%cf[i-1])/cf[i-1];
		if(now==0)  sum+=(quo-1)*cf[i-1]+rem+1;
		else   sum+=quo*cf[i-1];
	}
	return sum;
}
int main()
{
	cf[0]=1;
	for(int i=1;i<15;i++)  cf[i]=cf[i-1]*10;
	while(scanf("%I64d%I64d",&a,&b))
	{
		if((a==-1) || (b==-1))  break;
		else  printf("%I64d\n",calc(b)-calc(a-1));
	}
	//system("pause");
	return 0;
}
