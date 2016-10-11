#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<algorithm>
#define N 2200010
using namespace std;
int n,m,top,tot,sz;
int shuzi[10010],num[20010],shu[20010];
int sum[N],ls[N],rs[N];
int A[10010],B[10010],xw[10010],K[10010],root[10010];
int L[30],R[30],a,b;
inline int lowbit(int x)
{
       return x & (-x);
}
int find(int x)
{
    int l=1,r=tot,mid;
    while(l+1<r)
    {
        mid=(l+r)>>1;
        if(num[mid]>x)  r=mid;
        else l=mid;
    }
    if(num[r]==x)  return r; else return l;
}
void build(int l,int r,int &rt)
{
     rt=++sz;sum[rt]=0;
     if(l==r)  return;
     int mid=(l+r)>>1;
     build(l,mid,ls[rt]);build(mid+1,r,rs[rt]);
}
void updata(int last,int l,int r,int &rt,int w,int x)
{
     rt=++sz;
     sum[rt]=sum[last]+x;ls[rt]=ls[last];rs[rt]=rs[last];
     if(l==r)  return;
     int mid=(l+r)>>1;
     if(w<=mid)  updata(ls[last],l,mid,ls[rt],w,x);
     else  updata(rs[last],mid+1,r,rs[rt],w,x);
}
int query(int l,int r,int k)
{
     if(l==r)  return l;
     int i,suml=0,sumr=0;
     for(i=1;i<=a;i++)  suml+=sum[ls[L[i]]];
     for(i=1;i<=b;i++)  sumr+=sum[ls[R[i]]];
     int mid=(l+r)>>1;
     if(sumr-suml>=k) 
     {
         for(i=1;i<=a;i++)  L[i]=ls[L[i]];
         for(i=1;i<=b;i++)  R[i]=ls[R[i]];
         return query(l,mid,k);
     }
     else
     {
         for(i=1;i<=a;i++)  L[i]=rs[L[i]];
         for(i=1;i<=b;i++)  R[i]=rs[R[i]];
         return query(mid+1,r,k-(sumr-suml));
     }
}
int main()
{
    int i,j,ww;
    char s[3];
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)  {scanf("%d",&shuzi[i]);shu[++top]=shuzi[i];}
    for(i=1;i<=m;i++)
    {
         scanf("%s",s);  scanf("%d%d",&A[i],&B[i]);
         if(s[0]=='Q')  {scanf("%d",&K[i]);xw[i]=1;}
         else  {xw[i]=0;shu[++top]=B[i];}
    }
    sort(shu+1,shu+1+top);
    num[++tot]=shu[1];
    for(i=2;i<=top;i++)  if(shu[i]!=shu[i-1])  num[++tot]=shu[i];
    build(1,tot,root[0]);
    for(i=1;i<=n;i++)  
    {
        ww=find(shuzi[i]);
        for(j=i;j<=n;j+=lowbit(j))  updata(root[j],1,tot,root[j],ww,1);
    }
    for(i=1;i<=m;i++)
    {
        if(xw[i]==1)
        {
             a=0;b=0;A[i]--;
             for(j=A[i];j>0;j-=lowbit(j)) L[++a]=root[j];
             for(j=B[i];j>0;j-=lowbit(j)) R[++b]=root[j];
             printf("%d\n",num[query(1,tot,K[i])]);  
        }
        else
        {
             ww=find(shuzi[A[i]]);
             for(j=A[i];j<=n;j+=lowbit(j))  updata(root[j],1,tot,root[j],ww,-1);
             shuzi[A[i]]=B[i];
             ww=find(B[i]);
             for(j=A[i];j<=n;j+=lowbit(j))  updata(root[j],1,tot,root[j],ww,1);
        }
    }
    system("pause");
    return 0;
}
