#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,tt,id,ft[100010],sd[100010],w[100010],size[100010],deep[100010];
int fa[100010][18],pl[100010],belong[100010];
int sz,to[200010],pre[200010],last[100010];
int tmin[500010];
bool mark[500010];
inline int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9')) ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9') {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
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
    int i,a,b;
    n=read();m=read();
    for(i=1;i<n;i++)
    {
        a=read();b=read();
        Ins(a,b);Ins(b,a);
    }
    for(i=1;i<=n;i++) w[i]=read();
    id=read();
}
void dfs1(int x)
{
    for(int i=1;i<=17;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
    size[x]=1;
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0]) continue;
        fa[to[i]][0]=x;
        deep[to[i]]=deep[x]+1;
        dfs1(to[i]);
        size[x]+=size[to[i]];
    }
}
void dfs2(int x,int chain)
{
    pl[x]=++tt;ft[x]=tt;belong[x]=chain;
    int i,k=0,maxx=0;
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0]) continue;
        if(size[to[i]]>maxx) maxx=size[to[i]],k=to[i];
    }
    if(k==0) {sd[x]=tt;return;}
    dfs2(k,chain);
    for(i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0] || to[i]==k) continue;
        dfs2(to[i],to[i]);
    }
    sd[x]=tt;
}
inline void downput(int k)
{
    mark[k]=0;mark[k<<1]=1;mark[k<<1|1]=1;
    tmin[k<<1]=tmin[k];tmin[k<<1|1]=tmin[k];
}
void updata(int k,int l,int r,int zuo,int you,int v)
{
    if(l>=zuo && r<=you) {mark[k]=1;tmin[k]=v;return;}
    if(mark[k]) downput(k);
    int mid=(l+r)>>1;
    if(zuo<=mid) updata(k<<1,l,mid,zuo,you,v);
    if(you>mid) updata(k<<1|1,mid+1,r,zuo,you,v);
    tmin[k]=min(tmin[k<<1],tmin[k<<1|1]);
}
int askmin(int k,int l,int r,int zuo,int you)
{
    if(l>r || l>you || r<zuo) return 0x7fffffff;
    if(l>=zuo && r<=you) return tmin[k];
    if(mark[k]) downput(k);
    int mid=(l+r)>>1;
    return min(askmin(k<<1,l,mid,zuo,you),askmin(k<<1|1,mid+1,r,zuo,you));
}
int LCA(int a,int b)
{
    int i,c;
    if(deep[a]<deep[b]) swap(a,b);
    c=deep[a]-deep[b];
    for(i=17;i>=0;i--) if(c>=(1<<i)) {c-=(1<<i);a=fa[a][i];}
    for(i=17;i>=0;i--) if(fa[a][i]!=fa[b][i]) {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0]; 
}
void change(int a,int b,int k)
{
    int l,r;
    while(belong[a]!=belong[b])
    {
        l=pl[belong[a]];r=pl[a];
        updata(1,1,n,l,r,k);
        a=fa[belong[a]][0];
    }
    l=pl[b];r=pl[a];
    updata(1,1,n,l,r,k);
}
void solve()
{
    int i,j,op,a,b,k,c;
    dfs1(id);    
    dfs2(id,id); 
    for(i=1;i<=n;i++) updata(1,1,n,pl[i],pl[i],w[i]);        
    for(i=1;i<=m;i++)
    {
        op=read();
        if(op==1) scanf("%d",&id); else
        if(op==2) 
        {
            a=read();b=read();k=read();
            c=LCA(a,b);
            change(a,c,k);change(b,c,k);
        } 
        else
        {
            k=read();
            if(k==id) printf("%d\n",tmin[1]); 
            else
            {
                c=LCA(k,id);
                if(c!=k) printf("%d\n",askmin(1,1,n,ft[k],sd[k]));
                else
                {
                    a=id;b=deep[id]-deep[k]-1;
                    for(j=17;j>=0;j--) if(b>=(1<<j)) {b-=(1<<j);a=fa[a][j];}
                    printf("%d\n",min(askmin(1,1,n,1,ft[a]-1),askmin(1,1,n,sd[a]+1,n)));
                } 
            } 
        }
    }
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
