#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define M 1000010
#define N 100010
using namespace std;
int n,m,mod,sz,sz1;
int to[M],pre[M],last[N];
int to1[M],pre1[M],last1[N];
int zhan[N],top,dfn[N],low[N],tt;
bool in[N],mark[N];
int fl,shuyu[N],size[N],rd[N],fa[N];
int d[N],sum[N],dui[N];
int ans,zs;
void Ins1(int a,int b)
{
     sz1++;to1[sz1]=b;pre1[sz1]=last1[a];last1[a]=sz1;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;rd[b]++;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x)
{
     tt++;dfn[x]=tt;low[x]=tt;
     top++;zhan[top]=x;in[x]=1;
     int i=last1[x],g;
     while(i>0)
     {
               g=to1[i];
               if(!dfn[g]) {Tarjan(g);low[x]=min(low[x],low[g]);}
               else if(in[g])  low[x]=min(low[x],dfn[g]);
               i=pre1[i];
     }
     if(dfn[x]==low[x])
     {
               fl++;
               while(zhan[top]!=x) {size[fl]++;shuyu[zhan[top]]=fl;in[zhan[top]]=0;top--;}
               shuyu[x]=fl;in[x]=0;top--;size[fl]++;
     }
}
void init()
{
     int i,a,b;
     scanf("%d%d%d",&n,&m,&mod);
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&a,&b);
         Ins1(a,b);
     }
     for(i=1;i<=n;i++)  
     if(!dfn[i])  Tarjan(i);
}
void dfs(int x,int sy)
{
     int i=last1[x],g;
     mark[x]=1;
     while(i>0)
     {
            g=to1[i];
            if(shuyu[g]!=sy)  Ins(sy,shuyu[g]);
            else  if(!mark[g])  dfs(g,sy);
            i=pre1[i];
     }
}
void build()
{
     int i;
     for(i=1;i<=n;i++) if(!mark[i])  dfs(i,shuyu[i]);
}
void DP()
{
     int i,j,now,g,tou=1,wei=0;
     for(i=1;i<=fl;i++)  if(rd[i]==0)
     {
         wei++;dui[wei]=i;d[i]=size[i];sum[i]=1;
     }
     while(tou<=wei)
     {
          now=dui[tou];tou++;
          i=last[now];
          while(i>0)
          {
               rd[to[i]]--;
               if(rd[to[i]]==0)
               {wei++;dui[wei]=to[i];}
               i=pre[i];          
          }   
     }
     for(i=1;i<=fl;i++)
     {
         now=dui[i];
         j=last[now];
         while(j>0)
         {
             g=to[j];
             if(fa[g]!=now)  
             {
                  if(d[now]+size[g]>d[g])
                  {
                      fa[g]=now;d[g]=d[now]+size[g];sum[g]=sum[now];
                  }
                  else
                  if(d[now]+size[g]==d[g])
                  {
                      fa[g]=now;sum[g]=(sum[g]+sum[now])%mod;
                  }
             }
             j=pre[j];
         }
     }
     for(i=1;i<=fl;i++)
     {
          if(ans<d[i])  {ans=d[i];zs=sum[i];}
          else
          if(ans==d[i]) {zs=(sum[i]+zs)%mod;}
     }
     printf("%d\n%d",ans,zs);
}
int main()
{
    init();
    build();
    DP();
    system("pause");
    return 0;
}
