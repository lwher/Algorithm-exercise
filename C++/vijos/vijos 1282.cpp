#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
struct sth
{
	int w,bh;
}p[50010];
int n,k;
int e[11];
inline bool comp(sth a,sth b)
{
	if(a.w!=b.w)  return a.w>b.w;
	else return a.bh<b.bh;
}
int main()
{
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=10;i++)  scanf("%d",&e[i]);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&p[i].w);
		p[i].bh=i;
	}
	sort(p+1,p+1+n,comp);
	for(i=1;i<=n;i++)
	{
		p[i].w=p[i].w+e[(i-1)%10+1];
	}
	sort(p+1,p+1+n,comp);
	for(i=1;i<=k;i++)
	printf("%d ",p[i].bh);
	//system("pause");
	return 0;
}
