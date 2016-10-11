#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int x[1000001],y[1000001];
int n,m,dis[1001][1001],t,w=1;
int xx[4]={0,0,-1,1},yy[4]={1,-1,0,0};
char ch[1001];
void bfs()
{
    while(t<w)
    {
        int i=x[t],j=y[t++];
        for(int k=0;k<4;k++)
        {
            int nowx=i+xx[k],nowy=j+yy[k];
            if(nowx<1||nowy<1||nowx>n||nowy>m||dis[nowx][nowy]!=-1)continue;
            dis[nowx][nowy]=dis[i][j]+1;
            x[w]=nowx;y[w++]=nowy;
        }
    }
}
int main()
{
    memset(dis,-1,sizeof(dis));
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
       scanf("%s",ch);
       for(int j=1;j<=m;j++)
       if(ch[j-1]=='1')
       {
            x[w]=i;y[w++]=j;
            dis[i][j]=0;
       }
    }   
    bfs();
    for(int i=1;i<=n;i++)
    {
       for(int j=1;j<=m;j++)  printf("%d ",dis[i][j]);
       printf("\n");
    }
    return 0;
}