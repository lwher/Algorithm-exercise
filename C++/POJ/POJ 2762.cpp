#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#define M 10010
#define N 1010
using namespace std;
int n,m,sz,sz1;
int to[M],pre[M],last[N];
int to1[M],pre1[M],last1[N];
int zhan[N],top,dfn[N],low[N],tt;
bool in[N],mark[N];
int fl,shuyu[N],rd[N],cd[N];
void Ins1(int a,int b)
{
     sz1++;to1[sz1]=b;pre1[sz1]=last1[a];last1[a]=sz1;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;cd[a]++;rd[b]++;pre[sz]=last[a];last[a]=sz;
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
               while(zhan[top]!=x) {shuyu[zhan[top]]=fl;in[zhan[top]]=0;top--;}
               shuyu[x]=fl;in[x]=0;top--;
     }
}
void init()
{
     sz=0;sz1=0;
     memset(last,0,sizeof(last));
     memset(last1,0,sizeof(last1));
     int i,a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&a,&b);
         Ins1(a,b);
     }
     memset(dfn,0,sizeof(dfn));
     memset(low,0,sizeof(low));
     top=0;tt=0;fl=0;
     memset(in,0,sizeof(in));
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
     memset(mark,0,sizeof(mark));
     memset(rd,0,sizeof(rd));
     memset(cd,0,sizeof(cd));
     for(i=1;i<=n;i++) if(!mark[i])  dfs(i,shuyu[i]);
     int cc=0,rr=0;
     for(i=1;i<=fl;i++) { if(rd[i]==0)  rr++; if(cd[i]==0)  cc++;}
     if(rr>1 || cc>1)  printf("No\n");
     else printf("Yes\n");
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    init();
    build();
    }
    system("pause");
    return 0;
}
