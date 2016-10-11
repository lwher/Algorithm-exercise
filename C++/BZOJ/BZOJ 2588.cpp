#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,tt,lastans,dfsxu[100010],ft[100010],fa[100010][20],quan[100010],deep[100010];
int sz,root[100010],ls[2000010],rs[2000010],sum[2000010];
int bsz,to[200010],pre[200010],last[100010];
int top,shu[100010],tot,num[100010];
void Ins(int a,int b)
{
     bsz++;to[bsz]=b;pre[bsz]=last[a];last[a]=bsz;
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]==x)  return mid;
        if(num[mid]>x)  r=mid;
        else l=mid; 
    }
    if(num[l]==x) return l; return r;
}
void dfs(int x)
{
     dfsxu[++tt]=x;ft[x]=tt;
     for(int i=1;i<=17;i++)  fa[x][i]=fa[fa[x][i-1]][i-1];
     for(int i=last[x];i;i=pre[i]) 
     if(fa[x][0]!=to[i])  
     {
        fa[to[i]][0]=x;deep[to[i]]=deep[x]+1;
        dfs(to[i]);
     }
}
void updata(int l,int r,int x,int &y,int xx)
{
     y=++sz;
     sum[y]=sum[x]+1;
     if(l==r) return;
     ls[y]=ls[x];rs[y]=rs[x];
     int mid=(l+r)>>1;
     if(xx<=mid)  updata(l,mid,ls[x],ls[y],xx);
     else  updata(mid+1,r,rs[x],rs[y],xx);
}
void swap(int &a,int &b)
{
     int t=a;a=b;b=t;
}
int LCA(int a,int b)
{
    if(deep[a]<deep[b])  swap(a,b);
    int i,t;
    t=deep[a]-deep[b];
    for(i=17;i>=0;i--)  if(t>=(1<<i))  {t-=(1<<i);a=fa[a][i];}
    for(i=17;i>=0;i--)  if(fa[a][i]!=fa[b][i])  {a=fa[a][i];b=fa[b][i];}
    if(a==b) return a; return fa[a][0];
}
int query(int x,int y,int k)
{
    int a=x,b=y,c=LCA(x,y),d=fa[c][0],l=1,r=tot,mid,tmp;
    a=root[ft[a]];b=root[ft[b]];c=root[ft[c]];d=root[ft[d]];
    while(l!=r)
    {
        int mid=(l+r)>>1;
        tmp=sum[ls[a]]+sum[ls[b]]-sum[ls[c]]-sum[ls[d]];
        if(tmp>=k)  
        {
            r=mid;a=ls[a];b=ls[b];c=ls[c];d=ls[d];
        }
        else
        {
            l=mid+1;k-=tmp;a=rs[a];b=rs[b];c=rs[c];d=rs[d];
        }
    }
    return num[l];
}
int main()
{
    int i,a,b,k,t;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)  {scanf("%d",&quan[i]);shu[++top]=quan[i];}
    sort(shu+1,shu+1+n);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i]; 
    for(i=1;i<=n;i++)  quan[i]=find(quan[i]);    
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    deep[(n+1)/2]=1;
    dfs((n+1)/2);
    for(i=1;i<=n;i++)
    {
       t=dfsxu[i];
       updata(1,tot,root[ft[fa[t][0]]],root[i],quan[t]);
    }
    lastans=0;
    for(i=1;i<=q;i++)
    {
         scanf("%d%d%d",&a,&b,&k);
         a^=lastans;
         lastans=query(a,b,k);  
         printf("%d",lastans);
         if(i!=q)  printf("\n");     
    }
    system("pause");
    return 0;
}
