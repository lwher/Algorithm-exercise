#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,num[200010];
inline bool comp(int a,int b)
{
	return a<b;
}
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&num[i]);
	int gs=0;
	i=1;
	sort(num+1,num+1+n,comp);
	while(i<=n)
	{
		gs=1;
		while(i<n && num[i+1]==num[i]) {i++;gs++;}
		printf("%d %d\n",num[i],gs);
		i++;
	}
	//system("pause");
	return 0;
}