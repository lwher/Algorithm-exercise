#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,tt,fl,top,belong[500010],money[500010],stack[500010];
int sz,to[500010],pre[500010],last[500010];
int SZ,TO[500010],PRE[500010],LAST[500010];
int S,T[500010],v[500010],dfn[500010],low[500010],d[500010],dui[500010];
bool in[500010],mark[500010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline void INS(int a,int b)
{
    SZ++;TO[SZ]=b;PRE[SZ]=LAST[a];LAST[a]=SZ;
}
void Tarjan(int x)
{
     dfn[x]=low[x]=++tt;
     stack[++top]=x;in[x]=1;
     for(int i=last[x];i;i=pre[i])
     {
         if(!dfn[to[i]]) {Tarjan(to[i]);low[x]=min(low[x],low[to[i]]);}
         else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
     }
     if(low[x]==dfn[x])
     {
         fl++;
         while(stack[top]!=x)
         {
            int k=stack[top];top--;
            in[k]=0;v[fl]+=money[k];belong[k]=fl;
         }
         in[x]=0;v[fl]+=money[x];belong[x]=fl;top--;
     }
}
void init()
{
     int i,a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)
     {
         scanf("%d%d",&a,&b);
         Ins(a,b);
     }
     for(i=1;i<=n;i++) scanf("%d",&money[i]);
     scanf("%d%d",&S,&T[0]);
     for(i=1;i<=T[0];i++) scanf("%d",&T[i]);
}
inline void inc(int &x)
{
     x++; if(x==500009) x=0;
}
void spfa()
{
     int tou=0,wei=1,now,i;
     for(i=1;i<=fl;i++) d[i]=-1000000;
     d[belong[S]]=v[belong[S]];
     dui[1]=belong[S];mark[belong[S]]=1;
     while(tou!=wei)
     {
         inc(tou);now=dui[tou];
         for(i=LAST[now];i;i=PRE[i])
         if(d[TO[i]]<d[now]+v[TO[i]])
         {
             d[TO[i]]=d[now]+v[TO[i]];
             if(!mark[TO[i]]) 
             {
                 mark[TO[i]]=1;
                 inc(wei);
                 dui[wei]=TO[i];
             }
         }
         mark[now]=0;
     }
}
void solve()
{
     int i,j,ans=-10000000;
     for(i=1;i<=n;i++) if(!dfn[i]) Tarjan(i);
     for(i=1;i<=n;i++)  for(j=last[i];j;j=pre[j]) if(belong[to[j]]!=belong[i]) INS(belong[i],belong[to[j]]);
     spfa();
     for(i=1;i<=T[0];i++) if(d[belong[T[i]]]>ans) ans=d[belong[T[i]]];
     cout<<ans<<endl;
}
int main()
{    
    init();    
    solve();
    return 0;
}