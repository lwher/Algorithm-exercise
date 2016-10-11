#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define INF 1e15
using namespace std;
int n;
double map[151][151];
int x[151],y[151];
double zy[151],my[151];
double dis(int a,int b)
{
       return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
double ans=INF,now;
int main()
{
    int i,j,k;
    char ch;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    scanf("%d%d",&x[i],&y[i]);
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
     cin>>ch;
     map[i][j]=INF;
     if(ch=='1')
     map[i][j]=dis(i,j);
    }
    for(i=1;i<=n;i++)
    map[i][i]=0;
    for(k=1;k<=n;k++)
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(map[i][k]+map[k][j]<map[i][j])
    map[i][j]=map[i][k]+map[k][j];
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    {
      if(map[i][j]<INF && map[i][j]>zy[i])
      zy[i]=map[i][j];
    }
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       if(map[i][j]<INF && zy[j]>my[i])
       my[i]=zy[j];
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    if(map[i][j]==INF)
    {
       now=max(my[i],my[j]);
       now=max(dis(i,j)+zy[i]+zy[j],now);
       ans=min(ans,now);
    }
    printf("%.6lf\n",ans);
    system("pause");
    return 0;
}
