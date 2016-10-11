#include<iostream>
#include<stdio.h>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;
int dp[110];
int n,m,k,e;
bool mark[25];
int dui[1000],dis[25];
bool use[25][110];
int map[25][25],lu[25][25];
void init()
{
     int i,j,a,b,c,d;
     scanf("%d%d%d%d",&n,&m,&k,&e);
     for(i=1;i<=e;i++)
     {
       scanf("%d%d%d",&a,&b,&c);
       lu[a][0]++;lu[a][lu[a][0]]=b;map[a][b]=c;
       lu[b][0]++;lu[b][lu[b][0]]=a;map[b][a]=c;
     }
     scanf("%d",&d);
     for(i=1;i<=d;i++)
     {
        scanf("%d%d%d",&a,&b,&c);
        for(j=b;j<=c;j++)
        use[a][j]=1;
     }
}
int cost(int a,int b)
{
    int i,j,tou=1,wei=1;
    memset(mark,0,sizeof(mark));
    for(i=1;i<=m;i++)
    dis[i]=2147483647;
    dui[1]=1;
    dis[1]=0;
    mark[1]=1;
    for(i=a;i<=b;i++)
    for(j=2;j<=m-1;j++)
    if(use[j][i])
    mark[j]=1;
    int now;
    while(tou<=wei)
    {
        now=dui[tou];
        for(i=1;i<=lu[now][0];i++)
        {
          if(dis[now]+map[now][lu[now][i]]<dis[lu[now][i]])
          {
              dis[lu[now][i]]=dis[now]+map[now][lu[now][i]];
              if(!mark[lu[now][i]])
              {
              wei++;
              dui[wei]=lu[now][i];
              mark[lu[now][i]]=1;
              }
          }
        }
        mark[now]=0;
        tou++;
    }
    return dis[m];
}
int main()
{
    init();
    memset(dp,127,sizeof(dp));
    dp[0]=-k;
    int i,j,o;
    for(i=1;i<=n;i++)
    {
      for(j=i-1;j>=0;j--)
      {
        o=cost(j+1,i);
        if(o==2147483647)
        break;
        dp[i]=min(dp[i],dp[j]+o*(i-j)+k);
      }
    }
    cout<<dp[n]<<endl;   
    system("pause");
    return 0;
}
