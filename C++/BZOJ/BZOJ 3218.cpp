#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 5010
#define M 500010
#define INF 0x7fffffff
using namespace std;
int n,B[N],W[N],A[N],L[N],R[N],P[N],root[N],s,t;
int xsz,ls[M],rs[M];
int sz=1,to[M],v[M],pre[M],last[M],cur[M];
int top,shu[M],num[M],tot;
int dui[M],h[M],gap[M];
int read()
{
    char ch=getchar();
    while(!(ch>='0' && ch<='9'))  ch=getchar();
    int x=0;
    while(ch>='0' && ch<='9')  {x=x*10+(ch-'0');ch=getchar();}
    return x;
}
void Ins(int a,int b,int c)
{
    sz++;to[sz]=b;v[sz]=c;pre[sz]=last[a];last[a]=sz;
    sz++;to[sz]=a;v[sz]=0;pre[sz]=last[b];last[b]=sz;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x) return mid;
        if(num[mid]<x) l=mid; else r=mid;
    }
    if(num[l]==x) return l; return r;
}
void updata(int l,int r,int x,int &y,int shuzi,int k)
{
    y=++xsz;
    if(l==r){if(x!=0) Ins(y,x,INF);Ins(y,k,INF);return;}
    ls[y]=ls[x];rs[y]=rs[x];
    int mid=(l+r)>>1;
    if(shuzi<=mid)  updata(l,mid,ls[x],ls[y],shuzi,k);
    else  updata(mid+1,r,rs[x],rs[y],shuzi,k);
    if(ls[y]) Ins(y,ls[y],INF);
    if(rs[y]) Ins(y,rs[y],INF);
}
void findseg(int l,int r,int x,int zuo,int you,int y)
{
    if(!x) return;
    if(l>=zuo && r<=you)  {Ins(y,x,INF);return;}
    int mid=(l+r)>>1;
    if(zuo<=mid)  findseg(l,mid,ls[x],zuo,you,y);
    if(you>mid)  findseg(mid+1,r,rs[x],zuo,you,y);
}
void init()
{
    n=read();//scanf("%d",&n);
    int i;xsz=n+n;s=++xsz;t=++xsz;
    for(i=1;i<=n;i++)
    {
        //scanf("%d%d%d%d%d%d",&A[i],&B[i],&W[i],&L[i],&R[i],&P[i]);
        A[i]=read();B[i]=read();W[i]=read();L[i]=read();R[i]=read();P[i]=read();
        shu[++top]=A[i];shu[++top]=L[i];shu[++top]=R[i];
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++) if(shu[i]!=shu[i-1]) num[++tot]=shu[i];
    for(i=1;i<=n;i++)
    {
        A[i]=find(A[i]);L[i]=find(L[i]);R[i]=find(R[i]);
    }
}
void build()
{
    for(int i=1;i<=n;i++)
    {
        Ins(s,i,B[i]);Ins(i,i+n,P[i]);
        updata(1,tot,root[i-1],root[i],A[i],i);
        findseg(1,tot,root[i],L[i],R[i],i+n);
        Ins(i,t,W[i]);
    }
}
bool bfs()
{
    memset(h,-1,sizeof(h));
    int tou=1,wei=1,now,i;
    dui[1]=t;h[t]=1;gap[1]=1;
    while(tou<=wei)
    {
        now=dui[tou];tou++;
        for(int i=last[now];i;i=pre[i])
        if(h[to[i]]==-1)
        {
            h[to[i]]=h[now]+1;
            gap[h[to[i]]]++;
            dui[++wei]=to[i];
        }
    }
}
int dfs(int x,int F)
{
    if(x==t) return F;
    int used=0,w,i;
    for(i=cur[x];i;i=pre[i])
    if(v[i]>0 && h[x]-1==h[to[i]])
    {
        w=min(v[i],F-used);
        w=dfs(to[i],w);
        v[i]-=w;v[i^1]+=w;used+=w;
        if(v[i]>0)  cur[x]=i;
        if(F==used)  return F;
    }
    gap[h[x]]--;
    if(!gap[h[x]])  h[s]=xsz+2;
    cur[x]=last[x];
    gap[++h[x]]++;
    return used;
}
int SAP()
{
    int i,tmp=0;
    for(i=1;i<=xsz;i++) cur[i]=last[i];
    bfs();
    while(h[s]<xsz+2)  tmp+=dfs(s,INF);
    return tmp;
}
void solve()
{
    int i,sum=0;
    for(i=1;i<=n;i++)  sum+=B[i]+W[i];
    printf("%d\n",sum-SAP());
}
int main()
{       
    init();
    build();
    solve();
    return 0;
}