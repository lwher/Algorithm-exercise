#include<iostream>
#include<cstdio>
#include<cstdlib>
#define N 300010
using namespace std;
int n,m;
int l[N],r[N],x[N];
int t[N<<2];
bool mark[N<<2];
void change(int l,int r,int k,int num,int zuo,int you)
{
     if(l==r)  {t[k]=num;return;}
     if(l>=zuo && r<=you)  {t[k]=num;mark[k]=1;return;}
     if(mark[k])
     {
         mark[k]=0;
         mark[k+k]=1;mark[k+k+1]=1;
         t[k+k]=t[k];t[k+k+1]=t[k];
     }
     int mid=(l+r)>>1;
     if(zuo<=mid)  change(l,mid,k+k,num,zuo,you);
     if(you>mid)   change(mid+1,r,k+k+1,num,zuo,you);
}
int get(int l,int r,int k,int wei)
{
    if(l==r)  return t[k];
    if(mark[k])
     {
         mark[k]=0;
         mark[k+k]=1;mark[k+k+1]=1;
         t[k+k]=t[k];t[k+k+1]=t[k];
     }
     int mid=(l+r)>>1;
     if(wei<=mid)  return get(l,mid,k+k,wei);
     if(wei>mid)   return get(mid+1,r,k+k+1,wei);
}
void init()
{
     int i;
     int a,b;
     scanf("%d%d",&n,&m);
     for(i=1;i<=m;i++)   scanf("%d%d%d",&l[i],&r[i],&x[i]);
     for(i=m;i>=1;i--)
     {
         a=x[i]-1;b=x[i]+1;
         if(a>=l[i])  change(1,n,1,x[i],l[i],a);
         if(b<=r[i])  change(1,n,1,x[i],b,r[i]);
     }
     for(i=1;i<=n;i++)
     printf("%d ",get(1,n,1,i));
}
int main()
{
    init();
    system("pause");
    return 0;    
}
