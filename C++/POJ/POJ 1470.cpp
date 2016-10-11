#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 10001
int head[N],to[N],ne[N],fa[N][17],cnt=1,dep[N];
void insert(int u,int v) 
{to[++cnt]=v;ne[cnt]=head[u];head[u]=cnt;}
void dfs(int x)
{
	for(int i=head[x];i;i=ne[i])
	{
		if(!dep[to[i]])
		{
			dep[to[i]]=dep[x]+1;
			fa[to[i]][0]=x;
			dfs(to[i]);
		}
	}
}
int lca(int x,int y)
{
	if(dep[x]>dep[y])swap(x,y);
	int c=dep[y]-dep[x];
	for(int i=15;i>=0;i--)
	 if(c>=(1<<i)){c-=(1<<i);y=fa[y][i];}
	for(int i=15;i>=0;i--)
	 {
	 	if(dep[x]>(1<<i)&&fa[x][i]!=fa[y][i])
	 	{x=fa[x][i];y=fa[y][i];}
	 }
	 if(x==y)return y;
	 return fa[x][0];
}
int main()
{
	int n,num,v,u,m;
	while(scanf("%d",&n)!=EOF)
	{
		memset(head,0,sizeof(head));
		memset(dep,0,sizeof(dep));
		memset(fa,0,sizeof(fa));
		cnt=1;
		int in[N],root,res[N];
		memset(res,0,sizeof(res));
		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++)
		{
			scanf("%d:(%d)",&u,&num);
			while(num--)
			{
			   scanf("%d",&v);
			   insert(u,v);
			   in[v]++;
		    }
		}
		for(root=1;in[root];root++);
		dep[root]=1;
		dfs(root);
		for(int i=1;i<=15;i++)
		 for(int j=1;j<=n;j++)
		  fa[j][i]=fa[fa[j][i-1]][i-1];
		scanf("%d",&m);
		while(m--)
		{
			 while(getchar() != '(');
              scanf("%d%d",&u,&v);
              res[lca(u,v)]++;
              while(getchar() != ')');
		}
		
		for(int i=1;i<=n;i++)
		 if(res[i])printf("%d:%d\n",i,res[i]);
	}
	return 0;
}