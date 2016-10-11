#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int map[27][27],n,m,ans;
int shuyu[27][27];
int sz,to[5010],pre[5010],last[5010];
int dx[8]={2,1,2,1,-1,-1,-2,-2};
int dy[8]={1,2,-1,-2,2,-2,-1,1};
int pipei[5010];
bool vis[5010];
void Ins(int a,int b)
{
	sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
bool find(int x)
{
	int i=last[x];
	while(i>0)
	{
		if(!vis[to[i]])
		{
			vis[to[i]]=1;
			if(pipei[to[i]]==-1 || find(pipei[to[i]]))
			{
				pipei[to[i]]=x;return 1;
			}
		}
		i=pre[i];
	}
	return 0;
}
int main()
{
	int i,j,w,x,y,k;
	char ch;
	scanf("%d%d",&n,&m);
	getchar();
	for(i=1;i<=n;i+=2)  
	{
		shuyu[i][1]=0;
		for(j=2;j<=n;j++) shuyu[i][j]=(shuyu[i][j-1]^1);
	}
	for(i=2;i<=n;i+=2)  
	{
		shuyu[i][1]=1;
		for(j=2;j<=n;j++) shuyu[i][j]=(shuyu[i][j-1]^1);
	}
	for(i=1;i<=m;i++)
	{
		scanf("%c%d",&ch,&w);
		x=ch-'A'+1;
		map[x][w]=1;
		getchar();
	}
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
		if(shuyu[i][j]==0 && map[i][j]==1)
		{
			for(k=0;k<8;k++)
			{
				x=i+dx[k];y=j+dy[k];
				if(x<1 || y<1 || x>n || y>n || map[x][y]==0)  continue;
				Ins((i-1)*n+j,(x-1)*n+y);
			}
		}
	}
	memset(pipei,-1,sizeof(pipei));
	for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	if(shuyu[i][j]==0 && map[i][j]==1)
	{
		memset(vis,0,sizeof(vis));
		if(find((i-1)*n+j))  ans++;
	}
	cout<<ans<<endl;
//	system("pause");
	return 0;
}
