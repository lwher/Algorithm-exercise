#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,m,s,t;
int sz=1,to[50010],pre[50010],v[50010],cost[50010],last[6010];
int dui[100010],d[6010];
bool mark[6010];
long long ans;
int w[5010],l[5010],C[5010],D[5010],sum[5010];
void Ins(int a,int b,int c,int d)
{
     sz++;to[sz]=b;v[sz]=c;cost[sz]=d;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;cost[sz]=-d;pre[sz]=last[b];last[b]=sz;
}
bool spfa()
{
     memset(mark,0,sizeof(mark));
     memset(d,127,sizeof(d));
     int tou=1,wei=1,now,i,inf=d[0];
     dui[1]=t;d[t]=0;mark[t]=1;
     while(tou<=wei)
     {
         now=dui[tou];tou++;
         for(i=last[now];i;i=pre[i])
         {
             if(v[i^1]>0 && d[to[i]]>d[now]-cost[i])
             {
                 d[to[i]]=d[now]-cost[i];
                 if(!mark[to[i]])  {mark[to[i]]=1;dui[++wei]=to[i];}
             }
         }
         mark[now]=0;
     }
     if(d[s]==inf)  return 0; return 1;
}
int dfs(int x,int F)
{
    mark[x]=1;
    if(x==t) return F;
    int used=0,w,i;
    for(i=last[x];i;i=pre[i])
    {
       if(v[i]>0 && !mark[to[i]] && d[to[i]]==d[x]-cost[i])
       {
           w=min(v[i],F-used);
           w=dfs(to[i],w);
           v[i]-=w;
           v[i^1]+=w;
           used+=w;
           if(used==F) return F;
       }
    }
    return used;
}
void mincostflow()
{
     while(spfa())
     {
         mark[t]=1;
         while(mark[t])
         {
             memset(mark,0,sizeof(mark));
             ans+=dfs(s,INF)*d[s];
         }
     }
}
void init()
{
     int i,j,a,b,tmp,last;
     scanf("%d%d",&n,&m);
     s=n+m+1;t=s+1;
     for(i=1;i<=n;i++)  scanf("%d%d%d%d",&w[i],&l[i],&C[i],&D[i]);
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&a,&b);
         Ins(s,i,1,0);
         Ins(i,m+a,1,0);
         Ins(i,m+b,1,0);
         sum[a]++;sum[b]++;
     }
     for(i=1;i<=n;i++)
     {
         last=C[i]*w[i]*w[i]+D[i]*(l[i]+sum[i])*(l[i]+sum[i]);
         ans+=last;
         for(j=1;j<=sum[i];j++)
         {
             tmp=C[i]*(w[i]+j)*(w[i]+j)+D[i]*(l[i]+sum[i]-j)*(l[i]+sum[i]-j);
             Ins(m+i,t,1,tmp-last);
             last=tmp;
         }
     }
}
int main()
{
    init();
    mincostflow();
    cout<<ans<<endl;
    system("pause");
    return 0;
}
