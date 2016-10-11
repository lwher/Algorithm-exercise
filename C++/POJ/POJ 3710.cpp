#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int map[110][110];
int low[110],dfa[110],zhan[110],top;
bool vis[110],inzhan[110];
int n,m;
void tarjan(int u,int pre,int t)
{
	dfa[u]=low[u]=t;
	top++;zhan[top]=u;inzhan[u]=1;
	int i;
	for(i=1;i<=n;i++)
	if(i!=u)
	{
		if(i==pre && map[u][i]>0)
		{
			if(map[u][i]%2==0)
			vis[u]=1;
		    continue;
		}
		if(i!=pre && !dfa[i] && map[u][i]>0)
		{tarjan(i,u,t+1);low[u]=min(low[u],low[i]);}
		else
		if(i!=pre && map[u][i]>0 && inzhan[i])
		{low[u]=min(low[u],dfa[i]);}
	}
	if(low[u]==dfa[u])
	{
		int cnt=1;
		while(zhan[top]!=u)
		{
		    inzhan[zhan[top]]=0;
		    vis[zhan[top]]=1;
			cnt++;	
			top--;
		}
		if(cnt>1 && cnt & 1)
		vis[zhan[top+1]]=0;
		top--;
		inzhan[u]=0;
	}
}
int getsg(int u,int pre)
{
	int i;
	int res=0;
	for(i=1;i<=n;i++)
	if(i!=u && map[u][i]>0 && i!=pre && !vis[i])
	{
		res^=(1+getsg(i,u));
	}
	return res;
}
int main()
{
	int k;
	int a,b;
	int i,ans;
	while(scanf("%d",&k)!=EOF)
	{
	ans=0;
	while(k--)
	{
		scanf("%d%d",&n,&m);
		top=0;
		memset(map,0,sizeof(map));
		memset(low,0,sizeof(low));
		memset(dfa,0,sizeof(dfa));
		memset(inzhan,0,sizeof(inzhan));
		memset(vis,0,sizeof(vis));
		for(i=1;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			map[a][b]++;map[b][a]++;
		}
		tarjan(1,-1,1);
		ans^=getsg(1,-1);
	}
	if(ans==0)
	cout<<"Harry"<<endl;
	else
	cout<<"Sally"<<endl;
    }
	//system("pause");
	return 0;
}

