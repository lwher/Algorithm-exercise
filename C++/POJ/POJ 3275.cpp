#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int n,m,ans,cnt,head[1001],q[1001];
bool mp[1001][1001];
struct data{int to,next;}e[500001];
void insert(int u,int v)
{e[++cnt].to=v;e[cnt].next=head[u];head[u]=cnt;}
void bfs(int x)
{
	int t=0,w=1,now,i;
	q[t]=x;
	while(t<w)
	{
		now=q[t];t++;i=head[now];
		while(i)
		{
			if(!mp[x][e[i].to])
			{
				mp[x][e[i].to]=1;
				ans++;
			    q[w++]=e[i].to;
			    if(now!=x)insert(x,e[i].to);
		    }
		    i=e[i].next;
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		insert(u,v);
	}
	for(int i=1;i<=n;i++)bfs(i);
	printf("%d",n*(n-1)/2-ans);
	return 0;
}

