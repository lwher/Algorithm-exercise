#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,A[300010],deep[300010],fa[300010][20],ans[300010];
int sz,to[600010],pre[600010],last[300010];
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
    for(int i=1;i<=19;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0]) continue;
        deep[to[i]]=deep[x]+1;
        fa[to[i]][0]=x;
        dfs(to[i]);
    }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b]) {int t=a;a=b;b=t;}
    int c=deep[a]-deep[b],i;
    for(i=19;i>=0;i--) if(c>=(1<<i)) {c-=(1<<i);a=fa[a][i];}
    for(i=19;i>=0;i--) if(fa[a][i]!=fa[b][i]) {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void init()
{
    int i,a,b;
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&A[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
}
void calc(int x)
{   for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0]) continue;
        calc(to[i]);
        ans[x]+=ans[to[i]];
    }
}
void solve()
{
    int i,c;
    dfs(A[1]);
    for(i=1;i<n;i++) 
    {
        c=LCA(A[i],A[i+1]);
        ans[A[i]]++;ans[A[i+1]]++;
        ans[c]--;ans[fa[c][0]]--;
    }
    calc(A[1]);
    for(i=2;i<=n;i++) ans[A[i]]--;
    for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}
int main()
{
    init();
    solve();
    return 0;
}