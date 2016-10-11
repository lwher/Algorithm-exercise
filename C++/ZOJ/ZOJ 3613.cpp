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
}dui[50010];
int n,m,cf,cs,SZ,tou,wei,ans,cnt,vans,P[210],S[210],st[210],d[1<<8][210],dp[1<<8],fac[10];
int sz,to[10010],v[10010],pre[10010],last[210];
bool in[1<<8][210];
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
bool check(int x)
{
    int i,p=0;
    for(i=0;i<cf;i++) if(x & (1<<i)) p+=fac[i];
    for(i=cf;i<cf+cs;i++) if(x & (1<<i)) p--;
    if(p>=0) return 1; return 0;
}
int Count(int x)
{
    int i,p=0;
    for(i=cf;i<cs+cf;i++) if(x & (1<<i)) p++;
    return p;
}
void spfa()
{
     int s,x,i,ts,tx;
     while(tou<=wei)
     {
         s=dui[tou].s;
         x=dui[tou].x;
         in[s][x]=0;
         tou++;
         for(i=last[x];i;i=pre[i])
         {
            tx=to[i];ts=s|st[tx];
            if(d[ts][tx]>d[s][x]+v[i])
            {
                d[ts][tx]=d[s][x]+v[i];
                if(s==ts && !in[ts][tx])
                {
                    in[ts][tx]=1;
                    dui[++wei].s=ts;
                    dui[wei].x=tx;
                }
            }
         }
     }
}
void init()
{
    int i,j,k,x,z,y;
    memset(last,0,sizeof(last));
    memset(st,0,sizeof(st));
    memset(fac,0,sizeof(fac));
    cf=0;cs=0;sz=0;ans=0;cnt=0;vans=0;
    for(i=1;i<=n;i++) 
    {
        scanf("%d%d",&P[i],&S[i]);
        if(S[i] && P[i]) P[i]--,S[i]=0,ans++;
        if(P[i]) st[i]=1<<cf,fac[cf]=P[i],cf++;
    }
    for(i=1;i<=n;i++) if(S[i]) st[i]=1<<(cf+cs),cs++;
    SZ=1<<(cf+cs);
    for(i=0;i<SZ;i++) for(j=1;j<=n;j++) d[i][j]=INF;
    for(i=1;i<=n;i++) if(st[i]) d[st[i]][i]=0;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        Ins(x,y,z);Ins(y,x,z);
    }
}
void solve()
{
     int i,j,k;
     for(i=0;i<SZ;i++)
     {
         tou=1;wei=0;
         for(j=1;j<=n;j++)
         {
             if(st[j] && !(i & st[j])) continue;
             for(k=(i-1)&i;k;k=(k-1)&i) d[i][j]=min(d[i][j],d[k|st[j]][j]+d[(i^k)|st[j]][j]);
             if(d[i][j]<INF) {in[i][j]=1;dui[++wei].s=i;dui[wei].x=j;}
         }
         spfa();
     }     
     for(i=0;i<SZ;i++) 
     {
        dp[i]=INF;
        if(check(i)) for(j=1;j<=n;j++) dp[i]=min(dp[i],d[i][j]);
     }
     for(i=0;i<SZ;i++)
     {
        if(!check(i)) continue;
        for(k=(i-1)&i;k;k=(k-1)&i) if(check(k) && check(i^k)) dp[i]=min(dp[i],dp[k]+dp[i^k]);
     }
     for(i=0;i<SZ;i++)
     if(dp[i]<INF)
     {
        int t=Count(i);
        if(t>cnt || (t==cnt && vans>dp[i])) cnt=t,vans=dp[i];
     }
     printf("%d %d\n",ans+cnt,vans);
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        init();
        solve();
    }
    system("pause");
    return 0;
}
