#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 1000000000
using namespace std;
struct sth
{
    int s,x;
}dui[3001];
int n,m,K,SZ,tou,wei,st[60];
int sz,to[3010],pre[3010],v[3010],last[60];
int d[1030][60],dp[1030];
bool in[1030][60];
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
inline void inc(int &x)
{
    x++;if(x==3000) x=0;
}
bool check(int x)
{
    int i,p=0;
    for(i=1;i<=K;i++) if(x & (1<<(i-1))) p++;
    for(i=K+1;i<=K*2;i++) if(x & (1<<(i-1))) p--;
    if(p==0) return 1; return 0;
}
void init()
{
    int i,j,a,b,c;sz=0;
    memset(last,0,sizeof(last));
    memset(st,0,sizeof(st));
    scanf("%d%d%d",&n,&m,&K);
    SZ=(1<<(K*2));
    for(i=0;i<SZ;i++) for(j=1;j<=n;j++) d[i][j]=INF;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
    for(i=1;i<=K;i++)
    {
        st[i]=1<<(i-1);d[st[i]][i]=0;
        st[n-K+i]=1<<(K+i-1);d[st[n-K+i]][n-K+i]=0;
    }
}
void spfa()
{
    int i,s,x,ts,tx;
    while(tou!=wei)
    {
        inc(tou);
        s=dui[tou].s;
        x=dui[tou].x;
        in[s][x]=0;
        for(i=last[x];i;i=pre[i])
        {
            tx=to[i];ts=(s|st[tx]);
            if(d[ts][tx]>d[s][x]+v[i])
            {
                d[ts][tx]=d[s][x]+v[i];
                if(!in[ts][tx] && ts==s) 
                {
                   inc(wei);in[ts][tx]=1;
                   dui[wei].s=ts;
                   dui[wei].x=tx;
                }
            }
        }
    }
}
void solve()
{
     int i,j,k;
     for(i=0;i<SZ;i++)
     {
         tou=0;wei=0;
         for(j=1;j<=n;j++)
         {
             if(st[j] && !(st[j] & i)) continue;
             for(k=(i-1)&i;k;k=(k-1)&i) d[i][j]=min(d[i][j],d[k|st[j]][j]+d[(i^k)|st[j]][j]);
             if(d[i][j]<INF)
             {
                 dui[++wei].s=i;dui[wei].x=j;in[i][j]=1;
             }
         }
         spfa();
     }     
     
     for(i=0;i<SZ;i++) 
     {
         dp[i]=INF;
         for(j=1;j<=n;j++) dp[i]=min(dp[i],d[i][j]);
     }
     for(i=0;i<SZ;i++)
     {
         if(!check(i)) continue;
         for(j=(i-1)&i;j;j=(j-1)&i) if(check(j)) dp[i]=min(dp[i],dp[j]+dp[i^j]);
     }
     if(dp[SZ-1]>=INF) printf("No solution\n");
     else printf("%d\n",dp[SZ-1]);
}
int main()
{
    int T;
    scanf("%d",&T);    
    while(T--)
    {
        init();
        solve();
    }
    system("pause");
    return 0;
}
