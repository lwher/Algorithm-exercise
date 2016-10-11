#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,q;
int sz,to[500010],pre[500010],last[100010];
int tt,sum,dfn[100010],low[100010],fa[100010],bridge[100010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x,int FA)
{
	tt++;dfn[x]=tt;low[x]=tt;
	int i=last[x];
	while(i>0)
	{
		if(to[i]!=FA)
		{
			if(!dfn[to[i]])  
			{
				fa[to[i]]=x;
				Tarjan(to[i],x);low[x]=min(low[x],low[to[i]]);
			    if(low[to[i]]>dfn[x])
			    {
					sum++;bridge[to[i]]=1;
				}
			}
			else  low[x]=min(low[x],dfn[to[i]]);
		}
		i=pre[i];
	}
}
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
void LCA(int a,int b)
{
	if(dfn[a]<dfn[b])  swap(a,b);
	while(dfn[a]>dfn[b])
	{
		if(bridge[a]==1)  {sum--;bridge[a]=0;}
		a=fa[a];
	}
	while(a!=b)
	{
		if(bridge[a]==1)  {sum--;bridge[a]=0;}
		if(bridge[b]==1)  {sum--;bridge[b]=0;}
		a=fa[a];b=fa[b];
	}
}
int main()
{
	int i,a,b,dd=0;
	while(scanf("%d%d",&n,&m))
	{
		if(n==0 && m==0)  break;
		sz=0;memset(last,0,sizeof(last));
		for(i=1;i<=m;i++)  
		{
			scanf("%d%d",&a,&b);
			Ins(a,b);Ins(b,a);
		}
		memset(bridge,0,sizeof(bridge));
		memset(dfn,0,sizeof(dfn));
		memset(low,0,sizeof(low));
		memset(fa,0,sizeof(fa));
		tt=0;sum=0;
		Tarjan(1,0);
		scanf("%d",&q);
		printf("Case %d:\n",++dd);
		while(q--)
		{
			scanf("%d%d",&a,&b);  
			LCA(a,b);
			printf("%d\n",sum);
		}
		printf("\n");
	}
	//system("pause");
	return 0;
}