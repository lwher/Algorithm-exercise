#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define M 12000010
using namespace std;
int n,m,root[80010],fa[80010][17],v[80010],deep[80010];
int sz,ls[M],rs[M],sum[M];
int tt,ft[80010],sd[80010];
int bsz,to[160010],pre[160010],last[80010];
int top,tot,shu[160010],num[160010];
int K[80010],A[80010],B[80010],L[100],R[100];
int lowbit(int x)  {return (x & (-x));}
void swap(int &a,int &b) {int t=a;a=b;b=t;}
void updata(int l,int r,int &y,int k,int cnt)
{
    if(!y)  y=++sz;
    sum[y]+=cnt;
    if(l==r) return;
    int mid=(l+r)>>1;
    if(k<=mid)  updata(l,mid,ls[y],k,cnt);
    else  updata(mid+1,r,rs[y],k,cnt);
}
void xiugai(int x,int k)
{
    for(int i=ft[x];i<=n;i+=lowbit(i))  updata(1,tot,root[i],v[x],-1);
    for(int i=sd[x]+1;i<=n;i+=lowbit(i))  updata(1,tot,root[i],v[x],1);
    v[x]=k;
    for(int i=ft[x];i<=n;i+=lowbit(i))  updata(1,tot,root[i],v[x],1);
    for(int i=sd[x]+1;i<=n;i+=lowbit(i))  updata(1,tot,root[i],v[x],-1);
}
void Ins(int a,int b)
{
    bsz++;to[bsz]=b;pre[bsz]=last[a];last[a]=bsz;
}
void dfs(int x)
{
    ft[x]=++tt;
    for(int i=1;i<=16;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
    for(int i=last[x];i;i=pre[i])
    {
        if(to[i]==fa[x][0])  continue;
        fa[to[i]][0]=x;deep[to[i]]=deep[x]+1;
        dfs(to[i]);
    }
    sd[x]=tt;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x)  return mid;
        if(num[mid]>x)   r=mid;
        else l=mid;
    }
    if(num[r]==x) return r; return l;
}
int lca(int a,int b)
{
    if(deep[a]<deep[b]) swap(a,b);
    int i,t=deep[a]-deep[b];
    for(i=16;i>=0;i--) if(t>=(1<<i))  {t-=(1<<i);a=fa[a][i];}
    for(i=16;i>=0;i--) if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
int query(int a,int b,int k)
{
    int i,t=lca(a,b),p=fa[t][0];L[0]=0;R[0]=0;
    for(i=ft[t];i>0;i-=lowbit(i)) L[++L[0]]=root[i];
    for(i=ft[p];i>0;i-=lowbit(i)) L[++L[0]]=root[i];
    for(i=ft[a];i>0;i-=lowbit(i)) R[++R[0]]=root[i];
    for(i=ft[b];i>0;i-=lowbit(i)) R[++R[0]]=root[i];
    t=0;
    for(i=1;i<=R[0];i++)  t+=sum[R[i]];
    for(i=1;i<=L[0];i++)  t-=sum[L[i]];
    if(t<k)  return -1;
    int l=1,r=tot,mid;
    while(l!=r)
    {
        t=0;mid=(l+r)>>1;
        for(i=1;i<=R[0];i++)  t+=sum[rs[R[i]]];
        for(i=1;i<=L[0];i++)  t-=sum[rs[L[i]]];
        if(t>=k)  
        {
            l=mid+1;
            for(i=1;i<=R[0];i++)  R[i]=rs[R[i]];
            for(i=1;i<=L[0];i++)  L[i]=rs[L[i]];
        }
        else
        {
            r=mid;k-=t;
            for(i=1;i<=R[0];i++)  R[i]=ls[R[i]];
            for(i=1;i<=L[0];i++)  L[i]=ls[L[i]];
        }
    }
    return l;
}
int main()
{
    int i,j,k,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&v[i]);
        shu[++top]=v[i];
    }
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&K[i],&A[i],&B[i]);
        if(K[i]==0)  shu[++top]=B[i];
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++) if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
    deep[(n+1)/2]=1;dfs((n+1)/2);
    for(i=1;i<=n;i++)  
    {
        v[i]=find(v[i]);
        for(j=ft[i];j<=n;j+=lowbit(j))  updata(1,tot,root[j],v[i],1);
        for(j=sd[i]+1;j<=n;j+=lowbit(j))  updata(1,tot,root[j],v[i],-1);
    }
    for(i=1;i<=m;i++) 
    {
        if(K[i]==0)
        {
            B[i]=find(B[i]);
            xiugai(A[i],B[i]);
        }
        else
        {
            j=query(A[i],B[i],K[i]);
            if(j==-1)  printf("invalid request!\n");
            else  printf("%d\n",num[j]);
        }
    }
//  system("pause");
    return 0;
}