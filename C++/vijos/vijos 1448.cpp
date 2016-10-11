#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;
int tl[150010],tr[150010];
int n,m;
void charul(int l,int r,int k,int x)
{
     if(l==r) {tl[k]++;return;}
     int mid=(l+r)>>1;
     if(x<=mid)  charul(l,mid,k+k,x);
     if(x>mid)   charul(mid+1,r,k+k+1,x);
     tl[k]=tl[k+k]+tl[k+k+1];
}
int getl(int l,int r,int k,int zuo,int you)
{
    if(zuo>r || you<l)  return 0;
    if(l>=zuo && r<=you)  return tl[k];
    int mid=(l+r)>>1;
    return getl(l,mid,k+k,zuo,you)+getl(mid+1,r,k+k+1,zuo,you); 
}
void charur(int l,int r,int k,int x)
{
     if(l==r) {tr[k]++;return;}
     int mid=(l+r)>>1;
     if(x<=mid)  charur(l,mid,k+k,x);
     if(x>mid)   charur(mid+1,r,k+k+1,x);
     tr[k]=tr[k+k]+tr[k+k+1];
}
int getr(int l,int r,int k,int zuo,int you)
{
    if(zuo>r || you<l)  return 0;
    if(l>=zuo && r<=you)  return tr[k];
    int mid=(l+r)>>1;
    return getr(l,mid,k+k,zuo,you)+getr(mid+1,r,k+k+1,zuo,you); 
}
int main()
{
    int i,a,b,k,suml,sumr;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d%d%d",&k,&a,&b);
        if(k==1)
        {
            charul(1,n,1,a);charur(1,n,1,b);
        }
        else
        {
            sumr=getr(1,n,1,a,n);suml=getl(1,n,1,b+1,n);
            printf("%d\n",sumr-suml);
        }
    }
    system("pause");
    return 0;
}
