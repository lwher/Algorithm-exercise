#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
struct sth
{
    int l,r,lca,bh;
}xw[100010];
int n,m,q,tt,limt,v[40010],ft[40010],dfsxu[80010],fa[40010][16],deep[40010];
int top,tot,shu[40010],num[40010],ans[100010],sum[40010],gs[40010];
int sz,to[80010],pre[80010],last[40010];
inline int read()
{
     char ch=getchar();
     while(!(ch>='0' && ch<='9'))  ch=getchar();
     int x=0;
     while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
     return x;
}
inline void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline bool comp(sth a,sth b)
{
     if(a.l/limt==b.l/limt)  return a.r<b.r; return a.l/limt<b.l/limt;
}
inline int find(int x)
{
     int l=1,r=tot,mid;
     while(l+1<r)
     {
         mid=(l+r)>>1;
         if(num[mid]==x)  return mid;
         if(num[mid]<x) l=mid;
         else r=mid;
     }
     if(num[r]==x) return r; return l;
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void dfs(int x)
{
     ft[x]=++tt;dfsxu[tt]=x;
     for(int i=1;i<=15;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i])
     {
        if(fa[x][0]==to[i])  continue;
        deep[to[i]]=deep[x]+1;
        fa[to[i]][0]=x;
        dfs(to[i]);
     }
     dfsxu[++tt]=x;
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int i,c=deep[a]-deep[b];
    for(i=15;i>=0;i--)  if(c>=(1<<i))  {c-=(1<<i);a=fa[a][i];}
    for(i=15;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
inline void makexw(int a,int b,int i)
{
    int l,r;
    if(ft[a]+1<=ft[b]) {l=ft[a]+1;r=ft[b];}
    else {l=ft[b]+1;r=ft[a];}
    xw[++q].l=l;xw[q].r=r;xw[q].lca=LCA(a,b);xw[q].bh=i;
}
void init()
{
     int i,a,b;
     n=read();m=read();//scanf("%d%d",&n,&m);
     for(i=1;i<=n;i++) 
     {
        v[i]=read();//scanf("%d",&v[i]);
        shu[++top]=v[i];
     }
     for(i=1;i<n;i++)
     {
        a=read();b=read();//scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
     }
     sort(shu+1,shu+1+top);
     num[++tot]=shu[1];
     for(i=2;i<=n;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
     for(i=1;i<=n;i++) v[i]=find(v[i]);
     dfs(1);
     for(i=1;i<=m;i++)  
     {
         a=read();b=read();//scanf("%d%d",&a,&b);
         if(a==b) ans[i]=1; else makexw(a,b,i);
     }
} 
void solve()
{
     limt=sqrt(n*2);
     sort(xw+1,xw+1+q,comp);
     int L=1,R=0,i,t,now=0;
     for(i=1;i<=q;i++)
     {
         while(R<xw[i].r)
         {
            t=dfsxu[R+1];
            gs[t]++;
            if(gs[t]>1)
            {
                sum[v[t]]--;
                if(!sum[v[t]])  now--;
            }
            else
            {
                sum[v[t]]++;
                if(sum[v[t]]==1)  now++;
            }
            R++;
         }
         while(L>xw[i].l)
         {
            t=dfsxu[L-1];
            gs[t]++;
            if(gs[t]>1)
            {
                sum[v[t]]--;
                if(!sum[v[t]])  now--;
            }
            else
            {
                sum[v[t]]++;
                if(sum[v[t]]==1)  now++;
            }
            L--;
         }
         while(R>xw[i].r)
         {
            t=dfsxu[R];
            gs[t]--;
            if(gs[t])
            {
                sum[v[t]]++;
                if(sum[v[t]]==1)  now++;
            }
            else
            {
                sum[v[t]]--;
                if(!sum[v[t]])  now--;
            }
            R--;
         }
         while(L<xw[i].l)
         {
            t=dfsxu[L];
            gs[t]--;
            if(gs[t])
            {
                sum[v[t]]++;
                if(sum[v[t]]==1)  now++;
            }
            else
            {
                sum[v[t]]--;
                if(!sum[v[t]])  now--;
            }
            L++;
         }
         if(!sum[v[xw[i].lca]])  ans[xw[i].bh]=now+1; else ans[xw[i].bh]=now;
     }
     for(i=1;i<=m;i++)  printf("%d\n",ans[i]);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
