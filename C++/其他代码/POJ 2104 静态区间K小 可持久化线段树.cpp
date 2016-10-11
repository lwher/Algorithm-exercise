#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 100010
using namespace std;
int n,m,sz,tot;
int p[N],num[N],shu[N],root[N];
int ls[N*20],rs[N*20],sum[N*20];
void build(int l,int r,int &rt)
{
     rt=++sz;
     sum[rt]=0;
     if(l==r)  return;
     int mid=(l+r)>>1;
     build(l,mid,ls[rt]);
     build(mid+1,r,rs[rt]);
}
int findpm(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
         mid=(l+r)>>1;
         if(num[mid]>x)  r=mid;
         else l=mid;
    }
    if(num[r]==x)  return r;
    else  return l;
}
void updata(int l,int r,int last,int &rt,int x)
{
     rt=++sz;
     sum[rt]=sum[last]+1;
     ls[rt]=ls[last];rs[rt]=rs[last];
     if(l==r) return;
     int mid=(l+r)>>1;
     if(x<=mid)  updata(l,mid,ls[last],ls[rt],x);
     else updata(mid+1,r,rs[last],rs[rt],x);
}
int queuy(int l,int r,int zuo,int you,int k)
{
     if(l==r) return l;
     int mid=(l+r)>>1;
     if(sum[ls[you]]-sum[ls[zuo]]>=k)  return queuy(l,mid,ls[zuo],ls[you],k);
     else return queuy(mid+1,r,rs[zuo],rs[you],k-(sum[ls[you]]-sum[ls[zuo]]));
}
int main()
{
    int i,j,a,b,c;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) 
    {
                      scanf("%d",&p[i]);
                      shu[i]=p[i];
    }
    sort(shu+1,shu+1+n);
    num[++tot]=shu[1];
    for(i=2;i<=n;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
    build(1,tot,root[0]);
    for(i=1;i<=n;i++)  updata(1,tot,root[i-1],root[i],findpm(p[i]));
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&a,&b,&c);                
        printf("%d\n",num[queuy(1,tot,root[a-1],root[b],c)]);
    }
    system("pause");
    return 0;
}
