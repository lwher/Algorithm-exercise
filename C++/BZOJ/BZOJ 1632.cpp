#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
int map[31][31];
int d[31][31],hy[31][31];
long long sum[31][31];
int dx[3000010],dy[3000010];
bool mark[31][31];
int n,m;
int qx,qy,zx,zy,INF;
int xx[8]={1,-1,2,-2,1,-1,2,-2};
int yy[8]={2,2,1,1,-2,-2,-1,-1};
void init()
{
     int i,j;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  
     {
        scanf("%d",&map[i][j]);
        if(map[i][j]==3)  {qx=i;qy=j;}
        if(map[i][j]==4)  {zx=i;zy=j;}
     }
}
void spfa()
{
     int tou=1,wei=1;
     int x,y,h,nh,k,i,j;
     memset(d,127,sizeof(d));
     memset(hy,127,sizeof(hy));
     INF=d[0][0];
     hy[qx][qy]=0;
     d[qx][qy]=0;
     sum[qx][qy]=1;
     mark[qx][qy]=1;
     dx[1]=qx;dy[1]=qy;
     while(tou<=wei)
     {
        i=dx[tou];j=dy[tou];
        h=hy[i][j];
        tou++;
        for(k=0;k<8;k++)
        {
            x=i+xx[k];y=j+yy[k];
            if(x<1 || x>n || y<1 || y>m || map[x][y]==2)  {continue;}
            if(map[x][y]==0)   nh=h+1; else  nh=h;
            if(hy[x][y]>nh)
            {
               hy[x][y]=nh;
               d[x][y]=d[i][j]+1;
               sum[x][y]=sum[i][j];
               if(!mark[x][y])
               {wei++;dx[wei]=x;dy[wei]=y;mark[x][y]=1;}
            }
            else
            if(hy[x][y]==nh)
            {
            if(d[i][j]+1<d[x][y])
            {
               d[x][y]=d[i][j]+1;
               sum[x][y]=sum[i][j];
               if(!mark[x][y])
               {wei++;dx[wei]=x;dy[wei]=y;mark[x][y]=1;}
            }
            else
            if(d[i][j]+1==d[x][y])
            {
               sum[x][y]+=sum[i][j];
               if(!mark[x][y])
               {wei++;dx[wei]=x;dy[wei]=y;mark[x][y]=1;}
            }
            }
        }
        mark[i][j]=0;
     }
}
void solve()
{ 
     init(); 
     spfa();
     if(hy[zx][zy]!=INF)
     {
        cout<<hy[zx][zy]<<endl;
        cout<<d[zx][zy]<<endl;
        cout<<sum[zx][zy]<<endl;
     }
     else
     cout<<-1<<endl;
}
int main()
{
    solve();
    system("pause");
    return 0;
}
  
