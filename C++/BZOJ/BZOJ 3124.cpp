#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int n,fa[200010],leaf;
long long dep[200010],d[200010],ans,sum,tmp;
int sz,to[500010],pre[500010],v[500010],last[200010];
bool mark[200010];
void Ins(int a,int b,int c)
{
     sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void dfs(int x,int from)
{
     fa[x]=from;
     if(tmp<dep[x])  {tmp=dep[x];leaf=x;}
     for(int i=last[x];i;i=pre[i])
     {
         if(to[i]==from)  continue;
         dep[to[i]]=dep[x]+v[i];
         dfs(to[i],x);
     }
}
void getlen(int x,int from)
{
     if(tmp<d[x])  tmp=d[x];
     for(int i=last[x];i;i=pre[i])
     {
         if(mark[to[i]] || to[i]==from)  continue;
         d[to[i]]=d[x]+v[i];
         getlen(to[i],x);
     }
}
int main()
{
    int i,a,b,c,s,t;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
    }
    dep[1]=0;tmp=0;dfs(1,0);s=leaf;
    dep[s]=0;tmp=0;dfs(s,0);t=leaf;
    ans=tmp;
    for(i=t;i;i=fa[i]) 
    mark[i]=1;
    bool flag=1;int l=s,r=t,ldist,rdist;
    for(i=t;i;i=fa[i])
    {
        ldist=dep[i];rdist=ans-dep[i];
        tmp=0;d[i]=0; getlen(i,0);
        if(tmp==ldist && flag)  {l=i;flag=0;}
        if(tmp==rdist)  r=i;
    }
    for(i=r;i!=l;i=fa[i])  sum++;
    cout<<ans<<endl<<sum<<endl;
    system("pause");
    return 0;
}
