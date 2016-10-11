#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define mod 201314
using namespace std;
struct sth
{
    int w,id,z,k;
}xw[100010];
int n,q,tt,xsz,fa[50010],pl[50010],belong[50010],size[50010];
int sz,to[100010],pre[100010],last[50010];
int tsum[300010],msum[300010],ans[50010];
inline void Ins(int a,int b)
{
    sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
inline bool comp(sth a,sth b)
{
    return a.w<b.w;
}
void dfs1(int x)
{
    size[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x]) continue;
        fa[to[i]]=x;
        dfs1(to[i]);
        size[x]+=size[to[i]];
    }
}
void dfs2(int x,int chain)
{
    pl[x]=++tt;belong[x]=chain;
    int i,k=0,maxx=0;
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x]) continue;
        if(maxx<size[to[i]]) {maxx=size[to[i]];k=to[i];}
    }
    if(!k) return;
    dfs2(k,chain);
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x] || to[i]==k) continue;
        dfs2(to[i],to[i]);
    }
}
void init()
{
    int i,x,l,r,z;
    scanf("%d%d",&n,&q);
    for(i=1;i<n;i++)
    {
       scanf("%d",&x);
       Ins(i+1,x+1);Ins(x+1,i+1);
    }
    for(i=1;i<=q;i++)
    {
        scanf("%d%d%d",&l,&r,&z);
        l++;r++;z++;
        xw[++xsz].w=l-1;xw[xsz].z=z;xw[xsz].id=i;xw[xsz].k=-1;
        xw[++xsz].w=r;xw[xsz].z=z;xw[xsz].id=i;xw[xsz].k=1;
    }
}
inline void downput(int k,int l,int r)
{
    int mid=(l+r)>>1;
    msum[k<<1]=(msum[k<<1]+msum[k])%mod;msum[k<<1|1]=(msum[k<<1|1]+msum[k])%mod;
    tsum[k<<1]=(tsum[k<<1]+msum[k]*(mid-l+1))%mod;
    tsum[k<<1|1]=(tsum[k<<1|1]+msum[k]*(r-mid))%mod;
    msum[k]=0;
}
void add(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you) 
    {
        msum[k]=(msum[k]+1)%mod;
        tsum[k]=(tsum[k]+r-l+1)%mod;
        return;
    }
    if(msum[k]) downput(k,l,r);
    int mid=(l+r)>>1;
    if(zuo<=mid) add(k<<1,l,mid,zuo,you);
    if(you>mid) add(k<<1|1,mid+1,r,zuo,you);
    tsum[k]=(tsum[k<<1]+tsum[k<<1|1])%mod;
}
int asksum(int k,int l,int r,int zuo,int you)
{
    if(l>you || r<zuo || l>r) return 0;
    if(l>=zuo && r<=you) return tsum[k];
    if(msum[k]) downput(k,l,r);
    int mid=(l+r)>>1;
    return (asksum(k<<1,l,mid,zuo,you)+asksum(k<<1|1,mid+1,r,zuo,you))%mod;
}
void solveadd(int x)
{
    int l,r;
    while(belong[x]!=1) 
    {
        l=pl[belong[x]];r=pl[x];
        add(1,1,n,l,r);
        x=fa[belong[x]];
    }
    l=1;r=pl[x];
    add(1,1,n,l,r);
}
int solveask(int x)
{
    int l,r,sum=0;
    while(belong[x]!=1)
    {
        l=pl[belong[x]];r=pl[x];
        sum+=asksum(1,1,n,l,r);
        x=fa[belong[x]];
    }
    l=1;r=pl[x];
    sum=(sum+asksum(1,1,n,l,r))%mod;
    return sum;
}
void solve()
{
    int i,p=1;
    sort(xw+1,xw+1+xsz,comp);
    dfs1(1);
    dfs2(1,1);    
    while(!xw[p].w && p<=xsz) p++;    
    for(i=1;i<=n;i++) 
    {
        solveadd(i);
        while(xw[p].w==i && p<=xsz)
        {
            ans[xw[p].id]+=solveask(xw[p].z)*xw[p].k;
            p++;
        }
    }
    for(i=1;i<=q;i++) printf("%d\n",(ans[i]%mod+mod)%mod); 
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
