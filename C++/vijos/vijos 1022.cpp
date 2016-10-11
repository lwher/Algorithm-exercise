#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int n,ans,zhan[210],top,dfn[210],low[210],tt;
int sz,to[50010],pre[50010],last[210];
bool in[210];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x)
{
	tt++;dfn[x]=tt;low[x]=tt;
	top++;zhan[top]=x;in[x]=1;
	int i=last[x];
	while(i>0)
	{
		if(!dfn[to[i]])  {Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);}
		else
		if(in[to[i]])  low[x]=min(low[x],dfn[to[i]]);
		i=pre[i];
	}
	if(dfn[x]==low[x])
	{
		ans++;
		while(zhan[top]!=x)
		{
			in[zhan[top]]=0;top--;
		}
		in[x]=0;top--;
	}
}
int main()
{
	int x,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		while(scanf("%d",&x)!=EOF)
		{
			if(x==0)  break;
			Ins(i,x);
		}
	}
	for(i=1;i<=n;i++)  if(!dfn[i])  Tarjan(i);
	cout<<ans<<endl;
	//system("pause");
	return 0;
}
