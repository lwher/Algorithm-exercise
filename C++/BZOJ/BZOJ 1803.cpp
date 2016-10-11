#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,tt,dfsxu[100010],ft[100010],sd[100010],fa[100010],quan[100010],w[100010];
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
     for(int i=last[x];i;i=pre[i]) 
     if(fa[x]!=to[i])  
     {
        fa[to[i]]=x;
        dfs(to[i]);
     }
     sd[x]=tt; 
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
int query(int x,int k)
{
    int L=ft[x]-1,R=sd[x],l=1,r=tot,mid,tmp;
    L=root[L];R=root[R];
    while(l!=r)
    {
        int mid=(l+r)>>1;
        tmp=sum[ls[R]]-sum[ls[L]];
        if(tmp>=k)  
        {
            r=mid;L=ls[L];R=ls[R];
        }
        else
        {
            l=mid+1;k-=tmp;L=rs[L];R=rs[R];
        }
    }
    return w[l];
}
int main()
{
    int i,a,b,k,t;
    scanf("%d",&n);
    for(i=1;i<=n;i++)  {scanf("%d",&quan[i]);shu[++top]=quan[i];}
    sort(shu+1,shu+1+n);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i]; 
    for(i=1;i<=n;i++)  {quan[i]=find(quan[i]);w[quan[i]]=i;}        
    for(i=1;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        Ins(a,b);Ins(b,a);
    }
    dfs(1);
    for(i=1;i<=n;i++)
    {
       t=dfsxu[i];
       updata(1,tot,root[i-1],root[i],quan[t]);
    }
    scanf("%d",&q);
    for(i=1;i<=q;i++)
    {
         scanf("%d%d",&a,&k);
         printf("%d\n",query(a,k));      
    }
    system("pause");
    return 0;
}
