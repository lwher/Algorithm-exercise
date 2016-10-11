#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-6
using namespace std;
int n,m,qx,qy,dui[230][2];
char map[20][20];
bool flag[20][20];
double a[230][230];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void bfs()
{
    int tou=1,wei=0,x,y,nx,ny,i,j,k;
    for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  if(map[i][j]=='$')  
    {
        dui[++wei][0]=i;dui[wei][1]=j;flag[i][j]=1;
    }
    while(tou<=wei)
    {
        x=dui[tou][0];y=dui[tou][1];tou++;
        for(k=0;k<4;k++)
        {
            nx=x+dx[k];ny=y+dy[k];
            if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]=='#' || flag[nx][ny])  continue;
            flag[nx][ny]=1;
            dui[++wei][0]=nx;dui[wei][1]=ny;
        }
    }
}
int p(int x,int y)
{
    return (x-1)*m+y;
}
void swap(double &A,double &B)
{
    double t=A;A=B;B=t;
}
bool gauss()
{
    int nm=n*m,i,j,k,now=1;
    double tt;
    for(i=1;i<=nm;i++)
    {
        for(j=now;j<=nm;j++)  if(fabs(a[j][i])>eps)  break;
        if(j>nm)  continue;
        if(j!=now)  for(k=1;k<=nm+1;k++)  swap(a[now][k],a[j][k]);
        tt=1/a[now][i];
        for(k=nm+1;k>=i;k--)  a[now][k]*=tt;
        for(j=1;j<=nm;j++)
        if(j!=now) 
        {
            tt=a[j][i];
            for(k=nm+1;k>=i;k--)   a[j][k]-=a[now][k]*tt;
        }
        now++;
    }
    for(i=now;i<=nm;i++)  if(fabs(a[i][nm+1])>eps)  return 0;
    return 1;
}
int main()
{
    int i,j,k,nx,ny,cnt;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(flag,0,sizeof(flag));
        for(i=1;i<=n*m;i++)  for(j=1;j<=n*m+1;j++)  a[i][j]=0;
        for(i=1;i<=n;i++)  for(j=1;j<=m;j++)  cin>>map[i][j];
        bfs();
        for(i=1;i<=n;i++)  for(j=1;j<=m;j++)
        {
            cnt=0;
            if(map[i][j]=='@') {qx=i;qy=j;}
            if(map[i][j]=='$') {a[p(i,j)][p(i,j)]=1;a[p(i,j)][n*m+1]=0;continue;}
            if(map[i][j]=='#') continue;
            for(k=0;k<4;k++)
            {
                nx=i+dx[k];ny=j+dy[k];
                if(nx<1 || nx>n || ny<1 || ny>m || map[nx][ny]=='#' || !flag[nx][ny])  continue;
                a[p(i,j)][p(nx,ny)]=1; cnt++;
            }
            a[p(i,j)][p(i,j)]=-1*cnt;a[p(i,j)][n*m+1]=-1*cnt;
        }        
        if(flag[qx][qy] && gauss())
        {
            for(i=1;i<=n*m;i++)  if(fabs(a[i][p(qx,qy)]-1)<eps)  {printf("%.6f\n",a[i][n*m+1]);break;}
        }
        else printf("-1\n");
    }
    //system("pause");
    return 0;
}