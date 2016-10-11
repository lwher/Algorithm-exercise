#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,deep[100010],fa[100010];
int sz,to[100010],pre[100010],last[100010];
int top;
long long quan[100010],v[100010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x)
{
    for(int i=last[x];i;i=pre[i])
    {
        deep[to[i]]=deep[x]+1;
        dfs(to[i]);
    }
}
void swap(int &a,int &b)
{
    int t=a;a=b;b=t;
}
bool solve(int x,int y)
{
    int i;top=0;
    if(deep[x]<deep[y])  swap(x,y);
    while(deep[x]>deep[y])
    {
        quan[++top]=v[x];if(top>45)  return 1;
        x=fa[x];
    }
    while(x!=y)
    {
        quan[++top]=v[x];quan[++top]=v[y];if(top>45)  return 1;
        x=fa[x];y=fa[y];
    }
    quan[++top]=v[x];
     
    sort(quan+1,quan+1+top);
    for(i=1;i<=top-2;i++) if(quan[i]+quan[i+1]>quan[i+2])  return 1;
    return 0;
}
int main()
{
    int i,k,a,b;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) scanf("%lld",&v[i]);
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        fa[b]=a;Ins(a,b);
    }
    deep[1]=1;
    dfs(1);
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k==0)
        {
            if(solve(a,b)) printf("Y\n"); else printf("N\n");
        }
        else v[a]=b;
    }
    return 0;
}