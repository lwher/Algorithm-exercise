#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,K,size[50010],f[50010],sum,d[50010],root,ans;
int sz,to[100010],pre[100010],v[100010],last[50010];
int dist[50010],top;
bool mark[50010];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;last[a]=sz;
}
void getroot(int x,int fa)
{
	int i;
	size[x]=1;f[x]=0;
	for(i=last[x];i;i=pre[i])
	{
		if(to[i]==fa || mark[to[i]]) continue;
		getroot(to[i],x);
		f[x]=max(f[x],size[to[i]]);
		size[x]+=size[to[i]];
	}
	f[x]=max(f[x],sum-size[x]);
	if(f[root]>f[x])  root=x;
}
void dfs(int x,int fa)
{
	int i;size[x]=1;dist[++top]=d[x];
	for(i=last[x];i;i=pre[i])
	{
		if(to[i]==fa || mark[to[i]]) continue;
		d[to[i]]=d[x]+v[i];
		dfs(to[i],x);
		size[x]+=size[to[i]];
	}
}
int calc(int x,int k)
{
	d[x]=k;top=0;dfs(x,0);
	sort(dist+1,dist+1+top);
	int l=1,r=top,tmp=0;
	while(l<r)
	{
		if(dist[l]+dist[r]<=K)  {tmp+=r-l;l++;}
		else r--;
	}
	return tmp;
}
void work(int x)
{
	ans+=calc(x,0);
	mark[x]=1;
	for(int i=last[x];i;i=pre[i])
	{
		if(mark[to[i]])  continue;
		ans-=calc(to[i],v[i]);
		sum=size[to[i]];
		f[0]=sum;root=0;
		getroot(to[i],x);
		work(root);
	}
}
int main()
{
	int i,a,b,c;char s[10];
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d%d%s",&a,&b,&c,s);
		Ins(a,b,c);Ins(b,a,c);
	}
	scanf("%d",&K);	
	f[0]=n;sum=n;root=0;
	getroot(1,0);
	work(root);
	printf("%d\n",ans);
	return 0;
}