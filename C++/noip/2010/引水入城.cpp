#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
struct sth
{
	int zuo,you;
}xd[510];
int map[510][510],x[300010],y[300010];
int n,m,sum,sz;
int dx[4]={0,0,1,-1};
int dy[4]={-1,1,0,0};
bool o,mark[510][510];
int west[510][510],east[510][510],ans;
inline bool comp(sth a,sth b)
{
	return a.zuo<b.zuo;
}
void init()
{
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&map[i][j]);
}
void BFS()
{
	int l,tou,wei,xx,yy,i,k,nx,ny;
	for(l=1;l<=m;l++)
	if(!mark[1][l])
	{
		tou=1;wei=1;x[1]=1;y[1]=l;mark[1][l]=1;
		while(tou<=wei)
		{
			xx=x[tou];yy=y[tou];tou++;
			for(i=0;i<4;i++)
			{
				nx=xx+dx[i];ny=yy+dy[i];
				if(nx<1 || ny<1 || nx>n || ny>m || map[nx][ny]>=map[xx][yy])  continue;
				if(!mark[nx][ny])
				{
					mark[nx][ny]=1;wei++;x[wei]=nx;y[wei]=ny;
				}
			}
		}
	}
}
void bfs()
{
	memset(mark,0,sizeof(mark));
	int l,tou,wei,xx,yy,i,k,nx,ny;
	for(l=1;l<=m;l++)
	if(!mark[n][l])
	{
		tou=1;wei=1;x[1]=n;y[1]=l;mark[n][l]=1;west[n][l]=l;
		while(tou<=wei)
		{
			xx=x[tou];yy=y[tou];tou++;
			for(i=0;i<4;i++)
			{
				nx=xx+dx[i];ny=yy+dy[i];
				if(nx<1 || ny<1 || nx>n || ny>m || map[nx][ny]<=map[xx][yy])  continue;
				if(!mark[nx][ny])
				{
					mark[nx][ny]=1;wei++;x[wei]=nx;y[wei]=ny;west[nx][ny]=l;
				}
			}
		}
	}
	memset(mark,0,sizeof(mark));
	for(l=m;l>=1;l--)
	if(!mark[n][l])
	{
		tou=1;wei=1;x[1]=n;y[1]=l;mark[n][l]=1;east[n][l]=l;
		while(tou<=wei)
		{
			xx=x[tou];yy=y[tou];tou++;
			for(i=0;i<4;i++)
			{
				nx=xx+dx[i];ny=yy+dy[i];
				if(nx<1 || ny<1 || nx>n || ny>m || map[nx][ny]<=map[xx][yy])  continue;
				if(!mark[nx][ny])
				{
					mark[nx][ny]=1;wei++;x[wei]=nx;y[wei]=ny;east[nx][ny]=l;
				}
			}
		}
	}
}
void solve()
{
	int i;
	init();
	BFS();
	for(i=1;i<=m;i++)  
	{if(!mark[n][i]) {o=1;sum++;} }
	if(o) {printf("0\n%d\n",sum);return;}
	bfs();
	for(i=1;i<=m;i++)  
	if(west[1][i]!=0)
	{
		sz++;xd[sz].zuo=west[1][i];xd[sz].you=east[1][i];
	}
	sort(xd+1,xd+1+sz,comp);
	int nr=0,maxr=0;i=1;
	while(i<=sz && xd[i].zuo==1)
	{
		if(maxr<xd[i].you)  maxr=xd[i].you;i++;
	}
	nr=maxr;ans++;
	while(i<=sz)
	{
	while(i<=sz && xd[i].zuo<=nr+1)
	{
		if(maxr<xd[i].you)  maxr=xd[i].you;i++;
	}
	if(nr<maxr)  {nr=maxr;ans++;}
    }
	printf("1\n%d\n",ans);
}
int main()
{
	solve();
	//system("pause");
	return 0;
}
