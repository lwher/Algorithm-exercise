#include<iostream>
#include<cstdio>
using namespace std;
#define N 100010
int head[N],to[N],ne[N],v[N],fa[N][19],d[N],cnt=1,dep[N];
int n,m;
void charu(int u,int l,int w)
{to[++cnt]=l;v[cnt]=w;ne[cnt]=head[u];head[u]=cnt;}
void dfs(int x)
{
	for(int i=head[x];i;i=ne[i])
	{
		if(!dep[to[i]])
		{d[to[i]]=d[x]+v[i];
		 dep[to[i]]=dep[x]+1;
		 fa[to[i]][0]=x;
		 dfs(to[i]);}
	}
}
int lca(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
	int c=dep[y]-dep[x];
	for(int i=17;i>=0;i--)
	 if(c>=(1<<i)){c-=(1<<i);y=fa[y][i];}
	for(int i=17;i>=0;i--)
	 if(dep[x]>(1<<i)&&fa[x][i]!=fa[y][i])
	 {x=fa[x][i];y=fa[y][i];}
	if(x==y)return x;
	return fa[x][0];
}
int main()
{
	scanf("%d%d",&n,&m);
	int u,v,w,in[N],root;
	char ch;
	for(int i=1;i<=m;i++)
	{
		scanf("%d %d %d %c\n",&u,&v,&w,&ch);
		in[v]++;
		charu(u,v,w);
		charu(v,u,w);
	}
	dfs(1);
	for(int i=1;i<=17;i++)
	 for(int j=1;j<=n;j++)
	  fa[j][i]=fa[fa[j][i-1]][i-1];
	int q;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		int ans=d[u]+d[v]-2*d[lca(u,v)];
		printf("%d\n",ans);
	}
	return 0;
}