#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,fa[10010][15],deep[10010],dist[10010];
int sz,to[20010],pre[20010],v[20010],last[10010];
void Ins(int a,int b,int c)
{
	sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void init()
{
	int i,a,b,c;
	sz=0;memset(last,0,sizeof(last));
	memset(dist,0,sizeof(dist));
	memset(deep,0,sizeof(deep));
	memset(fa,0,sizeof(fa));
	scanf("%d",&n);
	for(i=1;i<n;i++)  
	{
		scanf("%d%d%d",&a,&b,&c);
		Ins(a,b,c);Ins(b,a,c);
	}
}
void dfs(int x,int father)
{
	for(int i=1;i<=14;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=last[x];i;i=pre[i])
	{
		if(to[i]==father)  continue;
		dist[to[i]]=dist[x]+v[i];
		deep[to[i]]=deep[x]+1;
		fa[to[i]][0]=x;
		dfs(to[i],x);
	}
}
void swap(int &a,int &b)
{
	int t=a;a=b;b=t;
}
int LCA(int a,int b)
{
	if(deep[a]<deep[b])  swap(a,b);
	int i,t=deep[a]-deep[b];
	for(i=14;i>=0;i--)  if(t>=(1<<i))  {t-=(1<<i);a=fa[a][i];}
	for(i=14;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
	if(a==b) return a; return fa[a][0]; 
}
int get(int a,int k)
{
	for(int i=14;i>=0;i--)  if(k>=(1<<i))  {k-=(1<<i);a=fa[a][i];}
	return a;
}
void solve()
{
	int a,b,c,k;char s[10];		
	while(scanf("%s",s))
	{
		if(s[1]=='O')  break;
		if(s[0]=='D')  
		{
			scanf("%d%d",&a,&b);
			
			c=LCA(a,b);
			printf("%d\n",dist[a]-dist[c]-dist[c]+dist[b]);
		}
		else
		{
			scanf("%d%d%d",&a,&b,&k);
			c=LCA(a,b);
			if(deep[a]-deep[c]+1<k) printf("%d\n",get(b,deep[b]-deep[c]-(k-deep[a]+deep[c]-1)));
			else  printf("%d\n",get(a,k-1));
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		init();
		dfs(1,0);
		solve();
	}
	return 0;
}
