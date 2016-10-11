#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int n,q,tt,fa[100010][17],deep[100010],W[100010],C[100010],pl[100010],belong[100010],size[100010];
int sz,to[200010],pre[200010],last[100010];
int tot,root[100010],ls[3500000],rs[3500000],tmax[3500000],tsum[3500000];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void Ins(int a,int b)
{
     sz++;to[sz]=b;pre[sz]=last[a];last[a]=sz;
}
void swap(int &a,int &b) {int t=a;a=b;b=t;}
void dfs1(int x)
{
     size[x]=1;
     for(int i=1;i<=16;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i])
     {
        if(to[i]==fa[x][0])  continue;
        deep[to[i]]=deep[x]+1;
        fa[to[i]][0]=x;
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
         if(to[i]==fa[x][0]) continue;
         if(size[to[i]]>maxx)  {maxx=size[to[i]];k=to[i];}
     }
     if(k==0) return;
     dfs2(k,chain);
     for(i=last[x];i;i=pre[i])
     {
         if(to[i]==fa[x][0] || to[i]==k)  continue;
         dfs2(to[i],to[i]);
     }
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int t=deep[a]-deep[b],i;
    for(i=16;i>=0;i--)  if(t>=(1<<i))  {t-=(1<<i);a=fa[a][i];}
    for(i=16;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void updata(int &x,int l,int r,int w,int num)
{
     if(!x) x=++tot;
     if(l==r)  {tmax[x]=num;tsum[x]=num;return;}
     int mid=(l+r)>>1;
     if(w<=mid) updata(ls[x],l,mid,w,num);
     else updata(rs[x],mid+1,r,w,num);
     tsum[x]=tsum[ls[x]]+tsum[rs[x]];
     tmax[x]=max(tmax[ls[x]],tmax[rs[x]]);
}
int askmax(int x,int l,int r,int zuo,int you)
{
    if(!x || l>you || r<zuo) return 0;
    if(l>=zuo && r<=you)  return tmax[x];
    int mid=(l+r)>>1;
    return max(askmax(ls[x],l,mid,zuo,you),askmax(rs[x],mid+1,r,zuo,you));
}
int asksum(int x,int l,int r,int zuo,int you)
{
    if(!x || l>you || r<zuo) return 0;
    if(l>=zuo && r<=you)  return tsum[x];
    int mid=(l+r)>>1;
    return asksum(ls[x],l,mid,zuo,you)+asksum(rs[x],mid+1,r,zuo,you);
}
int solvemax(int x,int f,int c)
{
    int maxx=0,l,r;
    while(belong[x]!=belong[f])
    {
        l=pl[belong[x]];r=pl[x];
        maxx=max(maxx,askmax(root[c],1,n,l,r));
        x=fa[belong[x]][0];
    }
    l=pl[f];r=pl[x];
    maxx=max(maxx,askmax(root[c],1,n,l,r));
    return maxx;
}
int solvesum(int x,int f,int c)
{
    int sum=0,l,r;
    while(belong[x]!=belong[f])
    {
        l=pl[belong[x]];r=pl[x];
        sum+=asksum(root[c],1,n,l,r);
        x=fa[belong[x]][0];
    }
    l=pl[f];r=pl[x];
    sum+=asksum(root[c],1,n,l,r);
    return sum;
}
void solve()
{
     int i,a,b,c,ans;char s[5];     
     for(i=1;i<=n;i++)  updata(root[C[i]],1,n,pl[i],W[i]);
     for(i=1;i<=q;i++)
     {
         scanf("%s",s);a=read();b=read();//scanf("%d%d",&a,&b);
         if(s[1]=='C')
         {
            updata(root[C[a]],1,n,pl[a],0);
            updata(root[b],1,n,pl[a],W[a]);
            C[a]=b;
         }else
         if(s[1]=='W')
         {
            updata(root[C[a]],1,n,pl[a],b);
            W[a]=b;
         }else
         if(s[1]=='M')
         {
              c=LCA(a,b);
              ans=max(solvemax(a,c,C[b]),solvemax(b,c,C[b]));
              printf("%d\n",ans);
         }else
         {
              c=LCA(a,b);
              ans=solvesum(a,c,C[b])+solvesum(b,c,C[b]);
              if(C[c]==C[b])  ans-=W[c];
              printf("%d\n",ans);
         }
     }
}
void init()
{
     int i,a,b;
     n=read();q=read();//scanf("%d%d",&n,&q);
     for(i=1;i<=n;i++)  {W[i]=read();C[i]=read();}//scanf("%d%d",&W[i],&C[i]);
     for(i=1;i<n;i++)
     {
         a=read();b=read();//scanf("%d%d",&a,&b);
         Ins(a,b);Ins(b,a);
     } 
    dfs1((n+1)/2);
    dfs2((n+1)/2,(n+1)/2);
}
int main()
{
    init();
    solve();
    system("pause");
    return 0;
}
