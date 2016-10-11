#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,ans;
int sz,to[20010],pre[20010],last[5010];
int dfn[5010],low[5010],stack[5010],top,tt,fl=1,belong[5010],du[5010];
bool mark[5010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x,int fa)
{
	tt++;dfn[x]=tt;low[x]=tt;
	stack[++top]=x;
	int i=last[x];
	while(i>0)
	{
		if(to[i]!=fa)
		{
			if(!dfn[to[i]])  
			{
				Tarjan(to[i],x);low[x]=min(low[x],low[to[i]]);
				if(low[to[i]]>dfn[x])
				{
					fl++;
					while(stack[top]!=to[i])
					{
						belong[stack[top]]=fl;
						top--;
					}
					belong[to[i]]=fl;top--;
				}
			}
			else low[x]=min(dfn[to[i]],low[x]);
		}
		i=pre[i];
	}
}

int main()
{
	int i,j,k,a,b;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		Ins(a,b);Ins(b,a);
	}	
	Tarjan(1,0);
	for(i=1;i<=n;i++)  if(belong[i]==0)  belong[i]=1;
	for(i=1;i<=fl;i++)
	{
		memset(mark,0,sizeof(mark));
		for(j=1;j<=n;j++)
		if(belong[j]==i)
		{
			k=last[j];
			while(k>0)
			{
				if(!mark[belong[to[k]]] && belong[to[k]]!=belong[j])
				{
					mark[belong[to[k]]]=1;
					du[belong[j]]++;
				}
				k=pre[k];
			}
		}
	}
	for(i=1;i<=fl;i++)  if(du[i]==1)  ans++;
	ans=(ans+1)/2;
	cout<<ans<<endl;
	//system("pause");
	return 0;
}