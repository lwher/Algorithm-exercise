#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define inf 0x7fffffff
using namespace std;
struct sth
{
       int k,x,y;
}dui[3000010];
int n,m,q,t,xk,yk,qx,qy,zx,zy;
int map[31][31],nowmap[31][31];
int dis[31][31][4],lu[31][31][4][4],dist[31][31];
bool mark[31][31][4];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void init()
{
     int i,j;
     scanf("%d%d%d",&n,&m,&q);
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  scanf("%d",&map[i][j]);
}
void bfs1_yuchuli(int xx,int yy,int k)
{
     int tou=1,wei=1,i,j,nx,ny,x,y;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  dist[i][j]=inf;
     nx=xx+dx[k];ny=yy+dy[k];
     if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]==0) 
     {
             for(i=0;i<4;i++)  lu[xx][yy][k][i]=-1;
             return;
     }
     dui[1].x=nx;dui[1].y=ny;dist[nx][ny]=0;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  nowmap[i][j]=map[i][j];
     nowmap[xx][yy]=0;
     while(tou<=wei)
     {
         x=dui[tou].x;y=dui[tou].y;tou++;
         for(i=0;i<4;i++)
         {
            nx=x+dx[i];ny=y+dy[i];
            if(nx<1 || nx>n || ny<1 || ny>m || nowmap[nx][ny]==0)  continue;
            if(dist[x][y]+1<dist[nx][ny])
            {
                 dist[nx][ny]=dist[x][y]+1;
                 dui[++wei].x=nx;dui[wei].y=ny;
            }
         }
     }
     for(i=0;i<4;i++)  
     {
         nx=xx+dx[i];ny=yy+dy[i];
         if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]==0) {lu[nx][ny][k][i]=-1;continue;}
         if(dist[nx][ny]!=inf)
         lu[xx][yy][k][i]=dist[nx][ny];
         else 
         lu[xx][yy][k][i]=-1;
     }
}
void bfs2_yidongkg(int xx,int yy,int jx,int jy)
{
     int tou=1,wei=1,i,j,nx,ny,x,y;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  dist[i][j]=inf;
     dui[1].x=xx;dui[1].y=yy;dist[xx][yy]=0;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  nowmap[i][j]=map[i][j];
     nowmap[jx][jy]=0;
     while(tou<=wei)
     {
         x=dui[tou].x;y=dui[tou].y;tou++;
         for(i=0;i<4;i++)
         {
            nx=x+dx[i];ny=y+dy[i];
            if(nx<1 || nx>n || ny<1 || ny>m || nowmap[nx][ny]==0)  continue;
            if(dist[x][y]+1<dist[nx][ny])
            {
                 dist[nx][ny]=dist[x][y]+1;
                 dui[++wei].x=nx;dui[wei].y=ny;
            }
         }
     }
}
int spfa(int xx,int yy)
{
     if(xx==zx && yy==zy)  return 0;
     if(map[zx][zy]==0)  return -1;
     if(map[xx][yy]==0)  return -1;
     if(map[xk][yk]==0)  return -1;
     int tou=0,wei=0,i,j,nx,ny,x,y,fx,ans=inf;
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++) for(nx=0;nx<4;nx++) dis[i][j][nx]=inf;
     memset(mark,0,sizeof(mark));
     for(i=0;i<4;i++)
     {
         nx=xx+dx[i];ny=yy+dy[i];
         if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]==0)  continue;
         if(dis[xx][yy][i]>dist[nx][ny])
         {
             dis[xx][yy][i]=dist[nx][ny];wei++;dui[wei].x=xx;dui[wei].y=yy;dui[wei].k=i;mark[xx][yy][i]=1;
         }
     }
     while(tou!=wei)
     {
         tou=(tou+1)%3000000;if(tou==0)  tou++;
         x=dui[tou].x;y=dui[tou].y;fx=dui[tou].k;
         for(i=0;i<4;i++)
         {
             nx=x+dx[i];ny=y+dy[i];
             if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]==0)  continue;
             if(i!=fx)
             {
                  if(lu[x][y][fx][i]!=-1 && dis[x][y][i]>dis[x][y][fx]+lu[x][y][fx][i])
                  {
                       dis[x][y][i]=dis[x][y][fx]+lu[x][y][fx][i];
                       if(!mark[x][y][i])
                       {
                           mark[x][y][i]=1;
                           wei=(wei+1)%3000000;if(wei==0)  wei++;
                           dui[wei].x=x;dui[wei].y=y;dui[wei].k=i;
                       }
                  }
             }
             else
             {
                 if(dis[nx][ny][fx^1]>dis[x][y][fx]+1)
                 {
                       dis[nx][ny][fx^1]=dis[x][y][fx]+1;
                       if(!mark[nx][ny][fx^1])
                       {
                           mark[nx][ny][fx^1]=1;
                           wei=(wei+1)%3000000;if(wei==0)  wei++;
                           dui[wei].x=nx;dui[wei].y=ny;dui[wei].k=fx^1;
                       }
                 }
             }
         }
         mark[x][y][fx]=0;
     }
     for(i=0;i<4;i++)  ans=min(ans,dis[zx][zy][i]);
     if(ans==inf)  return -1;
     else return ans;
}
void solve()
{
     int i,j,k,l;
     init();
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  for(k=0;k<4;k++)  bfs1_yuchuli(i,j,k);     
     for(i=1;i<=q;i++)
     {               
         scanf("%d%d%d%d%d%d",&xk,&yk,&qx,&qy,&zx,&zy);
         bfs2_yidongkg(xk,yk,qx,qy);         
         printf("%d\n",spfa(qx,qy));
     }
}
int main()
{
    //freopen("puzzle.in","r",stdin);
    //freopen("puzzle.out","w",stdout);    
    solve();
   // system("pause");
    return 0;
}