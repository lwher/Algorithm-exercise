#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int n,tt,deep[10010],belong[10010],quan[10010],pl[10010],bpl[10010],fa[10010][15],size[10010];
int sz,to[20010],v[20010],pre[20010],bh[20010],last[10010];
int tmax[40010];
void Ins(int a,int b,int c,int d)
{
     sz++;to[sz]=b;pre[sz]=last[a];v[sz]=c;bh[sz]=d;last[a]=sz;
}
inline int max(int a,int b) {if(a>b) return a;return b;}
inline void swap(int &a,int &b)  {int t=a;a=b;b=t;}
void dfs1(int x)
{
     size[x]=1;
     for(int i=1;i<=14;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i])
     if(to[i]!=fa[x][0])
     {
           deep[to[i]]=deep[x]+1;quan[to[i]]=v[i];bpl[bh[i]]=to[i];fa[to[i]][0]=x;
           dfs1(to[i]);
           size[x]+=size[to[i]];  
     }
}
void dfs2(int x,int chain)
{
     int k=0,i,maxx=0;
     pl[x]=++tt;belong[x]=chain;
     for(i=last[x];i;i=pre[i])  if(to[i]!=fa[x][0] && size[to[i]]>maxx) {k=to[i];maxx=size[to[i]];} 
     if(!k) return;
     dfs2(k,chain);
     for(i=last[x];i;i=pre[i])  if(to[i]!=fa[x][0] && to[i]!=k)  dfs2(to[i],to[i]);
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int i,c=deep[a]-deep[b];
    for(i=14;i>=0;i--)  if(c>=(1<<i))  {c-=(1<<i);a=fa[a][i];}
    for(i=14;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
void updata(int k,int l,int r,int x,int num)
{
    if(l==r)  {tmax[k]=num;return;}
    int mid=(l+r)>>1;
    if(x<=mid)  updata(k+k,l,mid,x,num);
    else  updata(k+k+1,mid+1,r,x,num);
    tmax[k]=max(tmax[k+k],tmax[k+k+1]);
}
int askmax(int k,int l,int r,int zuo,int you)
{
    if(l>=zuo && r<=you)  return tmax[k];
    if(l>you || r<zuo)  return -INF;
    int mid=(l+r)>>1;
    return max(askmax(k+k,l,mid,zuo,you),askmax(k+k+1,mid+1,r,zuo,you));
}
int query(int a,int b)  // a up to b ¡ü 
{
    int maxx=-INF,l,r,x;
    while(belong[a]!=belong[b])
    {
         x=belong[a];l=pl[x];r=pl[a];
         maxx=max(maxx,askmax(1,1,n,l,r));
         a=fa[x][0];
    }
    if(a==b)  return maxx;
    l=pl[b]+1;r=pl[a];
    maxx=max(maxx,askmax(1,1,n,l,r));
    return maxx;
}
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
char get_c()
{
    char ch=getchar();
    while(ch!='C' && ch!='D' && ch!='Q')  ch=getchar();
    return ch;
}
int main()
{
    int i,a,b,c,T;
    char ch;    
    T=read();
    while(T--)
    {
        sz=0;tt=0;
        memset(last,0,sizeof(last));
        memset(fa,0,sizeof(fa));
        n=read();a=4*n;
        for(i=1;i<=a;i++)  tmax[i]=-INF;
        for(i=1;i<n;i++)  
        {
            a=read();b=read();c=read();
            Ins(a,b,c,i);Ins(b,a,c,i);
        }
        deep[1]=1;
        dfs1(1);
        dfs2(1,1);
        for(i=1;i<=n;i++)  updata(1,1,n,pl[i],quan[i]);                
        while(1)
        {
            ch=get_c();
            if(ch=='D')  break; 
            a=read();b=read();
            if(ch=='C')  updata(1,1,n,pl[bpl[a]],b);
            else
            {
                c=LCA(a,b);
                printf("%d\n",max(query(a,c),query(b,c)));
            }
        }
    }
    system("pause");
    return 0;
}
