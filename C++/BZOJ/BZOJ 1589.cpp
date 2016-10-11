#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
int n,tt,fl,top,dfn[100010],low[100010],stack[100010],next[100010];
int sz,to[100010],pre[100010],last[100010];
int belong[100010],sum[100010],dp[100010];
bool in[100010];
void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void Tarjan(int x)
{
    dfn[x]=++tt;low[x]=tt;
    stack[++top]=x;in[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(!dfn[to[i]])   
        {
            Tarjan(to[i]);
            low[x]=min(low[x],low[to[i]]);
        }
        else if(in[to[i]])  low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        fl++;
        while(stack[top]!=x)
        {
            int k=stack[top];
            belong[k]=fl;sum[fl]++;in[k]=0;top--;
        }
        belong[x]=fl;sum[fl]++;in[x]=0;top--;
    }
}
int dfs(int x)
{
    if(dp[x]!=-1)  return dp[x];
    int k=next[x];
    if(belong[x]==belong[k]) return dp[x]=sum[belong[x]];
    return dp[x]=dfs(k)+1;  
}
int main()
{
    int i,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        Ins(i,x);next[i]=x;
    }
    for(i=1;i<=n;i++)  if(!dfn[i])  Tarjan(i);
    memset(dp,-1,sizeof(dp));
    for(i=1;i<=n;i++)
    {
        x=next[i];dp[i]=dfs(i);
    }
    for(i=1;i<=n;i++)  printf("%d\n",dp[i]);
    return 0;
}