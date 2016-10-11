#include<iostream>
#include<stdio.h>
#include<cmath>
#include<string.h>
using namespace std;
int xu[30010],d[10010];
int deep[10010];
int f[30010][19];
int t,n,sz,siz;
int last[10010],pre[10010],to[10010];
bool fa[10010];
int cf[19],A,B,ans;
void Ins(int a,int b)
{
	sz++;
	to[sz]=b;
	pre[sz]=last[a];
	last[a]=sz;
}
void dfs(int x,int top)
{
	int i;
	deep[x]=top;
	siz++;
	xu[siz]=x;
	if(!d[x])
	d[x]=siz;
	i=last[x];
	while(i>0)
	{
		dfs(to[i],top+1);
		siz++;
		xu[siz]=x;
		i=pre[i];
	}
}
int main()
{
	int a,b;
	int i,j;
	cf[0]=1;
	for(i=1;i<=18;i++)
	cf[i]=cf[i-1]*2;
	scanf("%d",&t);
	while(t--)
	{
		memset(fa,0,sizeof(fa));
		memset(d,0,sizeof(d));
		memset(last,0,sizeof(last));
		memset(f,0,sizeof(f));
		sz=0;siz=0;
		scanf("%d",&n);
		for(i=1;i<=n-1;i++)
		{
			scanf("%d%d",&a,&b);
			Ins(a,b);
			fa[b]=1;
		}
		for(i=1;i<=n;i++)
		{if(!fa[i])  {j=i;break;}}
		dfs(j,1);
		
		for(i=1;i<=siz;i++)
		f[i][0]=xu[i];
		for(j=1;cf[j]<=siz;j++)
		for(i=1;i+cf[j]-1<=siz;i++)
		{
			a=f[i][j-1];
			b=f[i+cf[j-1]][j-1];
			if(deep[a]<deep[b])
			f[i][j]=a;
			else
			f[i][j]=b;
		}
		
		scanf("%d%d",&A,&B);
		int k;
		if(d[A]<d[B])
		{
			k=int((log(d[B]-d[A]+1)*1.0)/log(2.0));
			a=f[d[A]][k];
			b=f[d[B]-cf[k]+1][k];
			if(deep[a]<deep[b])
			ans=a;
			else
			ans=b;
		}
		else
		{
			k=int((log(d[A]-d[B]+1)*1.0)/log(2.0));
			a=f[d[B]][k];
			b=f[d[A]-cf[k]+1][k];
			if(deep[a]<deep[b])
			ans=a;
			else
			ans=b;
		}
		printf("%d\n",ans);
	}
	//system("pause");
	return 0;
}

