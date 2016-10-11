#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
int sz,to[100010],pre[100010],last[10010];
bool used[100010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];used[sz]=0;last[a]=sz;
}
void dfs(int x)
{
	int i=last[x];
	while(i>0)
	{
		if(!used[i])
		{
			used[i]=1;
			dfs(to[i]);
		}
		i=pre[i];
	}
	printf("%d\n",x);
}
int main()
{
	int i,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{  
		scanf("%d%d",&a,&b);
		Ins(a,b);Ins(b,a);
	}
	dfs(1);
	//system("pause");
	return 0;
}

