#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 1000000007
using namespace std;
int n,m,dist[1510];
int sz,to[5010],pre[5010],v[5010],id[5010],last[1510];
int dui[5000010],cnt[1510][2],ans[5010],q[1510];
bool mark[1510];
inline void Ins(int a,int b,int c,int x)
{
    sz++;to[sz]=b;v[sz]=c;id[sz]=x;pre[sz]=last[a];last[a]=sz;
}
inline bool comp(int a,int b)
{
    return dist[a]<dist[b];
}
void spfa(int s)
{
    memset(mark,0,sizeof(mark));
    memset(dist,127,sizeof(dist));
    int i,now,tou=1,wei=1;
    dui[1]=s;dist[s]=0;mark[s]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(i=last[now];i;i=pre[i])
        if(dist[to[i]]>dist[now]+v[i])
        {
            dist[to[i]]=dist[now]+v[i];
            if(!mark[to[i]])
            {
               dui[++wei]=to[i];mark[to[i]]=1;
            }
        }
        mark[now]=0;
    }
}
void solve()
{
     int s,i,j,x;
     for(s=1;s<=n;s++)
     {
         spfa(s);
         for(i=1;i<=n;i++) q[i]=i;
         sort(q+1,q+1+n,comp);
         memset(cnt,0,sizeof(cnt));
         cnt[s][0]=1;
         for(i=1;i<=n;i++)
         {
             x=q[i];
             for(j=last[x];j;j=pre[j]) if(dist[x]+v[j]==dist[to[j]]) cnt[to[j]][0]=(cnt[to[j]][0]+cnt[x][0])%mod;
         }
         for(i=n;i>=1;i--)
         {
             x=q[i];
             cnt[x][1]=(cnt[x][1]+1)%mod;
             for(j=last[x];j;j=pre[j]) if(dist[x]+v[j]==dist[to[j]])
             {
                 ans[id[j]]=((long long)(cnt[x][0])*cnt[to[j]][1]+ans[id[j]])%mod;
                 cnt[x][1]=(cnt[x][1]+cnt[to[j]][1])%mod;
             }
         }
     }
     for(i=1;i<=m;i++) printf("%d\n",ans[i]);
}
int main()
{
    int i,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c,i);
    }
    solve();
    system("pause");
    return 0;
}
