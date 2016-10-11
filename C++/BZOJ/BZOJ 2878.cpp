#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,root,du[100010],fa[100010];
int sz,to[200010],pre[200010],v[200010],last[100010];
double f[100010],up[100010],ans;
inline void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
}
void DP(int x)
{
    f[x]=0;
    for(int i=last[x];i;i=pre[i])
    {
        if(fa[x]==to[i]) continue;
        fa[to[i]]=x;
        DP(to[i]);
        f[x]+=f[to[i]]+v[i];
    } 
    if(x!=root && du[x]==1) return;
    if(x==root) f[x]/=du[x]*1.0;
    else f[x]/=(double)(du[x]-1);
}
void getup(int x,int d)
{
    int i;
    if(fa[x]!=0)
    {
        up[x]+=up[fa[x]];
        for(i=last[fa[x]];i;i=pre[i]) if(to[i]!=x && to[i]!=fa[fa[x]]) up[x]+=f[to[i]]+v[i];
        if(du[fa[x]]!=1) up[x]/=(double)(du[fa[x]]-1); 
        up[x]+=d;
    }
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x]) continue;
        getup(to[i],v[i]);
    }
}
void work1()
{
    int i,a,b,c;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
        du[a]++;du[b]++;
    }
    root=1;
    DP(root);
    getup(root,0);
    ans+=f[1]/(n*1.0);
    for(i=2;i<=n;i++) ans+=(f[i]*(du[i]-1)+up[i])/(n*1.0*(du[i]));
    printf("%.5lf\n",ans);
}
//========================================================================
int tt,dfn[100010],low[100010];
int top,fl,stack[100010],belong[100010],size[100010];
bool inhuan[100010],in[100010];
int hsz,huan[200010],dist[200010];
void Tarjan(int x,int fa)
{
    dfn[x]=low[x]=++tt;
    stack[++top]=x;in[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa) continue;
        if(!dfn[to[i]]) {Tarjan(to[i],x);low[x]=min(low[x],low[to[i]]);}
        else if(in[to[i]]) low[x]=min(low[x],dfn[to[i]]);
    }
    if(dfn[x]==low[x])
    {
        fl++;
        while(stack[top]!=x)
        {
            int k=stack[top];
            in[k]=0;belong[k]=fl;size[fl]++;top--;
            inhuan[k]=1;
        }
        in[x]=0;belong[x]=fl;size[fl]++;top--;
        if(size[fl]>1) inhuan[x]=1;
    } 
}
void findhuan(int x,int fa,int from)
{
    for(int i=last[x];i;i=pre[i])
    {
        if(!inhuan[to[i]] || to[i]==fa) continue;
        if(to[i]==from) {huan[++hsz]=from;dist[hsz]=dist[hsz-1]+v[i];continue;}
        huan[++hsz]=to[i];dist[hsz]=dist[hsz-1]+v[i];
        findhuan(to[i],x,from);
        break;
    }
}
void DP1(int x)
{
    f[x]=0;
    for(int i=last[x];i;i=pre[i])
    {
        if(fa[x]==to[i] || inhuan[to[i]]) continue;
        fa[to[i]]=x;
        DP1(to[i]);
        f[x]+=f[to[i]]+v[i];
    } 
    if(x!=root && du[x]==1) return;
    if(x==root && du[x]>2) f[x]/=(double)(du[x]-2);
    else f[x]/=(double)(du[x]-1);
}
void getup1(int x,int d)
{
    int i;
    if(fa[x]!=0)
    {
        up[x]+=up[fa[x]];
        for(i=last[fa[x]];i;i=pre[i]) if(to[i]!=x && to[i]!=fa[fa[x]] && !inhuan[to[i]]) up[x]+=f[to[i]]+v[i];
        if(du[fa[x]]!=1) up[x]/=(double)(du[fa[x]]-1); 
        up[x]+=d;
    }
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x] || inhuan[to[i]]) continue;
        getup1(to[i],v[i]);
    }
}
void work2()
{
    int i,j,k,a,b,c;
    double now1,now2;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        Ins(a,b,c);Ins(b,a,c);
        du[a]++;du[b]++;
    }
    Tarjan(1,0);
    for(i=1;i<=n;i++) if(inhuan[i]) break;
    huan[++hsz]=i;dist[1]=0;
    findhuan(i,0,i);
    hsz--;
    for(i=1;i<=hsz;i++) root=huan[i],DP1(huan[i]);
    for(i=2;i<=hsz;i++) huan[hsz+i]=huan[i],dist[hsz+i]=dist[hsz+1]+dist[i];            
    for(i=1;i<=hsz;i++)
    {
        now1=0;now2=0;
        for(k=i+1;k<=i+hsz;k++) 
        {
            if(k!=i+1) now1+=dist[k]-dist[k-1];
            if(k==i+hsz) break;
            for(j=last[huan[k]];j;j=pre[j]) if(!inhuan[to[j]]) now1+=f[to[j]]+v[j];
            if(k==i+1 && du[huan[k]]>2) now1/=(double)(du[huan[k]]-2);
            else now1/=(double)(du[huan[k]]-1);
        }
        for(k=i+hsz-1;k>=i;k--)
        {
            if(k!=i+hsz-1) now2+=dist[k+1]-dist[k];
            if(k==i) break;
            for(j=last[huan[k]];j;j=pre[j]) if(!inhuan[to[j]]) now2+=f[to[j]]+v[j];
            if(k==i+hsz-1 && du[huan[k]]>2) now2/=(double)(du[huan[k]]-2);
            else now2/=(double)(du[huan[k]]-1);
        }
        up[huan[i]]=now1+now2;
    }
    for(i=1;i<=hsz;i++) getup1(huan[i],0);
    for(i=1;i<=n;i++) 
    {
       if(!inhuan[i]) ans+=(f[i]*(du[i]-1)+up[i])/du[i];
       else ans+=(f[i]*(du[i]-2)+up[i])/du[i];
    }
    ans/=n*1.0;
    printf("%.5lf\n",ans);
}
int main()
{
    scanf("%d%d",&n,&m); 
    if(m==n-1) work1();
    else work2();
    return 0;
}
