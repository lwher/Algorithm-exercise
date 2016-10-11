#include<cstdlib>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int i,j,w,h,kx,ky,qx,qy,tx,ty,l,r,ans,sum;
int map[1010][1010],f[1010][1010];
bool used[1010][1010];
int way[5][3];
struct p
{
       int x,y,deep;
}q[500000];
void readdata()
{
     int i,j,a;
     scanf("%d%d",&w,&h);
     memset(map,0,sizeof(map));
     sum=0;
     ans=0x7fffffff;
     for (i=1;i<=h;i++)
     {
         for (j=1;j<=w;j++)
         {
             map[i][j]=1;
             scanf("%d",&a);
             if (a==1)
             map[i][j]=0;
             if (a==2)
             {
                 kx=i;
                 ky=j;
             }
             if (a==3)
             {
                 qx=i;
                 qy=j;
             }
             if (a==4)
             {
                 map[i][j]=4;
             }
         }
     }
     way[1][0]=1;way[1][1]=0;
     way[2][0]=-1;way[2][1]=0;
     way[3][0]=0;way[3][1]=1;
     way[4][0]=0;way[4][1]=-1;
}
bool in(int x,int y)
{
     if (x<1||y<1||x>h||y>w) return 0;
     return 1;
}
void bfs1()
{
     int i,j;
     p now;
     memset(q,0,sizeof(q));
     memset(used,0,sizeof(used));
     l=0;
     q[r=1].x=qx;
     q[1].y=qy;
     map[kx][ky]=0;
     used[qx][qy]=1;
     while (l<r)
     {
           ++l;
           for (i=1;i<=4;i++)
           {
               now=q[l];
               now.x+=way[i][0];
               now.y+=way[i][1];
               if (in(now.x,now.y)&&map[now.x][now.y]&&!used[now.x][now.y])
               {
                   q[++r]=now;
                   q[r].deep++;
                   used[now.x][now.y]=1;
                   if (map[now.x][now.y]==4)
                   f[now.x][now.y]=q[r].deep;
               }
           }
     }
}
void bfs2()
{
     int i,j;
     p now;
     memset(q,0,sizeof(q));
     memset(used,0,sizeof(used));
     l=0;
     q[r=1].x=kx;
     q[1].y=ky;
     map[kx][ky]=1;
     map[qx][qy]=0;
     used[kx][ky]=1;
     while (l<r)
     {
           ++l;
           for (i=1;i<=4;i++)
           {
               now=q[l];
               now.x+=way[i][0];
               now.y+=way[i][1];
               if (in(now.x,now.y)&&map[now.x][now.y]&&!used[now.x][now.y])
               {
                   q[++r]=now;
                   q[r].deep++;
                   used[now.x][now.y]=1;
                   if (map[now.x][now.y]==4)
                   {
                        if (ans>f[now.x][now.y]+q[r].deep)
                        ans=f[now.x][now.y]+q[r].deep;
                   }
               }
           }
     }
}
int main(int argc, char *argv[])
{
    readdata();
    bfs1();
    bfs2();
    printf("%d\n",ans);
    system("pause");
    return 0;
}
