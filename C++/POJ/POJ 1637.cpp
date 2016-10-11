#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#define INF 0x7fffffff
using namespace std;
int T,n,m,sz,s,t,all;
bool o;
int to[9010],pre[9010],last[310],v[9010];
int in[310],out[310];
int h[310],gap[310],dui[310];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
     sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
void init()
{
     sz=1;o=0;all=0;
     memset(last,0,sizeof(last));
     memset(in,0,sizeof(in));
     memset(out,0,sizeof(out));
     int i,a,b,c;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
        scanf("%d%d%d",&a,&b,&c);
        if(a==b)  continue;
        out[a]++;in[b]++;
        if(!c)  Ins(a,b,1);
     }
     s=n+1;t=s+1;
     for(i=1;i<=n;i++)
     {
        if(abs(in[i]-out[i])%2!=0)  o=1;
        if(in[i]-out[i]<0) {all+=(out[i]-in[i])/2; Ins(s,i,(out[i]-in[i])/2);}
        if(in[i]-out[i]>0)  Ins(i,t,(in[i]-out[i])/2);
     }
}
void bfs()
{
     memset(h,-1,sizeof(h));
     memset(gap,0,sizeof(gap));
     int tou=1,wei=1,now,i;
     dui[1]=t;h[t]=1;gap[1]=1;
     while(tou<=wei)
     {
         now=dui[tou];
         tou++;
         i=last[now];
         while(i)
         {
             if(h[to[i]]==-1)
             {
                 h[to[i]]=h[now]+1;gap[h[to[i]]]++;
                 wei++;dui[wei]=to[i];
             }
             i=pre[i];
         }
     }
}
int dfs(int x,int F)
{
     if(x==t)   return F;
     int used=0,w,i;
     i=last[x];
     while(i)
     {
             if(v[i] && h[x]-1==h[to[i]])
             {
                    w=F-used;
                    w=dfs(to[i],min(v[i],w));
                    v[i]-=w;
                    v[i^1]+=w;
                    used+=w;
                    if(used==F)  return F;
             }
             i=pre[i];
     }
     gap[h[x]]--;
     if(gap[h[x]]==0)
     {h[s]=t+1;}
     gap[++h[x]]++;
     return used;
}
int sap()
{
     int ans=0;
     while(h[s]<t+1)
     ans+=dfs(s,INF);
     return ans;
}
void solve()
{
     int w;
     if(o)   {printf("impossible\n");return;}
     bfs();
     w=sap();
     if(w!=all)  {printf("impossible\n");return;}
     printf("possible\n");
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
              init();
              solve();
    }
    system("pause");
    return 0;
}
