#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,num[10010],sum[10010],last[10010];
void print(int l,int r)
{
	printf("%d\n",r-l+1);
	for(int i=l;i<=r;i++)  printf("%d\n",num[i]);
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&num[i]);
	for(i=1;i<=n;i++)
	{
		sum[i]=(sum[i-1]+num[i])%n;
		if(sum[i]==0)  {print(1,i);break;}
		if(last[sum[i]]!=0)  {print(last[sum[i]]+1,i);break;}
		else  last[sum[i]]=i;
	}
	return 0;
}