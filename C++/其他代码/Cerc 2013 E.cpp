#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const long long INF=1LL<<50;
struct sth
{
    long long pay,gain;
}w[200010];
int n,t,root[200010],ls[200010],rs[200010],dist[200010],fa[200010];
int sz,to[500010],pre[500010],last[200010];
long long A[200010];
inline void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int merge(int a,int b)
{
     if(!a || !b) return a+b;
     if(w[a].pay>w[b].pay || (w[a].pay==w[b].pay && w[a].gain<w[b].gain))  swap(a,b);
     rs[a]=merge(rs[a],b);
     if(dist[ls[a]]<dist[rs[a]])  swap(ls[a],rs[a]);
     dist[a]=dist[rs[a]]+1;
     return a;
}
void dfs(int x)
{
     root[x]=0;
     for(int i=last[x];i;i=pre[i])
     {
         if(to[i]==fa[x]) continue;
         fa[to[i]]=x;
         dfs(to[i]);
         root[x]=merge(root[x],root[to[i]]);
     }
     long long pay,gain;
     if(A[x]>0) pay=0,gain=A[x];
     else pay=-A[x],gain=0;
     while(root[x]!=0)
     {
         if(pay<w[root[x]].pay && pay<gain)  break;
         if(gain>w[root[x]].pay)
         {
             gain+=w[root[x]].gain-w[root[x]].pay;
         }
         else
         {
             pay+=w[root[x]].pay-gain;
             gain=w[root[x]].gain;
         }
         root[x]=merge(ls[root[x]],rs[root[x]]);
     }
     if(pay<gain)  
     {
         w[x].pay=pay;w[x].gain=gain;
         root[x]=merge(root[x],x);
     }
}
int main()
{
    freopen("escape.in","r",stdin);
    freopen("escape.out","w",stdout);
    int T,i,a,b;
    scanf("%d",&T);
    while(T--)
    {
        sz=0;memset(last,0,sizeof(last));
        scanf("%d%d",&n,&t);
        for(i=1;i<=n;i++)  scanf("%I64d",&A[i]);
        for(i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            Ins(a,b);Ins(b,a);
        }
        A[++n]=INF;                
        Ins(t,n);Ins(n,t);
        memset(ls,0,sizeof(ls));
        memset(rs,0,sizeof(rs));
        memset(dist,0,sizeof(dist));      
        dfs(1);
        long long red=0;        
        while(root[1]!=0)
        {
            if(w[root[1]].pay<=red)
            {
                red+=w[root[1]].gain-w[root[1]].pay;
                root[1]=merge(ls[root[1]],rs[root[1]]);
            }
            else break;
        }
        if(red<INF) printf("trapped\n");
        else printf("escaped\n");
    }
   // system("pause");
    return 0;
}
