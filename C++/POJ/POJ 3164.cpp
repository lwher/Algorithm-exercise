#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
struct sth
{
	double x,y;
}p[110];
struct orz
{
	int u,v;
	double w;
}e[50010];
int n,m,fa[110],vis[110],mark[110];
double in[110];
double dist(sth a,sth b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double work(int root)
{
	int i,j,k,u,v;
	double ans=0;
	while(1)
	{
		for(i=1;i<=n;i++)  in[i]=INF;
		for(i=1;i<=m;i++)
		{
			u=e[i].u;v=e[i].v;
			if(u!=v)
			{
				if(in[v]>e[i].w) {in[v]=e[i].w;fa[v]=u;}
	    	}
		}
		for(i=1;i<=n;i++)  if(i!=root && in[i]==INF)  return -1;
		in[root]=0;
		int cnt=0;
		memset(vis,-1,sizeof(vis));
		memset(mark,-1,sizeof(mark));
		for(i=1;i<=n;i++)
		{
			ans+=in[i];
			k=i;
			while(k!=root && vis[k]!=i && mark[k]==-1)
			{
				vis[k]=i;k=fa[k];
			}
			if(k!=root && mark[k]==-1)
			{
				cnt++;
				for(u=fa[k];u!=k;u=fa[u])  mark[u]=cnt;	
				mark[k]=cnt;
			}
		}
		if(cnt==0)  break;
		for(i=1;i<=n;i++)  if(mark[i]==-1)  mark[i]=++cnt;
		for(i=1;i<=m;i++)
		{
			u=e[i].u;v=e[i].v;
			e[i].u=mark[u];e[i].v=mark[v];
			if(mark[u]!=mark[v]) e[i].w-=in[v];
		}
	    n=cnt;root=mark[root];
	}
	return ans;
}
int main()
{
	int i,a,b;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(i=1;i<=n;i++)  scanf("%lf%lf",&p[i].x,&p[i].y);
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			e[i].u=a;e[i].v=b;
			if(e[i].u!=e[i].v)  e[i].w=dist(p[a],p[b]);
			else e[i].w=INF;
	    }
		double ans=work(1);
		if(ans<0)  printf("poor snoopy\n");
		else printf("%.2lf\n",ans);
	}
	//system("pause");
	return 0;
}