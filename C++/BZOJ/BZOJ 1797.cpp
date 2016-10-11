#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath> 
using namespace std;
#define N 4010
#define M 300010
#define INF 0x7fffffff
int n,m,s,t;
int from[M],to[M],pre[M],last[N],v[M];
int to1[M],pre1[M],last1[N];
int zhan[N],top,ft[N],low[N];
bool in[N];
int fl,shuyu[N],tt;
int h[N],gap[N],dui[N];
int sz=1,sz1;
void Ins(int a,int b,int c)
{
     sz++;from[sz]=a;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void Ins1(int a,int b)
{
     sz1++;to1[sz1]=b;pre1[sz1]=last1[a];last1[a]=sz1;
}
void bfs()
{
     int tou=1,wei=1,now,i;
     memset(h,-1,sizeof(h));
     h[t]=1;gap[1]++;dui[1]=t;
     while(tou<=wei)
     {
          now=dui[tou];tou++;
          i=last[now];
          while(i>0)
          {
               if(h[to[i]]==-1)
               {
                   h[to[i]]=h[now]+1;gap[h[to[i]]]++;wei++;dui[wei]=to[i];
               }
               i=pre[i];
          }
     }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int i=last[x],used=0,w;
    while(i>0)
    {
        if(v[i] && h[to[i]]==h[x]-1)
        {
            w=F-used;
            w=dfs(to[i],min(v[i],w));
            used+=w;
            v[i]-=w;
            v[i^1]+=w;
            if(F==used)  return F;
        }
        i=pre[i];
    }
    gap[h[x]]--;
    if(gap[h[x]]==0)  h[s]=n+1;
    gap[++h[x]]++;
    return used;
}
void Tarjan(int x)
{
     tt++;ft[x]=tt;low[x]=tt;
     top++;zhan[top]=x;in[x]=1;
     int i=last1[x];
     while(i>0)
     {
         if(ft[to1[i]]==0)  {Tarjan(to1[i]);low[x]=min(low[x],low[to1[i]]);}
         else if(in[to1[i]])  low[x]=min(low[x],ft[to1[i]]);
         i=pre1[i];
     }    
     if(low[x]==ft[x])
     {
         fl++;
         while(zhan[top]!=x)
         {shuyu[zhan[top]]=fl;in[zhan[top]]=0;top--;}
         shuyu[x]=fl;in[x]=0;top--;
     }
}
void init()
{
     int i,b,a,c;
     scanf("%d%d%d%d",&n,&m,&s,&t);
     for(i=1;i<=m;i++)
     {
          scanf("%d%d%d",&a,&b,&c);Ins(a,b,c);
     }
}
void SAP()
{
     int ans=0,i;
     bfs();
     while(h[s]<=n)  
     dfs(s,INF);
}
void rebuild()
{
     int i,j;
     for(i=1;i<=n;i++)
     {
         j=last[i];
         while(j>0)
         {
             if(v[j])  Ins1(i,to[j]);
             j=pre[j];
         }
     }
}
void solve()
{
     int i;     
     init();
     SAP();
     rebuild();
     for(i=1;i<=n;i++)   if(ft[i]==0) Tarjan(i);
     for(i=2;i<=sz;i+=2)
     if(v[i]==0 && shuyu[from[i]]!=shuyu[to[i]])
     {
         printf("1 ");
         if(shuyu[s]!=shuyu[t] && shuyu[from[i]]==shuyu[s] && shuyu[to[i]]==shuyu[t]) printf("1\n");
         else printf("0\n");
     }
     else
     printf("0 0\n");
}
int main()
{
    solve();
    system("pause");
    return 0;
}
