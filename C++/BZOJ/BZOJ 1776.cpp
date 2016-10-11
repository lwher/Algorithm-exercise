#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,K,root,deep[200010],fa[200010][18];
int next[200010],start[200010];
int stack[200010],top;
int sz,to[200010],pre[200010],last[200010];
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
void init()
{
     int i,a,p;
     scanf("%d%d",&n,&K);
     for(i=1;i<=n;i++)
     {
         scanf("%d%d",&a,&p);
         if(p==0) root=i; else Ins(p,i);
         next[i]=start[a];start[a]=i;
     }
}
void dfs(int x)
{
     for(int i=1;i<=17;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i])
     {
         fa[to[i]][0]=x;deep[to[i]]=deep[x]+1;
         dfs(to[i]);
     }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b]) swap(a,b);
    int i,t=deep[a]-deep[b];
    for(i=17;i>=0;i--) if(t>=(1<<i)) {t-=(1<<i);a=fa[a][i];}
    for(i=17;i>=0;i--) if(fa[a][i]!=fa[b][i]) {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void solve()
{
     int i,j,k,nans;
     deep[root]=1;dfs(root);
     for(i=1;i<=K;i++)
     {
         top=0;k=0;nans=0;
         for(j=start[i];j;j=next[j]) stack[++top]=j;
         for(j=1;j<=top;j++) if(deep[k]<deep[stack[j]]) k=stack[j];
         for(j=1;j<=top;j++) nans=max(nans,deep[k]+deep[stack[j]]-2*deep[(LCA(k,stack[j]))]);
         printf("%d\n",nans);
     }
}
int main()
{
    init();
    solve();
    return 0;
}