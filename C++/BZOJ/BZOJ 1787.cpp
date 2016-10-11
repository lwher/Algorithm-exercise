#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#define inf 0x7fffffff
using namespace std;
int n,m,fa[500010][20],deep[500010];
int sz,to[1000010],pre[1000010],last[500010];
bool mark[500010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
    int i;mark[x]=1;
    for(i=1;i<=19;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
    for(i=last[x];i>0;i=pre[i])
    {
        if(mark[to[i]])  continue;
        deep[to[i]]=deep[x]+1;
        fa[to[i]][0]=x;
        dfs(to[i]);
    }
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b]) swap(a,b);
    int i,c=deep[a]-deep[b];
    for(i=19;i>=0;i--)
    {
        if(c>=(1<<i))  {a=fa[a][i];c-=(1<<i);}
    }
    for(i=19;i>=0;i--)
    {
        if(fa[a][i]!=fa[b][i])
        {
            a=fa[a][i];
            b=fa[b][i]; 
        }
    }
    if(a==b)  return a;  else return fa[a][0];
}
int main()
{
    int i,a,b,c,d,e,ans,tmp,k;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;i++)  
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    dfs(1);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        ans=inf; 
        d=LCA(a,b);
        e=LCA(d,c);
        tmp=deep[a]+deep[b]-2*deep[d]+deep[c]+deep[d]-2*deep[e];
        if(tmp<ans)  {k=d;ans=tmp;}
        d=LCA(a,c);
        e=LCA(d,b);
        tmp=deep[a]+deep[c]-2*deep[d]+deep[b]+deep[d]-2*deep[e];
        if(tmp<ans)  {k=d;ans=tmp;}
        d=LCA(c,b);
        e=LCA(d,a);
        tmp=deep[c]+deep[b]-2*deep[d]+deep[a]+deep[d]-2*deep[e];
        if(tmp<ans)  {k=d;ans=tmp;}
        printf("%d %d\n",k,ans);
    }
    return 0;
}