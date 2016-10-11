#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int low[110],fa[110],v[110];
bool mark[110],ans[110];;
int t;
bool map[110][110];
int n,answer;
void dfs(int x)
{
	int i;
	t++;
	low[x]=t;
	v[x]=t;
	mark[x]=1;
	for(i=1;i<=n;i++)
	{
		if(!mark[i] && map[x][i])
		{
			fa[i]=x;
			dfs(i);
		}
	}
	for(i=1;i<=n;i++)
	if(map[x][i] && fa[x]!=i)
	{low[x]=min(low[x],low[i]);}
}
int main()
{
	int a,b;
	int i;
	while(scanf("%d",&n))
	{
		if(n==0) break;
		memset(map,0,sizeof(map));
		memset(mark,0,sizeof(mark));
		memset(fa,0,sizeof(fa));
		memset(low,0,sizeof(low));
		memset(ans,0,sizeof(ans));
		answer=0;t=0;
		while(scanf("%d",&a) && a)
		{
			while(getchar()!='\n')
			{
				scanf("%d",&b);
				map[a][b]=1;
				map[b][a]=1;
			}
		}
		
		dfs(1);
		
		int sum=0;
		for(i=2;i<=n;i++)
		if(fa[i]==1)
		sum++;
		if(sum>1)
		ans[1]=1;
		for(i=2;i<=n;i++)
		{
			if(low[i]>=v[fa[i]] && fa[i]!=1)
			ans[fa[i]]=1;
		}
		for(i=1;i<=n;i++)
		if(ans[i])
		answer++;
		printf("%d\n",answer);
	}
	//system("pause");
	return 0;
}

