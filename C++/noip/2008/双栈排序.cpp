#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int num[1010];
int sz,to[2000010],pre[2000010],last[1010];
int color[1010],minn[1010];
int z1[1010],z2[1010],top1,top2,now;
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool dfs(int x)
{
	int i=last[x];
	while(i>0)
	{
		if(!color[to[i]])
		{
			color[to[i]]=3-color[x];
			if(!dfs(to[i]))  return 0;
		}
		else
		{
			if(color[to[i]]!=3-color[x])  return 0;
		}
		i=pre[i];
	}
	return 1;
}
void solve()
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(!color[i])
		{
			color[i]=1;
			if(!dfs(i))  {printf("0\n");return;}
		}
	}
	now=1;
	for(i=1;i<=n;i++)
	{
		if(color[i]==1)  
		{
			printf("a ");top1++;z1[top1]=num[i];
		}
		else
		{
			printf("c ");top2++;z2[top2]=num[i];
		}
		while(z1[top1]==now || z2[top2]==now)
		{
			if(z1[top1]==now)  {
			printf("b ");top1--;	
			}
			if(z2[top2]==now)  {
			printf("d ");top2--;	
			}
			now++;
		}
	}
}
int main()
{
	int i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)  scanf("%d",&num[i]);
	minn[n+1]=n+1;
	for(i=n;i>=1;i--)  minn[i]=min(num[i],minn[i+1]);
	for(i=1;i<=n;i++)
	for(j=i+1;j<=n;j++)
	if(num[j]>num[i] && num[i]>minn[j+1])
	{
		Ins(i,j);Ins(j,i);
	}
	solve();
	//system("pause");
	return 0;
}