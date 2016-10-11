#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,root,sum,f[10010],size[10010],d[10010];
int sz,to[20010],v[20010],pre[20010],last[10010];
int stack[10010],top,xw;
bool mark[10010],flag,have[1000010];
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void getroot(int x,int fa)
{
    size[x]=1;f[x]=0;
    for(int i=last[x];i;i=pre[i])
    if(!mark[to[i]] && to[i]!=fa)
    {
        getroot(to[i],x);
        size[x]+=size[to[i]];
        f[x]=max(f[x],size[to[i]]);
    }
    f[x]=max(f[x],sum-size[x]);
    if(f[x]<f[root])  root=x;
}
void getsize(int x,int fa)
{
    size[x]=1;
    for(int i=last[x];i;i=pre[i])
    if(!mark[to[i]] && to[i]!=fa)
    {
        getsize(to[i],x);
        size[x]+=size[to[i]];
    }
}
void dfsans(int x,int fa)
{
    if(d[x]==xw)  flag=1;
    if(d[x]<xw && have[xw-d[x]])  flag=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa || mark[to[i]])  continue;
        d[to[i]]=d[x]+v[i];
        dfsans(to[i],x);
    }
}
void dfshash(int x,int fa)
{
    if(d[x]<xw && !have[d[x]])
    {
        stack[++top]=d[x];have[d[x]]=1;
    }
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa || mark[to[i]])  continue;
        dfshash(to[i],x);
    }
}
void calc(int x)
{
    top=0;
    for(int i=last[x];i;i=pre[i])
    {
        if(mark[to[i]])  continue;
        d[to[i]]=v[i];
        dfsans(to[i],x);
        dfshash(to[i],x);
    }
    while(top>0)  {have[stack[top]]=0;top--;}
}
void work(int x)
{
    if(flag)  return;
    calc(x);
    if(flag)  return;
    mark[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(mark[to[i]])   continue;
        getsize(to[i],x);
        sum=size[to[i]];root=0;f[0]=sum;
        getroot(to[i],x);
        work(root);
    }
}
int main()
{
    int i,a,b,c;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++) 
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d",&xw);
        memset(mark,0,sizeof(mark));
        sum=n;root=0;f[0]=sum;flag=0;
        getroot(1,0);
        work(root);
        if(flag || xw==0)  printf("Yes\n");
        else  printf("No\n");
    }
    return 0;
}