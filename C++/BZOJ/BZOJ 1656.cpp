#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
char map[51][51];
int f[51][51][2];
int qx,qy,n,m,xx,yy;
int dx[30010],dy[30010],dz[30010];
int X[8]={1,0,0,-1,1,1,-1,-1};
int Y[8]={0,1,-1,0,1,-1,1,-1};
void init()
{
     int i,j;
     scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++)
     for(j=1;j<=m;j++)
     {
          cin>>map[i][j];
          if(map[i][j]=='*')    {qx=i;qy=j;}
          if(map[i][j]=='X')    {xx=i;yy=j;}
     }
}
void bfs()
{
     int i,j,p;
     int x,y,z,k;
     int tou=1,wei=1;
     memset(f,-1,sizeof(f));
     f[qx][qy][0]=0;
     dx[1]=qx;dy[1]=qy;dz[1]=0;
     while(tou<=wei)
     {
          i=dx[tou];j=dy[tou];p=dz[tou];
          tou++;
          for(k=0;k<8;k++)
          {
              x=i+X[k];y=j+Y[k];z=p;
              if(x<1 || x>n || y<1 || y>m || map[x][y]=='X')  continue;
              if(i==xx && x<xx && j>yy)  z^=1;
              else 
              if(i==xx-1 && x==xx && y>yy)  z^=1;
              if(f[x][y][z]==-1)
              {
              f[x][y][z]=f[i][j][p]+1;
              wei++;
              dx[wei]=x;dy[wei]=y;dz[wei]=z;
              }
          }
     }
}
void solve()
{
     init();
     bfs();
     long long ans;
     ans=f[qx][qy][1];
     cout<<ans<<endl;
}
int main()
{
    solve();
    system("pause");
    return 0;
}
