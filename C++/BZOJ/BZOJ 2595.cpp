#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define INF 1000000000
using namespace std;
int n,m,cnt,K,tou,wei,map[10][10],st[10][10];
int dp[1030][10][10],pre[1030][10][10],dui[300001];
bool in[1030][10][10],vis[10][10];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
inline void inc(int &x)
{
    x++;if(x==300000) x=0;
}
void spfa()
{
    int k,x,y,s,tx,ty,ts;
    while(tou!=wei)
    {
        inc(tou);
        x=dui[tou]/100000;
        y=(dui[tou]-x*100000)/10000;
        s=dui[tou]-x*100000-y*10000;
        in[s][x][y]=0;
        for(k=0;k<4;k++)
        {
            tx=x+dx[k];ty=y+dy[k];
            if(tx>=n || tx<0 || ty>=m || ty<0) continue;
            ts=s|st[tx][ty];
            if(dp[s][x][y]+map[tx][ty]<dp[ts][tx][ty])
            {
                dp[ts][tx][ty]=dp[s][x][y]+map[tx][ty];
                pre[ts][tx][ty]=dui[tou];
                if(!in[ts][tx][ty] && s==ts)
                {
                    in[ts][tx][ty]=1;inc(wei);
                    dui[wei]=tx*100000+ty*10000+ts;
                }
            }
        }
    }
}
void go(int x,int y,int s)
{
    vis[x][y]=1;
    int t=pre[s][x][y],tx,ty,ts;
    if(!t) return;
    tx=t/100000;
    ty=(t-tx*100000)/10000;
    ts=t-tx*100000-ty*10000;
    go(tx,ty,ts);
    if(x==tx && y==ty) go(x,y,(s-ts)|st[x][y]);
}
int main()
{
    int i,j,k,x,y,t;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    {
        scanf("%d",&map[i][j]);
        if(!map[i][j]) {st[i][j]=1<<cnt;cnt++;}
    }
    K=1<<cnt;
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    {
        for(k=0;k<K;k++) dp[k][i][j]=INF;
        if(st[i][j]) dp[st[i][j]][i][j]=0;
    }
    for(k=1;k<K;k++)
    {
        tou=0;wei=0;
        for(i=0;i<n;i++) for(j=0;j<m;j++)
        {
            if(st[i][j] && !(k & st[i][j])) continue;
            for(x=(k-1)&k;x;x=(x-1)&k)
            {
                t=dp[x|st[i][j]][i][j]+dp[(k-x)|st[i][j]][i][j]-map[i][j];
                if(t<dp[k][i][j]) {dp[k][i][j]=t;pre[k][i][j]=i*100000+j*10000+(x|st[i][j]);} 
            }
            if(dp[k][i][j]<INF) dui[++wei]=i*100000+j*10000+k,in[k][i][j]=1;
        }
        spfa();
    }
    for(i=0;i<n;i++) for(j=0;j<m;j++)
    if(st[i][j])
    {
        printf("%d\n",dp[K-1][i][j]);
        go(i,j,K-1);
        for(x=0;x<n;x++) 
        {
           for(y=0;y<m;y++)
           {
              if(st[x][y]) putchar('x'); else
              if(vis[x][y]) putchar('o'); else
              putchar('_');
           }
           printf("\n");
        }
        system("pause");
        return 0;
    }
}
