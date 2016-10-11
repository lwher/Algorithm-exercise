#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define eps 1e-10
using namespace std;
struct sth
{
       double x,y;
}yuan[510];
struct sss
{
       double x,y;
}need[510];
int n,m;
int map[510][510];
void init()
{
     int i,j;
     double a,b,c;
     scanf("%d%d",&m,&n);
     for(i=1;i<=m;i++)
     {
        scanf("%lf%lf%lf",&a,&b,&c);
        yuan[i].x=a;yuan[i].y=b;
     }
     for(i=1;i<=n;i++)
     {
        scanf("%lf%lf%lf",&a,&b,&c);
        need[i].x=a;need[i].y=b;
     }
}
double guaixiang(sth a,sth b,sss c)
{
       return (c.x-a.x)*(b.y-a.y)-(c.y-a.y)*(b.x-a.x);
}
bool scheck(sth a)
{
     int i;
     for(i=1;i<=n;i++)
     if(fabs(a.x-need[i].x)>eps || fabs(a.y-need[i].y)>eps)
     return 0;
     return 1;
}
bool check1(sth a,sth b)
{
     int i;
     for(i=1;i<=n;i++)
     {
     sss c=need[i];
     if(c.x<min(a.x,b.x) || c.x>max(a.x,b.x))
     return 0;
     if(c.y<min(a.y,b.y) || c.y>max(a.y,b.y))
     return 0;
     }
     return 1;
}
bool check(int a,int b)
{
     int i;
     for(i=1;i<=n;i++)
     {
     if(guaixiang(yuan[a],yuan[b],need[i])<-eps)
     return 0;
     }
     return 1;
}
void solve()
{
    
     int i,j,k;
     for(i=1;i<=m;i++)
     {
        if(scheck(yuan[i]))
        {printf("1\n");return;}
     }
     for(i=1;i<=m;i++)
     for(j=1;j<=m;j++)
     map[i][j]=1000;
     for(i=1;i<=m;i++)
     for(j=1;j<=m;j++)
     {
        if(i!=j)
        {
          if(check(i,j))
          map[i][j]=1;
        }
     }
     for(i=1;i<m;i++)
     for(j=i+1;j<=m;j++)
     {
        if(map[i][j]==1 && map[j][i]==1 && check1(yuan[i],yuan[j]))
        {
          printf("2\n");
          return;
        }
     }
     int ans=600;
     for (int k=1;k<=m;k++)
     {
      for (int i=1;i<=m;i++)
      if (i!=k)
      for (int j=1;j<=m;j++)
      if (j!=i && j!=k)
      ans=min(ans,map[i][k]+map[k][j]+map[j][i]);
      for (int i=1;i<=m;i++)
      for (int j=1;j<=m;j++)
      map[i][j]=min(map[i][j],map[i][k]+map[k][j]);
     }
     if(ans==600)  cout<<-1<<endl;
     else
     cout<<ans<<endl;
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
